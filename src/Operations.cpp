#include "Operations.hpp"
#include "Errors.hpp"
#include "History.hpp"
#include "Log.hpp"

constexpr double DEG_TO_RAD = M_PI / 180.0;
constexpr double RAD_TO_DEG = 180.0 / M_PI;
constexpr double NONE = 0.0;

History history;
Log _log;

void Operation::add(double x, double y) 
{   
    std::cout << "Value equals: " << (x + y) << "\n\n";

    history.save("ADDITION", "+", x, y, (x + y), true);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}

void Operation::subtract(double x, double y) 
{
    std::cout << "Value equals: " << (x - y) << "\n\n";

    history.save("SUBTRACTION", "-", x, y, (x - y), true);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}

void Operation::multiply(double x, double y) 
{
    std::cout << "Value equals: " << (x * y) << "\n\n";

    history.save("MULTIPLICATION", "*", x, y, (x * y), true);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}

void Operation::divide(double x, double y)
{
    if(y == 0)
    {
        print_division_by_zero_error();
        return;
    }
       
    std::cout << "Value equals: " << (x / y) << "\n\n";

    history.save("DIVISION", "/", x, y, (x / y), true);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}

void Operation::power(double x, double y) 
{
    double value = 1;
    
    for(int i = 0; i < y; ++i) 
    {
        value = value * x;
    }
    
    std::cout << "Value equals: " << value << "\n\n";

    history.save("EXPONENTIATION", "^", x, y, value, true);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}

void Operation::factorial(double x) 
{
    if(!is_integer(x) || x < 0)
    {
        print_undefined_value_error();
        return;
    }

    unsigned long long value = 1;

    for(int i = 1; i <= x; ++i) 
    {
        value *= i;
    }

    std::cout << "Value equals: " << value << "\n\n";

    history.save("FACTORIAL", "!", x, NONE, static_cast<double>(value), false);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}

void _sqrt(double x)
{
    std::cout << "Value equals: " << sqrt(x) << "\n\n";

    history.save("SQRT", "√", x, NONE, sqrt(x), false);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}

void Operation::_sin(double x)
{
    x *= DEG_TO_RAD;
    std::cout << "Value equals: " << sin(x) << "\n\n";

    history.save("SIN", "sin", (x * RAD_TO_DEG), NONE, sin(x), false);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}

void Operation::_cos(double x)
{
    x *= DEG_TO_RAD;
    std::cout << "Value equals: " << cos(x) << "\n\n";

    history.save("COS", "cos", (x * RAD_TO_DEG), NONE, cos(x), false);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}

void Operation::_tan(double x)
{
    x *= DEG_TO_RAD;
    std::cout << "Value equals: " << tan(x) << "\n\n";

    history.save("TAN", "tg", (x * RAD_TO_DEG), NONE, tan(x), false);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}

void Operation::_ctan(double x)
{
    x *= DEG_TO_RAD;
    std::cout << "Value equals: " << (1.0 / tan(x)) << "\n\n";
    
    history.save("CTAN", "ctg", (x * RAD_TO_DEG), NONE, (1.0 / tan(x)), false);
    _log.save(__LINE__, __PRETTY_FUNCTION__);
}