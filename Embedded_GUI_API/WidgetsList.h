#pragma once

#include "Widget.h"

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