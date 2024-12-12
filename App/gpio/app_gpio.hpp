#pragma once

#include "stm32f4xx_hal.h"

class GpioPin
{
    public:
    GpioPin(GPIO_TypeDef *port, uint16_t pin);
    void set();
    void reset();
    void toggle();
    bool read();
    void write(bool state);

    private:
    GPIO_TypeDef *port;
    uint16_t pin;
};