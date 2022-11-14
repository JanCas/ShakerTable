#include "OledDisplay.hpp"

OledDisplay::OledDisplay(int height, int width, uint8_t addr){
    oled = Adafruit_SSD1306(width, height);
    this->addr = addr;
}

bool OledDisplay::init(){  
    if (!oled.begin(SSD1306_SWITCHCAPVCC, addr)) {
        //Serial.println(F("SSD1306 allocation failed"));
        return false;
    }

    this->clear();
    delay(2000);
    return true;
}

void OledDisplay::clear(){
    oled.clearDisplay();
    oled.display();
}

void OledDisplay::write_text(int x, int y, int size, String message){
    oled.setCursor(x, y);
    oled.setTextColor(WHITE);
    oled.setTextSize(size);
    oled.println(message);
    oled.display();
}