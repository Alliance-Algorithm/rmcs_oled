#include "entrypoint.hh"

#include "hal/base/gpio.hh"
#include "hal/base/timer.hh"
#include "oled/ssd1306.hh"
#include "oled/ssd1306_fonts.hh"

#include <cstdint>
#include <cstdio>

void entrypoint()
{
    using namespace hal;

    auto green = gpio::PH<11> {};
    auto blue = gpio::PH<10> {};
    auto red = gpio::PH<12> {};

    green.set();
    blue.set();
    red.set();

    ssd1306_Init();
    delay(10);
    ssd1306_Fill(SSD1306_COLOR::Black);

    ssd1306_SetCursor(10, 10);
    ssd1306_WriteString("El Psy Cangroo", Font_7x10, SSD1306_COLOR::White);

    ssd1306_SetCursor(15, 45);
    ssd1306_WriteString("STM32F407IGH6", Font_7x10, SSD1306_COLOR::White);

    ssd1306_UpdateScreen();

    delay(1000);

    while (true) {
        static int count;
        static char string[20];

        sprintf(string, "count: %d", count++);

        ssd1306_SetCursor(30, 30);
        ssd1306_WriteString(string, Font_6x8, SSD1306_COLOR::White);

        ssd1306_UpdateScreen();
    }
}
