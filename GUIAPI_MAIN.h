#ifndef __GUIAPI_MAIN__
#define __GUIAPI_MAIN__

#include "GUIAPI_Layout.h"

class GUIAPI_MAIN {
public:
    GUIAPI_MAIN();
    GUIAPI_MAIN(uint32_t sWidth, uint32_t sHeight);
    GUIAPI_MAIN(void* fnDrawPixel, void* fnClearScreen, void* fnDisplay);
    GUIAPI_MAIN(uint32_t sWidth, uint32_t sHeight, void* fnDrawPixel, void* fnClearScreen, void* fnDisplay);
    ~GUIAPI_MAIN();

    void addLayout(GUIAPI_Layout lLayout);
    void setScreenSize(uint32_t sWidth, uint32_t sHeight);
    void setDrawPixelFn(void* fnDrawPixel);
    void setClearScreenFn(void* fnClearScreen);
    void setDisplayFn(void* fnDisplay);

    void display();     /*lLayout[selectedLayout].draw(); fnDisplay;*/

    GUIAPI_Layout getLayout(uint32_t iLayoutIndex);
    uint32_t getScreenWidth();
    uint32_t getScreenHeight();

private:
    uint32_t sWidth;
    uint32_t sHeight;

    void* fnDrawPixel;
    void* fnClearScreen;
    void* fnDisplay;

    GUIAPI_Layout* lLayouts;

    uint32_t selectedLayout;
};


#endif