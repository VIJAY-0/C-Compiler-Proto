// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 26 "Parser/grammer.y"


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

#line 60 "Parser/grammer.cpp"


#include "grammer.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 138 "Parser/grammer.cpp"

  /// Build a parser object.
  parser::parser (Quad** resultAddr_yyarg, MyLexer* lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      resultAddr (resultAddr_yyarg),
      lexer (lexer_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}


  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, lexer));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // $@1: %empty
#line 82 "Parser/grammer.y"
                          {
                    createQuadList(&QuadTable);
                    std::cerr<<"\nsize of "<<sizeof(SymbolTable)<<'\n';

                }
#line 600 "Parser/grammer.cpp"
    break;

  case 3: // root: _int _main $@1 "(" params ")" "{" stms "}"
#line 87 "Parser/grammer.y"
                                                      {
                    *resultAddr = QuadTable;  
                    printTable(SymbolTable);
                }
#line 609 "Parser/grammer.cpp"
    break;

  case 9: // expression1: var_decl
#line 98 "Parser/grammer.y"
                         {}
#line 615 "Parser/grammer.cpp"
    break;

  case 12: // var_decl1: _data_type _identifier
#line 103 "Parser/grammer.y"
                                      {
                    SymbolTable[std::string((yystack_[0].value.attr)->name)] =  new Symbol(std::string((yystack_[0].value.attr)->name),(yystack_[1].value.d_type).datatype,(yystack_[1].value.d_type).dataSize,relAddr);
                    relAddr = relAddr +  (yystack_[1].value.d_type).dataSize ;
                }
#line 624 "Parser/grammer.cpp"
    break;

  case 15: // _data_type: _char
#line 111 "Parser/grammer.y"
                     {
                    (yylhs.value.d_type).datatype = CHAR;
                    (yylhs.value.d_type).dataSize = SIZEOFCHAR;
                }
#line 633 "Parser/grammer.cpp"
    break;

  case 16: // _data_type: _int
#line 115 "Parser/grammer.y"
                    {
                    (yylhs.value.d_type).datatype = INT;
                    (yylhs.value.d_type).dataSize = SIZEOFINT;
                }
#line 642 "Parser/grammer.cpp"
    break;

  case 17: // _data_type: _float
#line 119 "Parser/grammer.y"
                      {
                    (yylhs.value.d_type).datatype = FLOAT;
                    (yylhs.value.d_type).dataSize = SIZEOFFLOAT;
                }
#line 651 "Parser/grammer.cpp"
    break;

  case 18: // assignment: _identifier _assign arithmetic_exp
#line 124 "Parser/grammer.y"
                                                  {
                    if(SymbolTable.find((yystack_[2].value.attr)->name)==SymbolTable.end()) std::cerr<<"Variable not declared !!!\n";
                    else{addCode(QuadTable,labelPending,'=',(yystack_[2].value.attr),(yystack_[0].value.attr),(yystack_[2].value.attr));
                    std::cerr<<(yystack_[2].value.attr)->name<<" "<<(yystack_[2].value.attr)->name<<" = "<<(yystack_[0].value.attr)->name<<'\n';}
                }
#line 661 "Parser/grammer.cpp"
    break;

  case 19: // arithmetic_exp: arithmetic_exp "+" arithmetic_exp
#line 129 "Parser/grammer.y"
                                                     {
                    (yylhs.value.attr)->name= "temp"+std::to_string(temp_var_cnt);  
                    addCode(QuadTable,(yylhs.value.attr)->name,'+',(yystack_[2].value.attr),(yystack_[0].value.attr),(yylhs.value.attr));
                    std::cerr<<(yylhs.value.attr)->name<<" = "<<(yystack_[2].value.attr)->name<<" + "<<(yystack_[0].value.attr)->name<<'\n';
                    temp_var_cnt++;

                    SymbolTable[std::string((yylhs.value.attr)->name)] = new Symbol(std::string((yylhs.value.attr)->name),(yylhs.value.attr)->type,(yylhs.value.attr)->dataSize,relAddr);
                    relAddr = relAddr +  (yylhs.value.attr)->dataSize ;
                }
#line 675 "Parser/grammer.cpp"
    break;

  case 20: // arithmetic_exp: arithmetic_exp "-" arithmetic_exp
#line 138 "Parser/grammer.y"
                                                       {
                }
#line 682 "Parser/grammer.cpp"
    break;

  case 21: // arithmetic_exp: arithmetic_exp _f_slash arithmetic_exp
#line 140 "Parser/grammer.y"
                                                         {
}
#line 689 "Parser/grammer.cpp"
    break;

  case 22: // arithmetic_exp: arithmetic_exp " _f_slash " arithmetic_exp
#line 142 "Parser/grammer.y"
                                                      {
                }
#line 696 "Parser/grammer.cpp"
    break;

  case 23: // arithmetic_exp: "(" arithmetic_exp ")"
#line 144 "Parser/grammer.y"
                                            {
                    (yylhs.value.attr) = (yystack_[1].value.attr);
                }
