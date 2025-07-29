#include "CommandMap.hpp"

std::unordered_map<std::string, std::function<void()>> get_commands_map(Operation& operation, History& history)
{
    std::array<double, 2> values;
    double x, y;

    return 
    {
        {UI::ADDITION, [&operation, &values, &x, &y]()
        {
            get_values(values, x, y);
            operation.add(x, y);
        }},

        {UI::SUBTRACTION, [&operation, &values, &x, &y]()
        {
            get_values(values, x, y);
            operation.subtract(x, y);
        }},

        {UI::MULTIPLICATION, [&operation, &values, &x, &y]()
        {
            get_values(values, x, y);
            operation.multiply(x, y);
        }},

        {UI::DIVISION, [&operation, &values, &x, &y]()
        {
            get_values(values, x, y);
            operation.divide(x, y);
        }},

        {UI::EXPONENTIATION, [&operation, &values, &x, &y]()
        {
            get_values(values, x, y);
            operation.power(x, y);
        }},

        {UI::FACTORIAL, [&operation, &x]()
        {
            get_value(x);
            operation.factorial(x);
        }},

        {UI::SQRT, [&operation, &x]()
        {
            get_value(x);
            operation._sqrt(x);
        }},

        {UI::SIN, [&operation, &x]()
        {
            get_value(x);
            operation._sin(x);
        }},

        {UI::COS, [&operation, &x]()
        {
            get_value(x);
            operation._cos(x);
        }},

        {UI::TG, [&operation, &x]()
        {
            get_value(x);
            operation._tan(x);
        }},

        {UI::CTG, [&operation, &x]()
        {
            get_value(x);
            operation._ctan(x);
        }},

        {UI::EXIT, []()
        {
            std::exit(0);
        }},

        {UI::CLEAR_HISTORY, [&history]()
        {
            history.clear();
        }}
    };
}
