#include "EmbedGUIAPI.h"
#include <stdlib.h>
#include <string.h>

/*********************** Func prototypes ********************************/
void drawCursor_(CGUI* pGUI, int x_pos, int y_pos);


/************************************************************************/
struct CGUI_
{
	void* pUData;  

	//тут тоже нужно список из лэйаутов хранить, а не текущий лэйаут
	CGUILayout* pLayout;

	//коллбэки для доступа к драйверу дисплея
	SGUI_Callbacks* pstCallbacks;

};

/************************************************************************/
EGUIResult GUI_create(CGUI** ppGUI, const SGUI_Callbacks *pstCallbacks, void* pUData)
{
	CGUI* pGUI = 0;

	//создаем объект 
	(*ppGUI) = (CGUI*)calloc(1, sizeof(CGUI));
	pGUI = (*ppGUI);

	//проверяем, что объект создан
	if (!pGUI)
		return GUI_RESULT_OUT_OF_MEMORY;

	//заполняем пользовательские данные
	pGUI->pUData = pUData;

	//Коллбэки
	pGUI->pstCallbacks = pstCallbacks;

	//лэйаут пока не назначили
	pGUI->pLayout = 0;

	return GUI_RESULT_SUCCESSFUL;
}


/************************************************************************/
EGUIResult GUI_destroy(CGUI* pGUI)
{
	free(pGUI);
	pGUI = 0;

	return GUI_RESULT_SUCCESSFUL;
}

/************************************************************************/
EGUIResult GUI_displayLayout(CGUI* pGUI, CGUILayout* pLayout)
{
	Layout_draw(pLayout);

	return GUI_RESULT_SUCCESSFUL;
}


/************************************************************************/
EGUIResult GUI_setCursor(CGUI* pGUI, CGUILayout* pLayout, CGUIWidget* pWidget)
{
	//ищем позицию виджета в лэйауте
	int x_pos;
	int y_pos;
	Layout_findWidget(pLayout, pWidget, &x_pos, &y_pos);

	//рисуем курсор из этой позиции
	drawCursor_(pGUI, x_pos, y_pos);
}

/************************************************************************/
EGUIResult GUI_createLayout(CGUI* pGUI, CGUILayout** ppLayout)
{
	Layout_create(ppLayout, 0);

	//добавляем его как текущий (потом тут будет добавление в список лэйаутов)
	pGUI->pLayout = *ppLayout;

	return GUI_RESULT_SUCCESSFUL;
}

/************************************************************************/
EGUIResult GUI_createWidget(CGUI* pGUI, CGUIWidget** ppWidget)
{
	Widget_create(ppWidget, pGUI->pstCallbacks, 0);

	return GUI_RESULT_SUCCESSFUL;
}

/************************************************************************/
EGUIResult GUI_addWidgetToLayout(CGUI* pGUI, CGUILayout* pLayout, CGUIWidget* pWidget, int x_pos, int y_pos)
{
	Layout_addWidget(pLayout, pWidget, x_pos, y_pos);

	return GUI_RESULT_SUCCESSFUL;
}


/************************************************************************/
void drawCursor_(CGUI* pGUI, int x_pos, int y_pos)
{
	//дергаем pGUI->pstCallbacks->fnDrawPixel, чтобы нарисовать попиксельно курсор
}
