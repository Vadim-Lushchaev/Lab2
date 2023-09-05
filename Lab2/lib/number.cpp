#include "number.h"

// 280
// { 2, 80 }

uint2022_t from_uint(uint32_t i) {
    uint2022_t result;
    for (int j = 0; i > 0 && j < result.bits_size; j++)
    {
        result.data[j] = i % 100;
        i /= 100;
    }
    return result;
}
// 3
// "45 54 65 76 54 65 76 54"
// {  }

uint2022_t from_string(const char* buff) {
    uint2022_t result;
    int pos = 0;
    for (int i = strlen(buff) - 1; i >= 0; i -= 2)
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

uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs) {
    return false;
}

bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs) {
    return false;
}

std::ostream& operator<<(std::ostream& stream, const uint2022_t& value) {
    stream << "Implement me";

    return stream;
}
