#include "History.hpp"

History::History() : history_file_name("history.txt") {}

void History::fill_dynamic_args_store(fmt::dynamic_format_arg_store<fmt::format_context>& arg_store, int line_number, const std::string& operation, const std::string& symbol, const double x, const double y, const double result)
{
    arg_store.push_back(fmt::arg("line_number", line_number));
    arg_store.push_back(fmt::arg("operation",   operation));
    arg_store.push_back(fmt::arg("symbol",      symbol));
    arg_store.push_back(fmt::arg("result",      result));  
    arg_store.push_back(fmt::arg("x",           x));
    arg_store.push_back(fmt::arg("y",           y));
}

std::string History::format_operation_string(const std::string& operation, fmt::dynamic_format_arg_store<fmt::format_context>& arg_store, double y, bool is_binary)
{
    if(is_binary && y >= 0)
        return fmt::vformat("{line_number}. {operation}: {x} {symbol} {y} = {result}\n", arg_store);
    
    else if(is_binary && y < 0)
        return fmt::vformat("{line_number}. {operation}: {x} {symbol} ({y}) = {result}\n", arg_store);

    else if(operation == "SQRT")
        return fmt::vformat("{line_number}. {operation}: {symbol}{x} = {result}\n", arg_store);
     
    else if(operation == "FACTORIAL")
        return fmt::vformat("{line_number}. {operation}: {x}{symbol} = {result}\n", arg_store);
    
    else if(operation == "SIN" || operation == "COS" || operation == "TAN" || operation == "CTAN")
        return fmt::vformat("{line_number}. {operation}: {symbol}({x}°) = {result}\n", arg_store); 

    return Error::NONE_FORMAT;
}

int History::count_lines()
{
    std::ifstream history_file(history_file_name);
    
    if(!history_file.is_open())
        throw std::runtime_error("Failed to open history file.");

    int lines = 0;

    if(is_empty(history_file_name))
        return ++lines;

    else
    {
        std::string tmp;

        while(std::getline(history_file, tmp))
            ++lines;
    }

    return ++lines;
}

void History::save(const std::string& operation, const std::string& symbol, const double x, const double y, const double result, bool is_binary)
{
    std::ofstream history_file(history_file_name, std::ios::app);
    
    if(!history_file.is_open())
        throw std::runtime_error("Failed to open history file.");

    int line_number = count_lines();
   
    fmt::dynamic_format_arg_store<fmt::format_context> arg_store;
    fill_dynamic_args_store(arg_store, line_number, operation, symbol, x, y, result);

    std::string formated_str = format_operation_string(operation, arg_store, y, is_binary);

    if(formated_str == Error::NONE_FORMAT)
        throw std::runtime_error("The required string format could not be found.");
    
    else
        history_file << formated_str;
}

void History::clear()
{
    std::ofstream history_file(history_file_name);

    if(!history_file.is_open())
        throw std::runtime_error("Failed to open history file.");
}