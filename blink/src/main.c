#include "peripherals/gpio.h"
#include "reg/io.h"
#include "reg/resets.h"
#include "reg/sio.h"
#include "util.h"

#define LED_PIN 25

static void delay(void) {
}

void main(void) {
    // Release reset on IO_BANK0
    REG_CLR(RESETS_RESET_REG) = RESETS_RESET_IO_BANK0;
    while ((REG_RW(RESETS_RESET_REG) & RESETS_RESET_IO_BANK0) != 0)
        ;

    // output disable
    SIO_GPIO_OE_CLR_REG = 1 << LED_PIN;

    // turn off pin 25
    SIO_GPIO_OUT_CLR_REG = 1 << LED_PIN;

    // set the function select to SIO (software controlled I/O)
    gpio_set_pin_function(LED_PIN, SIO);

    // output enable
    SIO_GPIO_OE_SET_REG = BIT32(LED_PIN);

    while (1) {
        SIO_GPIO_OUT_XOR_REG = BIT32(LED_PIN);
        delay();
    }
}