#line 704 "Parser/grammer.cpp"
    break;

  case 24: // arithmetic_exp: "[" arithmetic_exp "]"
#line 147 "Parser/grammer.y"
                                             {}
#line 710 "Parser/grammer.cpp"
    break;

  case 25: // arithmetic_exp: "}" arithmetic_exp "}"
#line 148 "Parser/grammer.y"
                                             {}
#line 716 "Parser/grammer.cpp"
    break;

  case 26: // arithmetic_exp: _identifier
#line 149 "Parser/grammer.y"
                                        {

                }
#line 724 "Parser/grammer.cpp"
    break;

  case 27: // arithmetic_exp: _int_lit
#line 152 "Parser/grammer.y"
                                       {
                    (yylhs.value.attr) = (yystack_[0].value.attr);
                }
#line 732 "Parser/grammer.cpp"
    break;

  case 28: // arithmetic_exp: _float_lit
#line 155 "Parser/grammer.y"
                                       {
                    (yylhs.value.attr) = (yystack_[0].value.attr);
                }
#line 740 "Parser/grammer.cpp"
    break;


#line 744 "Parser/grammer.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -27;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
       0,    10,    24,   -27,   -27,    -5,     2,   -27,   -27,   -27,
      20,   -27,    28,    25,   -27,    18,    35,    31,    -3,   -27,
      40,   -27,   -27,    48,   -27,    53,    26,   -27,   -27,   -27,
      31,   -27,   -27,   -27,   -27,   -27,    26,    26,    26,    38,
      12,    27,    33,    26,    26,    26,    26,   -27,   -27,   -27,
     -27,   -27,    -6,     8
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     1,     0,    11,    16,    17,    15,
       0,    10,     0,     0,    12,     0,     0,     0,     0,     5,
       0,    13,     9,     0,     8,     0,     0,     3,     4,     6,
      12,    14,     7,    27,    28,    26,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      19,    20,    22,    21
  };

  const signed char
  parser::yypgoto_[] =
  {
     -27,   -27,   -27,   -27,    45,   -27,   -27,    58,   -27,    59,
      43,   -26
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     5,    18,    19,    20,    10,    21,    22,    23,
      24,    39
  };

  const signed char
  parser::yytable_[] =
  {
       7,     8,     9,     1,    16,     7,     8,     9,     6,    17,
      40,    41,    42,    43,    44,    27,     3,    50,    51,    52,
      53,     7,     8,     9,     4,    16,    47,    43,    44,    45,
      17,    43,    44,    45,    13,    46,    33,    34,    35,    36,
      14,    37,    15,    48,    38,    25,    43,    44,    45,    29,
      46,    49,    43,    44,    45,    26,    46,    43,    44,    45,
      30,    46,    32,    28,    11,    12,    31
  };

  const signed char
  parser::yycheck_[] =
  {
       3,     4,     5,     3,     7,     3,     4,     5,    13,    12,
      36,    37,    38,    19,    20,    18,     6,    43,    44,    45,
      46,     3,     4,     5,     0,     7,    14,    19,    20,    21,
      12,    19,    20,    21,    14,    23,    10,    11,    12,    13,
      12,    15,    17,    16,    18,    10,    19,    20,    21,     9,
      23,    18,    19,    20,    21,    24,    23,    19,    20,    21,
      12,    23,     9,    18,     6,     6,    23
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    26,     6,     0,    27,    13,     3,     4,     5,
      31,    32,    34,    14,    12,    17,     7,    12,    28,    29,
      30,    32,    33,    34,    35,    10,    24,    18,    29,     9,
      12,    35,     9,    10,    11,    12,    13,    15,    18,    36,
      36,    36,    36,    19,    20,    21,    23,    14,    16,    18,
      36,    36,    36,    36
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    25,    27,    26,    28,    28,    29,    29,    30,    30,
      31,    31,    32,    33,    33,    34,    34,    34,    35,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     9,     2,     1,     2,     3,     1,     1,
       1,     0,     2,     1,     2,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "_int", "_float",
  "_char", "_main", "_return", "UNKNOWN", "_semi_col", "_int_lit",
  "_float_lit", "_identifier", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"",
  "\"}\"", "\"+\"", "\"-\"", "\" _f_slash \"", "\"=\"", "_f_slash",
  "_assign", "$accept", "root", "$@1", "stms", "stm", "expression1",
  "params", "var_decl1", "var_decl", "_data_type", "assignment",
  "arithmetic_exp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    82,    82,    82,    92,    92,    94,    95,    97,    98,
     100,   101,   103,   108,   109,   111,   115,   119,   124,   129,
     138,   140,   142,   144,   147,   148,   149,   152,   155
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
    };
    // Last valid token kind.
    const int code_max = 279;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1128 "Parser/grammer.cpp"

#line 158 "Parser/grammer.y"


void yy::parser::error(const std::string &msg){
    std::cerr<<msg;
}
