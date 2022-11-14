/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-oled
 */
#include <Arduino.h>
#include "RotaryEncoderClick.hpp"
#include "OledDisplay.hpp"
#include "Menu/Menu.hpp"
#include "Menu/MenuItems/FloatMenuItem.hpp"
#include "Menu/MenuItems/ActionMenuItem.hpp"

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

float frequency = .1;
float time = 100.02;

OledDisplay oled(SCREEN_HEIGHT, SCREEN_WIDTH, 0x3C);
Menu menu(&oled);

void action_function()
{
  oled.clear();
  oled.write_text(0, 10, 5, "Ac");
}

ActionMenuItem m3 = ActionMenuItem("Action", "RUN", &action_function);
Button b(53);

// MenuItem *items[3] = {&m1, &m2, &m3};
// int index = 0;

// RotaryEncoderClick re(A2, A3, 25);
RotaryEncoder re(A2, A3, RotaryEncoder::LatchMode::TWO03);

FloatMenuItem m1 = FloatMenuItem("Frequency_view", "Frequency:", &frequency, &re, &b);
FloatMenuItem m2 = FloatMenuItem("Second_view", "Time", &time, &re, &b);
void setup()
{
  if (!oled.init())
  {
    // Serial.println("testing failed");
  }
  b.begin();
  //Serial.begin(9600);
  // re.init();

  menu.add_menu_item(&m1);
  menu.add_menu_item(&m2);
  menu.add_menu_item(&m3);

  menu.display_current_menu_item();

  //menu.display_current_menu_item();
  //delay(2000);
  //menu.scroll_right();

}

void loop()
{
  // items[index]->display(&oled);
  //  menu.scroll_right();
  //  delay(5000);

  //  items[index]->on_click(&oled);
   
  // menu.clicked();
  //  delay(5000);
  //delay(5000);

  re.tick();

  static int pos = 0;
  int newPos = re.getPosition();
  if (pos != newPos)
  {
    int dir = (int)(re.getDirection());
    if (dir == 1)
    {
      menu.scroll_right();
    }else if (dir == -1){
      menu.scroll_left();
    }
    pos = newPos;
  }

  if (b.pressed()){
    menu.clicked();
  }
  // if (re.has_rotated()){
  //   re.get_pos();
  //   Serial.println(re.get_directon());
  // }
  /*
  if (re.has_rotated()){
    re.get_pos();
    if (re.get_directon() == 1){
      //Serial.println("Here");
      menu.scroll_right();
    }else{
      //Serial.println("Here2");
      menu.scroll_left();
    }
  }
  if (re.pressed()){
    //Serial.println("pressed");
    menu.clicked();
  }
  */
}
