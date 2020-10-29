#ifndef __GUIAPI_WIDGET__
#define __GUIAPI_WIDGET__

#include "GUIAPI_String.h"
#include "GUIAPI_Vector.h"

class GUIAPI_Widget{
public:
    GUIAPI_Widget() {}
    ~GUIAPI_Widget() {}
    
private:
    uint32_t xPos;
    uint32_t yPos;
    uint32_t width;
    uint32_t height;

    bool isEnabled;
    bool isVisible;
    /*style*/
private:
    void draw() {}

    inline void setXPos(uint32_t xPos) { this->xPos = xPos; }
    inline void setYPos(uint32_t yPos) { this->yPos = yPos; }
    inline void setWidth(uint32_t width) { this->width = width; }
    inline void setHeight(uint32_t height) { this->height = height; }

    inline void setEnabled(bool newState) { isEnabled = newState; }
    inline void setVisible(bool newState) { isVisible = newState; }

    inline uint32_t getXPos() { return xPos; }
    inline uint32_t getYPos() { return yPos; }
    inline uint32_t getWidth() { return width; }
    inline uint32_t getHeight() { return height; }
};

#endif