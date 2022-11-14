#include "Menu/Menu.hpp"

Menu::Menu(OledDisplay *oled){
    index = 0;
    // MenuItem *backing_array[MAX_MENU_ITEMS];
    // menu_items = backing_array;
    // menu_items = Vector<MenuItem*>(backing_array);
    size = 0;
    this->oled = oled;
}

void Menu::add_menu_item(MenuItem *menu_item){
    menu_items[size] = menu_item;
    size++;    
}

void Menu::display_current_menu_item(){
    menu_items[index]->display(oled);
}

void Menu::scroll_right(){
    set_index(true);

    display_current_menu_item();
}

void Menu::scroll_left(){
    set_index(false);

    display_current_menu_item();
}

void Menu::set_index(bool increment){
    if (increment){
        index++;
    }else{
        index--;
    }
    if (index == size){
        index = 0;
    }
    if (index < 0){
        index = size -1;
    }
}

void Menu::clicked(){
    menu_items[index]->on_click(oled);
}