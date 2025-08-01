#include "Utils/PrintUtils.hpp"

void print_result_and_save_history(History& history, const std::string& operation, const std::string& symbol, const double x, const double y, const double result, bool is_binary)
{
    fmt::print(fg(fmt::color::lime_green), "Value equals: {}\a\n\n", result);

    try
    {
        history.save(operation, symbol, x, y, result, is_binary);
    }
    
    catch(const std::exception& e)
    {
        fmt::print(fg(fmt::color::red), "{}\n\n", e.what());
    }
}

void print_start_menu()
{
    fmt::print(fg(fmt::color::white),
    "The history of your calculations is saved in the file history.txt. To clear it, enter the command 'clearh'.\n\n"
    "Enter a number of operation you want to use:\n"
    "1. Addition.\n"
    "2. Subtraction.\n"
    "3. Multiplication.\n"
    "4. Division.\n"
    "5. Exponentiation.\n"
    "6. Factorial.\n"
    "7. SQRT.\n"
    "8. Sin(x).\n"
    "9. Cos(x).\n"
    "10. Tan(x).\n"
    "11. Ctg(x).\n\n");
}

void print_division_by_zero_error()
{
    fmt::print(fg(fmt::color::red), "Cannot divide by zero.\n\n");
}

void print_invalid_input_error()
{
    fmt::print(fg(fmt::color::red), "Invalid input.\n\n");
}

void print_undefined_value_error()
{
    fmt::print(fg(fmt::color::red), "Value is undefined.\n\n");
}

void print_overflow_error()
{
    fmt::print(fg(fmt::color::red), "Value is too large.\n\n");
}