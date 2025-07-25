#pragma once
#include <fstream>
#include <string>
#include <fmt/core.h>
#include <fmt/args.h>

class History
{
private:
    std::string history_file_name;

    void fill_dynamic_args_store(fmt::dynamic_format_arg_store<fmt::format_context>& arg_store, int str_number, const std::string& operation, const std::string& symbol, const double x, const double y, const double result);

    std::string get_str_format(const std::string& operation, fmt::dynamic_format_arg_store<fmt::format_context>& arg_store);

    int count_lines();
 
public:
    History();

    void save(const std::string& operation, const std::string& symbol, const double x, const double y, const double result, bool is_binary);

    void clear();
};