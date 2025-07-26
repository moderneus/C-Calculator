#pragma once
#include <iostream>
#include <string>
#include <array>
#include "Utils/CheckUtils.hpp"
#include "Utils/Utils.hpp"

void get_values(std::array<double, 2>& values, double& x, double& y);

void get_value(double& x);

std::array<double, 2> request_values();

double request_value();



