#include <stdlib.h>
#include <stdint.h>

/**************************************************************************************/
typedef struct{
    uint32_t x;
    uint32_t y;
} GUIAPI_UT_POSITION;

/**************************************************************************************/
typedef struct{
    uint32_t width;
    uint32_t height;
} GUIAPI_UT_SIZE;

/**************************************************************************************/
typedef struct{
    void* fnDrawPixel;
    void* fnClearScreen;
    void* fnDisplay;

    GUIAPI_UT_SIZE szDisplaySize;
} GUIAPI_MAIN;

enum {
    E_LAYOUT_ITEM_TEXTBOX,
    E_LAYOUT_ITEM_PUSHBUTTON,
    E_LAYOUT_ITEM_PROGRESSBAR
}E_GUIAPI_LAYOUT_ITEM_CLASS;

typedef struct{
    E_GUIAPI_LAYOUT_ITEM_CLASS eItemClass;
}GUIAPI_LAYOUT_ITEM;

/**************************************************************************************/
typedef struct {
    GUIAPI_UT_POSITION pLayoutPosition;
    GUIAPI_UT_SIZE     szLayoutSize;       //0, 0 - full screen

    bool bEnabled;
    GUIAPI_LAYOUT_ITEM aLayoutItems;
} GUIAPI_UI_LAYOUT_BOX;

/**************************************************************************************/
typedef struct {
    GUIAPI_UT_POSITION pLayoutPosition;
    GUIAPI_UT_SIZE     szLayoutSize;       //0, 0 - full screen

    char cText[128];
    bool bEnabled;
    void* fnChangeEvent;
    /*Style...*/
} GUIAPI_UI_TEXTBOX;

typedef struct {
    GUIAPI_UT_POSITION pLayoutPosition;
    GUIAPI_UT_SIZE     szLayoutSize;       //0, 0 - full screen

    char cText[64];
    bool bEnabled;
    void* fnClickEvent;
    /*Style...*/
} GUIAPI_UI_PUSH_BUTTON;

typedef struct {
    GUIAPI_UT_POSITION pLayoutPosition;
    GUIAPI_UT_SIZE     szLayoutSize;       //0, 0 - full screen

    uint32_t
    bool bEnabled;
    void* fnClickEvent;
    /*Style...*/
} GUIAPI_UI_PROGRESSBAR;


int main(){

  while (1){
  
  }
  return 0;
}

