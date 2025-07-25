#pragma once
#include <unordered_map>
#include <functional>
#include <string>
#include <cstdlib>
#include "Utils/RequestUtils.hpp"
#include "Utils/PrintUtils.hpp"
#include "Operations.hpp"
#include "History.hpp"

inline constexpr const char* UI_ADDITION        = "1";
inline constexpr const char* UI_SUBTRACTION     = "2";
inline constexpr const char* UI_MULTIPLICATION  = "3";
inline constexpr const char* UI_DIVISION        = "4";
inline constexpr const char* UI_EXPONENTIATION  = "5";
inline constexpr const char* UI_FACTORIAL       = "6";
inline constexpr const char* UI_SQRT            = "7";
inline constexpr const char* UI_SIN             = "8";
inline constexpr const char* UI_COS             = "9";
inline constexpr const char* UI_TG              = "10";
inline constexpr const char* UI_CTG             = "11";

inline constexpr const char* UI_EXIT            = "exit";
inline constexpr const char* UI_CLEAR_HISTORY   = "clearh";
inline constexpr const char* UI_ADVANCED_CALC   = "adv";

std::unordered_map<std::string, std::function<void()>> get_commands_map(Operation& operation, History& history);