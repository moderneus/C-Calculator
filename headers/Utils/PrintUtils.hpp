#pragma once
#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include "History.hpp"
#include "Utils/Constants.hpp"

class History;

void print_result_and_save_history(History& history, const std::string& operation, const std::string& symbol, const double x, const double y, const double result, bool is_binary);

void print_start_menu();

void print_division_by_zero_error();

void print_invalid_input_error();

void print_undefined_value_error();

void print_overflow_error();