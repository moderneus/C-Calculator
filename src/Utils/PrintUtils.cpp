#include "Utils/PrintUtils.hpp"

void print_result_and_save_history(History& history, const std::string& operation, const std::string& symbol, const double x, const double y, const double result, bool is_binary)
{
    std::cout << "Value equals: " << result << "\n\n";

    history.save(operation, symbol, x, y, result, is_binary);
}

void print_start_menu()
{
    std::cout <<
    "You can use 'clearh' to clear history.\n"
    "You can use 'adv' to get advanced menu.\n\n"
    "Enter a number of operation you want to use:\n"
    "1. Addition.\n"
    "2. Subtraction.\n"
    "3. Multiplication.\n"
    "4. Division.\n"
    "5. Exponentiation.\n";
}

void print_advanced_menu()
{
    std::cout <<
    "\nEnter a number of operation you want to use:\n"
    "1. Addition.\n"
    "2. Subtraction.\n"
    "3. Multiplication.\n"
    "4. Division.\n"
    "5. Exponentiation.\n"
    "6. Factorial.\n"
    "7. SQRT\n"
    "8. Sin(x)\n"
    "9. Cos(x)\n"
    "10. Tan(x)\n"
    "11. Ctg(x)\n\n";
}

void print_division_by_zero_error()
{
    std::cerr << "Cannot divide by zero.\n\n";
}

void print_invalid_input_error()
{
    std::cerr << "Invalid Input.\n\n";
}

void print_undefined_value_error()
{
    std::cerr << "Value is undefined.\n\n";
}

void print_overflow_warning()
{
    std::cout << "Warning: Value too large. Cannot compute factorial of numbers greater than 65.\n\n";
}