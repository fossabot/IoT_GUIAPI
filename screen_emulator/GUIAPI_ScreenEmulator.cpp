#include "GUIAPI_ScreenEmulator.h"

#include "stdio.h"

static GUIAPI_ScreenEmulator* pData;

char errNames[9][36] = {
    "Unknown OpenGL error",
    "GL_INVALID_ENUM", "GL_INVALID_VALUE", "GL_INVALID_OPERATION",
    "GL_INVALID_FRAMEBUFFER_OPERATION", "GL_OUT_OF_MEMORY",
    "GL_STACK_UNDERFLOW", "GL_STACK_OVERFLOW", "GL_CONTEXT_LOST" };

//Threads
/*****************************************************************************************/
extern "C"
void* drawingRunner(void* pUData){
    GUIAPI_ScreenEmulator* pTPO  = (GUIAPI_ScreenEmulator*)pUData;
    GLFWwindow *window = pTPO->window;
    glfwMakeContextCurrent(window);
    while (pTPO->running) {
        pTPO->drawFrame();

    }
    pTPO->isThreadStopped = true;
    return NULL;
}

//Callbacks
/*****************************************************************************************/
extern "C"
void window_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);		// Draw into entire window
}

/*****************************************************************************************/
extern "C"
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_RELEASE) {
        printf("Key pressed: %c \r\n", (char)key);
		return;			// Ignore key up (key release) events
	}
	if (key == GLFW_KEY_ESCAPE || key == GLFW_KEY_X) {
        pData->running = false;
		glfwSetWindowShouldClose(window, true);
	}
	else if (key == GLFW_KEY_SPACE) {
		//CurrentMode = (CurrentMode+1) % 6;	// Takes on values from 0 to 5
	}
}

/*****************************************************************************************/
extern "C"
void error_callback(int error, const char* description)
{
	// Print error
	fputs(description, stderr);
}

/*****************************************************************************************/
extern "C"
bool check_for_opengl_errors() {
    int numErrors = 0;
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR) {
        numErrors++;
        int errNum = 0;
        switch (err) {
        case GL_INVALID_ENUM:
            errNum = 1;
            break;
        case GL_INVALID_VALUE:
            errNum = 2;
            break;
        case GL_INVALID_OPERATION:
            errNum = 3;
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            errNum = 4;
            break;
        case GL_OUT_OF_MEMORY:
            errNum = 5;
            break;
        case GL_STACK_UNDERFLOW:
            errNum = 6;
            break;
        case GL_STACK_OVERFLOW:
            errNum = 7;
            break;
        case GL_CONTEXT_LOST:
            errNum = 8;
            break;
        }
        printf("OpenGL ERROR: %s.\n", errNames[errNum]);
    }
    return (numErrors != 0);
}


/*****************************************************************************************/
GUIAPI_ScreenEmulator::GUIAPI_ScreenEmulator(){
    setScreenSize(240, 320);
    init();
}

/*****************************************************************************************/
GUIAPI_ScreenEmulator::GUIAPI_ScreenEmulator(uint32_t sWidth, uint32_t sHeight){
    setScreenSize(sWidth, sHeight);
    init();
}

/*****************************************************************************************/
GUIAPI_ScreenEmulator::~GUIAPI_ScreenEmulator(){
    pthread_kill(drawingThread, 0);
	while (!isThreadStopped) {
		//_sleep(1);
	}
    glfwTerminate();
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::setScreenSize(uint32_t width, uint32_t height){
    this->width = width;
    this->height = height;
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::init(){
    glfwSetErrorCallback(error_callback);
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
		return;
	}

    glfwMakeContextCurrent(window);

    GLenum result = glewInit();
	if(result != GLEW_OK){
        fprintf(stdout, "GLEW init error. %s\r\n", glewGetErrorString(result));
    }

    #ifdef GL_SHADING_LANGUAGE_VERSION
        printf("Supported GLSL version is %s.\n", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
    #endif
    printf("Using GLEW version %s.\n", glewGetString(GLEW_VERSION));
	printf("------------------------------\n");
	printf("Press space bar to cycle thru images.\n");
	printf("Press ESCAPE or 'X' or 'x' to exit.\n");

    pData = this;

    glfwSetFramebufferSizeCallback(window, window_size_callback);
    glfwSetKeyCallback(window, key_callback);
    window_size_callback(window, width, height);

    unsigned int a;
    glGenBuffers(1, &a);

    pthread_mutex_init(&drawingMutex, 0);

    if(pthread_create(&drawingThread, NULL, drawingRunner, this) != 0){
        printf("Error while starting drawing thread.\r\n");
        return;
    }

    running = true;
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
    
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::setColor(Pixel color){
    
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::display(){
    isDrawRequired = true;
    glfwSwapBuffers(window);
    glfwWaitEvents();
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::clear(){
    
}

/*****************************************************************************************/
bool GUIAPI_ScreenEmulator::getWindowWorker(){
    return !glfwWindowShouldClose(window);
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::drawFrame(){

    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
}

/*****************************************************************************************/
void GUIAPI_ScreenEmulator::keyboardHandler(unsigned char c, int x, int y){
    printf("Received: %c, Coords:%d, %d\r\n", c, x, y);
}