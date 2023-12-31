﻿#include "number.h"

uint2022_t from_uint(uint32_t i) {
	uint2022_t result;
	for (int j = 0; i > 0 && j < result.bits_size; j++)
	{
		result.data[j] = i % uint2022_t::base;
		i /= uint2022_t::base;
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

uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs) {
	uint2022_t result;
	uint8_t carry = 0;
	result.position = std::max(lhs.position, rhs.position);
	for (uint8_t i = 0; i <= result.position; i++)
	{
		uint8_t sum = lhs.data[i] + rhs.data[i] + carry;
		result.data[i] = sum % uint2022_t::base;
		carry = sum / uint2022_t::base;
	}
	result.position += carry;
	result.data[result.position] += carry;
	return result;
}

uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs) {
	uint2022_t result;
	uint8_t carry = 0;
	result.position = std::max(lhs.position, rhs.position);
	for (uint8_t i = 0; i <= result.position; i++)
	{
		if (lhs.data[i] >= (rhs.data[i] + carry))
		{
			result.data[i] = lhs.data[i] - (rhs.data[i] + carry);
			carry = 0;
		}
		else
		{
			result.data[i] = uint2022_t::base + lhs.data[i] - (rhs.data[i] + carry);
			carry = 1;
		}
	}
	while (result.data[result.position] == 0 && result.position > 0)
	{
		result.position--;
	}
	return result;
}

uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs) {
	uint2022_t result;
	uint16_t mul = 0;
	uint8_t* carry = new uint8_t[result.bytes_size];
	for (uint8_t i = 0; i< result.bytes_size; i++)
	{
		carry[i] = 0;
	}
	for (uint8_t i = 0; i <= lhs.position + 1; i++)
	{
		for (uint8_t j = 0; j <= rhs.position + 1; j++)
		{
			mul = lhs.data[i] * rhs.data[j];
			mul += carry[i + j] + result.data[i + j]; /////ааа
			carry[i + j] = 0;
			result.data[i + j] = mul % uint2022_t::base;
			carry[i + j + 1] = mul / uint2022_t::base;
		}
	}
	result.position = lhs.position + rhs.position + 1;
	while (result.data[result.position] == 0 && result.position > 0)
	{
		result.position--;
	}
	//delete carry;
	return result;
}

uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs) {
	return uint2022_t();
}

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs) {
	if (lhs.position != rhs.position)
	{
		return false;
	}
	for (uint8_t i = 0; i <= lhs.position; i++)
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
	for (int i = value.position; i >= 0; i-=1)
	{
		if (value.data[i] < 10 && i != value.position)
		{
			stream << '0';
		}
		stream << int(value.data[i]);
	}
	return stream;
}