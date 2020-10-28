#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "GUIAPI_String.h"
#include "GUIAPI_Vector.h"

#include "SE_MAIN.h"

#include <random>
#include <unistd.h>

/**************************************************************************************/
//This is the main class for all classes, except for one
/**************************************************************************************/
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

/**************************************************************************************/
//This class is for items inside layout.
/**************************************************************************************/
class GUIAPI_LayoutItem : private GUIAPI_Widget{
private:
    bool isReadOnly;
    GUIAPI_String tText;

    void setText(GUIAPI_String newText) { tText = newText; }
    void setText(const char* newText) { tText = GUIAPI_String(newText); }
    GUIAPI_String getText() { return tText; }
public:
    GUIAPI_LayoutItem(/* args */) {}
    ~GUIAPI_LayoutItem() {}
};

/*------------------------------------------------------------------------------------*/
//Layout items

/**************************************************************************************/
//This class with realisation of Label.
/**************************************************************************************/
class GUIAPI_IT_Label : private GUIAPI_LayoutItem{
private:
    void draw() {}
public:
    GUIAPI_IT_Label();
    GUIAPI_IT_Label(GUIAPI_String labelText);
    ~GUIAPI_IT_Label();
};

/**************************************************************************************/
//This class with realisation of TextBox.
/**************************************************************************************/
class GUIAPI_IT_TextBox : private GUIAPI_LayoutItem{
private:
    void draw() {}
public:
    GUIAPI_IT_TextBox();
    GUIAPI_IT_TextBox(GUIAPI_String textboxText);
    ~GUIAPI_IT_TextBox();
};

/**************************************************************************************/
//This class with realisation of PushButton.
/**************************************************************************************/
class GUIAPI_IT_PushButton : private GUIAPI_LayoutItem{
private:
    void draw() {}
public:
    GUIAPI_IT_PushButton(/* args */);
    GUIAPI_IT_PushButton(GUIAPI_String buttonText);
    ~GUIAPI_IT_PushButton();
};

/**************************************************************************************/
//This class with realisation of RadioButton.
/**************************************************************************************/
class GUIAPI_IT_RadioButton : private GUIAPI_LayoutItem{
private:
    void draw() {}
public:
    GUIAPI_IT_RadioButton(/* args */);
    GUIAPI_IT_RadioButton(GUIAPI_String buttonText);
    ~GUIAPI_IT_RadioButton();
};
/*------------------------------------------------------------------------------------*/


/**************************************************************************************/
//This class is a container for layout items. 
/**************************************************************************************/
class GUIAPI_Layout : private GUIAPI_Widget{
public:
    GUIAPI_Layout(/* args */);
    ~GUIAPI_Layout();

    void addWidget(GUIAPI_LayoutItem lItem) { lItems.append(lItem); iItems++; }
    
private:
    void draw() {}
    GUIAPI_Vector<GUIAPI_LayoutItem> lItems;
    uint32_t iItems;

};

/**************************************************************************************/
//This class is for drawing effects. 
/**************************************************************************************/
class GUIAPI_INPUT_MANAGER{
public:
    GUIAPI_INPUT_MANAGER();
    ~GUIAPI_INPUT_MANAGER();

    void connect(GUIAPI_LayoutItem* lItem, void* lItemParam, void* eItem, void* eItemParam);
};

/**************************************************************************************/
//This class is for drawing effects. 
/**************************************************************************************/
class GUIAPI_GFX{
private:
    static GUIAPI_GFX * p_instance;
    // Конструкторы и оператор присваивания недоступны клиентам
    GUIAPI_GFX() {}
    GUIAPI_GFX(const GUIAPI_GFX&);  
    GUIAPI_GFX& operator=(GUIAPI_GFX&);

    void* fnDrawPixel;

public:
    static GUIAPI_GFX *getInstance() {
        if(!p_instance)           
            p_instance = new GUIAPI_GFX();
        return p_instance;
    }

    void setDrawPixel(void* fnDrawPixel) { this->fnDrawPixel = fnDrawPixel; }
};

