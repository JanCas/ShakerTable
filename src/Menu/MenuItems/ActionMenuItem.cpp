#include "Menu/MenuItems/ActionMenuItem.hpp"

ActionMenuItem::ActionMenuItem(String ID, String prompt, void (*click_function)()){
    this->click_function = click_function;
    this->ID = ID;
    this->prompt = prompt;
}

ActionMenuItem::ActionMenuItem(String ID, String prompt){
    this->ID = ID;
    this->prompt = prompt;
}

void ActionMenuItem::register_event(void (*click_function)()){
    this->click_function = click_function;
}

void ActionMenuItem::display(OledDisplay *oled){
    oled->clear();
    oled->write_text(0,10,3, prompt);
}

void ActionMenuItem::on_click(OledDisplay *oled){
    click_function();
}