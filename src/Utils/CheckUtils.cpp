#include "Utils/CheckUtils.hpp"

void check_input(const std::string& user_input) 
{
    std::istringstream iss(user_input);

    double x;

    if(!(iss >> x))
        throw std::runtime_error("Invalid input error.");

    char c;

    if (iss >> c)
        throw std::runtime_error("Invalid input error.");
}

bool is_integer(const double user_value) 
{
    return (std::floor(user_value) == user_value);
}
