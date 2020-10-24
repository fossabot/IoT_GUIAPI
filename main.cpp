#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**************************************************************************************/
//This is the main class for all classes, except for one
/**************************************************************************************/
class GUIAPI_Widget{
public:
    GUIAPI_Widget();
    ~GUIAPI_Widget();
    
private:
    void draw();
    uint32_t xPos;
    uint32_t yPos;
    uint32_t width;
    uint32_t height;
};

/**************************************************************************************/
//This class is for items inside layout.
/**************************************************************************************/
class GUIAPI_LayoutItem : private GUIAPI_Widget{
private:
    /* data */
public:
    GUIAPI_LayoutItem(/* args */);
    ~GUIAPI_LayoutItem();
};

/*------------------------------------------------------------------------------------*/
//Layout items

/**************************************************************************************/
//This class of realisation of TextBox.
/**************************************************************************************/
class GUIAPI_IT_TextBox : private GUIAPI_LayoutItem{
private:
    /* data */
public:
    GUIAPI_IT_TextBox(/* args */);
    ~GUIAPI_IT_TextBox();
};

/**************************************************************************************/
//This class of realisation of PushButton.
/**************************************************************************************/
class GUIAPI_IT_PushButton : private GUIAPI_LayoutItem{
private:
    /* data */
public:
    GUIAPI_IT_PushButton(/* args */);
    ~GUIAPI_IT_PushButton();
};
/*------------------------------------------------------------------------------------*/


/**************************************************************************************/
//This class is a container for layout items. 
/**************************************************************************************/
class GUIAPI_Layout : private GUIAPI_Widget{
public:
    GUIAPI_Layout(/* args */);
    ~GUIAPI_Layout();

    void addWidget(GUIAPI_LayoutItem lItem);
    
private:
    GUIAPI_LayoutItem* lItems;

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
public:
    static GUIAPI_GFX *getInstance() {
        if(!p_instance)           
            p_instance = new GUIAPI_GFX();
        return p_instance;
    }
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

int main(){

  while (1){
  
  }
  return 0;
}

