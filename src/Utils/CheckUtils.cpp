#include "Utils/CheckUtils.hpp"

void check_input(const std::string& user_input) 
{
    std::istringstream iss(user_input);

    double x;

    if(!(iss >> x))
        print_invalid_input_error();

    char c;

    if (iss >> c)
        print_invalid_input_error();
}

bool is_integer(const double user_value) 
{
    return (std::floor(user_value) == user_value);
}
