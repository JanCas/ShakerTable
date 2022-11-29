#include "ShakerTable.hpp"

ShakerTable::ShakerTable(float *frequency, float *time, Menu *menu, OledDisplay *oled, RotaryEncoderClick *rotaryEncoderClick, MotorEncoder *motorEncoder){
    this->frequency = frequency;
    this->time = time;

    this->oled = oled;
    this->menu = menu;
    this->rotaryEncoderClick = rotaryEncoderClick;
    this->motorEncoder = motorEncoder;
}

void ShakerTable::step(){
    rotaryEncoderClick->tick();

    navigate_menu();
}

void ShakerTable::navigate_menu(){
    switch (rotaryEncoderClick->get_directon()){
        case RotaryEncoder::Direction::NOROTATION:
            break;
        case RotaryEncoder::Direction::CLOCKWISE:
            menu->scroll_right();
            break;
        case RotaryEncoder::Direction::COUNTERCLOCKWISE:
            menu->scroll_left();
            break;
    }

    if (rotaryEncoderClick->pressed()){
        menu->clicked();
    }
}

void ShakerTable::run(){

    // initial time in seconds
    float initial_time = millis() / 1000;

    while(initial_time + *time > (millis() / 1000)){
        motorEncoder->drive_to(*frequency);        
    }
}