#pragma once
#include "Utils/CheckUtils.hpp"
#include "Utils/Utils.hpp"
#include <fmt/core.h>
#include <fmt/color.h>
#include <iostream>
#include <string>
#include <array>

void get_values(std::array<double, 2>& values, double& x, double& y);

void get_value(double& x);

std::array<double, 2> request_values();

double request_value();