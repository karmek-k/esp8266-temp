#include "screen.h"

using namespace karmek;

Screen::Screen(uint8_t clockPin, uint8_t dataPin)
    : device(U8G2_R0, clockPin, dataPin, U8X8_PIN_NONE)
{
    device.begin();
}

void Screen::print(int x, int y, const char *str)
{
    device.firstPage();

    do
    {
        device.setFont(u8g2_font_inr21_mr);
        device.drawStr(x, y, str);
    } while (device.nextPage());
}