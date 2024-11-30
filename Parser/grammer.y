%language "c++"


%code requires{
    #include<string>
    #include <cstdlib>
    #include<cstring>
    #include<map>
    #include "grammer.hpp"
    #include "./../InterMedCode/IC.hpp"
    #include "./../SymbolTable/symbol.hpp"
    #include "./../LDefs/define.hpp"
    
    class MyLexer ;
    #define NAMESIZE 20
    #define m(X) std::move(X)
}


%parse-param {Quad** resultAddr}
%parse-param {std::map<std::string,Symbol*>* SymbolTableAddr}
%parse-param {MyLexer* lexer}

%lex-param {MyLexer* lexer}


%{

    #include "./../Lexer/MyLexer.hpp"
    int yylex(yy::parser::semantic_type *yylval , MyLexer* lexer){
        return lexer->yylex(yylval);
    }


    Quad *QuadTable=nullptr;
    char c= ' ';
    char *labelPending=&c;
    char temp[8] = "temp" ;
    int temp_var_cnt;

    //symbol table
    long int relAddr = 0;
    std::map<std::string,Symbol*> SymbolTable;
    Attribute* null_attr = nullptr;
%}
%token _lpar "(" _rpar ")"  _lbrac "[" _rbrac "]" _lcurl "{" _rcurl "}"
%token _plus "+" _minus "-" _star" _f_slash "_asssign "="


%token _and
%token _or

%token _xor

%token _modulus
%token _assign
%token _equals
%token _not
%token _not_equals
%token _less_than
%token _greater_than
%token _less_equal
%token _greater_equal
%token _increment
%token _decrement



%token _semi_col
%token _col

%token _plus_equals
%token _minus_equals
%token _divide_equals
%token _multiply_equals

%token _if
%token _else
%token _switch
%token _case
%token _default
%token _for
%token _while
%token _do
%token _break
%token _continue
%token _return

%token _int
%token _float
%token _double
%token _char
%token _bool
%token _void
%token _long
%token _short
%token _unsigned
%token _signed

%token _main


%token _int_lit _float_lit 

%token _identifier  




%left _f_slash 
%left _star
%left _plus _minus 
%left _lpar _rpar _lcurl
%left _assign _semi_col

%type<attr> _int_lit
%type<attr> _identifier
%type<attr> _float_lit
%type<attr> arithmetic_exp

%type<d_type> _data_type


%type<ival> root

%union{
    Attribute* attr ;
    short int s_int;
    struct d_type{
        short int datatype;
        short int dataSize;
    }d_type;
}

%start root
%%

/*Grammar Rules*/

root :          _int _main{
                    createQuadList(&QuadTable);
                    std::cerr<<"\nsize of "<<sizeof(SymbolTable)<<'\n';

                }
                _lpar params _rpar _lcurl stms _rcurl {

                    
                    addCode(QuadTable,"exit",'!',null_attr,null_attr,null_attr);
                    
                    
                    *resultAddr = QuadTable;
                    *SymbolTableAddr = SymbolTable;  
                    printTable(SymbolTable);
                };

stms:           stms stm | stm ;


stm:            expression1 _semi_col
             | _return _int_lit _semi_col 
             | _if _lpar expression1 _rpar stm
             | _if _lpar expression1 _rpar stm _else stm
             | _switch _lpar expression1 _rpar _lcurl switch_cases _rcurl
             | _for _lpar opt_expr _semi_col opt_expr _semi_col opt_expr _rpar stm
             | _while _lpar expression1 _rpar stm
             | _do stm _while _lpar expression1 _rpar _semi_col
             | _break _semi_col
             | _continue _semi_col
             | _return opt_expr _semi_col
             | _identifier _assign arithmetic_exp _semi_col;

switch_cases:   switch_cases _case expression1 _col stm 
              | switch_cases _default _col stm 
              | _case expression1 _col stm 
              | _default _col stm;

opt_expr:       expression1 | /* empty */;


expression1:    assignment
|               var_decl {};

params :        var_decl1
|               %empty ;

