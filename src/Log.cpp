#include "Log.hpp"

std::string Log::get_str_format(const int line_number, const std::string& func_signature)
{
    return fmt::format("{line_number}. function «{func_signature}» has been called and nothing returned\n", 
    fmt::arg("line_number", line_number), 
    fmt::arg("func_signature", func_signature));
}    

std::string Log::get_str_format(const int line_number, const std::string& class_name, bool is_deleted)
{
    if(is_deleted)
        return fmt::format("{line_number}. Object of type «{class_name}» has been deleted\n",
        fmt::arg("line_number", line_number),
        fmt::arg("class_name", class_name));

    else
        return fmt::format("{line_number}. Object of type «{class_name}» has been created\n",
        fmt::arg("line_number", line_number),
        fmt::arg("class_name", class_name));
}

void Log::save(int line_number, const std::string& func_signature)
{
    std::ofstream log_file(log_file_name, std::ios::app);

    std::string str = get_str_format(line_number, func_signature);

    log_file << str;   
}

void Log::save(int line_number, const std::string& class_name, bool is_deleted)
{
    std::ofstream log_file(log_file_name, std::ios::app);

    std::string str = get_str_format(line_number, class_name, is_deleted);

    log_file << str;
}

void Log::clear()
{
    std::ofstream log_file(log_file_name);
}

Log::Log() : log_file_name("log.txt") 
{
    save(__LINE__, "Log", false);
}

Log::~Log()
{
    save(__LINE__, "Log", true);
}
