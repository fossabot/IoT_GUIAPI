
#include <iostream>
#include "EmbedGUIAPI.h"

int main()
{
    /*Create GUI*/
    /*******************************************************/
    CGUI* GUI;
    if (GUI_create(&GUI, 0) == GUI_RESULT_SUCCESSFUL)
        std::cout << "GUI created successfully\n";
    else
        std::cout << "GUI create error\n";

    /*GUI application example*/
    /*******************************************************/
    CGUILayout* layout;
    GUI_createLayout(GUI, &layout);

    CGUIWidget* widget;
    GUI_createWidget(GUI, &widget);

    GUI_addWidgetToLayout(GUI, layout, widget);

    GUI_displayLayout(GUI, layout);


    /*******************************************************/
    while (1) {};
    
}

