%option c++
%option noyywrap

%option yyclass = "MyLexer"

%{
// #include<iostream>
#include "./../Parser/grammer.hpp"
#include "MyLexer.hpp"
// #include "MyLexer.hpp"

#define TOKEN(X) yy::parser::token::X 

%}

%%

[ \r\t]+                                    { /* Ignore whitespace. */ }
"+"                                         {std::cout<<"PLUS{"<<yytext<<"} \n"; return TOKEN(PLUS) ;}
"-"                                         {printf("MINUS\n", yytext); return TOKEN(MINUS) ;}
"/"                                         {printf("SLASH\n", yytext); return TOKEN(DIV) ;}
"*"                                         {printf("STAR\n", yytext); return TOKEN(STAR) ;}
"{"                                         {printf("LPAREN1\n", yytext); return TOKEN(LPAREN1) ;}
"}"                                         {printf("RPAREN1\n", yytext); return TOKEN(RPAREN1) ;}
[0-9]+                                      {yylval->int_value = std::stoi(std::string(yytext,yyleng));std::cout<<"INT{"<<yytext<<"} \n"; return TOKEN(INT) ;}
"qwe"                                       {std::cout<<"YYEOF_MAN{"<<yytext<<"} \n"; return TOKEN(YYEOF) ; }
.                                           {std::cout<<"UNKNOWN{"<<yytext<<"} \n"; return TOKEN(UNKNOWN) ;}
<<EOF>>                                     {std::cout<<"EOF{"<<yytext<<"} \n"; return TOKEN(YYEOF) ;}


%%




int MyFlexLexer::yylex(){return TOKEN(YYEMPTY);}
int MyFlexLexer::yywrap(){return TOKEN(YYEMPTY);}


MyLexer::MyLexer(std::istream &is , std::ostream &os)
:MyFlexLexer(is,os)
{

}

int MyLexer::yylex(yy::parser::semantic_type *yylval){
    this->yylval= yylval;
    return yylex();
}
