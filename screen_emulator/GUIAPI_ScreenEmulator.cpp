#include "GUIAPI_ScreenEmulator.h"

#include "stdio.h"
#include "stdlib.h"
#include <cstring>

#include <chrono>
#include <cmath>

#include "character_codes.h"

static GUIAPI_ScreenEmulator* pData;

/*****************************************************************************************/
/****************************************CALLBACKS****************************************/
/*****************************************************************************************/
extern "C"
void window_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);		// Draw into entire window
}

/*****************************************************************************************/
extern "C"
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    pData->keyboardHandler((unsigned char)key, scancode, action, mods);
}

/*****************************************************************************************/
/**************************************CONSTRUCTORS***************************************/
/*****************************************************************************************/
GUIAPI_ScreenEmulator::GUIAPI_ScreenEmulator(){
    setScreenSize(240, 320);
    pixelCounter = 0;
}

/*****************************************************************************************/
GUIAPI_ScreenEmulator::GUIAPI_ScreenEmulator(uint32_t sWidth, uint32_t sHeight){
    setScreenSize(sWidth, sHeight);
    pixelCounter = 0;
}

/*****************************************************************************************/
GUIAPI_ScreenEmulator::~GUIAPI_ScreenEmulator(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::setScreenSize(uint32_t width, uint32_t height){
    this->width = width;
    this->height = height;
    pixelCounter = 0;
}

/*****************************************************************************************/
/**************************************INITIALISATION*************************************/
/*****************************************************************************************/
bool GUIAPI_ScreenEmulator::init(){
    return init("");
}
bool GUIAPI_ScreenEmulator::init(std::string shaderFolderPath){
    printf("Before init anything is ok.\r\n");
    glfwInit();

    #ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    window = glfwCreateWindow(width, height, "Screen Simulator", NULL, NULL);
	if (window == NULL) {
		fprintf(stdout, "Failed to create GLFW window!\n");
		glfwTerminate();
		return false;
	}

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetFramebufferSizeCallback(window, window_size_callback);
    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        fprintf(stdout, "Failed to initialize GLAD\n");
        return false;
    }

    //Shaders initialisation
    shaderLoader.addShaderPath(shaderFolderPath);
    shaderLoader.loadShaders();

    //Init vertex array
    initVertexes();

    glEnable(GL_DOUBLEBUFFER);
    glDisable(GL_DEPTH_TEST);

    #ifdef GL_SHADING_LANGUAGE_VERSION
        printf("Supported GLSL version is %s.\n", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
    #endif
    printf("Using GLEW version %s.\n", glGetString(GL_VERSION));
	printf("------------------------------\n");
	printf("Press space bar to cycle thru images.\n");
	printf("Press ESCAPE or 'X' or 'x' to exit.\n");

    pData = this;
    return true;
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::initVertexes(){

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, getBufferSize(), 0, GL_DYNAMIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::display(){
    /*static std::chrono::steady_clock::time_point prv = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point cur = std::chrono::steady_clock::now();
    const float dt = std::chrono::duration< float >( cur - prv ).count();
    prv = cur;*/
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(shaderLoader.getProgram());
    glBindVertexArray(VAO);

    glDrawArrays(GL_POINTS, 0, pixelCounter);

    //printf("FPS: %f\r\n", 1000/dt);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::clear(){
    //glDeleteBuffers();
    //glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * width*height, 0, GL_DYNAMIC_DRAW);
    pixelCounter = 0;
}

/*****************************************************************************************/
bool GUIAPI_ScreenEmulator::getWindowWorker(){
    return !glfwWindowShouldClose(window);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::keyboardHandler(unsigned char c, int scancode, int action, int mods){
    if (action == GLFW_RELEASE) {
        printf("Pixels in array: %llu \r\n", pixelCounter);
		return;			// Ignore key up (key release) events
	}
	if (c == GLFW_KEY_ESCAPE || c == GLFW_KEY_X) {
		glfwSetWindowShouldClose(window, true);
	}
	else if (c == GLFW_KEY_SPACE) {
		//CurrentMode = (CurrentMode+1) % 6;	// Takes on values from 0 to 5
	}
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::createPixel(float x, float y, Color color){
    Pixel pixel;
    pixel.pos.x = x;
    pixel.pos.y = y;
    pixel.pos.z = 0.0f;
    pixel.color = color;
    setPixel(pixel);
    pixelCounter++;
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::setPixel(Pixel pixel){
    union dataToData{
        Pixel pix;
        float floats[6];
    } data;

    data.pix = pixel;
    glBufferSubData(GL_ARRAY_BUFFER, pixelCounter*sizeof(data.floats), sizeof(data.floats), &data.floats);
}

/*****************************************************************************************/
/**********************************Drawing GFX methods************************************/
/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawPixel(uint32_t x, uint32_t y, Color color){
    float x0 = ((2.0f*(float)x+1.0f)/width)-1.0f;
    float y0 = ((2.0f*(float)y+1.0f)/height)-1.0f;
    createPixel(x0, y0, color);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, Color color){
    int steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        swap(x0, y0);
        swap(x1, y1);
    }
    if (x0 > x1) {
        swap(x0, x1);
        swap(y0, y1);
    }
    int dx, dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);
    int err = dx / 2;
    int ystep;
    if (y0 < y1) {ystep = 1;}
    else {ystep = -1;};
    for ( ; x0 <= x1; x0++) {
        if (steep) {drawPixel(y0, x0, color);}
        else {drawPixel(x0, y0, color);};
		err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawFastVLine(uint32_t x, uint32_t y, uint32_t h, Color color){
    drawLine(x, y, x, y+h-1, color);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawFastHLine(uint32_t x, uint32_t y, uint32_t w, Color color){
    drawLine(x, y, x+w-1, y, color);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, Color color){
    drawFastHLine(x, y, w, color);
    drawFastHLine(x, y+h-1, w, color);
    drawFastVLine(x, y, h, color);
    drawFastVLine(x+w-1, y, h, color);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::fillRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, Color color){
    for (int16_t i=x; i<x+w; i++) {
        drawFastVLine(i, y, h, color);
    }
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::fillScreen(Color color){
    fillRect(0, 0, width, height, color);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawEllipse(uint32_t x, uint32_t y, uint32_t width, uint32_t height, Color color){
    for (uint32_t j = 0; j < 360; j++){
        double angle_circle = (j*0.01745331);
        uint32_t x_edge = (x + (width*cos(angle_circle)));
        uint32_t y_edge = (y + (height*sin(angle_circle)));
        drawPixel(x_edge,y_edge, color);
    }
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::fillEllipse(uint32_t x, uint32_t y, uint32_t width, uint32_t height, Color color){
    uint32_t newWidth = width;
    uint32_t newHeight = height;
    while(newWidth > 0 && newHeight > 0){
        drawEllipse(x, y, newWidth, newHeight, color);
        newWidth--;
        newHeight--;
    }
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawCircle(uint32_t x, uint32_t y, uint32_t radius, Color color){
    drawEllipse(x, y, radius, radius, color);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::fillCircle(uint32_t x, uint32_t y, uint32_t radius, Color color){
    fillEllipse(x, y, radius, radius, color);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::roundRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t r, Color color){
    uint32_t max_radius = ((w < h) ? w : h) / 2; // 1/2 minor axis
    //if (r > max_radius)
    //    r = max_radius;
    // smarter version
    //writeFastHLine(x + r, y, w - 2 * r, color);         // Top
    //writeFastHLine(x + r, y + h - 1, w - 2 * r, color); // Bottom
    //writeFastVLine(x, y + r, h - 2 * r, color);         // Left
    //writeFastVLine(x + w - 1, y + r, h - 2 * r, color); // Right
    // draw four corners
    //drawCircleHelper(x + r, y + r, r, 1, color);
    //drawCircleHelper(x + w - r - 1, y + r, r, 2, color);
    //drawCircleHelper(x + w - r - 1, y + h - r - 1, r, 4, color);
    //drawCircleHelper(x + r, y + h - r - 1, r, 8, color);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawTriangle(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, Color color){
    drawLine(x0, y0, x1, y1, color);
    drawLine(x1, y1, x2, y2, color);
    drawLine(x2, y2, x0, y0, color);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawChar(uint32_t x, uint32_t y, Color bg, Color color, uint32_t size, unsigned char c){
    if((x >= width) ||(y >= height) || ((x + 4) < 0) || ((y + 7) < 0)) return;
	if(c<128)            c = c-32;
	if(c>=144 && c<=175) c = c-48;
	if(c>=128 && c<=143) c = c+16;
	if(c>=176 && c<=191) c = c-48;
	if(c>191)  return;
	for (uint8_t i=0; i<6; i++ ) {
		uint8_t line;
		if (i == 5) {line = 0x00;}
		else {
			line = font[(c*5)+i];
			for (uint8_t j = 0; j<8; j++)
			{
				if (line & 0x01) {
					if(size == 1){
						drawPixel(x+i, y+j, color);
					}else{
						fillRect(x+(i*size), y+(j*size), size, size, color);
					}
				}else if(true){
					if(size == 1){
						drawPixel(x+i, y+j, bg);
					}else{
						fillRect(x+(i*size), y+(j*size), size, size, bg);
					}
				}
				line >>= 1;
			}
		}
	}
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::print(const char* str){

}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::println(const char* str){

}

/*****************************************************************************************/
/**************************************Static utils***************************************/
/*****************************************************************************************/
float GUIAPI_ScreenEmulator::getRandomFloat(){
    union UNION {
        uint32_t i;
        float f;
    } r;
    r.i = (rand() & 0xffffff) + ((rand() & 0x3fffff) << 16);
    return r.f;
}

/*****************************************************************************************/
Color GUIAPI_ScreenEmulator::getRandomColor(){
    Color color;
    color.r = getRandomFloat();
    color.g = getRandomFloat();
    color.b = getRandomFloat();
    return color;
}

/*****************************************************************************************/
Color GUIAPI_ScreenEmulator::RGBtoColor(float r, float g, float b){
    Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    return color;
}  