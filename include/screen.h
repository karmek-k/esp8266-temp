#ifndef SCREEN_H
#define SCREEN_H

#include <U8g2lib.h>

namespace karmek
{
    class Screen
    {
    private:
        U8G2_SSD1306_128X64_NONAME_1_SW_I2C device;

    public:
        Screen(uint8_t clockPin, uint8_t dataPin);

        void print(int x, int y, const char *str);
    };
}

#endif