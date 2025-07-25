#include "Utils/RequestUtils.hpp"

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