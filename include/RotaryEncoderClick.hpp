#ifndef E63D2C9E_830A_49B3_B9CB_ED9C733043AE
#define E63D2C9E_830A_49B3_B9CB_ED9C733043AE

#include <RotaryEncoder.h>
#include <Button.h>

class RotaryEncoderClick{
    public:
        RotaryEncoderClick(int Pin1, int Pin2, int click_pin);

        void init();
        void tick();

        int get_pos();
        int get_directon();
        bool pressed();
        bool has_rotated();

    private:
        RotaryEncoder *re;
        Button *b;
        int pos;
};

#endif /* E63D2C9E_830A_49B3_B9CB_ED9C733043AE */
