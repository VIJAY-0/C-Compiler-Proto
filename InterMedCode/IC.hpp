#ifndef IC_H
#define IC_H 

#include<string>

class Attribute{
    public:
        short int type; 
        short int subtype;
        short int dataSize; 
        std::string name;


        Attribute(short int type ,short int subtype,short int dataSize , std::string name):
            type(type),
            subtype(subtype),
            dataSize(dataSize),
            name(name){}
        
        Attribute(){}
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
    result(result){}

    Quad(){}


}Quad ;

void createQuadList(Quad **quadListHead);
void addCode(Quad *quadListHead,std::string label,char operatr,Attribute *operand1,Attribute *operand2,Attribute *result);
void printCode(Quad **quadListHead);
void createTemp(char temp[]);
void createLabel(char temp[]);


#endif