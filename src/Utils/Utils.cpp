#include "Utils/Utils.hpp"

void to_lowercase(std::string& str)
{
    for(char& c : str)
    {
        if(c >= 'A' && c <= 'Z')
        {
            c += ASCII::ASCII_CASE_DIFF;
        }      
    }
}

bool is_empty(const std::filesystem::path& path)
{
    return (std::filesystem::file_size(path) == File::EMPTY_SIZE); 
}

void enable_ANSI()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}