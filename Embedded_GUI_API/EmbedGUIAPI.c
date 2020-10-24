#include "EmbedGUIAPI.h"
#include <stdlib.h>
#include <string.h>



/************************************************************************/
struct CGUI_
{
	void* pUData;  

	//тут тоже нужно список из лэйаутов хранить, а не текущий лэйаут
	CGUILayout* pLayout;

};

/************************************************************************/
EGUIResult GUI_create(CGUI** ppGUI, void* pUData)
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
	Widget_create(ppWidget, 0);

	return GUI_RESULT_SUCCESSFUL;
}

/************************************************************************/
EGUIResult GUI_addWidgetToLayout(CGUI* pGUI, CGUILayout* pLayout, CGUIWidget* pWidget)
{
	Layout_addWidget(pLayout, pWidget);

	return GUI_RESULT_SUCCESSFUL;
}
