#pragma once
#include <fstream>
#include <string>
#include <fmt/core.h>

class Log 
{
private:
    std::string log_file_name;
  
    template <typename T>
    std::string get_str_format(const int line_number, const std::string& func_signature, const T returned_value)
    {
        return fmt::format("{line_number}. function «{func_signature}» has been called and returned {returned_value}\n", 
        fmt::arg("line_number", line_number), 
        fmt::arg("func_signature", func_signature), 
        fmt::arg("returned_value", returned_value));
    }

    std::string get_str_format(const int line_number, const std::string& func_signature); 

    std::string get_str_format(const int line_number, const std::string& object_name, bool is_deleted); 

public:
    Log();

    ~Log();

    template <typename T>
    void save(int line_number, const std::string& func_signature, T returned_value)
    {
        std::ofstream log_file(log_file_name, std::ios::app);

        std::string str = get_str_format(line_number, func_signature, returned_value);

        log_file << str;
    }

    void save(int line_number, const std::string& func_signature);

    void save(int line_number, const std::string& object_name, bool is_deleted);

    void clear();
};