#pragma once

#include "Widget.h"

typedef struct WidgetsList_ {
	CGUIWidget* value;
	struct WidgetsList_* next;
} WidgetsList;


void createList();
void clearList();
void deleteList();
void pushList();
void popList();