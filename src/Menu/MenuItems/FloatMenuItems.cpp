#include "Menu/MenuItems/FloatMenuItem.hpp"

FloatMenuItem::FloatMenuItem(String ID, String title, String unit, float *num, float *increment, RotaryEncoder *re, Button *b){
    this->num = num;
    this->ID = ID;
    this->title = title;
    this->unit = unit;
    clicked = false;
    this->re = re;
    this->b = b;

}

void FloatMenuItem::display(OledDisplay *oled){
    oled->clear();
    oled->write_text(0, 10, 1, title);
    oled->write_text(0, 20, 4, String(*num));
}

void FloatMenuItem::on_click(OledDisplay *oled){
    if (clicked){
        display(oled);
        clicked = false;
        return;
    }
    clicked = true;
    oled->clear();

while (!b->pressed()){
    re->tick();
  static int pos = 0;
  int newPos = re->getPosition();
  if (pos != newPos)
  {
    int dir = (int)(re->getDirection());
    if (dir == 1)
    {
      (*num) += increment;
    }else if (dir == -1){
      (*num) -= increment;
    }
    display(oled);
    pos = newPos;
  }
}
}