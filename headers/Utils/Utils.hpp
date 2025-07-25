#pragma once
#include <array>
#include <string>

std::array<double, 2> convert_to_double(const std::array<std::string, 2>& values);

std::string to_lowercase(std::string& str);