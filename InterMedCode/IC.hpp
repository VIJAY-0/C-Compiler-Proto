#ifndef IC_H
#define IC_H 

#include<string>
#include<iostream>

class Attribute{
    public:
        short int type;
        bool is_symbol=1; 
        short int subtype;
        short int dataSize; 
        std::string name;


        Attribute(short int type ,short int subtype,short int dataSize , std::string name):
            type(type),
            subtype(subtype),
            dataSize(dataSize),
            name(name){
                // std::cerr<<"Attribute  called for -> "<<this->name<<'\n';
            }
        
        Attribute(std::string name):name(name){
                // std::cerr<<"Attribute  called for -> "<<this->name<<'\n';
        }
        ~Attribute(){
                // std::cerr<<"~Attribute called for -> "<<this->name<<'\n';
            }
};


typedef struct Quad{
    std::string label;
    char operatr;
    Attribute *operand1;
    Attribute *operand2;
    Attribute *result;
    struct Quad *NextQuad=nullptr;

    Quad(std::string label , char operatr ,    Attribute *operand1,Attribute *operand2,Attribute *result ):
    label(label),
    operatr(operatr),
    operand1(operand1),
    operand2(operand2),
    result(result){
        // std::cerr<<"Quad  called for -> "<<this->operatr<<'\n';
    }
    Quad(){
            // std::cerr<<"Quad  called for -> "<<this->operatr<<'\n';
    }
    ~Quad(){
        // std::cerr<<"~Quad called for -> "<<this->operatr<<'\n';
        if(this->operand1!=nullptr) delete this->operand1;
        if(this->operand2!=nullptr) delete this->operand2;
        if(this->result!=nullptr) delete this->result;
    }



}Quad ;


void createQuadList(Quad **quadListHead);
void addCode(Quad *quadListHead,std::string label,char operatr,Attribute *operand1,Attribute *operand2,Attribute *result);
void printCode(Quad **quadListHead);
void createTemp(char temp[]);
void createLabel(char temp[]);

void destructQuadTable(Quad *quadListHead);


#endif