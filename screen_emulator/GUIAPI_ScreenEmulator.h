#ifndef __GUIAPI_SCREEN_EMULATOR__
#define __GUIAPI_SCREEN_EMULATOR__

#include "stdint.h"

#define GLEW_STATIC
#include <GL/glew.h> 
#include <GLFW/glfw3.h>


typedef struct{
    float r, g, b;
} Pixel;

class GUIAPI_ScreenEmulator{
public:
    GUIAPI_ScreenEmulator();
    GUIAPI_ScreenEmulator(uint32_t sWidth, uint32_t sHeight);
    ~GUIAPI_ScreenEmulator();

    void setScreenSize(uint32_t width, uint32_t height);

    void init(int argc, char** argv);

    void setPixel(uint32_t x, uint32_t y);
    void setColor(float r, float g, float b);
    void setColor(Pixel color);
    void display();
    void clear();
private:
    GLFWwindow* window;
    uint32_t width;
    uint32_t height;

    uint32_t xPos, yPos;

public:
    void drawFrame();
    void keyboardHandler(unsigned char c, int x, int y);
};


#endif