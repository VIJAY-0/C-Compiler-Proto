%{
#include <stdio.h>
#include"TokenType.h"

#pragma once

%}

%%

[ \t]+                                      { /* Ignore whitespace. */ }
"IF"                                        {printf("INTEGER(%s)\n", yytext); return static_cast<int>(TokenType::IF) ; }
"return"                                    {printf("RETURN\n");return static_cast<int>(TokenType::RETURN) ; }
\r\n?|\n                                    {printf("NEWLINE_CHAR\n");return 100;/* Ignore newlines. */ }
[a-zA-Z_][a-zA-Z0-9_]*                      {printf("IDENTIFIER(%s)\n", yytext);return static_cast<int>(TokenType::ID) ; }
[0-9]+                                      {printf("INTEGER(%s)\n", yytext); return static_cast<int>(TokenType::INT_LIT) ;}
[-+]?[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?       {printf("REAL_NUMBER(%s)\n", yytext);return static_cast<int>(TokenType::REAL_LIT) ; }
";"                                         {printf("SEMI COlON\n");return static_cast<int>(TokenType::SEMI_COL) ; }
"="                                         {printf("=\n");return static_cast<int>(TokenType::EQUALS) ; }
"+"                                         {printf("PLUS\n"); }
"-"                                         {printf("MINUS\n"); }
"*"                                         {printf("MULTIPLY\n"); }
"/"                                         {printf("DIVIDE\n"); }
"("                                         {printf("LPAREN\n"); }
")"                                         {printf("RPAREN\n"); }
[0-9]+[a-zA-Z_][a-zA-Z0-9_]*                {printf("INVALID_IDENTIFIER(%s)\n", yytext); }
.                                           {printf("UNKNOWN()\n", yytext); }
%%

int yywrap() {
    return 1;
}
