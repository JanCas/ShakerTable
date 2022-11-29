#ifndef A5AC9153_70CD_4607_84F1_51A5E722E22E
#define A5AC9153_70CD_4607_84F1_51A5E722E22E

#include "Menu/Menu.hpp"
#include "OledDisplay.hpp"
#include "Menu/MenuItems/FloatMenuItem.hpp"
#include "Menu/MenuItems/ActionMenuItem.hpp"
#include "RotaryEncoderClick.hpp"
#include "MotorEncoder.hpp"

class ShakerTable{

    ShakerTable(float *frequency, float *time, Menu *menu, OledDisplay *oled, RotaryEncoderClick *rotaryEncoderClick, MotorEncoder *motorEncoder);

    void step();

    private:

        void run();
        void navigate_menu();

        float *frequency;

        float *time;

        Menu *menu;
        OledDisplay *oled;
        RotaryEncoderClick *rotaryEncoderClick;
        MotorEncoder *motorEncoder;


};

#endif /* A5AC9153_70CD_4607_84F1_51A5E722E22E */
