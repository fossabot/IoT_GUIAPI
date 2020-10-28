#ifndef __WIDGET__
#define __WIDGET__

#include "Common.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

typedef enum EWidgetType_
{
	EWIDGET_TYPE_BUTTON,
	EWIDGET_TYPE_LABEL,
	EWIDGET_TYPE_COMBOBOX,
	EWIDGET_TYPE_LINEEDIT
}EWidgetType;

/*������ Widget*/
typedef struct CGUIWidget_ CGUIWidget;

/*************************************************************************/
void/*EGUIResult*/ Widget_create(CGUIWidget** ppWidget, const SGUI_Callbacks* pstCallbacks, void* pUData);
void/*EGUIResult*/ Widget_destroy(CGUIWidget* pWidget);

void/*EGUIResult*/ Widget_draw(CGUIWidget* pWidget);

#ifdef __cplusplus
} /*extern "C"*/
#endif /*__cplusplus*/

#endif