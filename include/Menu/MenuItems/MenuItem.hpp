#ifndef DD6660EC_A33D_4778_9D10_59CADBF1DC2F
#define DD6660EC_A33D_4778_9D10_59CADBF1DC2F

#include <Arduino.h>
#include "OledDisplay.hpp"

class MenuItem{
    public:
        MenuItem() {}
        virtual void display(OledDisplay *oled)=0;
        virtual void on_click(OledDisplay *oled)=0;
        String id() { return ID; } ;

        ~MenuItem() {}

    protected:
        bool clicked;
        String ID;
};

#endif /* DD6660EC_A33D_4778_9D10_59CADBF1DC2F */
