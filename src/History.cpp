#include "History.hpp"

History::History() : history_file_name("history.txt"), last_change_time(std::filesystem::last_write_time(history_file_name)) {}

void History::fill_dynamic_args_store(fmt::dynamic_format_arg_store<fmt::format_context>& arg_store, int line_number, const std::string& operation, const std::string& symbol, const double x, const double y, const double result)
{
    arg_store.push_back(fmt::arg("line_number", line_number));
    arg_store.push_back(fmt::arg("operation",   operation));
    arg_store.push_back(fmt::arg("symbol",      symbol));
    arg_store.push_back(fmt::arg("result",      result));  
    arg_store.push_back(fmt::arg("x",           x));
    arg_store.push_back(fmt::arg("y",           y));
}

std::string History::format_operation_string(const std::string& operation, fmt::dynamic_format_arg_store<fmt::format_context>& arg_store)
{
    if(operation == "SQRT")
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

    int lines = 1;

    if(std::filesystem::file_size(history_file_name) == 0)
        return lines;

    else
    {
        std::string tmp;

        while(std::getline(history_file, tmp))
            ++lines;
    }

    return lines;
}

void History::save(const std::string& operation, const std::string& symbol, const double x, const double y, const double result, bool is_binary)
{
    std::ofstream history_file(history_file_name, std::ios::app);
    
    if(!history_file.is_open())
        throw std::runtime_error("Failed to open history file.");

    int line_number = count_lines();
   
    fmt::dynamic_format_arg_store<fmt::format_context> arg_store;
    fill_dynamic_args_store(arg_store, line_number, operation, symbol, x, y, result);

    if(is_binary)
        history_file << fmt::vformat("{line_number}. {operation}: {x} {symbol} {y} = {result}\n", arg_store);
    
    else
    {
        if(format_operation_string(operation, arg_store) == Error::NONE_FORMAT)
            print_str_format_was_not_found_error();
        
        else
            history_file << format_operation_string(operation, arg_store);
    }
}

void History::clear()
{
    std::ofstream history_file(history_file_name);

    if(!history_file.is_open())
        throw std::runtime_error("Failed to open history file.");
}