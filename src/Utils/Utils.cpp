#include "Utils/Utils.hpp"

std::array<double, 2> convert_to_double(const std::array<std::string, 2>& values) 
{
    return 
    {
        std::stod(values[0]),
        std::stod(values[1])
    };
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