/**************************************************************************************/
//This class is the main class of all api. In this class you have to init layouts and main 
//procedures for communicate with display controller.
/**************************************************************************************/
class GUIAPI {
public:
    GUIAPI();
    GUIAPI(uint32_t sWidth, uint32_t sHeight);
    GUIAPI(void* fnDrawPixel, void* fnClearScreen, void* fnDisplay);
    GUIAPI(uint32_t sWidth, uint32_t sHeight, void* fnDrawPixel, void* fnClearScreen, void* fnDisplay);
    ~GUIAPI();

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

uint32_t width = 240;
uint32_t height = 320;

void drawPixelsTest(SE_MAIN *emu){
    emu->clear();
    emu->gfx.setCursorDefault();
    emu->gfx.print("Pixels test.", CL_YELLOW());
    for(uint32_t i = 0; i < 100; i++){
        emu->gfx.drawPixel(rand()%240, rand()%320, getRandomColor());
        emu->display();
    }
}

void drawLinesTest(SE_MAIN *emu){
    emu->clear();
    emu->gfx.setCursorDefault();
    emu->gfx.print("Lines test.", CL_YELLOW());
    for (int16_t x=0; x < width; x+=6){
        emu->gfx.drawLine(0, 0, x, height-1, getRandomColor());
        emu->display();
    }
        
    for (int16_t y=0; y < height; y+=6){
        emu->gfx.drawLine(0, 0, width-1, y, CL_RED());
        emu->display();
    }

    emu->clear();
    for (int16_t x=0; x < width; x+=6){
        emu->gfx.drawLine(width-1, 0, x, height-1, CL_GREEN());
        emu->display();
    }

    for (int16_t y=0; y < height; y+=6){
        emu->gfx.drawLine(width-1, 0, 0, y, CL_BLUE());
        emu->display();
    }

    emu->clear();
    for (int16_t x=0; x < width; x+=6){
        emu->gfx.drawLine(0, height-1, x, 0, CL_PINK());
        emu->display();
    }

    for (int16_t y=0; y < height; y+=6){
        emu->gfx.drawLine(0, height-1, width-1, y, CL_MAGENTA());
        emu->display();
    }

    emu->clear();
    for (int16_t x=0; x < width; x+=6){
        emu->gfx.drawLine(width-1, height-1, x, 0, CL_YELLOW());
        emu->display();
    }

    for (int16_t y=0; y < height; y+=6){
        emu->gfx.drawLine(width-1, height-1, 0, y, CL_GREY());
        emu->display();
    }
}

void drawFastLinesTest(SE_MAIN *emu){
    emu->clear();
    emu->gfx.setCursorDefault();
    emu->gfx.print("Fast lines test.", CL_YELLOW());
    for (int16_t y=0; y < height; y+=5) {
        emu->gfx.drawFastHLine(0, y, width, CL_MAGENTA());
        emu->display();
    }
    for (int16_t x=0; x < width; x+=5) {
        emu->gfx.drawFastVLine(x, 0, height, CL_YELLOW());
        emu->display();
    }
}

void drawRectTest(SE_MAIN *emu){
    emu->clear();
    emu->gfx.setCursorDefault();
    emu->gfx.print("Rect test.", CL_YELLOW());
    for (int16_t x=0; x < width; x+=6) {
        emu->gfx.drawRect(width/2 -x/2, height/2 -x/2 , x, x, getRandomColor());
        emu->display();
  }
}

void drawFillRectTest(SE_MAIN *emu){
    emu->clear();
    emu->gfx.setCursorDefault();
    emu->gfx.print("Fill rect test.", CL_YELLOW());
    for (int16_t x=0; x < width; x+=6) {
        emu->clear();
        emu->gfx.fillRect(width/2 -x/2, height/2 -x/2 , x, x, getRandomColor());
        emu->display();
  }
}

void drawTriangleTest(SE_MAIN *emu){
    emu->clear();
    int x = height-1;
    int y = 0;
    int z = width;
    emu->gfx.setCursorDefault();
    emu->gfx.print("Triangle test.", CL_YELLOW());
    for(uint32_t t = 0 ; t <= 30; t++) {
        emu->gfx.drawTriangle(width/2, y, y, x, z, x, getRandomColor());
        x-=2;
        y+=2;
        z-=2;
        emu->display();
    }
}

void drawCirclesTest(SE_MAIN *emu){
    emu->clear();
    uint32_t radius = 10;
    emu->gfx.setCursorDefault();
    emu->gfx.print("Circles test.", CL_YELLOW());
    for (int16_t x=0; x < width+radius; x+=radius*2) {
        for (int16_t y=0; y < height+radius; y+=radius*2) {
            emu->gfx.drawCircle(x, y, radius, getRandomColor());
        }
    }
    emu->display();
}

void drawFillCirclesTest(SE_MAIN *emu){
    emu->clear();
    uint32_t radius = 10;
    emu->gfx.setCursorDefault();
    emu->gfx.print("Fill circles test.", CL_YELLOW());
    for (int16_t x=0; x < width+radius; x+=radius*2) {
        for (int16_t y=0; y < height+radius; y+=radius*2) {
            emu->clear();
            emu->gfx.fillCircle(x, y, radius, getRandomColor());
            emu->display();
        }
    }
}

void drawPrintTextTest(SE_MAIN *emu){
    emu->clear();
    const char loremIpsum[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
    "Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla"
    "sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae"
    "malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem."
    "In vestibulum purus a tortor imperdiet posuere. ";
    emu->gfx.setCursorDefault();
    emu->gfx.print("Long text test.", CL_YELLOW());
    emu->gfx.setCursorDefault();
    for(uint32_t i = 0; i < 4; i++){
        emu->gfx.printText(loremIpsum, getRandomColor());
        emu->display();
    }
}

int main(int argc, char* argv[]){
    SE_MAIN emu(width, height);
    if(emu.init("..\\screen_emulator\\shaders\\")){
        while(emu.getWindowWorker()){
            emu.clear();
            drawPixelsTest(&emu);
            usleep(500000);

            drawLinesTest(&emu);
            usleep(500000);

            drawFastLinesTest(&emu);
            usleep(500000);

            drawRectTest(&emu);
            usleep(500000);

            drawFillRectTest(&emu);
            usleep(500000);

            drawTriangleTest(&emu);
            usleep(500000);

            drawCirclesTest(&emu);
            usleep(500000);

            drawFillCirclesTest(&emu);
            usleep(500000);

            drawPrintTextTest(&emu);
            usleep(500000);

            emu.gfx.setCursorDefault();
            emu.gfx.print("ALL TESTS DONE!.", CL_GREEN());
            emu.display();
            usleep(5000000);
            
            //emu.gfx.println("Hello World!!!");
            emu.display();
        }
    }
    system("pause");
    return 0;
}

