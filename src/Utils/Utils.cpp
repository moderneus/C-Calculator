#include "Utils/Utils.hpp"

void to_lowercase(std::string& str)
{
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }      
    }
}