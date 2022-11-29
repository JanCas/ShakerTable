#include <Arduino.h>
#include "RotaryEncoderClick.hpp"
#include "OledDisplay.hpp"
#include "Menu/Menu.hpp"
#include "Menu/MenuItems/FloatMenuItem.hpp"
#include "Menu/MenuItems/ActionMenuItem.hpp"

/*

for motor wires:

  12  white
  11 grey 
  10 brown
  3 grey
  2 red

*/

#include <MotorEncoder.hpp>

MotorEncoder Enc1(12,11,10,3,2,195,20); // (int ena_pin, int in1_pin, int in2_pin, int encoder_pin1, int encoder_pin2, int gear_ratio, int count)
float t = 0;

void setup()
{
 Serial.begin(9600);
 Enc1.turn_on();
Enc1.set_pid_values(600,0,1.8,1);
  Enc1.reset_time();
//Enc1.set_speed(255);
}

void loop()
{
//  Serial.println(Enc1.get_pos());
   Enc1.pid(.5); 
}
