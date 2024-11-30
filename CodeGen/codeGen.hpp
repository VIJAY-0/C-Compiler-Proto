#ifndef CODEGEN_H
#define CODEGEN_H

#include "./../InterMedCode/IC.hpp"
#include "./../SymbolTable/symbol.hpp"

namespace CG{
    void codeGenerator(Quad * QuadT,std::map<std::string,Symbol*>* SymbolTable);
    std::string genCode(Quad * quad,std::map<std::string,Symbol*>* SymbolTable);
}

#endif