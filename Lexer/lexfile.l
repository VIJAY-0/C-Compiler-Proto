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
                                            strcpy(yylval->attr.name,yytext);
                                            yylval->attr.type = 0; //ID
                                            TOKEN(_identifier);}

[0-9]+                                      {
                                            strcpy(yylval->attr.name,yytext);
                                            yylval->attr.type = INT; //Integer Lit
                                            yylval->attr.dataSize = SIZEOFINT; //Integer Lit
                                            yylval->attr.value.ival = std::stoi(yytext);
                                            TOKEN(_int_lit) ;}

['].[']                                     {
                                            strcpy(yylval->attr.name,yytext);
                                            yylval->attr.type = 2;
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
