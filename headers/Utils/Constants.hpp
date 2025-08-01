#pragma once
#include <cmath>
#include <cstdint>

namespace UI 
{
    inline constexpr const char* ADDITION        = "1";
    inline constexpr const char* SUBTRACTION     = "2";
    inline constexpr const char* MULTIPLICATION  = "3";
    inline constexpr const char* DIVISION        = "4";
    inline constexpr const char* EXPONENTIATION  = "5";
    inline constexpr const char* FACTORIAL       = "6";
    inline constexpr const char* SQRT            = "7";
    inline constexpr const char* SIN             = "8";
    inline constexpr const char* COS             = "9";
    inline constexpr const char* TG              = "10";
    inline constexpr const char* CTG             = "11";
    inline constexpr const char* EXIT            = "exit";
    inline constexpr const char* CLEAR_HISTORY   = "clear";
}

namespace Math
{
    inline constexpr const double MAX_FACTORIAL_INPUT = 65;
    inline constexpr const double DEG_TO_RAD = M_PI / 180.0;
    inline constexpr const double NO_VALUE = 0.0;
}

namespace Error
{
    inline constexpr const char* NONE_FORMAT = "";
}

namespace ASCII
{
    inline constexpr const int ASCII_CASE_DIFF = 32;
}

namespace File
{
    inline constexpr const std::uintmax_t EMPTY_SIZE = 0;
}