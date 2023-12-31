#pragma once

#include "../reg.h"

#define SIO_BASE 0xd0000000

#define SIO_GPIO_OUT_RW_REG  REG(SIO_BASE + 0x10)
#define SIO_GPIO_OUT_SET_REG REG(SIO_BASE + 0x14)
#define SIO_GPIO_OUT_CLR_REG REG(SIO_BASE + 0x18)
#define SIO_GPIO_OUT_XOR_REG REG(SIO_BASE + 0x1c)

#define SIO_GPIO_OE_RW_REG  REG(SIO_BASE + 0x20)
#define SIO_GPIO_OE_SET_REG REG(SIO_BASE + 0x24)
#define SIO_GPIO_OE_CLR_REG REG(SIO_BASE + 0x28)
#define SIO_GPIO_OE_XOR_REG REG(SIO_BASE + 0x2C)
