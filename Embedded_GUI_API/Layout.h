#pragma once

#include "WidgetsList.h"

/*Объект Layout*/
typedef struct CGUILayout_ CGUILayout;

/*************************************************************************/
void/*EGUIResult*/ Layout_create(CGUILayout** ppLayout, void* pUData);
void/*EGUIResult*/ Layout_destroy(CGUILayout* pLayout);

void/*EGUIResult*/ Layout_addWidget(CGUILayout* pLayout, CGUIWidget* widget, int x_pos, int y_pos);
void/*EGUIResult*/ Layout_draw(CGUILayout* pLayout);
void/*EGUIResult*/ Layout_findWidget(CGUILayout* pLayout, CGUIWidget* widget, int* x_pos, int *y_pos);
