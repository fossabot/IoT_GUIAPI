#ifndef __GUIAPI_IT_PUSHBUTTON__
#define __GUIAPI_IT_PUSHBUTTON__

#include "../../GUIAPI_LayoutItem.h"

class GUIAPI_IT_PushButton : private GUIAPI_LayoutItem{
private:
    void draw();
public:
    GUIAPI_IT_PushButton(/* args */);
    GUIAPI_IT_PushButton(GUIAPI_String buttonText);
    ~GUIAPI_IT_PushButton();
};

#endif