#pragma once
#include <cmath>
#include "Utils/CheckUtils.hpp"
#include "Utils/PrintUtils.hpp"
#include "Utils/Constants.hpp"
#include "History.hpp"

using namespace Math;

class Operation
{
private:
    double x, y;

public:
    void add(History& history, double x, double y);

    void subtract(History& history, double x, double y);

    void multiply(History& history, double x, double y);

    void divide(History& history, double x, double y);

    void power(History& history, double x, double y);
 
    void factorial(History& history, double x);

    void _sqrt(History& history, double x);

    void _sin(History& history, double x);

    void _cos(History& history, double x);

    void _tan(History& history, double x);

    void _ctan(History& history, double x);
};