#include "RotaryEncoderClick.hpp"

RotaryEncoderClick::RotaryEncoderClick(int Pin1, int Pin2, int clicked_pin){
    re = new RotaryEncoder(Pin1, Pin2, RotaryEncoder::LatchMode::TWO03);
    b = new Button(clicked_pin);
}

void RotaryEncoderClick::init(){
    b->begin();
}

void RotaryEncoderClick::tick(){
    //pos = re->getPosition();
    re->tick();
}

bool RotaryEncoderClick::pressed(){
    b->pressed();
}

int RotaryEncoderClick::get_directon(){
    return (int)re->getDirection();
}

int RotaryEncoderClick::get_pos(){
    pos = re->getPosition();
    return pos;
}

bool RotaryEncoderClick::has_rotated(){
    return (pos != re->getPosition());
}