#pragma once
#include <iostream>

inline void print_division_by_zero_error()
{
    std::cerr << "Cannot divide by zero.\n\n";
}

inline void print_invalid_input_error()
{
    std::cerr << "Invalid Input.\n\n";
}

inline void print_undefined_value_error()
{
    std::cerr << "Value is undefined.\n\n";
}