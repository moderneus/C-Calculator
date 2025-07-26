#include "Utils/RequestUtils.hpp"

void get_values(std::array<double, 2>& values, double& x, double& y)
{   
    values = request_values();
    x = values[0];
    y = values[1];
}

void get_value(double& x)
{
    x = request_value();
}

std::array<double, 2> request_values() 
{
    std::cout << "Enter a first value: ";

    std::string first_value;
    std::cin >> first_value;
    
    check_input(first_value);

    std::cout << "Enter a second value: ";

    std::string second_value;
    std::cin >> second_value;
    
    check_input(second_value);

    return {std::stod(first_value), std::stod(second_value)};
}

double request_value() 
{
    std::cout << "Enter a value: ";

    std::string value;
    std::cin >> value;
    
    check_input(value);

    return std::stod(value);
}