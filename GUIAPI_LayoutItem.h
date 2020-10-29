#ifndef __GUIAPI_LAYOUTITEM__
#define __GUIAPI_LAYOUTITEM__

#include "GUIAPI_Widget.h"

class GUIAPI_LayoutItem : private GUIAPI_Widget{
private:
    bool isReadOnly;
    GUIAPI_String tText;

    void setText(GUIAPI_String newText) { tText = newText; }
    void setText(const char* newText) { tText = GUIAPI_String(newText); }
    GUIAPI_String getText() { return tText; }
public:
    GUIAPI_LayoutItem(/* args */) {}
    ~GUIAPI_LayoutItem() {}
};

#endif