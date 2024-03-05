#ifndef __MYLEXER_H
#define __MYLEXER_H

// #ifndef yyFlexLexerOnce
        #undef yyFlexLexer
        #define yyFlexLexer MyFlexLexer
        #include<FlexLexer.h>
// #endif
#include "./../Parser/grammer.hpp"


class MyLexer: public MyFlexLexer{
    private:
        yy::parser::semantic_type *yylval;
        int yylex();

    public:
        MyLexer(std::istream &is , std::ostream &os);
        int yylex(yy::parser::semantic_type *yylval);

};







#endif