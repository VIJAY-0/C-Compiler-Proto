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

"&"                                         {TOKEN(_and) ;}
"|"                                         {TOKEN(_or) ;}
"^"                                         {TOKEN(_xor) ;}

"%"                                         {TOKEN(_modulus);}
"="                                         {TOKEN(_assign);}
"=="                                        {TOKEN(_equals);}
"!="                                        {TOKEN(_not_equals);}
"<"                                         {TOKEN(_less_than);}
">"                                         {TOKEN(_greater_than);}
"<="                                        {TOKEN(_less_equal);}
">="                                        {TOKEN(_greater_equal);}
"&&"                                        {TOKEN(_and);}
"||"                                        {TOKEN(_or);}
"!"                                         {TOKEN(_not);}
"++"                                        {TOKEN(_increment);}
"--"                                        {TOKEN(_decrement);}

"("                                         {TOKEN(_lpar) ;}
")"                                         {TOKEN(_rpar) ;}
"["                                         {TOKEN(_lbrac) ;}
"]"                                         {TOKEN(_rbrac) ;}
"{"                                         {TOKEN(_lcurl) ;}
"}"                                         {TOKEN(_rcurl) ;}
"="                                         {TOKEN(_assign) ;}
";"                                         {TOKEN(_semi_col) ;}
":"                                         {TOKEN(_col) ;}



"+="                                        {TOKEN(_plus_equals) ;}
"-="                                        {TOKEN(_minus_equals) ;}
"/="                                        {TOKEN(_divide_equals) ;}
"*="                                        {TOKEN(_multiply_equals) ;}

"|="                                        {TOKEN(_col) ;}
"^="                                        {TOKEN(_col) ;}
"&="                                        {TOKEN(_col) ;}

"if"                                        {TOKEN(_if);}
"else"                                      {TOKEN(_else);}
"switch"                                    {TOKEN(_switch);}
"case"                                      {TOKEN(_case);}
"default"                                   {TOKEN(_default);}
"for"                                       {TOKEN(_for);}
"while"                                     {TOKEN(_while);}
"do"                                        {TOKEN(_do);}
"break"                                     {TOKEN(_break);}
"continue"                                  {TOKEN(_continue);}
"return"                                    {TOKEN(_return);}


"int"                                       {TOKEN(_int);}
"float"                                     {TOKEN(_float);}
"double"                                    {TOKEN(_double);}
"char"                                      {TOKEN(_char);}
"bool"                                      {TOKEN(_bool);}
"void"                                      {TOKEN(_void);}
"long"                                      {TOKEN(_long);}
"short"                                     {TOKEN(_short);}
"unsigned"                                  {TOKEN(_unsigned);}
"signed"                                    {TOKEN(_signed);}

"main"                                      {TOKEN(_main);}         
"return"                                    {TOKEN(_return);}         

[a-zA-Z_]+[0-9a-zA-Z_]*                     {
                                            yylval->attr = new Attribute(100,0,SIZEOFINT,std::string(yytext));
                                            TOKEN(_identifier);}

[0-9]+                                      {
                                            yylval->attr = new Attribute(INT,0,SIZEOFINT,std::string(yytext));
                                            yylval->attr->is_symbol=0;
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
