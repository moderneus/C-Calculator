#include "Utils.hpp"
#include "Errors.hpp"

std::array<double, 2> convert_to_double(const std::array<std::string, 2>& values) 
{
    return 
    {
        std::stod(values[0]),
        std::stod(values[1])
    };
}

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
    double tmp = user_value;
    return (std::floor(user_value) == tmp);
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

    std::array<std::string, 2> values {first_value, second_value};
    return convert_to_double(values);
}

double request_value() 
{
    std::cout << "Enter a value: ";

    std::string value;
    std::cin >> value;
    
    check_input(value);

    return std::stod(value);
}

void print_menu()
{
    std::cout <<
    "Type a number of operation you want to use:\n"
    "1. Addition.\n"
    "2. Subtraction.\n"
    "3. Multiplication.\n"
    "4. Division.\n"
    "5. Exponentiation.\n"
    "6. Factorial.\n"
    "7. Sin(x)\n"
    "8. Cos(x)\n"
    "9. Tan(x)\n"
    "10. Ctg(x)\n\n";
}

std::string to_lowercase(std::string& str)
{
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }

    return str;
}