#pragma once
#include <cinttypes>
#include <iostream>

// base = 100

struct uint2022_t {
    uint8_t* data = nullptr;
    // Положение крайнего значащего байта числа
    uint8_t position; 
    // Размер числа в байтах
    uint16_t bytes_size;
    uint16_t bits_size;
    static const uint16_t base = 100;
    uint2022_t(const uint16_t bits_size = 2022)
    {
        position = 0;
        this->bits_size = bits_size;
        this->bytes_size = (bits_size / 8) + static_cast<uint16_t>((bits_size % 8) != 0);
        this->data = new uint8_t[this->bytes_size];
        for (uint16_t i = 0; i < this->bytes_size; i++)
        {
            this->data[i] = 0;
        }
    }
};

static_assert(sizeof(uint2022_t) <= 300, "Size of uint2022_t must be no higher than 300 bytes");

uint2022_t from_uint(uint32_t i);

uint2022_t from_string(const char* buff);

uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs);

uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs);

uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs);

uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs);

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs);

bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs);

std::ostream& operator<<(std::ostream& stream, const uint2022_t& value);
