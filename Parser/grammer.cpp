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
#line 27 "Parser/grammer.y"


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

#line 61 "Parser/grammer.cpp"


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
#line 139 "Parser/grammer.cpp"

  /// Build a parser object.
  parser::parser (Quad** resultAddr_yyarg, std::map<std::string,Symbol*>* SymbolTableAddr_yyarg, MyLexer* lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      resultAddr (resultAddr_yyarg),
      SymbolTableAddr (SymbolTableAddr_yyarg),
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
#line 140 "Parser/grammer.y"
                          {
                    createQuadList(&QuadTable);
                    std::cerr<<"\nsize of "<<sizeof(SymbolTable)<<'\n';

                }
#line 602 "Parser/grammer.cpp"
    break;

  case 3: // root: _int _main $@1 "(" params ")" "{" stms "}"
#line 145 "Parser/grammer.y"
                                                      {

                    
                    addCode(QuadTable,"exit",'!',null_attr,null_attr,null_attr);
                    
                    
                    *resultAddr = QuadTable;
                    *SymbolTableAddr = SymbolTable;  
                    printTable(SymbolTable);
                }
#line 617 "Parser/grammer.cpp"
    break;

  case 25: // expression1: var_decl
#line 181 "Parser/grammer.y"
                         {}
#line 623 "Parser/grammer.cpp"
    break;

  case 28: // var_decl1: _data_type _identifier
#line 186 "Parser/grammer.y"
                                      {
                    SymbolTable[std::string((yystack_[0].value.attr)->name)] =  new Symbol(std::string((yystack_[0].value.attr)->name),(yystack_[1].value.d_type).datatype,(yystack_[1].value.d_type).dataSize,relAddr);
                    relAddr = relAddr +  (yystack_[1].value.d_type).dataSize ;
                }
#line 632 "Parser/grammer.cpp"
    break;

  case 31: // _data_type: _char
#line 198 "Parser/grammer.y"
                     {
                    (yylhs.value.d_type).datatype = CHAR;
                    (yylhs.value.d_type).dataSize = SIZEOFCHAR;
                }
#line 641 "Parser/grammer.cpp"
    break;

  case 32: // _data_type: _int
#line 202 "Parser/grammer.y"
                    {
                    (yylhs.value.d_type).datatype = INT;
                    (yylhs.value.d_type).dataSize = SIZEOFINT;
                }
#line 650 "Parser/grammer.cpp"
    break;

  case 33: // _data_type: _float
#line 206 "Parser/grammer.y"
                      {
                    (yylhs.value.d_type).datatype = FLOAT;
                    (yylhs.value.d_type).dataSize = SIZEOFFLOAT;
                }
#line 659 "Parser/grammer.cpp"
    break;

  case 34: // assignment: _identifier _assign arithmetic_exp
#line 211 "Parser/grammer.y"
                                                  {
                    if(SymbolTable.find((yystack_[2].value.attr)->name)==SymbolTable.end()) std::cerr<<"Variable not declared !!!\n";
                    else{addCode(QuadTable,"assign",'=',(yystack_[2].value.attr),(yystack_[0].value.attr),(yystack_[2].value.attr));
                    // std::cerr<<$1->name<<" "<<$1->name<<" = "<<$3->name<<'\n';
                    }
                }
#line 670 "Parser/grammer.cpp"
    break;

  case 35: // arithmetic_exp: arithmetic_exp "+" arithmetic_exp
#line 218 "Parser/grammer.y"
                                                     {
                    // std::cerr<<'\n'<<$$->name<<" = "<<$1->name<<" + "<<$3->name<<'\n';
                    std::string name = "temp"+std::to_string(temp_var_cnt) ;
                    (yylhs.value.attr) = new Attribute((yystack_[2].value.attr)->type,(yystack_[2].value.attr)->subtype,(yystack_[2].value.attr)->dataSize,name);
                    temp_var_cnt++;

                    std::cerr<<(yylhs.value.attr)->name<<" = "<<(yystack_[2].value.attr)->name<<" + "<<(yystack_[0].value.attr)->name<<'\n';
                    addCode(QuadTable,"arithmetic",'+',(yystack_[2].value.attr),(yystack_[0].value.attr),(yylhs.value.attr));

                    SymbolTable[std::string((yylhs.value.attr)->name)] = new Symbol(std::string((yylhs.value.attr)->name),(yylhs.value.attr)->type,(yylhs.value.attr)->dataSize,relAddr);
                    relAddr = relAddr +  (yylhs.value.attr)->dataSize ;
                }
#line 687 "Parser/grammer.cpp"
    break;

  case 36: // arithmetic_exp: arithmetic_exp "-" arithmetic_exp
#line 230 "Parser/grammer.y"
                                                       {
                    std::string name = "temp"+std::to_string(temp_var_cnt) ;
                    (yylhs.value.attr) = new Attribute((yystack_[2].value.attr)->type,(yystack_[2].value.attr)->subtype,(yystack_[2].value.attr)->dataSize,name);
                    temp_var_cnt++;

                    std::cerr<<(yylhs.value.attr)->name<<" = "<<(yystack_[2].value.attr)->name<<" - "<<(yystack_[0].value.attr)->name<<'\n';
                    addCode(QuadTable,"arithmetic",'-',(yystack_[2].value.attr),(yystack_[0].value.attr),(yylhs.value.attr));

                    SymbolTable[std::string((yylhs.value.attr)->name)] = new Symbol(std::string((yylhs.value.attr)->name),(yylhs.value.attr)->type,(yylhs.value.attr)->dataSize,relAddr);
                    relAddr = relAddr +  (yylhs.value.attr)->dataSize ;
                }
#line 703 "Parser/grammer.cpp"
    break;

  case 37: // arithmetic_exp: arithmetic_exp _f_slash arithmetic_exp
#line 241 "Parser/grammer.y"
                                                         {
                
                    std::string name = "temp"+std::to_string(temp_var_cnt) ;
                    (yylhs.value.attr) = new Attribute((yystack_[2].value.attr)->type,(yystack_[2].value.attr)->subtype,(yystack_[2].value.attr)->dataSize,name);
                    temp_var_cnt++;

                    std::cerr<<(yylhs.value.attr)->name<<" = "<<(yystack_[2].value.attr)->name<<" / "<<(yystack_[0].value.attr)->name<<'\n';
                    addCode(QuadTable,"arithmetic",'/',(yystack_[2].value.attr),(yystack_[0].value.attr),(yylhs.value.attr));

                    SymbolTable[std::string((yylhs.value.attr)->name)] = new Symbol(std::string((yylhs.value.attr)->name),(yylhs.value.attr)->type,(yylhs.value.attr)->dataSize,relAddr);
                    relAddr = relAddr +  (yylhs.value.attr)->dataSize ;
                }
#line 720 "Parser/grammer.cpp"
    break;

  case 38: // arithmetic_exp: arithmetic_exp " _f_slash " arithmetic_exp
#line 253 "Parser/grammer.y"
                                                      {
                    std::string name = "temp"+std::to_string(temp_var_cnt) ;
                    (yylhs.value.attr) = new Attribute((yystack_[2].value.attr)->type,(yystack_[2].value.attr)->subtype,(yystack_[2].value.attr)->dataSize,name);
                    temp_var_cnt++;

                    std::cerr<<(yylhs.value.attr)->name<<" = "<<(yystack_[2].value.attr)->name<<" * "<<(yystack_[0].value.attr)->name<<'\n';
                    addCode(QuadTable,"arithmetic",'*',(yystack_[2].value.attr),(yystack_[0].value.attr),(yylhs.value.attr));

                    SymbolTable[std::string((yylhs.value.attr)->name)] = new Symbol(std::string((yylhs.value.attr)->name),(yylhs.value.attr)->type,(yylhs.value.attr)->dataSize,relAddr);
                    relAddr = relAddr +  (yylhs.value.attr)->dataSize ;
                }
#line 736 "Parser/grammer.cpp"
    break;

  case 39: // arithmetic_exp: "(" arithmetic_exp ")"
#line 264 "Parser/grammer.y"
                                            {
                    (yylhs.value.attr) = (yystack_[1].value.attr);
                }
#line 744 "Parser/grammer.cpp"
    break;

  case 40: // arithmetic_exp: _identifier
#line 268 "Parser/grammer.y"
                                        {

                }
#line 752 "Parser/grammer.cpp"
    break;

  case 41: // arithmetic_exp: _int_lit
#line 271 "Parser/grammer.y"
                                       {
                    (yylhs.value.attr) = (yystack_[0].value.attr);
                }
#line 760 "Parser/grammer.cpp"
    break;

  case 42: // arithmetic_exp: _float_lit
#line 274 "Parser/grammer.y"
                                       {
                    (yylhs.value.attr) = (yystack_[0].value.attr);
                }
#line 768 "Parser/grammer.cpp"
    break;


#line 772 "Parser/grammer.cpp"

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









  const signed char parser::yypact_ninf_ = -45;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
     -41,   -40,    34,   -45,   -45,     7,     6,   -45,   -45,   -45,
      33,   -45,   -16,    36,   -45,    69,    41,    52,    55,    58,
      69,    25,    42,    -9,    56,    49,   -45,    47,   -45,   -45,
      18,   -45,    15,    15,    15,    15,    39,   -45,   -45,    59,
      62,    68,   -45,     9,   -45,   -45,   -45,    62,   -45,    81,
      93,    71,    95,    97,   -45,     9,   -45,     9,   -45,   -45,
     -45,    10,    69,    94,    15,    69,    15,    10,    -2,     9,
       9,     9,     9,    83,    -7,    76,   -45,   101,   -45,   -45,
     -45,    30,    13,    69,    15,    87,    -4,    15,    91,   -45,
      92,    69,   -45,    15,    96,   115,   -45,    69,   -45,    99,
      69,    69,   -45,    69,   -45,   -45,   -45
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     1,     0,    27,    32,    33,    31,
       0,    26,     0,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     5,     0,    29,    25,
       0,    24,     0,     0,    23,     0,     0,    14,    15,     0,
       0,     0,    22,     0,     3,     4,     6,    28,    30,     0,
       0,     0,     0,     0,     7,     0,    16,     0,    41,    42,
      40,    34,     0,     0,    23,     0,     0,    34,     0,     0,
       0,     0,     0,     8,     0,     0,    12,     0,    39,    35,
      36,    38,    37,     0,     0,     0,     0,    23,     0,     9,
       0,     0,    10,     0,     0,     0,    13,     0,    21,     0,
       0,     0,    20,     0,    19,    11,    18
  };

  const signed char
  parser::yypgoto_[] =
  {
     -45,   -45,   -45,   -45,   -20,   -45,   -33,   -17,   -45,   116,
     -45,   117,    98,   -44
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     5,    25,    26,    86,    41,    27,    10,    28,
      29,    30,    31,    61
  };

  const signed char
  parser::yytable_[] =
  {
      36,    51,    78,     1,    92,    45,    42,    69,    70,    71,
       6,    67,    57,    68,     3,    49,    50,    42,    52,    69,
      70,    71,    69,    70,    71,    79,    80,    81,    82,    84,
      85,    75,    93,    94,     4,     7,     8,    13,     9,    69,
      70,    14,    73,    15,    32,    76,    39,    42,    40,    77,
       7,     8,    37,     9,    95,    33,    72,    44,    34,     7,
       8,    35,     9,    89,    58,    59,    60,    90,    72,    38,
      42,    98,    40,    43,    46,    47,    99,   102,    53,    55,
     104,   105,    16,   106,    17,    62,    54,    18,    19,    20,
      21,    22,    23,     7,     8,    56,     9,    63,    64,    65,
      66,    74,    16,    87,    17,    88,    24,    18,    19,    20,
      21,    22,    23,     7,     8,    91,     9,    83,    96,   101,
      97,     0,    11,    12,   100,     0,    24,   103,    48
  };

  const signed char
  parser::yycheck_[] =
  {
      20,    34,     4,    44,     8,    25,    23,     9,    10,    11,
       3,    55,     3,    57,    54,    32,    33,    34,    35,     9,
      10,    11,     9,    10,    11,    69,    70,    71,    72,    36,
      37,    64,    36,    37,     0,    44,    45,     4,    47,     9,
      10,    57,    62,     7,     3,    65,    55,    64,    57,    66,
      44,    45,    27,    47,    87,     3,    58,     8,     3,    44,
      45,     3,    47,    83,    55,    56,    57,    84,    58,    27,
      87,    91,    57,    17,    27,    57,    93,    97,    39,    17,
     100,   101,    33,   103,    35,     4,    27,    38,    39,    40,
      41,    42,    43,    44,    45,    27,    47,     4,    27,     4,
       3,     7,    33,    27,    35,     4,    57,    38,    39,    40,
      41,    42,    43,    44,    45,    28,    47,    34,    27,     4,
      28,    -1,     6,     6,    28,    -1,    57,    28,    30
  };

  const signed char
  parser::yystos_[] =
  {
       0,    44,    60,    54,     0,    61,     3,    44,    45,    47,
      67,    68,    70,     4,    57,     7,    33,    35,    38,    39,
      40,    41,    42,    43,    57,    62,    63,    66,    68,    69,
      70,    71,     3,     3,     3,     3,    63,    27,    27,    55,
      57,    65,    66,    17,     8,    63,    27,    57,    71,    66,
      66,    65,    66,    39,    27,    17,    27,     3,    55,    56,
      57,    72,     4,     4,    27,     4,     3,    72,    72,     9,
      10,    11,    58,    63,     7,    65,    63,    66,     4,    72,
      72,    72,    72,    34,    36,    37,    64,    27,     4,    63,
      66,    28,     8,    36,    37,    65,    27,    28,    63,    66,
      28,     4,    63,    28,    63,    63,    63
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    59,    61,    60,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    70,    71,    72,    72,    72,    72,    72,
      72,    72,    72
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     9,     2,     1,     2,     3,     5,     7,
       7,     9,     5,     7,     2,     2,     3,     4,     5,     4,
       4,     3,     1,     0,     1,     1,     1,     0,     2,     1,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"+\"", "\"-\"", "\" _f_slash \"",
  "\"=\"", "_and", "_or", "_xor", "_modulus", "_assign", "_equals", "_not",
  "_not_equals", "_less_than", "_greater_than", "_less_equal",
  "_greater_equal", "_increment", "_decrement", "_semi_col", "_col",
  "_plus_equals", "_minus_equals", "_divide_equals", "_multiply_equals",
  "_if", "_else", "_switch", "_case", "_default", "_for", "_while", "_do",
  "_break", "_continue", "_return", "_int", "_float", "_double", "_char",
  "_bool", "_void", "_long", "_short", "_unsigned", "_signed", "_main",
  "_int_lit", "_float_lit", "_identifier", "_f_slash", "$accept", "root",
  "$@1", "stms", "stm", "switch_cases", "opt_expr", "expression1",
  "params", "var_decl1", "var_decl", "_data_type", "assignment",
  "arithmetic_exp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   140,   140,   140,   156,   156,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   172,   173,
     174,   175,   177,   177,   180,   181,   183,   184,   186,   195,
     196,   198,   202,   206,   211,   218,   230,   241,   253,   264,
     268,   271,   274
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
    };
    // Last valid token kind.
    const int code_max = 313;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1199 "Parser/grammer.cpp"

#line 277 "Parser/grammer.y"


void yy::parser::error(const std::string &msg){
    std::cerr<<msg;
}

