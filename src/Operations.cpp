#include "Operations.hpp"

void Operation::add(History& history, double x, double y) 
{   
    print_result_and_save_history(history, "ADDITION", "+", x, y, (x + y), true);
}

void Operation::subtract(History& history, double x, double y) 
{
    print_result_and_save_history(history, "SUBTRACTION", "-", x, y, (x - y), true);
}

void Operation::multiply(History& history, double x, double y) 
{
    print_result_and_save_history(history, "MULTIPLICATION", "*", x, y, (x * y), true);
}

void Operation::divide(History& history, double x, double y)
{
    if(y == 0)
    {
        print_division_by_zero_error();
        return;
    }
       
    print_result_and_save_history(history, "DIVISION", "/", x, y, (x / y), true);
}

void Operation::power(History& history, double x, double y) 
{
    print_result_and_save_history(history, "EXPONENTIATION", "^", x, y, pow(x, y), true);
}

void Operation::factorial(History& history, double x) 
{
    if(!is_integer(x) || x < 0)
    {
        print_undefined_value_error();
        return;
    }

    else if(x > MAX_FACTORIAL_INPUT)
    {
        print_overflow_error();
        return;
    }
       
    unsigned long long result = 1;

    for(int i = 1; i <= x; ++i) 
        result *= i;
    
    print_result_and_save_history(history, "FACTORIAL", "!", static_cast<double>(x), NO_VALUE, result, false);
}

void Operation::_sqrt(History& history, double x)
{
    if(x < 0)
    {
        print_undefined_value_error();
        return;
    }

    print_result_and_save_history(history, "SQRT", "√", x, NO_VALUE, sqrt(x), false);
}

void Operation::_sin(History& history, double x)
{
    print_result_and_save_history(history, "SIN", "sin", x, NO_VALUE, sin(x*DEG_TO_RAD), false);
}

void Operation::_cos(History& history, double x)
{
    print_result_and_save_history(history, "COS", "cos", x, NO_VALUE, cos(x*DEG_TO_RAD), false);
}

void Operation::_tan(History& history, double x)
{
    print_result_and_save_history(history, "TAN", "tg", x, NO_VALUE, tan(x*DEG_TO_RAD), false);
}

void Operation::_ctan(History& history, double x)
{
    if(tan(x*DEG_TO_RAD) == 0)
    {
        print_division_by_zero_error();
        return;
    }

    print_result_and_save_history(history, "CTAN", "ctg", x, NO_VALUE, (1.0 / tan(x*DEG_TO_RAD)), false);
}