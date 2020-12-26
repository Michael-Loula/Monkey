#include <string>

enum class token_type{ILLEGAL,EOFF,IDENT,
                        INT,ASSIGN,PLUS,
                        COMMA,SEMICOLON,LPAREN,
                        RPAREN,LBRACE,RBRACE,FUNCTION,
                        LET, IF, ELSE, TRUE, FALSE,
                         RETURN, EQ, NOT, NEQ, MINUS, 
                         DIV, STAR, LESS, GREATER };

class Token {
    public:
    token_type type;
    std::string literal;
    Token(token_type t,std::string s) {
        this->type = t;
        this->literal = s;
    }
    Token() {}
};