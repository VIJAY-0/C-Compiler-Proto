#ifndef SYMBOLTABLE_H

#define SYMBOLTABLE_H
#include "./../InterMedCode/IC.hpp"
#include <string>
#include <map>
// #include ""

class Symbol{
    public:
        short int type;  // ID , Const
        short int subtype;  // Basic , Array ,Pointer , Reference 
        short int datatype;  // char , integer , long , float ,double
        short int mem_reqd;
        long int relAddr;
        std::string name;

        union {
            char cval;
            int ival;
            long lval;
            double dval;
            char* string;
        }
        value;

        Symbol(std::string name ,short int datatype,short int mem_reqd ,long int relAddr):
        name(name),
        datatype(datatype),
        mem_reqd(mem_reqd),
        relAddr(relAddr){}
};


void printTable(std::map<std::string , Symbol*> &Table);


#endif
