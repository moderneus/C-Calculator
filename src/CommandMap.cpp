#include "CommandMap.hpp"

std::array<double, 2> values;
double value;

#define x values[0]
#define y values[1]

std::unordered_map<std::string, std::function<void()>> get_commands_map(Operation& operation, History& history)
{
    return 
    {
        {UI::ADDITION, [&operation]()
        {
            values = request_values();
            operation.add(x, y);
        }},

        {UI::SUBTRACTION, [&operation]()
        {
            values = request_values();
            operation.subtract(x, y);
        }},

        {UI::MULTIPLICATION, [&operation]()
        {
            values = request_values();
            operation.multiply(x, y);
        }},

        {UI::DIVISION, [&operation]()
        {
            values = request_values();
            operation.divide(x, y);
        }},

        {UI::EXPONENTIATION, [&operation]()
        {
            values = request_values();
            operation.power(x, y);
        }},

        {UI::FACTORIAL, [&operation]()
        {
            value = request_value();
            operation.factorial(value);
        }},

        {UI::SQRT, [&operation]()
        {
            value = request_value();
            operation._sqrt(value);
        }},

        {UI::SIN, [&operation]()
        {
            value = request_value();
            operation._sin(value);
        }},

        {UI::COS, [&operation]()
        {
            value = request_value();
            operation._cos(value);
        }},

        {UI::TG, [&operation]()
        {
            value = request_value();
            operation._tan(value);
        }},

        {UI::CTG, [&operation]()
        {
            value = request_value();
            operation._ctan(value);
        }},

        {UI::EXIT, [&history]()
        {
            std::exit(0);
        }},

        {UI::CLEAR_HISTORY, [&history]()
        {
            history.clear();
        }},

        {UI::ADVANCED_CALC, []()
        {
            print_advanced_menu();
        }}
    };
}