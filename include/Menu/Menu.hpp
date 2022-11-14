#ifndef AB13C0BA_9FE3_42F4_9F0E_BE5C2527C71B
#define AB13C0BA_9FE3_42F4_9F0E_BE5C2527C71B

#include <Arduino.h>
#include "OledDisplay.hpp"
#include "Menu/MenuItems/MenuItem.hpp"
#include <Vector.h>

#define MAX_MENU_ITEMS 10

/// @brief a class for displaying and managing a menu
/// there can be a maximum of 10 menu items
class Menu{
    public:
        Menu(OledDisplay *oled);

        void add_menu_item(MenuItem *menu_item);
        
        void scroll_right();
        void scroll_left();

        void display_current_menu_item();

        void clicked();

    private:

        OledDisplay *oled;
        // Vector<MenuItem*> menu_items;   
        MenuItem *menu_items[MAX_MENU_ITEMS];
        int index;
        int size;

        void set_index(bool increment);
};

#endif /* AB13C0BA_9FE3_42F4_9F0E_BE5C2527C71B */
