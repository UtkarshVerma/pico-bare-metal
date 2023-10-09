#pragma once

#include <stdint.h>

#define BIT32(n)             (uint32_t)(1 << (n))
#define MSK32(msb, lsb)      ((BIT32(msb + 1) - 1) - (BIT32(lsb) - 1))
#define FLD32(val, msb, lsb) ((val << lsb) & MSK32(msb, lsb))
