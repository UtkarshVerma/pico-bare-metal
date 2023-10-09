#pragma once

#include "../reg.h"
#include "util.h"
#define IO_BANK0_GPIO_COUNT 30

#define IO_BANK0_BASE                   0x40014000
#define IO_BANK0_GPIO_CTRL_REG(gpio)    REG(IO_BANK0_BASE + 0x8 * (gpio))
#define IO_BANK0_GPIO_CTRL_FUNCSEL(val) FLD32(val, 4, 0)
