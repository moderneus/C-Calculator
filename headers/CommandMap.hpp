#pragma once
#include <unordered_map>
#include <functional>
#include <string>
#include <cstdlib>
#include "Utils/RequestUtils.hpp"
#include "Utils/PrintUtils.hpp"
#include "Utils/Constants.hpp"
#include "Operations.hpp"
#include "History.hpp"

std::unordered_map<std::string, std::function<void()>> get_commands_map(Operation& operation, History& history);