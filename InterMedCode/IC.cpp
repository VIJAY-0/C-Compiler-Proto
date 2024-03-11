#include "IC.hpp"
#include<iostream>

void createQuadList(Quad **quadListHead){
    *quadListHead = new Quad();
}

void printCode(Quad **quadListHead){
    std::cerr<<"\n------------printing enterd----------\n";
    if(*quadListHead == nullptr){
        std::cerr<<"EMPTY Quad list!!!\n";
    }
    else{
        Quad *ptr = *quadListHead;
        while(ptr!= nullptr){
            if(ptr->label!="")std::cerr<<ptr->operatr<<" : "<<ptr->operand1->name<<" : "<<ptr->operand2->name<<" : "<<ptr->result->name<<'\n';
            ptr= ptr->NextQuad ;
        } 
    }
    std::cerr<<"------------printing exited----------\n";

}
void addCode(Quad *quadListHead,std::string label,char operatr,Attribute* operand1,Attribute* operand2,Attribute* result){

    // if(label!=nullptr)std::cerr<<"inside addCode ->   "<<operatr<<" : "<<operand1.name<<" : "<<operand2.name<<" : "<<result.name<<'\n';
    if(quadListHead == nullptr){
        quadListHead = new Quad(label,operatr,operand1,operand2,result) ;
    }
    else{
        Quad *ptr = quadListHead;
        while(ptr->NextQuad != nullptr) ptr= ptr->NextQuad ;
        ptr->NextQuad = new Quad(label,operatr,operand1,operand2,result) ;
    }
    // std::cerr<<"--------  "<<ptr<<"  -----------\n";
    // std::cerr<<"--------  "<<ptr<<"  -----------\n";
}
