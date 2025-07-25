#include "CommandMap.hpp"
#include "Operations.hpp"
#include "Errors.hpp"
#include "Utils.hpp"
#include "History.hpp"

int main() 
{ 
    print_menu();

    std::string user_input;
    Operation operation;
    History history;
  
    auto commands = get_commands_map(operation, history);

    while(true) 
    {   
        std::cout << "Operation number: ";
        std::cin >> user_input;

        user_input = to_lowercase(user_input);

        auto it = commands.find(user_input);

        if(it != commands.end()) 
        {
            it->second();
        }

        else
        {
            print_invalid_input_error();
        }
    }

    return 0;
}