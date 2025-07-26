#include "Utils/PrintUtils.hpp"
#include "CommandMap.hpp"
#include "Operations.hpp"
#include "History.hpp"

int main() 
{ 
    print_start_menu();

    Operation operation;
    History history;

    auto commands = get_commands_map(operation, history);
    
    std::string user_input;
    
    while(true) 
    {   
        std::cout << "Operation number: ";

        std::cin >> user_input;
        to_lowercase(user_input);

        auto it = commands.find(user_input);

        if(it != commands.end()) 
            it->second();
        
        else
            print_invalid_input_error();
    }

    return 0;
}