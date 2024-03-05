%language "c++"


%code requires{

    #include "grammer.hpp"
class MyLexer ;

}


%parse-param {int* result}
%parse-param {MyLexer* lexer}

%lex-param {MyLexer* lexer}



%{
    #include "./../Lexer/MyLexer.hpp"
    int yylex(yy::parser::semantic_type *yylval , MyLexer* lexer){
        return lexer->yylex(yylval);
    }
%}

%token ENDOFFILE
%token INT REAL UNKNOWN
%token LPAREN1 "{" RPAREN1 "}" 
%token PLUS "+" MINUS "-" STAR "*" DIV "/" EQUALS "="

%left DIV
%left STAR
%left PLUS MINUS 


%type<int_value> INT
%type<real_value> REAL
%type<real_value> expression

%type<int_value> root


%union{
    int int_value;
    float real_value;
    std::string* str_value ;
}

%start root
%%
 /*  Grammar Rules */



root :          expression {*result  = $1;};

expression : expression  PLUS  expression {$$ = $1 + $3 ;std::cout<<"AddItion\n";} 
|            expression  MINUS  expression {$$ = $1 - $3 ;std::cout<<"Subtraction\n";}
// |            expression  DIV  expression {$$ = $1 / $3 ;std::cout<<"Division\n";}
// |            expression  STAR  expression {$$ = $1 * $3 ;std::cout<<"Multiplication\n";}
// |            LPAREN1 expression RPAREN1 {$$ = $2 ;std::cout<<"curly\n";}
// |            '[' expression ']' {$$ = $2 ;std::cout<<"Square\n";}
// |            '(' expression ')' {$$ = $2 ;std::cout<<"parenthese\n";}
// |             REAL             {$$ = $1;std::cout<<"REAL expression\n";}
|             INT               {$$ = $1;std::cout<<"int expression\n";};
%%


void yy::parser::error(const std::string &msg){
    std::cerr<<msg;
}