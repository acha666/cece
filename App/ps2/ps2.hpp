#pragma once

#include "stm32f4xx_hal_spi.h"

#include "app_gpio.hpp"

class Ps2State;

class Ps2Receiver
{
public:
    Ps2Receiver(SPI_HandleTypeDef *spi_bus, GpioPin *cs_pin);

    void read_raw(uint8_t *data);
    void read_raw_set(uint8_t *data, uint8_t motor_w, uint8_t motor_y);
    Ps2State read();
    Ps2State read_set(uint8_t motor_w, uint8_t motor_y);


private:
    SPI_HandleTypeDef *spi_bus;
    GpioPin *cs_pin;
    uint8_t spi_data_buffer[9];
    uint8_t spi_command_buffer[9] = {0x01, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    const uint32_t default_timeout = 100;

    void set_cs(bool state);
    void spi_read_write(uint8_t *data, uint8_t *command, uint16_t size, uint32_t timeout);
};

class Ps2State
{
public:
    Ps2State(uint8_t *data);

    void deadzone_correction(uint8_t threshold);

    bool button_select;
    bool button_l3;
    bool button_r3;
    bool button_start;
    bool button_up;
    bool button_right;
    bool button_down;
    bool button_left;
    bool button_l2;
    bool button_r2;
    bool button_l1;
    bool button_r1;
    bool button_triangle;
    bool button_circle;
    bool button_cross;
    bool button_square;

    int8_t right_analog_x;
    int8_t right_analog_y;
    int8_t left_analog_x;
    int8_t left_analog_y;
};