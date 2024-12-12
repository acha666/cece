#include "app_gpio.hpp"

#include "stm32f4xx_hal.h"

GpioPin::GpioPin(GPIO_TypeDef *port, uint16_t pin)
{
    this->port = port;
    this->pin = pin;
}

void GpioPin::set()
{
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

void GpioPin::reset()
{
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

void GpioPin::toggle()
{
    HAL_GPIO_TogglePin(port, pin);
}

bool GpioPin::read()
{
    return HAL_GPIO_ReadPin(port, pin);
}

void GpioPin::write(bool state)
{
    HAL_GPIO_WritePin(port, pin, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}