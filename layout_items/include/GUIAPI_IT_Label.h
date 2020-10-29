#ifndef __GUIAPI_IT_LABEL__
#define __GUIAPI_IT_LABEL__

#include "../../GUIAPI_LayoutItem.h"

class GUIAPI_IT_Label : private GUIAPI_LayoutItem{
private:
    void draw();
public:
    GUIAPI_IT_Label();
    GUIAPI_IT_Label(GUIAPI_String labelText);
    ~GUIAPI_IT_Label();
};

#endif