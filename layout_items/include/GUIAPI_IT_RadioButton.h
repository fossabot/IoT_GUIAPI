#ifndef __GUIAPI_IT_RADIOBUTTON__
#define __GUIAPI_IT_RADIOBUTTON__

#include "../../GUIAPI_LayoutItem.h"

class GUIAPI_IT_RadioButton : private GUIAPI_LayoutItem{
private:
    void draw();
public:
    GUIAPI_IT_RadioButton(/* args */);
    GUIAPI_IT_RadioButton(GUIAPI_String buttonText);
    ~GUIAPI_IT_RadioButton();
};

#endif