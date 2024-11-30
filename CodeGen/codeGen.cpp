#include "codeGen.hpp"
#include<sstream>
#include<string>


// very very ineffecient ;

void CG::codeGenerator(Quad * QuadT,std::map<std::string,Symbol*>* SymbolTable){
    
}

std::string CG::genCode(Quad * quad,std::map<std::string,Symbol*>* SymbolTable){
    //before every execution push all the registers to the stack and 
    //handle the calculations and then pop registers
    std::stringstream strm ;
    if(quad->label == "arithmetic") {

        bool isop1sym = quad->operand1->is_symbol;
        bool isop2sym = quad->operand2->is_symbol;

        std::string operation ;

        char opr = quad->operatr;

        if(opr=='/'){
            if(isop1sym)strm<<"MOV rax, "<<"["<<quad->operand1->name<<"]"<<'\n';
            else strm<<"MOV rax, "<<quad->operand1->name<<'\n';
        
            if(isop2sym)strm<<"MOV r8, "<<"["<<quad->operand2->name<<"]"<<'\n';
            else strm<<"MOV r8, "<<quad->operand2->name<<'\n';
            
            strm<<"DIV r8"<<'\n';

            strm<<"MOV ["<<quad->result->name<<"], rax"<<'\n';
        }
        else if(opr == '*'){
            if(isop1sym)strm<<"MOV rax, "<<"["<<quad->operand1->name<<"]"<<'\n';
            else strm<<"MOV rax, "<<quad->operand1->name<<'\n';
            
            if(isop2sym)strm<<"MOV rdi, "<<"["<<quad->operand2->name<<"]"<<'\n';
            else strm<<"MOV rdi, "<<quad->operand2->name<<'\n';
            
            strm<<"MUL rdi"<<'\n';
            strm<<"MOV ["<<quad->result->name<<"], rax"<<'\n';

        }
        else if(opr == '+') {
            if(isop1sym)strm<<"MOV rdi, "<<"["<<quad->operand1->name<<"]"<<'\n';
            else strm<<"MOV rdi, "<<quad->operand1->name<<'\n';
            
            if(isop2sym)strm<<"ADD rdi, "<<"["<<quad->operand2->name<<"]"<<'\n';
            else strm<<"ADD rdi, "<<quad->operand2->name<<'\n';
            
            strm<<"MOV ["<<quad->result->name<<"], rdi"<<'\n';
        }
        else if(opr == '-') {
            if(isop1sym)strm<<"MOV rdi, "<<"["<<quad->operand1->name<<"]"<<'\n';
            else strm<<"MOV rdi, "<<quad->operand1->name<<'\n';
            
            if(isop2sym)strm<<"SUB rdi, "<<"["<<quad->operand2->name<<"]"<<'\n';
            else strm<<"SUB rdi, "<<quad->operand2->name<<'\n';
            
            strm<<"MOV ["<<quad->result->name<<"], rdi"<<'\n';
        }
    }
    else if(quad->label == "exit"){
        
        int exit_code = 0;
        strm<<"MOV rax, 60 \n";
        // strm<<"MOV rdi, "<<exit_code<<'\n';
        strm<<"syscall"<<'\n';
    }
        return strm.str();
}