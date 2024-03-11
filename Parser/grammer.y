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
%}


%token _int _float _char _main _return UNKNOWN _semi_col
%token _int_lit _float_lit 
%token _identifier  
%token _lpar "(" _rpar ")"  _lbrac "[" _rbrac "]" _lcurl "{" _rcurl "}"
%token _plus "+" _minus "-" _star" _f_slash "_asssign "="

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
    Attribute attr ;
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
                    *resultAddr = QuadTable;  
                    printTable(SymbolTable);
                };

stms:           stms stm | stm ;

stm:            expression1 _semi_col
|               _return _int_lit _semi_col; 

expression1:    assignment
|               var_decl {};

params :        var_decl1
|               %empty ;

var_decl1:      _data_type _identifier{
                    SymbolTable[std::string($2.name)] =  new Symbol(std::string($2.name),$1.datatype,$1.dataSize,relAddr);
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
                    if(SymbolTable.find(std::string($1.name))==SymbolTable.end()) std::cerr<<"Variable not declared !!!\n";
                    else{addCode(QuadTable,labelPending,'=',$1,$3,$1);
                    std::cerr<<$1.name<<" "<<$1.name<<" = "<<$3.name<<'\n';}
                };
arithmetic_exp :arithmetic_exp  _plus arithmetic_exp {
                    char tmp_no[5] ;sprintf(tmp_no, "%d",temp_var_cnt);
                    strcpy($$.name , "temp");
                    $$.name[4]=tmp_no[0];
                    $$.name[5]=tmp_no[1];
                    $$.name[6]=tmp_no[2];
                    addCode(QuadTable,$$.name,'+',$1,$3,$$);
                    std::cerr<<$$.name<<" = "<<$1.name<<" + "<<$3.name<<'\n';
                    temp_var_cnt++;

                       SymbolTable[std::string($$.name)] = new Symbol(std::string($$.name),$$.type,$$.dataSize,relAddr);
                    relAddr = relAddr +  $$.dataSize ;
                } 
|               arithmetic_exp  _minus  arithmetic_exp {
                    char tmp_no[5] ; sprintf(tmp_no, "%d",temp_var_cnt);
                    strcpy($$.name , "temp");
                    $$.name[4]=tmp_no[0];
                    $$.name[5]=tmp_no[1];
                    $$.name[6]=tmp_no[2];
                    addCode(QuadTable,$$.name,'-',$1,$3,$$);
                    std::cerr<<$$.name<<" = "<<$1.name<<" - "<<$3.name<<'\n';
                    temp_var_cnt++;

                    SymbolTable[std::string($$.name)] = new Symbol(std::string($$.name),$$.type,$$.dataSize,relAddr);
                    relAddr = relAddr +  $$.dataSize ;
                }
|               arithmetic_exp  _f_slash  arithmetic_exp {
                    char tmp_no[5] ; sprintf(tmp_no, "%d",temp_var_cnt);
                    strcpy($$.name , "temp");
                    $$.name[4]=tmp_no[0];
                    $$.name[5]=tmp_no[1];
                    $$.name[6]=tmp_no[2];
                    addCode(QuadTable,$$.name,'/',$1,$3,$$);
                    std::cerr<<$$.name<<" = "<<$1.name<<" / "<<$3.name<<'\n';
                    temp_var_cnt++;

                       SymbolTable[std::string($$.name)] = new Symbol(std::string($$.name),$$.type,$$.dataSize,relAddr);
                    relAddr = relAddr +  $$.dataSize ;
}
|               arithmetic_exp  _star  arithmetic_exp {
                    char tmp_no[5] ; sprintf(tmp_no, "%d",temp_var_cnt);
                    strcpy($$.name , "temp");
                    $$.name[4]=tmp_no[0];
                    $$.name[5]=tmp_no[1];
                    $$.name[6]=tmp_no[2];
                    addCode(QuadTable,$$.name,'*',$1,$3,$$);
                    std::cerr<<$$.name<<" = "<<$1.name<<" * "<<$3.name<<'\n';
                    temp_var_cnt++;

                       SymbolTable[std::string($$.name)] = new Symbol(std::string($$.name),$$.type,$$.dataSize,relAddr);
                    relAddr = relAddr +  $$.dataSize ;
                }
|               _lpar  arithmetic_exp _rpar {
                    $$ = $2;
                }
|               _lbrac arithmetic_exp _rbrac {}
|               _rcurl arithmetic_exp _rcurl {}
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