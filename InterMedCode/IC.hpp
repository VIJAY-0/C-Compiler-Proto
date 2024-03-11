#ifndef IC_H
#define IC_H 

#include<string>

typedef struct Attribute{
    short int type; 
    short int dataSize; 
    short int subtype;
    char name[40];

    union{
        char cval;
        int ival;
        char *string;
    }value;

}Attribute;


typedef struct Quad{
    char *label;
    char operatr;
    Attribute operand1;
    Attribute operand2;
    Attribute result;
    struct Quad *NextQuad=nullptr;

    Quad(char *label , char operatr ,    Attribute operand1,Attribute operand2,Attribute result ):
    label(label),
    operatr(operatr),
    operand1(operand1),
    operand2(operand2),
    result(result){}

    Quad(){}
}Quad ;

void createQuadList(Quad **quadListHead);
void addCode(Quad *quadListHead,char *label,char operatr,Attribute operand1,Attribute operand2,Attribute result);
void printCode(Quad **quadListHead);
void createTemp(char temp[]);
void createLabel(char temp[]);


#endif