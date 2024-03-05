#include<iostream>
#include<fstream>

#include "Lexer/MyLexer.hpp"
#include "Parser/grammer.hpp"



int main(int argc , char * argv[]){

    if(argc <2) return 1;
    int *result;
    int ans =-2;
    result=&ans;


    std::ifstream inp(argv[1]);
    MyLexer *l = new MyLexer(inp, std::cerr) ;

    yy::parser *p = new yy::parser(result,l) ;
    yy::parser::semantic_type yylval;
    int a;
    a=p->parse();
    // while(){
    //     std::cout<<" cout : "<<a<<" : "<<'\n';
    //     std::cout<<" cerr : "<<a<<" : "<<'\n';
    // }
    inp.close();
    std::cout<<"parsed result is >>> "<<*result<<'\n';
    delete l;
    delete p;
    return 0 ;
}