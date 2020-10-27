#ifndef __GUIAPI_SCREEN_EMULATOR__
#define __GUIAPI_SCREEN_EMULATOR__

#include "stdint.h"

#define GLEW_STATIC
//#include <GL/glew.h> 
#include "glad/glad.h"
#include <GLFW/glfw3.h>

typedef struct{
    float r, g, b;
} Color;

typedef struct{
    uint32_t x, y;
} Position;

typedef struct{
    Position pos;
    Color color;
} Pixel;

class GUIAPI_ScreenEmulator{
public:
    GUIAPI_ScreenEmulator();
    GUIAPI_ScreenEmulator(uint32_t sWidth, uint32_t sHeight);
    ~GUIAPI_ScreenEmulator();

    void setScreenSize(uint32_t width, uint32_t height);

    void init();

    void initShaders();
    void initVertexes();

    void setColor(Pixel &pixel);
    void display();
    void clear();

    bool getWindowWorker();

/********************************Public GFX Methods**************************************/
public:
    void drawPixel(uint32_t x, uint32_t y, Color color);
    void drawLine(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, Color color);
    void drawFastVLine(uint32_t x, uint32_t y, uint32_t h, Color color);
    void drawFastHLine(uint32_t x, uint32_t y, uint32_t w, Color color);
    void drawRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, Color color);
    void fillRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, Color color);
    void fillScreen(Color color);
    void drawEllipse(uint32_t x, uint32_t y, uint32_t width, uint32_t height, Color color);
    void fillEllipse(uint32_t x, uint32_t y, uint32_t width, uint32_t height, Color color);
    void drawCircle(uint32_t x, uint32_t y, uint32_t radius, Color color);
    void fillCircle(uint32_t x, uint32_t y, uint32_t radius, Color color);
    //void drawTriangle();
    //void fillTriangle();

    void drawChar(uint32_t x, uint32_t y, Color bg, Color color, uint32_t size, unsigned char c);
    void print(const char* str);
    void println(const char* str);

/**********************************Utils**************************************/
public:
    static float getRandomFloat();
    static Color getRandomColor();
    static Color RGBtoColor(float r, float g, float b);
    static Color CL_BLACK()   { return RGBtoColor(0.0f, 0.0f, 0.0f); }
    static Color CL_WHITE()   { return RGBtoColor(1.0f, 1.0f, 1.0f); }
    static Color CL_RED()     { return RGBtoColor(1, 0.0f, 0.0f); }
    static Color CL_GREEN()   { return RGBtoColor(0.0f, 1.0f, 0.0f); }
    static Color CL_BLUE()    { return RGBtoColor(0.0f, 0.0f, 1.0f); }
    static Color CL_GREY()    { return RGBtoColor(0.5f, 0.5f, 0.5f); }
    static Color CL_YELLOW()  { return RGBtoColor(1.0f, 1.0f, 0.0f); }
    static Color CL_MAGENTA() { return RGBtoColor(0.55f, 0.0f, 0.55f); }
    static Color CL_PINK()    { return RGBtoColor(1.0f, 0.43f, 0.71f); }

/**********************************GL private variables**************************************/
private:
    GLFWwindow* window;
    GLuint VBO, VAO, EBO;
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program;

/**********************************Emulator variables**************************************/
private:
    //Screen size
    uint64_t width;
    uint64_t height;

    //Text cursor
    uint32_t cursorX;
    uint32_t cursorY;

    uint64_t pixelCounter;
    Pixel *pixels;

private:
    void setPixel(Pixel pixel);
    void setColor(Color color);
    void setPosition(Position position);

    void swap(uint32_t &a, uint32_t &b) { 
        uint32_t t = a; 
        a = b; 
        b = t; 
    }

public:
    void keyboardHandler(unsigned char c, int scancode, int action, int mods);
};


#endif