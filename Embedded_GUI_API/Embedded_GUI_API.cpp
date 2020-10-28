
#include <iostream>
#include "EmbedGUIAPI.h"
#include "SE_MAIN.h"
#include <unistd.h>

EGUICallbackResult fnDrawPixel();
EGUICallbackResult fnClearScreen();


int main()
{
    uint64_t width = 240, height = 320;
    //Creating emulator object
    SE_MAIN emu(width, height);
    //Init object with path to shaders
    if(emu.init("..\\..\\screen_emulator\\shaders\\")){
        //Starting main program loop
        //It's just example and test how it works in this project
        while(emu.getWindowWorker()){
            emu.clear();
            emu.gfx.setCursorDefault();
            emu.gfx.print("Lines test.", CL_YELLOW());
            for (int16_t x=0; x < width; x+=6){
                emu.gfx.drawLine(0, 0, x, height-1, getRandomColor());
                emu.display();
            }
                
            for (int16_t y=0; y < height; y+=6){
                emu.gfx.drawLine(0, 0, width-1, y, CL_RED());
                emu.display();
            }

            emu.clear();
            for (int16_t x=0; x < width; x+=6){
                emu.gfx.drawLine(width-1, 0, x, height-1, CL_GREEN());
                emu.display();
            }

            for (int16_t y=0; y < height; y+=6){
                emu.gfx.drawLine(width-1, 0, 0, y, CL_BLUE());
                emu.display();
            }

            emu.clear();
            for (int16_t x=0; x < width; x+=6){
                emu.gfx.drawLine(0, height-1, x, 0, CL_PINK());
                emu.display();
            }

            for (int16_t y=0; y < height; y+=6){
                emu.gfx.drawLine(0, height-1, width-1, y, CL_MAGENTA());
                emu.display();
            }

            emu.clear();
            for (int16_t x=0; x < width; x+=6){
                emu.gfx.drawLine(width-1, height-1, x, 0, CL_YELLOW());
                emu.display();
            }

            for (int16_t y=0; y < height; y+=6){
                emu.gfx.drawLine(width-1, height-1, 0, y, CL_GREY());
                emu.display();
            }
            usleep(500000);
        }
    }
    /*Create GUI*/
    /*******************************************************/
    CGUI* GUI;
    //� ��������� ������� ��������������� ����� ��������
    SGUI_Callbacks stCallbacks;
    
    stCallbacks.fnDrawPixel    = fnDrawPixel;
    stCallbacks.fFnClearScreen = fnClearScreen;

    if (GUI_create(&GUI, &stCallbacks, 0) == GUI_RESULT_SUCCESSFUL)
        std::cout << "GUI created successfully\n";
    else
        std::cout << "GUI create error\n";

    /*GUI application example*/
    /*******************************************************/
    CGUILayout* layout;
    GUI_createLayout(GUI, &layout);

    CGUIWidget* widget;
    GUI_createWidget(GUI, &widget);

    GUI_addWidgetToLayout(GUI, layout, widget, 1/*x_pos*/, 1/*y_pos*/);

    GUI_displayLayout(GUI, layout);

    //� �������� �������� ��������������� ����� ������� ����������
    //��������, ���� ������ �� ������� �� ������� ������ ��������� �� ��������� ������
    GUI_setCursor(GUI, layout, widget);


    /*******************************************************/
    while (1) {};
    
}

/*******************************************************/
EGUICallbackResult fnDrawPixel()
{
    return GUI_CALLBACK_RESULT_SUCCESSFUL;
}

/*******************************************************/
EGUICallbackResult fnClearScreen()
{
    return GUI_CALLBACK_RESULT_SUCCESSFUL;
}
