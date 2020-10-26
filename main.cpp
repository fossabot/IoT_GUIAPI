#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "GUIAPI_String.h"
#include "GUIAPI_Vector.h"

#include "GUIAPI_ScreenEmulator.h"

#include <random>

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

int main(int argc, char* argv[]){

  GUIAPI_ScreenEmulator emu(240, 320);
    emu.init(argc, argv);

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 200); // define the range

    while(true){
        //emu.clear();
        emu.setPixel(distr(gen), distr(gen));
        emu.display();
    }
    system("pause");
    return 0;
}