var_decl1:      _data_type _identifier{
                    SymbolTable[std::string($2->name)] =  new Symbol(std::string($2->name),$1.datatype,$1.dataSize,relAddr);
                    relAddr = relAddr +  $1.dataSize ;
                };





var_decl:       var_decl1
|               _data_type assignment;

_data_type:     _char{
                    $$.datatype = CHAR;
                    $$.dataSize = SIZEOFCHAR;
                }
|               _int{
                    $$.datatype = INT;
                    $$.dataSize = SIZEOFINT;
                }
|               _float{
                    $$.datatype = FLOAT;
                    $$.dataSize = SIZEOFFLOAT;
                };
 
assignment:     _identifier _assign arithmetic_exp{
                    if(SymbolTable.find($1->name)==SymbolTable.end()) std::cerr<<"Variable not declared !!!\n";
                    else{addCode(QuadTable,"assign",'=',$1,$3,$1);
                    // std::cerr<<$1->name<<" "<<$1->name<<" = "<<$3->name<<'\n';
                    }
                };
                
arithmetic_exp :arithmetic_exp  _plus arithmetic_exp {
                    // std::cerr<<'\n'<<$$->name<<" = "<<$1->name<<" + "<<$3->name<<'\n';
                    std::string name = "temp"+std::to_string(temp_var_cnt) ;
                    $$ = new Attribute($1->type,$1->subtype,$1->dataSize,name);
                    temp_var_cnt++;

                    std::cerr<<$$->name<<" = "<<$1->name<<" + "<<$3->name<<'\n';
                    addCode(QuadTable,"arithmetic",'+',$1,$3,$$);

                    SymbolTable[std::string($$->name)] = new Symbol(std::string($$->name),$$->type,$$->dataSize,relAddr);
                    relAddr = relAddr +  $$->dataSize ;
                } 
|               arithmetic_exp  _minus  arithmetic_exp {
                    std::string name = "temp"+std::to_string(temp_var_cnt) ;
                    $$ = new Attribute($1->type,$1->subtype,$1->dataSize,name);
                    temp_var_cnt++;

                    std::cerr<<$$->name<<" = "<<$1->name<<" - "<<$3->name<<'\n';
                    addCode(QuadTable,"arithmetic",'-',$1,$3,$$);

                    SymbolTable[std::string($$->name)] = new Symbol(std::string($$->name),$$->type,$$->dataSize,relAddr);
                    relAddr = relAddr +  $$->dataSize ;
                }
|               arithmetic_exp  _f_slash  arithmetic_exp {
                
                    std::string name = "temp"+std::to_string(temp_var_cnt) ;
                    $$ = new Attribute($1->type,$1->subtype,$1->dataSize,name);
                    temp_var_cnt++;

                    std::cerr<<$$->name<<" = "<<$1->name<<" / "<<$3->name<<'\n';
                    addCode(QuadTable,"arithmetic",'/',$1,$3,$$);

                    SymbolTable[std::string($$->name)] = new Symbol(std::string($$->name),$$->type,$$->dataSize,relAddr);
                    relAddr = relAddr +  $$->dataSize ;
                }
|               arithmetic_exp  _star  arithmetic_exp {
                    std::string name = "temp"+std::to_string(temp_var_cnt) ;
                    $$ = new Attribute($1->type,$1->subtype,$1->dataSize,name);
                    temp_var_cnt++;

                    std::cerr<<$$->name<<" = "<<$1->name<<" * "<<$3->name<<'\n';
                    addCode(QuadTable,"arithmetic",'*',$1,$3,$$);

                    SymbolTable[std::string($$->name)] = new Symbol(std::string($$->name),$$->type,$$->dataSize,relAddr);
                    relAddr = relAddr +  $$->dataSize ;
                }
|               _lpar  arithmetic_exp _rpar {
                    $$ = $2;
                }

|               _identifier             {

                }
|               _int_lit               {
                    $$ = $1;
                }
|               _float_lit             {
                    $$ = $1;
                } ;
%%

void yy::parser::error(const std::string &msg){
    std::cerr<<msg;
}

