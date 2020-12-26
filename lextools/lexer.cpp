#include "lexer.hpp"

int is_letter(char c) {
    return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_');
}

int is_number(char c) {
    return ('0' <= c) && (c <= '9');
}

int Lexer::read_char() {
    this->readpos >= this->input.length() ?
         (this->ch = 0) :
         (this->ch = this->input[this->readpos]);
    this->pos = this->readpos;
    this->readpos++;
    return 0;
}
char Lexer::peek_char() {
         return this->readpos >= this->input.length() ? 0 : this->input[this->readpos];
}

std::string Lexer::check_special(int (*fun)(char)) {
    size_t pos = this->pos;
    while((*fun)(this->ch)) {
        this->read_char();
    }
    return this->input.substr(pos,this->pos - pos);
}


int Lexer::skip_whitespace() {
    while(this->ch == ' ' || this->ch == '\t' || this->ch == '\n' || this->ch == '\r') {
        this->read_char();
    }
    return 0;
}

token_type Lexer::lookup_ident(std::string s) {
    auto comp = this->keywords.find(s);
    return comp != this->keywords.end() ?  comp->second : token_type::IDENT;
}

Token Lexer::emit_token() {
    Token tok;
    this->skip_whitespace();
    switch(this->ch) {
        
        case '=':
            if (this->peek_char() == '=') {
                this->read_char();
                tok = Token(token_type::EQ,"==");
            } else {
                tok = Token(token_type::ASSIGN,"=");
            }
            break;
        case ';':
            tok = Token(token_type::SEMICOLON,";");
            break;
        case '(':
            tok = Token(token_type::RPAREN,"(");
            break;
        case ')':
            tok = Token(token_type::LPAREN,")");
            break;
        case ',':
            tok = Token(token_type::COMMA,",");
            break;
        case '+':
            tok = Token(token_type::PLUS,"+");
            break;
        case '{':
            tok = Token(token_type::LBRACE,"{");
            break;
        case '}':
            tok = Token(token_type::RBRACE,"}");
            break;
        case '<':
            tok = Token(token_type::LESS,"<");
            break;
        case '>':
            tok = Token(token_type::GREATER,">");
            break;
        case '*':
            tok = Token(token_type::STAR,"*");
            break;
        case '!':
            if (this->peek_char() == '=') {
                this->read_char();
                tok = Token(token_type::NEQ,"!=");
            } else {
                tok = Token(token_type::NOT,"!");
            }
            break;
        case '/':
            tok = Token(token_type::DIV,"/");
            break;
        case '-':
            tok = Token(token_type::MINUS,"-");
            break;
        case 0:
            tok = Token(token_type::EOFF,"EOF");
            break;
        

        default:
            if(is_letter(this->ch)) {
                tok.literal = this->check_special(&is_letter);
                
                tok.type = this->lookup_ident(tok.literal);
                return tok;
            }
            else if(is_number(this->ch)) {
                
                tok.literal = this->check_special(&is_number);
                tok.type = token_type::INT;
                return tok;
            }
            else {
                std::string str(1,this->ch);
                tok = Token(token_type::ILLEGAL,str);
            }
            break;
    }
    this->read_char();
    return tok;
}

std::vector<Token> Lexer::vectorize_input() {
    Token t = this->emit_token();
    auto vec = std::vector<Token>();
    for(;;) {
        t = this->emit_token();
        vec.push_back(t);
        if (t.type == token_type::EOFF) {
            break;
        }
    }
    return vec;
}
