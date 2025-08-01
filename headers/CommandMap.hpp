#pragma once
#include "Utils/RequestUtils.hpp"
#include "Utils/PrintUtils.hpp"
#include "Utils/Constants.hpp"
#include "Operations.hpp"
#include "History.hpp"
#include <unordered_map>
#include <functional>
#include <string>
#include <cstdlib>

std::unordered_map<std::string, std::function<void()>> get_commands_map(Operation& operation, History& history);