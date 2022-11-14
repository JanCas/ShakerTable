#ifndef DAA365B9_3897_49EA_9EAA_437DB492AFCE
#define DAA365B9_3897_49EA_9EAA_437DB492AFCE

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OledDisplay{
    private:
        int height;
        int width;
        uint8_t addr;
        Adafruit_SSD1306 oled;

    public:
        OledDisplay(int height, int width, uint8_t addr);

        bool init();

        void clear();

        void write_text(int x, int y, int size, String message);
};

#endif /* DAA365B9_3897_49EA_9EAA_437DB492AFCE */
