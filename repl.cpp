#include "lextools/lexer.hpp"
#include <iostream>

//VERY basic repl
int main(int ac, char** av) {
    std::cout << "type whatever you want:" << std::endl;
    std::string data;
    while(1) {
        std::getline(std::cin, data);
        Lexer l(data);
        auto vec = l.vectorize_input();
        for (auto &elem : vec)
            std::cout << elem.literal << " (" << int(elem.type) << ")" << std::endl;
        }
    return 0;
}