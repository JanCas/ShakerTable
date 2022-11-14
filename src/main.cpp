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

#include <MotorEncoder.hpp>

MotorEncoder Enc1(12,11,10,3,2,195,20); // (int ena_pin, int in1_pin, int in2_pin, int encoder_pin1, int encoder_pin2, int gear_ratio, int count)


void setup()
{
 Serial.begin(9600);
 Enc1.turn_on();
 Enc1.set_pid_values(1000,0,0,1);
 Enc1.reset_time();
 delay(50);
}

void loop()
{
  // Serial.println(Enc1.get_pos());
  // Testing range .12 Hz to .41 Hz
  Enc1.pid(6); 
  delay(100);  
}
