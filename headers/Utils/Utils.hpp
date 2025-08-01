#pragma once
#include "Utils/Constants.hpp"
#include <filesystem>
#include <string>
#include <windows.h>

void to_lowercase(std::string& str);

bool is_empty(const std::filesystem::path& path);

void enable_ANSI();