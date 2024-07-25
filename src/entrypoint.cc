#include "entrypoint.hh"

#include "hal/base/gpio.hh"
#include "hal/base/timer.hh"

extern "C" {
#include "oled/ssd1306.h"
#include "oled/ssd1306_fonts.h"
}

void entrypoint()
{
    using namespace hal;

    auto green = gpio::PH<11> {};
    auto blue = gpio::PH<10> {};
    auto red = gpio::PH<12> {};

    ssd1306_Init();
    delay(10);
    ssd1306_Fill(SSD1306_COLOR::Black);

    ssd1306_SetCursor(10, 10);
    ssd1306_WriteString("Genshin", Font_6x8, SSD1306_COLOR::White);

    ssd1306_UpdateScreen();

    while (true) {
        delay(200);

        green.toggle();
        blue.toggle();
        red.toggle();
    }
}
