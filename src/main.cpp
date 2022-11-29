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

MotorEncoder Enc1(12, 11, 10, 3, 2, 195, 20); // (int ena_pin, int in1_pin, int in2_pin, int encoder_pin1, int encoder_pin2, int gear_ratio, int count)
int test_length = 30000;                      // ms
int num_tests = 3;
void setup()
{
  Serial.begin(9600);
  Enc1.turn_on();
  Enc1.set_pid_values(600, 0, 1.8, 1);
  Enc1.reset_time();
  // Enc1.set_speed(255);
}

void loop()
{
  for (float freq = .5; freq <= 1.0; freq += .25)
  {
    Serial.println("---------------------------------------------------------------------------------------------");
    Serial.print("Setting the frequency: ");
    Serial.println(freq);
    Serial.println("---------------------------------------------------------------------------------------------");
    Serial.println();

    for (int i = 0; i < num_tests; i++)
    {
      Serial.print("Test: ");
      Serial.println(i);

      long start_time = millis();
      Enc1.reset_time();
      while (start_time + test_length > millis())
      {
        Enc1.pid(.5);
      }
    }
    Serial.println();
    Serial.println();
  }
}
