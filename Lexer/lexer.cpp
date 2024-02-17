#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include"lexer.h"

class Token{
    private:
        TokenType token;
        std::string value;
    public:
        Token(int token_id , std::string value):token(static_cast<TokenType>(token_id)) , value(value){

    }

};

int main(int argc , char* argv[]){
    std::vector<Token> tokens;
    
    yyin = fopen(argv[1] ,"r");
    int c;
    while((c=yylex())){
        tokens.push_back(Token(c,yytext));
    }
    std::cout<<"Number of Tokens generated ->"<<tokens.size()<<'\n';

    return 0;
}