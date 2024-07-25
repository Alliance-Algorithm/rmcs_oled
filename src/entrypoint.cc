#include "entrypoint.hh"

#include "hal/base/gpio.hh"
#include "hal/base/timer.hh"
#include "oled/ssd1306.hh"
#include "oled/ssd1306_fonts.hh"

#include <cstdio>

void entrypoint()
{
    using namespace hal;
    using namespace oled;

    auto green = gpio::PH<11> {};
    auto blue = gpio::PH<10> {};
    auto red = gpio::PH<12> {};

    green.set();
    blue.set();
    red.set();

    init();
    delay(10);
    fill(Color::Black);

    set_cursor(10, 10);
    write_string((char*)"El Psy Cangroo", Font_7x10, Color::White);

    set_cursor(15, 45);
    write_string((char*)"STM32F407IGH6", Font_7x10, Color::White);

    update();

    while (true) {
        static int count;
        static char string[20];

        sprintf(string, "count: %d", count++);

        set_cursor(30, 30);
        write_string(string, Font_6x8, Color::White);

        update();
    }
}
