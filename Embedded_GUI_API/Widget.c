#include "Widget.h"
#include <stdlib.h>
#include <string.h>

struct CGUIWidget_
{
	void* pUData;
	
	//коллбэки для доступу к драйверу дисплея
	SGUI_Callbacks* pstCallbacks;

	//Параметры виджета
	EWidgetType eType;
	int			height;
	int			width;
	char*		text;
};

/*************************************************************************/
void Widget_create(CGUIWidget** ppWidget, const SGUI_Callbacks* pstCallbacks, void* pUData)
{
	CGUIWidget* pWidget;

	//создаем виджет
	(*ppWidget) = (CGUIWidget*)calloc(1, sizeof(CGUIWidget));
	pWidget = (*ppWidget);

	//проверяем, что объект создан
	if (!pWidget)
		return /*GUI_RESULT_OUT_OF_MEMORY*/;

	pWidget->pUData       = pUData;
	pWidget->pstCallbacks = pstCallbacks;

	//return GUI_RESULT_SUCCESSFUL;
}

/*************************************************************************/
void Widget_destroy(CGUIWidget* pWidget)
{

}


/*************************************************************************/
void Widget_draw(CGUIWidget* pWidget)
{
	switch (pWidget->eType)
	{
		//рисуем попиксельно виджет нужного типа в прямоугольнике height*width, 
		//дергаем драйвер дисплея через pWidget->pstCallbacks->fnDrawPixel();

	case EWIDGET_TYPE_BUTTON:
		break;
	case EWIDGET_TYPE_LABEL:
		break;
	case EWIDGET_TYPE_COMBOBOX:
		break;
	case EWIDGET_TYPE_LINEEDIT:
		break;
	default:
		return;
	}
}
