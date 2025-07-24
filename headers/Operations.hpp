#pragma once
#include "Utils.hpp"
#include <cmath>

class Operation
{
private:
    double x, y;

public:
    void add(double x, double y);

    void subtract(double x, double y);

    void multiply(double x, double y);

    void divide(double x, double y);

    void power(double x, double y);
 
    void factorial(double x);

    void _sqrt(double x);

    void _sin(double x);

    void _cos(double x);

    void _tan(double x);

    void _ctan(double x);
};