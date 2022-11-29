#include "RotaryEncoderClick.hpp"

RotaryEncoderClick::RotaryEncoderClick(int Pin1, int Pin2, int clicked_pin){
    re = new RotaryEncoder(Pin1, Pin2, RotaryEncoder::LatchMode::TWO03);
    b = new Button(clicked_pin);
}

void RotaryEncoderClick::init(){
    b->begin();
}

void RotaryEncoderClick::tick(){
    re->tick();
    pos = re->getPosition();
}

bool RotaryEncoderClick::pressed(){
    return b->pressed();
}

RotaryEncoder::Direction RotaryEncoderClick::get_directon(){
    return re->getDirection();
}

int RotaryEncoderClick::get_pos(){
    return pos;
}

bool RotaryEncoderClick::has_rotated(){
    return (pos != re->getPosition());
}