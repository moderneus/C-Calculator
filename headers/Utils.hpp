#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <utility>
#include <array>
#include <cmath>

std::array<double, 2> convert_to_double(const std::array<std::string, 2>& values);

std::array<double, 2> request_values();

double request_value();

void check_input(const std::string& user_input);

bool is_integer(const double user_value);

void print_menu();

std::string to_lowercase(std::string& str);