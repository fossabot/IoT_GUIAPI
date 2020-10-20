#ifndef OPEN_GUI_FRAMEWORK
#define OPEN_GUI_FRAMEWORK

#include <stdint.h>
#include <libs/List.h>

class LayoutItem{
public:
    void setDrawPixel(void (*drawPixel)(uint16_t, uint16_t, uint16_t)){
        this->drawPixel = drawPixel;
    }

    void draw(){

    }
private:
    void (*drawPixel)(uint16_t, uint16_t, uint16_t);

};

class Layout{
public:
    void draw(){
        for(int i = 0; i < items.GetSize(); i++){
            items[i].draw();
        }
    };

    void setDrawPixel(void (*drawPixel)(uint16_t, uint16_t, uint16_t)){
        this->drawPixel = drawPixel;
    }

    void add(LayoutItem item){
        LayoutItem *newItem = &item;
        newItem->setDrawPixel(drawPixel);
        items.push_back(*newItem);
    }

private:
    void (*drawPixel)(uint16_t, uint16_t, uint16_t);
    List<LayoutItem> items;
};

class GUI{
public:
    GUI() {}
    GUI(void (*drawPixelMethod)(uint16_t, uint16_t, uint16_t) = nullptr, void (*display)(void) = nullptr, void (*clear)(void) = nullptr){
        this->drawPixel = drawPixelMethod;
        this->display = display;
        this->clear = clear;
        current_layout = layout_size = 0;
    }

    void draw(){
        clear();
        layouts[current_layout].draw();
        //TODO: сделать вызов draw у всех нод
        display();
    }

    void add(Layout item){
        Layout *newLayout = &item;
        newLayout->setDrawPixel(drawPixel);
        layouts.push_back(*newLayout);
        layout_size++;
    }

    void setLayout(int layout_number) { 
        if(layout_number < layout_size){
            current_layout = layout_number;
        }else{
            return;
        }
    }
private:
    int current_layout;
    int layout_size;
    List<Layout> layouts;
    void (*display)(void);
    void (*clear)(void);
    void (*drawPixel)(uint16_t, uint16_t, uint16_t);
};

#endif