#include "number.h"

uint2022_t from_uint(uint32_t i) {
    uint2022_t result;
    for (int j = 0; i > 0 && j < result.bits_size; j++)
    {
        result.data[j] = i % 100;
        i /= 100;
        if (i > 0)
        {
            result.position++;
        }
    }
    return result;
}

uint2022_t from_string(const char* buff) {
    uint2022_t result;
    int pos = 0;
    int len = strlen(buff);
    result.position = std::max(len / 2, 0);
    if (len % 2 == 0) 
    {
        result.position--;
    }
    for (int i = len - 1; i >= 0; i -= 2)
    {
        for (int j = std::max(i - 1, 0); j <= i; j++)
        {
            result.data[pos] *= 10;
            result.data[pos] += buff[j] - '0';
        }
        pos++;
    }
    return result;
}

uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs) {//переполнение?
    uint2022_t result;
    bool Deka = false;
    uint8_t carry = 0; 
    result.position = std::max(lhs.position, rhs.position);
    for (int i = 0; i<=result.position; i++)
    {
        uint8_t sum = lhs.data[i] + rhs.data[i];
        if (Deka)
        {
            sum++;
            Deka = false;
        }
        if (sum >= 100)
        {
            Deka = true;
            sum = sum % 100;
        }
        result.data[i] = sum;
    }
    if (Deka)
    {
        result.position++;
        result.data[result.position]++;
    }
    return result;
}

uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs) {//lhs только больше
    uint2022_t result;
    bool Deka = false;
    result.position = std::max(lhs.position, rhs.position);
    for (int i = 0;i <= result.position; i++)
    {
        if (lhs.data[i] >= (rhs.data[i] + Deka))
        {
            result.data[i] = lhs.data[i] - (rhs.data[i] + Deka);
            Deka = false;
        }
        else
        {
            result.data[i] = 100 + lhs.data[i] - (rhs.data[i] + Deka);
            Deka = true;
        }
    }
    while (result.data[result.position] == 0)
    {
        result.position--;
    }
    return result;
}

uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs) {
    if (lhs.position != rhs.position)
    {
        return false;
    }
    for (int i = 0; i <= lhs.position; i++)
    {
        if (lhs.data[i] != rhs.data[i])
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs) {
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& stream, const uint2022_t& value) {
    for (int i = value.position; i >= 0; i--)
    { 
        if (int(value.data[i]) < 10 && i != value.position) 
        {
            stream << '0';
        }
        stream << int(value.data[i]);
    }
    return stream;
}
