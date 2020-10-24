#include "Layout.h"
#include <stdlib.h>
#include <string.h>

struct CGUILayout_
{
	void* pUData;

	WidgetsList* widgets;	//Список добавленных виджетов
};


/*************************************************************************/
void Layout_create(CGUILayout** ppLayout, void* pUData)
{
	CGUILayout* pLayout;

	//создаем Layout
	(*ppLayout) = (CGUILayout*)calloc(1, sizeof(CGUILayout));
	pLayout = (*ppLayout);

	//проверяем, что объект создан
	if (!pLayout)
		return /*GUI_RESULT_OUT_OF_MEMORY*/;

	//список виджетиов пока пуст
	pLayout->widgets = 0;

	//return GUI_RESULT_SUCCESSFUL;
}


/*************************************************************************/
void Layout_destroy(CGUILayout* pLayout)
{

}


/*************************************************************************/
void Layout_addWidget(CGUILayout* pLayout, CGUIWidget* widget)
{
	//добавляем его в список виджетов для данного лэйаута
	pushList();
}


/*************************************************************************/
void Layout_draw(CGUILayout* pLayout)
{
	//проходимся по всему списку виджетов и вызываем метод Widget_draw для каждого
}
