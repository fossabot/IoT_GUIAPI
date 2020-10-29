#ifndef __GUIAPI_LAYOUT__
#define __GUIAPI_LAYOUT__

#include "GUIAPI_LayoutItem.h"

class GUIAPI_Layout : private GUIAPI_Widget{
public:
    GUIAPI_Layout(/* args */);
    ~GUIAPI_Layout();

    void addWidget(GUIAPI_LayoutItem lItem) { lItems.append(lItem); iItems++; }
    
private:
    void draw() {}
    GUIAPI_Vector<GUIAPI_LayoutItem> lItems;
    uint32_t iItems;

};

#endif