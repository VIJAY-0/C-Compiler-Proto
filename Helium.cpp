#include<iostream>
#include<fstream>
#include<sstream>

#include "Lexer/MyLexer.hpp"
#include "Parser/grammer.hpp"
#include "InterMedCode/IC.hpp"
#include "SymbolTable/symbol.hpp"
#include "CodeGen/codeGen.hpp"



typedef struct res{
    Quad * QuadList;
    Symbol* SymbolTable;
};



int main(int argc , char * argv[]){


    if(argc <2) return 1;



    Quad *QuadsList = nullptr;
    typedef std::map<std::string , Symbol*> SymbolTable;
    SymbolTable symT;

    res res;

    std::ifstream inp(argv[1]);
    MyLexer *l = new MyLexer(inp, std::cerr) ;
    yy::parser *p = new yy::parser(&QuadsList,&symT,l) ;
    yy::parser::semantic_type yylval;
    int a;
    a=p->parse();
    // while(){
    //     std::cout<<" cout : "<<a<<" : "<<'\n';
    //     std::cout<<" cerr : "<<a<<" : "<<'\n';
    // }
    inp.close();

    std::cerr<<"back in main"<<'\n';

    printCode(&QuadsList);

    std::stringstream CODE  ;
    



    CODE<<"section .data\n";
    for(auto it:symT){
        CODE<<it.second->name<<" dq "<<it.second->relAddr<<'\n';
    }    
    CODE<<"section .text\n";
    CODE<<"global _start \n";
    CODE<<" _start: \n";

    Quad*ptr = QuadsList;
    
    
    while(ptr!=nullptr){
        CODE<<CG::genCode(ptr,&symT)<<'\n';
        ptr = ptr->NextQuad;
    }

    
    std::ofstream outp("CODE.asm");
    outp<<CODE.str();
    outp.close();


    std::cout<<CODE.str()<<'\n';

    delete QuadsList;
    delete l;
    delete p;
    return 0 ;
}
