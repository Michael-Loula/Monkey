#include "../token.hpp"
#include <map>
#include <vector>

class Lexer {
    public:
    //input buffer
    std::string input;

    //position 
    size_t pos;
    size_t readpos;

    //current datum
    char ch;

    //keywords
    std::map<std::string,token_type> keywords;

    Lexer(std::string s) {
        this->input = s;
        this->readpos = 0;
        this->pos = 0;
        keywords.insert(std::pair<std::string,token_type>("fn",token_type::FUNCTION));
        keywords.insert(std::pair<std::string,token_type>("let",token_type::LET));
        keywords.insert(std::pair<std::string,token_type>("true",token_type::TRUE));
        keywords.insert(std::pair<std::string,token_type>("false",token_type::FALSE));
        keywords.insert(std::pair<std::string,token_type>("return",token_type::RETURN));
        keywords.insert(std::pair<std::string,token_type>("if",token_type::IF));
        keywords.insert(std::pair<std::string,token_type>("else",token_type::ELSE));
    }

    int read_char();
    char peek_char();
    std::string check_special(int (*)(char));
    int skip_whitespace();
    token_type lookup_ident(std::string);
    Token emit_token();
    std::vector<Token> vectorize_input();
};

