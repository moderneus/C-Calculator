#include "CommandMap.hpp"

std::unordered_map<std::string, std::function<void()>> get_commands_map(Operation& operation, History& history)
{
    std::array<double, 2> values;
    double x, y;

    return 
    {
        {UI::ADDITION, [&operation, &history, &values, &x, &y]()
        {
            get_values(values, x, y);
            operation.add(history, x, y);
        }},

        {UI::SUBTRACTION, [&operation, &history, &values, &x, &y]()
        {
            get_values(values, x, y);
            operation.subtract(history, x, y);
        }},

        {UI::MULTIPLICATION, [&operation, &history, &values, &x, &y]()
        {
            get_values(values, x, y);
            operation.multiply(history, x, y);
        }},

        {UI::DIVISION, [&operation, &history, &values, &x, &y]()
        {
            get_values(values, x, y);
            operation.divide(history, x, y);
        }},

        {UI::EXPONENTIATION, [&operation, &history, &values, &x, &y]()
        {
            get_values(values, x, y);
            operation.power(history, x, y);
        }},

        {UI::FACTORIAL, [&operation, &history, &x]()
        {
            get_value(x);
            operation.factorial(history, x);
        }},

        {UI::SQRT, [&operation, &history, &x]()
        {
            get_value(x);
            operation._sqrt(history, x);
        }},

        {UI::SIN, [&operation, &history, &x]()
        {
            get_value(x);
            operation._sin(history, x);
        }},

        {UI::COS, [&operation, &history, &x]()
        {
            get_value(x);
            operation._cos(history, x);
        }},

        {UI::TG, [&operation, &history, &x]()
        {
            get_value(x);
            operation._tan(history, x);
        }},

        {UI::CTG, [&operation, &history, &x]()
        {
            get_value(x);
            operation._ctan(history, x);
        }},

        {UI::EXIT, []()
        {
            std::exit(0);
        }},

        {UI::CLEAR_HISTORY, [&history]()
        {
            history.clear();
            print_history_cleared();
        }}
    };
}
