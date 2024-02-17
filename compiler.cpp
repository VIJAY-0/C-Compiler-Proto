#include<iostream>
#include<fstream>
#include<sstream>
#include<optional>
#include<vector>
#include "Tokenization.hpp"

enum class TokenType{
    EXIT,
    INTEGER_LIT,
    SEMI_COLON
};

struct Token{
    TokenType type;
    std::optional<std::string> value;
};

std::vector<Token> tokenizer(const std::string &str){

    std::vector<Token> tokens={};

    std::string buff="";
    for(int i=0;i<str.size();i++){

        char c = str.at(i);
        if(isalpha(c)){
            buff.push_back(c);
            i++;
            while(isalnum(str.at(i))){
                buff.push_back(str.at(i));
                i++;
            }
            i--;

            // std::cerr<<buff<<std::endl;

            if(buff == "exit"){
                tokens.push_back({.type = TokenType::EXIT,.value="exit"});
                buff.clear();
            }
            else{
                std::cerr<<"return statement not found !!\n"<<std::endl;
                exit(EXIT_FAILURE);
            }

        }
        else if(isdigit(c)){
            buff.push_back(c);
            i++;
            while(isdigit(str.at(i))){
                buff.push_back(c);
                i++;
            }
            i--;
            
            tokens.push_back({.type = TokenType::INTEGER_LIT,.value = buff});
            buff.clear();
        }
        else if(c==';'){
            tokens.push_back({.type = TokenType::SEMI_COLON,.value = ";"});
            buff.clear();
        }
        else if(isspace(c)) continue;
        else{
              std::cerr<<"return statement not found !!\n"<<std::endl;
                exit(EXIT_FAILURE);
        }

    }
    
    return tokens;

}

std::string token_to_asm(const std::vector<Token> &tokens){
    std::stringstream output;
    output<<"global _start\n";
    output<<"_start:\n";

    for(int i=0;i<tokens.size();i++){
        const Token token= tokens.at(i);
        if(token.type == TokenType::EXIT){
            if(i+1 < tokens.size() && tokens.at(i+1).type == TokenType::INTEGER_LIT){
                if(i+2 < tokens.size() && tokens.at(i+2).type == TokenType::SEMI_COLON){
                    output<<"   mov rax, 60\n";
                    output<<"   mov rdi,"<<tokens.at(i+1).value.value()<<"\n";
                    output<<"   syscall\n";
                }
            }
        } 
    }

    return output.str();

}

int main(int argc , char* argv[]){

    if(argc != 2 ) {
        std::cerr<<"Invalid Usage !!\n";
        std::cerr<<"helium <input.heli>\n";

    }
    std::stringstream content_string;
    {
        std::fstream input(argv[1],std::ios::in);
        content_string << input.rdbuf();
    }

    std::string content = content_string.str();

    std::vector<Token> stm = tokenizer(content); 
    // for(auto &it:stm) std::cout<<it->value<<std::endl;

    {
        std::fstream file("out.asm",std::ios::out);
        file << token_to_asm(stm);
    }

    return 0;
}