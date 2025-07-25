#include "CommandMap.hpp"

std::array<double, 2> values;

#define x values[0]
#define y values[1]

std::unordered_map<std::string, std::function<void()>> get_commands_map(Operation& operation, History& history)
{
    return 
    {
        {UI_ADDITION, [&operation]()
        {
            auto values = request_values();
            operation.add(x, y);
        }},

        {UI_SUBTRACTION, [&operation]()
        {
            auto values = request_values();
            operation.subtract(x, y);
        }},

        {UI_MULTIPLICATION, [&operation]()
        {
            auto values = request_values();
            operation.multiply(x, y);
        }},

        {UI_DIVISION, [&operation]()
        {
            auto values = request_values();
            operation.divide(x, y);
        }},

        {UI_EXPONENTIATION, [&operation]()
        {
            auto values = request_values();
            operation.power(x, y);
        }},

        {UI_FACTORIAL, [&operation]()
        {
            auto value = request_value();
            operation.factorial(value);
        }},

        {UI_SQRT, [&operation]()
        {
            auto value = request_value();
            operation._sqrt(value);
        }},

        {UI_SIN, [&operation]()
        {
            auto value = request_value();
            operation._sin(value);
        }},

        {UI_COS, [&operation]()
        {
            auto value = request_value();
            operation._cos(value);
        }},

        {UI_TG, [&operation]()
        {
            auto value = request_value();
            operation._tan(value);
        }},

        {UI_CTG, [&operation]()
        {
            auto value = request_value();
            operation._ctan(value);
        }},

        {UI_EXIT, []()
        {
            std::exit(0);
        }},

        {UI_CLEAR_HISTORY, [&history]()
        {
            history.clear();
        }},

        {UI_ADVANCED_CALC, []()
        {
            print_advanced_menu();
        }}
    };
}