#include "IC.hpp"
#include<iostream>
#include<string>

void createQuadList(Quad **quadListHead){
    *quadListHead = new Quad();
    (*quadListHead)->label = "INIT";
    (*quadListHead)->operatr = 'I';
}





void printCode(Quad **quadListHead){
    if(*quadListHead == nullptr){
        std::cerr<<"EMPTY Quad list!!!\n";
    }
    else{
        Quad *ptr = *quadListHead;
        while(ptr!= nullptr){



            if(ptr->label == "exit") std::cerr<<ptr->label<<" : "<<'\n'<<'\n';
            else if(ptr->label!="INIT" && ptr->label!="")std::cerr<<ptr->operatr<<" : "<<ptr->operand1->name<<" : "<<ptr->operand2->name<<" >> "<<ptr->result->name<<'\n';
            ptr= ptr->NextQuad ;
        } 
    }
}




void addCode(Quad *quadListHead,std::string label,char operatr,Attribute* operand1,Attribute* operand2,Attribute* result){
    if(quadListHead == nullptr){
        quadListHead = new Quad(label,operatr,operand1,operand2,result) ;
    }
    else{
        Quad *ptr = quadListHead;
        while(ptr->NextQuad != nullptr) ptr= ptr->NextQuad ;
        ptr->NextQuad = new Quad(label,operatr,operand1,operand2,result) ;
    }
}



void destructQuadTable(Quad* qhead){
    Quad * ptr1 = qhead ;
    Quad * ptr2;
    while(ptr1!=nullptr){

        ptr2 = ptr1->NextQuad;
        delete ptr1;
        ptr1=ptr2;

    }
}