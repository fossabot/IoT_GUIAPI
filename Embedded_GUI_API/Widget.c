#include "Widget.h"
#include <stdlib.h>
#include <string.h>

struct CGUIWidget_
{
	void* pUData;
	
	//�������� ��� ������� � �������� �������
	SGUI_Callbacks* pstCallbacks;

	//��������� �������
	EWidgetType eType;
	int			height;
	int			width;
	char*		text;
};

/*************************************************************************/
void Widget_create(CGUIWidget** ppWidget, const SGUI_Callbacks* pstCallbacks, void* pUData)
{
	CGUIWidget* pWidget;

	//������� ������
	(*ppWidget) = (CGUIWidget*)calloc(1, sizeof(CGUIWidget));
	pWidget = (*ppWidget);

	//���������, ��� ������ ������
	if (!pWidget)
		return /*GUI_RESULT_OUT_OF_MEMORY*/;

	pWidget->pUData       = pUData;
	//pWidget->pstCallbacks = pstCallbacks;

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
		//������ ����������� ������ ������� ���� � �������������� height*width, 
		//������� ������� ������� ����� pWidget->pstCallbacks->fnDrawPixel();

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
