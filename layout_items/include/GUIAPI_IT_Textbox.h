#ifndef __GUIAPI_IT_TEXTBOX__
#define __GUIAPI_IT_TEXTBOX__

#include "../../GUIAPI_LayoutItem.h"

class GUIAPI_IT_TextBox : private GUIAPI_LayoutItem{
private:
    void draw();
public:
    GUIAPI_IT_TextBox();
    GUIAPI_IT_TextBox(GUIAPI_String textboxText);
    ~GUIAPI_IT_TextBox();
};

#endif