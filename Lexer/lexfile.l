%option c++
%option noyywrap

%option yyclass = "MyLexer"

%{
// #include<iostream>
#include "./../Parser/grammer.hpp"
#include "MyLexer.hpp"
// #include "MyLexer.hpp"

// #define ST_CST(a) static_cast<int>(arithmetic::a)
#define TOKEN(X)  return yy::parser::token::X ;

%}

%%

[ \r\t]+                                    { /* Ignore whitespace. */ }
"+"                                         {TOKEN(_plus) ;}
"-"                                         {TOKEN(_minus) ;}
"/"                                         {TOKEN(_f_slash) ;}
"*"                                         {TOKEN(_star) ;}
"("                                         {TOKEN(_lpar) ;}
")"                                         {TOKEN(_rpar) ;}
"["                                         {TOKEN(_lbrac) ;}
"]"                                         {TOKEN(_rbrac) ;}
"{"                                         {TOKEN(_lcurl) ;}
"}"                                         {TOKEN(_rcurl) ;}
"="                                         {TOKEN(_assign) ;}
";"                                         {TOKEN(_semi_col) ;}
"int"                                       {TOKEN(_int);}         
"float"                                     {TOKEN(_float);}         
"main"                                      {TOKEN(_main);}         
"return"                                    {TOKEN(_return);}         

[a-zA-Z_]+[0-9a-zA-Z_]*                     {
                                            yylval->attr = new Attribute(100,0,SIZEOFINT,std::string(yytext));
                                            TOKEN(_identifier);}

[0-9]+                                      {
                                            yylval->attr = new Attribute(INT,0,SIZEOFINT,std::string(yytext));
                                            TOKEN(_int_lit) ;}

['].[']                                     {
                                            yylval->attr = new Attribute(CHAR,0,SIZEOFCHAR,std::string(yytext));
                                            }

<<EOF>>                                     {TOKEN(YYEOF) ;}

%%




int MyFlexLexer::yylex(){TOKEN(YYEMPTY);}
int MyFlexLexer::yywrap(){TOKEN(YYEMPTY);}


MyLexer::MyLexer(std::istream &is , std::ostream &os):MyFlexLexer(is,os){}

int MyLexer::yylex(yy::parser::semantic_type *yylval){
    this->yylval= yylval;
    return yylex();
}
