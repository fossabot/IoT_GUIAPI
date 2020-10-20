#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>

#include <oguifw.h>
#include <Adafruit_GFX_rus.h>
#include <Adafruit_PCD8544_rus.h>

Adafruit_PCD8544 disp = Adafruit_PCD8544(10, 9, 8, 7, 6);

void drawPixel(uint16_t x, uint16_t y, uint16_t color){
  disp.drawPixel(x, y, color);
}

void display(){
  disp.display();
}

void clear(){
  disp.clearDisplay();
}

GUI gui = GUI(drawPixel, display, clear);

int main(){
  
  disp.begin();
  disp.setContrast(60);
  //disp.clearDisplay();
  //disp.drawPixel(5, 5, 1);
  //disp.display();
  Layout testLayout;

  gui.add(testLayout);
  
  gui.draw();
  //disp.display();

  while (1){
  
  }
  return 0;
}

