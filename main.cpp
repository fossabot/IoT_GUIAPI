#include <stdlib.h>
#include <stdint.h>

#include "oguifw.h"

void drawPixel(uint16_t x, uint16_t y, uint16_t color){
  return;
}

void display(){
  return;
}

void clear(){
  return;
}

GUI gui = GUI(drawPixel, display, clear);

int main(){
  Layout testLayout;

  gui.add(testLayout);
  
  gui.draw();

  while (1){
  
  }
  return 0;
}

