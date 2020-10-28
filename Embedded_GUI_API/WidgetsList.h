#ifndef __WIDGETSLIST__
#define __WIDGETSLIST__

#include "Widget.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

typedef struct WidgetsList_ {
	CGUIWidget* value;
	int x_pos;
	int y_pos;
	struct WidgetsList_* next;
} WidgetsList;

void createList();
void clearList();
void deleteList();
void pushList();
void popList();
CGUIWidget* findListByPos(int x_pos, int y_pos);
void        findListByValue(CGUIWidget* value, int* x_pos, int* y_pos);

#ifdef __cplusplus
} /*extern "C"*/
#endif /*__cplusplus*/

#endif