#include "app_gpio.hpp"
#include "ps2.hpp"

#include "stm32f4xx_hal_spi.h"

#include <stdexcept>

Ps2Receiver::Ps2Receiver(SPI_HandleTypeDef *spi_bus, GpioPin *cs_pin)
{
    this->spi_bus = spi_bus;
    this->cs_pin = cs_pin;
    this->cs_pin->write(1);
}

void Ps2Receiver::read_raw_set(uint8_t *data, uint8_t motor_w, uint8_t motor_y)
{
    this->spi_command_buffer[3] = motor_w;
    this->spi_command_buffer[4] = motor_y;

    this->set_cs(0);
    this->spi_read_write(data, this->spi_command_buffer, 9, this->default_timeout);
    this->set_cs(1);
}

void Ps2Receiver::read_raw(uint8_t *data)
{
    this->read_raw_set(data, 0, 0);
}

Ps2State Ps2Receiver::read_set(uint8_t motor_w, uint8_t motor_y)
{
    this->read_raw_set(this->spi_data_buffer, motor_w, motor_y);
    return Ps2State(this->spi_data_buffer);
}

Ps2State Ps2Receiver::read()
{
    return this->read_set(0, 0);
}

void Ps2Receiver::set_cs(bool state)
{
    this->cs_pin->write(state);
}

void Ps2Receiver::spi_read_write(uint8_t *data, uint8_t *command, uint16_t size, uint32_t timeout)
{
    if (HAL_SPI_TransmitReceive(this->spi_bus, command, data, size, timeout) != HAL_OK)
    {
        throw std::runtime_error("SPI error");
    }
}

Ps2State::Ps2State(uint8_t *data)
{
    if (data[3] != 0x5A)
    {
        throw std::runtime_error("Invalid data");
    }
    this->button_select = data[3] & 0x01;
    this->button_l3 = data[3] & 0x02;
    this->button_r3 = data[3] & 0x04;
    this->button_start = data[3] & 0x08;
    this->button_up = data[3] & 0x10;
    this->button_right = data[3] & 0x20;
    this->button_down = data[3] & 0x40;
    this->button_left = data[3] & 0x80;

    this->button_l2 = data[4] & 0x01;
    this->button_r2 = data[4] & 0x02;
    this->button_l1 = data[4] & 0x04;
    this->button_r1 = data[4] & 0x08;
    this->button_triangle = data[4] & 0x10;
    this->button_circle = data[4] & 0x20;
    this->button_cross = data[4] & 0x40;
    this->button_square = data[4] & 0x80;

    this->right_analog_x = (int16_t)data[5] - 0x80;
    this->right_analog_y = (int16_t)data[6] - 0x80;
    this->left_analog_x = (int16_t)data[7] - 0x80;
    this->left_analog_y = (int16_t)data[8] - 0x80;
}

void Ps2State::deadzone_correction(uint8_t threshold)
{
    if (this->right_analog_x<threshold &&this->right_analog_x> - threshold)
    {
        this->right_analog_x = 0;
    }
    if (this->right_analog_y<threshold &&this->right_analog_y> - threshold)
    {
        this->right_analog_y = 0;
    }
    if (this->left_analog_x<threshold &&this->left_analog_x> - threshold)
    {
        this->left_analog_x = 0;
    }
    if (this->left_analog_y<threshold &&this->left_analog_y> - threshold)
    {
        this->left_analog_y = 0;
    }
}