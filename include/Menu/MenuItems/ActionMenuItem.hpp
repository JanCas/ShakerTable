#ifndef B34AE10D_35D1_4503_83DD_BE1A92BD961C
#define B34AE10D_35D1_4503_83DD_BE1A92BD961C

#include "Menu/MenuItems/MenuItem.hpp"

class ActionMenuItem : public MenuItem{
    public:
        ActionMenuItem(String ID, String prompt,void (*click_function)());
        
        void display(OledDisplay *oled);

        void on_click(OledDisplay *oled);
    
    private:
        String prompt;

        void (*click_function)();
};

#endif /* B34AE10D_35D1_4503_83DD_BE1A92BD961C */
