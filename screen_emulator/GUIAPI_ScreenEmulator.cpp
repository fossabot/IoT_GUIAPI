#include "GUIAPI_ScreenEmulator.h"

#include "stdio.h"

bool drawRequest, clearRequest;
static GUIAPI_ScreenEmulator* currentInstance;

//Callbacks
/*****************************************************************************************/
extern "C"
void drawCallback(){
    currentInstance->drawFrame();
}

/*****************************************************************************************/
extern "C"
void resizeCallback(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1, 1);
    glScalef(1, -1, 1);
    glTranslatef(0, -h, 0);
}

/*****************************************************************************************/
extern "C"
void keyboardCallback(unsigned char c, int x, int y){
    currentInstance->keyboardHandler(c, x, y);
}



/*****************************************************************************************/
GUIAPI_ScreenEmulator::GUIAPI_ScreenEmulator(){
    setScreenSize(240, 320);
}

/*****************************************************************************************/
GUIAPI_ScreenEmulator::GUIAPI_ScreenEmulator(uint32_t sWidth, uint32_t sHeight){
    setScreenSize(sWidth, sHeight);
}

/*****************************************************************************************/
GUIAPI_ScreenEmulator::~GUIAPI_ScreenEmulator(){

}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::setScreenSize(uint32_t width, uint32_t height){
    this->width = width;
    this->height = height;
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::init(int argc, char* argv[]){
    glfwInit();
    #if defined(__APPLE__) || defined(__linux__)
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    window = glfwCreateWindow(width, height, "Screen Simulator", NULL, NULL);
	if (window == NULL) {
		fprintf(stdout, "Failed to create GLFW window!\n");
		glfwTerminate();
		return -1;
	}

    glfwMakeContextCurrent(window);

	glewInit();

    #ifdef GL_SHADING_LANGUAGE_VERSION
        printf("Supported GLSL version is %s.\n", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
    #endif
    printf("Using GLEW version %s.\n", glewGetString(GLEW_VERSION));
	printf("------------------------------\n");
	printf("Press space bar to cycle thru images.\n");
	printf("Press ESCAPE or 'X' or 'x' to exit.\n");

    while (!glfwWindowShouldClose(window)) {

    }
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::setPixel(uint32_t x, uint32_t y){
    xPos = x; yPos = y;
}

/*****************************************************************************************/
/*void GUIAPI_ScreenEmulator::setPixel(uint32_t x, uint32_t y, Pixel color){
    pixels[x][y] = color;
    newPixels[x][y] = color;
}*/

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::setColor(float r, float g, float b){
    glColor3f(r,g,b);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::setColor(Pixel color){
    glColor3f(color.r,color.g,color.b);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::display(){
    glutPostRedisplay();
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::clear(){
    glClear(GL_COLOR_BUFFER_BIT);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawFrame(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
    glPointSize(1);
    glColor3f(1, 1, 1);

    glBegin(GL_POINTS);
    glVertex2i(xPos,yPos);
    glEnd();
    glFlush();
    drawRequest = false;
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::keyboardHandler(unsigned char c, int x, int y){
    printf("Received: %c, Coords:%d, %d\r\n", c, x, y);
}