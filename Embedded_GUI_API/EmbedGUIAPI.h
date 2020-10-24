#pragma once

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

#include "Layout.h"
#include "Widget.h"

/*************************************************************************/
/*Коды, возвращаемые функциями объекта*/
typedef enum
{
	GUI_RESULT_SUCCESSFUL = 0,     /*OK*/
	GUI_RESULT_ERROR = -1001, /*Ошибка*/
	GUI_RESULT_OUT_OF_MEMORY = -1002, /*Нехватака памяти*/
}
EGUIResult;

/*Объект GUI*/
typedef struct CGUI_ CGUI;

/*************************************************************************/
EGUIResult GUI_create(CGUI** ppGUI, void* pUData);
EGUIResult GUI_destroy(CGUI* ppGUI);
/*************************************************************************/

//создаем Layout
EGUIResult GUI_createLayout(CGUI* pGUI, CGUILayout** ppLayout);
//создаем Виджет
EGUIResult GUI_createWidget(CGUI* pGUI, CGUIWidget** ppWidget);

//добавить виджет в Layout
EGUIResult GUI_addWidgetToLayout(CGUI* pGUI, CGUILayout* pLayout, CGUIWidget* pWidget);

//нарисовать лэйаут
EGUIResult GUI_displayLayout(CGUI* pGUI, CGUILayout* pLayout);


#ifdef __cplusplus
} /*extern "C"*/
#endif /*__cplusplus*/
