#pragma once

#include "../reg.h"
#include "util.h"

#define RESETS_BASE 0x4000c000

#define RESETS_RESET_REG      REG(RESETS_BASE + 0x0)
#define RESETS_RESET_IO_BANK0 BIT32(5)

#define RESETS_WDSEL_REG REG(RESETS_BASE + 0x4)

#define RESETS_RESET_DONE_REG REG(RESETS_BASE + 0x8)
