#pragma once

//#ifdef __cplusplus
extern "C" {
//#endif /*__cplusplus*/

#include "Layout.h"
#include "Widget.h"

/*������ GUI*/
typedef struct CGUI_ CGUI;


/************************ Functions **************************************/
EGUIResult GUI_create(CGUI** ppGUI, const SGUI_Callbacks* pstCallbacks, void* pUData);
EGUIResult GUI_destroy(CGUI* ppGUI);

//������� Layout
EGUIResult GUI_createLayout(CGUI* pGUI, CGUILayout** ppLayout);
//������� ������
EGUIResult GUI_createWidget(CGUI* pGUI, CGUIWidget** ppWidget);

//�������� ������ � Layout
EGUIResult GUI_addWidgetToLayout(CGUI* pGUI, CGUILayout* pLayout, CGUIWidget* pWidget, int x_pos, int y_pos);

//���������� ������
EGUIResult GUI_displayLayout(CGUI* pGUI, CGUILayout* pLayout);

//���������� ������
EGUIResult GUI_setCursor(CGUI* pGUI, CGUILayout* pLayout, CGUIWidget* pWidget);


//#ifdef __cplusplus
} /*extern "C"*/
//#endif /*__cplusplus*/
