#include<iostream>
#include<fstream>

#include "Lexer/MyLexer.hpp"
#include "Parser/grammer.hpp"
#include "InterMedCode/IC.hpp"



int main(int argc , char * argv[]){


    if(argc <2) return 1;
    Quad *result = nullptr;

    std::ifstream inp(argv[1]);

    MyLexer *l = new MyLexer(inp, std::cerr) ;
    yy::parser *p = new yy::parser(&result,l) ;
    yy::parser::semantic_type yylval;
    int a;
    a=p->parse();
    // while(){
    //     std::cout<<" cout : "<<a<<" : "<<'\n';
    //     std::cout<<" cerr : "<<a<<" : "<<'\n';
    // }
    inp.close();

    std::cerr<<"back in main"<<'\n';
    printCode(&result);
    

    delete result;
    delete l;
    delete p;
    return 0 ;
}