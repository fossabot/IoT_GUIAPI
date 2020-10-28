
#include <iostream>
#include "EmbedGUIAPI.h"

EGUICallbackResult fnDrawPixel();
EGUICallbackResult fnClearScreen();


int main()
{
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
