#ifndef CE9F2571_3A04_402B_BA6C_835CAF34030C
#define CE9F2571_3A04_402B_BA6C_835CAF34030C

#include "Menu/MenuItems/MenuItem.hpp"
#include "RotaryEncoder.h"
#include "Button.h"

class FloatMenuItem : public MenuItem{
    public:

        void display(OledDisplay *oled);
        void on_click(OledDisplay *oled);

        FloatMenuItem(String ID, String title, String unit,float *num, float *increment, RotaryEncoder *re, Button *b);

    private:

        String title;
        String unit;
        float *num;
        float increment;
        Button *b;
        RotaryEncoder *re;

};

#endif /* CE9F2571_3A04_402B_BA6C_835CAF34030C */
