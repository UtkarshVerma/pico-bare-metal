#pragma once

#include "reg/io.h"

enum gpio_function {
    SIO = 5,
};

static inline void gpio_set_pin_function(const unsigned short pin,
                                         const enum gpio_function func) {
    // TODO: Asset `func` validity at compile-time
    IO_BANK0_GPIO_CTRL_REG(pin) = IO_BANK0_GPIO_CTRL_FUNCSEL(func);
}
