#pragma once

#include <stdint.h>

#define REG(addr)    *(volatile uint32_t*)(addr)
#define REG_RW(reg)  REG(&reg + 0x0000)
#define REG_XOR(reg) REG(&reg + 0x1000)
#define REG_SET(reg) REG(&reg + 0x2000)
#define REG_CLR(reg) REG(&reg + 0x3000)
