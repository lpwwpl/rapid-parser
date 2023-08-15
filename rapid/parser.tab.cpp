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


// Take the name prefix into account.
#define yylex   D_yylex



#include "parser.tab.hpp"


// Unqualified %code blocks.
#line 90 "parser.y"

    #include "translator.hpp"
    #include "ast.h"
    #include <stack>
    
    static int yylex(Language::Parser::semantic_type *yylval, Language::location* loc,Language::Lexer  &lexer);

    extern std::string cur_yytext;
    extern std::stack<std::string> fileNames;
    extern Language::location loc;//ÉùÃ÷Î»ÖÃÊµÀý
    # define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin.line   = YYRHSLOC (Rhs, 1).begin.line;        \
          (Current).begin.column = YYRHSLOC (Rhs, 1).begin.column;      \
          (Current).end.line    = YYRHSLOC (Rhs, N).end.line;         \
          (Current).end.column  = YYRHSLOC (Rhs, N).end.column;       \
          (Current).end.filename = &(fileNames.top());            \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin.line   = (Current).end.line   =              \
            YYRHSLOC (Rhs, 0).end.line;                                \
          (Current).begin.column = (Current).end.column =              \
            YYRHSLOC (Rhs, 0).end.column;                              \
          (Current).end.filename = &(fileNames.top());            \
        }                                                               \
    while (0)


#line 80 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"


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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if D_YYDEBUG

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

#else // !D_YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !D_YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 15 "parser.y"
namespace Language {
#line 173 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"

  /// Build a parser object.
  Parser::Parser (Lexer  &lexer_yyarg)
#if D_YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}


  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if D_YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if D_YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // D_YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, lexer));
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

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: module_list
#line 204 "parser.y"
                {}
#line 646 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 3: // module_list: module
#line 208 "parser.y"
                {(yylhs.value.moduleListNode) = new ListNode<ModuleNode>((yystack_[0].value.moduleNode));}
#line 652 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 4: // module_list: module_list module
#line 209 "parser.y"
                         {(yystack_[1].value.moduleListNode)->push_back((yystack_[0].value.moduleNode));}
#line 658 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 5: // module: MODULE Identifier declaration_list ENDMODULE
#line 213 "parser.y"
                                                     {(yylhs.value.moduleNode) = new ModuleNode((yystack_[2].value.sval),(yystack_[1].value.listNode));}
#line 664 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 6: // declaration_list: declaration
#line 218 "parser.y"
                 {(yylhs.value.listNode) = new DeclareListNode((yystack_[0].value.pNode));}
#line 670 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 7: // declaration_list: declaration_list declaration
#line 219 "parser.y"
                                     {(yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));}
#line 676 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 8: // declaration: variable_declaration
#line 223 "parser.y"
                           {(yylhs.value.pNode)=(yystack_[0].value.variableNode);}
#line 682 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 9: // declaration: function_declaration
#line 224 "parser.y"
                               {(yylhs.value.pNode)=(yystack_[0].value.functionNode);}
#line 688 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 10: // declaration: var_assignment
#line 225 "parser.y"
                    {(yylhs.value.pNode)=(yystack_[0].value.pNode);}
#line 694 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 11: // declaration: Record_declare
#line 226 "parser.y"
                     {(yylhs.value.pNode)=(yystack_[0].value.pNode);}
#line 700 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 12: // Type: NUM
#line 229 "parser.y"
            { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("NUM")); (yylhs.value.pNode) = id;}
#line 706 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 13: // Type: BOOL
#line 230 "parser.y"
                { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("BOOL")); (yylhs.value.pNode) = id;}
#line 712 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 14: // Type: STRING
#line 231 "parser.y"
                  { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("STRING")); (yylhs.value.pNode) = id;}
#line 718 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 15: // Type: ROBTARGET
#line 232 "parser.y"
                     { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("ROBTARGET")); (yylhs.value.pNode) = id;}
#line 724 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 16: // Type: JOINTTARGET
#line 233 "parser.y"
                        {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("JOINTTARGET")); (yylhs.value.pNode) = id;}
#line 730 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 17: // Type: WOBJDATA
#line 234 "parser.y"
               {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("WOBJDATA")); (yylhs.value.pNode) = id;}
#line 736 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 18: // Type: ZONEDATA
#line 235 "parser.y"
               {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("ZONEDATA")); (yylhs.value.pNode) = id;}
#line 742 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 19: // Type: SPEEDDATA
#line 236 "parser.y"
                { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("SPEEDDATA")); (yylhs.value.pNode) = id;}
#line 748 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 20: // Type: TOOLDATA
#line 237 "parser.y"
               {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("TOOLDATA")); (yylhs.value.pNode) = id;}
#line 754 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 21: // Type: SEAMDATA
#line 238 "parser.y"
               {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("SEAMDATA")); (yylhs.value.pNode) = id;}
#line 760 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 22: // Type: WELDDATA
#line 239 "parser.y"
               {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("WELDDATA")); (yylhs.value.pNode) = id;}
#line 766 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 23: // Type: Identifier
#line 240 "parser.y"
                 {(yylhs.value.pNode) = new StringLiteralNode((yystack_[0].value.sval)); /*$$ = $1;*/ }
#line 772 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 24: // Record_declare: RECORD Identifier struct_members ENDRECORD
#line 244 "parser.y"
                                               { (yylhs.value.pNode) = new StructDescNode((yystack_[2].value.sval), (yystack_[1].value.listNode)); }
#line 778 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 25: // struct_members: var_decl
#line 248 "parser.y"
              { (yylhs.value.listNode) = new  ListNode<ASTNode>(); (yylhs.value.listNode)->push_back((yystack_[0].value.pNode)); }
#line 784 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 26: // struct_members: struct_members var_decl
#line 249 "parser.y"
                              { (yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode)); }
#line 790 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 27: // var_decl: Type Identifier SEMICOLON
#line 252 "parser.y"
                              {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval)); (yylhs.value.pNode) = new VariableDeclareNode((yystack_[2].value.pNode),id); }
#line 796 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 28: // scope_pers: PERS
#line 256 "parser.y"
       { (yylhs.value.ival) =  PERS;}
#line 802 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 29: // scope1: TASK PERS
#line 260 "parser.y"
              { (yylhs.value.ival) =  TASK_PERS;}
#line 808 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 30: // scope1: CONST_L
#line 262 "parser.y"
            { (yylhs.value.ival) = eCONST;}
#line 814 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 31: // scope2: VAR
#line 266 "parser.y"
        { (yylhs.value.ival) =  VAR;}
#line 820 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 32: // function_declaration: PROC Identifier LC parameter_declaration_list RC function_body ENDPROC
#line 274 "parser.y"
                                                                           {(yylhs.value.functionNode) = new FunctionNode(nullptr, (yystack_[5].value.sval), (yystack_[3].value.parameterListNode), (yystack_[1].value.statementListNode)); }
#line 826 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 33: // function_declaration: FUNC Type Identifier LC parameter_declaration_list RC function_body ENDFUNC
#line 275 "parser.y"
                                                                                 {(yylhs.value.functionNode) = new FunctionNode((yystack_[6].value.pNode), (yystack_[5].value.sval), (yystack_[3].value.parameterListNode), (yystack_[1].value.statementListNode)); }
#line 832 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 34: // parameter_declaration_list: parameter_declaration
#line 279 "parser.y"
                          { (yylhs.value.parameterListNode) = new ListNode<ParameterNode>((yystack_[0].value.parameterNode)); }
#line 838 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 35: // parameter_declaration_list: parameter_declaration_list COMMA parameter_declaration
#line 280 "parser.y"
                                                             {(yystack_[2].value.parameterListNode)->push_back((yystack_[0].value.parameterNode));}
#line 844 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 36: // parameter_declaration_list: %empty
#line 281 "parser.y"
      {(yylhs.value.parameterListNode) = new ListNode<ParameterNode>();}
#line 850 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 37: // parameter_declaration: Type Identifier
#line 285 "parser.y"
                    {(yylhs.value.parameterNode) = new ParameterNode((yystack_[1].value.pNode),(yystack_[0].value.sval));}
#line 856 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 38: // parameter_declaration: INOUT Type Identifier
#line 287 "parser.y"
    {
        StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("INOUT"));
        (yylhs.value.parameterNode) = new ParameterNode(id,(yystack_[1].value.pNode),(yystack_[0].value.sval));
    }
#line 865 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 39: // func_call_parameter_list: expression
#line 295 "parser.y"
    {
        (yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.pNode)); 
    }
#line 873 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 40: // func_call_parameter_list: func_call_parameter_list COMMA expression
#line 299 "parser.y"
        {
        (yystack_[2].value.listNode)->push_back((yystack_[0].value.pNode));   
	}
#line 881 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 41: // function_body: %empty
#line 313 "parser.y"
  {(yylhs.value.statementListNode)=NULL;}
#line 887 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 42: // function_body: statement_list
#line 314 "parser.y"
                     {(yylhs.value.statementListNode) = (yystack_[0].value.statementListNode);}
#line 893 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 43: // statement_list: statement
#line 318 "parser.y"
              {(yylhs.value.statementListNode) = new StatementListNode((yystack_[0].value.pNode));}
#line 899 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 44: // statement_list: statement_list statement
#line 319 "parser.y"
                               {(yystack_[1].value.statementListNode)->push_back((yystack_[0].value.pNode));}
#line 905 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 45: // function_call: Identifier SEMICOLON
#line 324 "parser.y"
                           { (yylhs.value.pNode) = new FunctionCallNode((yystack_[1].value.sval), new ListNode<ASTNode>());}
#line 911 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 46: // function_call: Identifier func_call_parameter_list SEMICOLON
#line 325 "parser.y"
                                                     { (yylhs.value.pNode) = new FunctionCallNode((yystack_[2].value.sval), (yystack_[1].value.listNode));}
#line 917 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 47: // inst_modifer: CONC
#line 329 "parser.y"
           { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("Conc")); (yylhs.value.pNode) = id;}
#line 923 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 48: // inst_modifer: TOOL_P
#line 330 "parser.y"
             { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("Tool")); (yylhs.value.pNode) = id;}
#line 929 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 49: // inst_modifer: PLEN
#line 331 "parser.y"
           { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("PLength")); (yylhs.value.pNode) = id;}
#line 935 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 50: // inst_modifer: MAXTIME
#line 332 "parser.y"
              { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("MaxTime")); (yylhs.value.pNode) = id;}
#line 941 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 51: // inst_modifer: TIMEFLAG
#line 333 "parser.y"
               { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("TimeFlag")); (yylhs.value.pNode) = id;}
#line 947 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 52: // inst_modifer: WOBJ_P
#line 334 "parser.y"
              { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("WObj")); (yylhs.value.pNode) = id;}
#line 953 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 53: // inst_modifer: SEAM_NAME
#line 335 "parser.y"
                { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("SeamName")); (yylhs.value.pNode) = id;}
#line 959 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 54: // inst_modifer: ZONE_P
#line 336 "parser.y"
             { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("Z")); (yylhs.value.pNode) = id;}
#line 965 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 55: // inst_modifer: INPOS
#line 337 "parser.y"
            { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("InPos")); (yylhs.value.pNode) = id;}
#line 971 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 56: // inst_modifer: VEL_P
#line 338 "parser.y"
            { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("V")); (yylhs.value.pNode) = id;}
#line 977 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 57: // inst_modifer: TCP_P
#line 339 "parser.y"
            { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("T")); (yylhs.value.pNode) = id;}
#line 983 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 58: // inst_modifer: NOEOFFS
#line 340 "parser.y"
              { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("NoEOffs")); (yylhs.value.pNode) = id;}
#line 989 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 59: // inst_modifer: ID_P
#line 341 "parser.y"
           { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("ID")); (yylhs.value.pNode) = id;}
#line 995 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 60: // statement: variable_for_body
#line 345 "parser.y"
                      {(yylhs.value.pNode) = (yystack_[0].value.variableNode);}
#line 1001 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 61: // statement: assignment
#line 346 "parser.y"
                  {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1007 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 62: // statement: if
#line 347 "parser.y"
         { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1013 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 63: // statement: while_loop
#line 348 "parser.y"
                 { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1019 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 64: // statement: for
#line 349 "parser.y"
          { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1025 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 65: // statement: return
#line 350 "parser.y"
              { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1031 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 66: // statement: function_call
#line 351 "parser.y"
                    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1037 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 67: // statement: MOVEJ func_call_parameter_list SEMICOLON
#line 352 "parser.y"
                                               {(yylhs.value.pNode) = new MoveJNode((yystack_[1].value.listNode));}
#line 1043 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 68: // statement: ACTUNIT func_call_parameter_list SEMICOLON
#line 353 "parser.y"
                                                {(yylhs.value.pNode) = new ActUnitNode((yystack_[1].value.listNode));}
#line 1049 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 69: // statement: ARCLSTART func_call_parameter_list SEMICOLON
#line 354 "parser.y"
                                                  {(yylhs.value.pNode) = new ArcLStartNode((yystack_[1].value.listNode));}
#line 1055 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 70: // statement: ARCL func_call_parameter_list SEMICOLON
#line 355 "parser.y"
                                             {(yylhs.value.pNode) = new ArcLNode((yystack_[1].value.listNode));}
#line 1061 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 71: // statement: ARCC func_call_parameter_list SEMICOLON
#line 356 "parser.y"
                                             {(yylhs.value.pNode) = new ArccNode((yystack_[1].value.listNode));}
#line 1067 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 72: // statement: ARCEND func_call_parameter_list SEMICOLON
#line 357 "parser.y"
                                               {(yylhs.value.pNode) = new ArcEndNode((yystack_[1].value.listNode));}
#line 1073 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 73: // statement: MOVEL func_call_parameter_list SEMICOLON
#line 358 "parser.y"
                                              { (yylhs.value.pNode) = new MoveLNode((yystack_[1].value.listNode));}
#line 1079 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 74: // statement: MOVEABSJ func_call_parameter_list SEMICOLON
#line 359 "parser.y"
                                                 {(yylhs.value.pNode) = new MoveABSJNode((yystack_[1].value.listNode));}
#line 1085 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 75: // statement: DEACTUNIT func_call_parameter_list SEMICOLON
#line 360 "parser.y"
                                                  { (yylhs.value.pNode) = new DeActUnitNode((yystack_[1].value.listNode));}
#line 1091 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 76: // statement: TPWRITE expression SEMICOLON
#line 361 "parser.y"
                                  {(yylhs.value.pNode) = new TpWriteNode((yystack_[1].value.pNode));}
#line 1097 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 77: // statement: ACCSET expression COMMA expression SEMICOLON
#line 362 "parser.y"
                                                   {(yylhs.value.pNode) = new AccSetNode((yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1103 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 78: // statement: VELSET expression COMMA expression SEMICOLON
#line 363 "parser.y"
                                                  {(yylhs.value.pNode) = new VelSetNode((yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1109 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 79: // statement: WAITTIME func_call_parameter_list SEMICOLON
#line 364 "parser.y"
                                                  {(yylhs.value.pNode) = new WaitTimeNode((yystack_[1].value.listNode));}
#line 1115 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 80: // statement: SETDO Identifier COMMA expression SEMICOLON
#line 365 "parser.y"
                                                   {IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new SetDoNode(id,(yystack_[1].value.pNode));}
#line 1121 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 81: // statement: SET Identifier SEMICOLON
#line 366 "parser.y"
                               {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval));(yylhs.value.pNode) = new SetNode(id);}
#line 1127 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 82: // statement: RESET Identifier SEMICOLON
#line 367 "parser.y"
                                 {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval));(yylhs.value.pNode) = new ReSetNode(id);}
#line 1133 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 83: // statement: WAITDI Identifier COMMA expression SEMICOLON
#line 368 "parser.y"
                                                   {(yylhs.value.pNode) = new WaitDiNode((yystack_[3].value.sval),(yystack_[1].value.pNode));}
#line 1139 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 84: // statement: WAITUNTIL expression SEMICOLON
#line 369 "parser.y"
                                     {(yylhs.value.pNode) = new WaitUntilNode((yystack_[1].value.pNode));}
#line 1145 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 85: // statement: PULSEDO func_call_parameter_list SEMICOLON
#line 370 "parser.y"
                                                 {  (yylhs.value.pNode) = new PulseDONode((yystack_[1].value.listNode));}
#line 1151 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 86: // statement: switch
#line 371 "parser.y"
             {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1157 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 87: // return: RETURN SEMICOLON
#line 375 "parser.y"
                 {(yylhs.value.pNode) = new ReturnNode(NULL); }
#line 1163 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 88: // return: RETURN expression SEMICOLON
#line 376 "parser.y"
                                {(yylhs.value.pNode) = new ReturnNode((yystack_[1].value.pNode)); }
#line 1169 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 89: // while_loop: WHILE expression DO function_body ENDWHILE
#line 380 "parser.y"
                                                            { (yylhs.value.pNode) = new WhileNode((yystack_[3].value.pNode), (yystack_[1].value.statementListNode)); }
#line 1175 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 90: // switch: TEST expression switch_case_list ENDTEST
#line 385 "parser.y"
    {
        (yylhs.value.pNode) = new SWitchNode((yystack_[2].value.pNode),(yystack_[1].value.listNode),NULL);
    }
#line 1183 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 91: // switch_case_list: switch_case_define
#line 393 "parser.y"
        {
        (yylhs.value.listNode) = new SWitchCaseListNode((yystack_[0].value.pNode));
	}
#line 1191 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 92: // switch_case_list: switch_case_list switch_case_define
#line 398 "parser.y"
        {
        (yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));   
	}
#line 1199 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 93: // switch_case_define: CASE expression COLON function_body
#line 405 "parser.y"
        {
        (yylhs.value.pNode) = new CaseNode((yystack_[2].value.pNode),(yystack_[0].value.statementListNode)); //$$->dimListType->push_back($1);
	}
#line 1207 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 94: // for: FOR Identifier FROM expression TO expression STEP expression DO function_body ENDFOR
#line 411 "parser.y"
                                                                                         {  IdentifierNode* id = new IdentifierNode((yystack_[9].value.sval));(yylhs.value.pNode) = new ForNode(id,(yystack_[7].value.pNode),(yystack_[5].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.statementListNode));}
#line 1213 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 95: // if: IF expression THEN function_body ENDIF
#line 415 "parser.y"
                                             { (yylhs.value.pNode) = new IfNode((yystack_[3].value.pNode), (yystack_[1].value.statementListNode)); }
#line 1219 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 96: // if: IF expression statement
#line 416 "parser.y"
                               { (yylhs.value.pNode) = new IfNode((yystack_[1].value.pNode), (yystack_[0].value.pNode)); }
#line 1225 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 97: // if: IF expression THEN function_body elseif_statment_list ENDIF
#line 417 "parser.y"
                                                                  { (yylhs.value.pNode) = new IfNode((yystack_[4].value.pNode), (yystack_[2].value.statementListNode), (yystack_[1].value.elseifListNode)); }
#line 1231 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 98: // elseif_statment_list: elseif_statment
#line 421 "parser.y"
                     {(yylhs.value.elseifListNode) = new ListNode<ElseIfNode>((yystack_[0].value.elseif_stmNode));}
#line 1237 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 99: // elseif_statment_list: elseif_statment_list elseif_statment
#line 422 "parser.y"
                                           {(yystack_[1].value.elseifListNode)->push_back((yystack_[0].value.elseif_stmNode));}
#line 1243 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 100: // elseif_statment: ELSE function_body
#line 426 "parser.y"
                        { (yylhs.value.elseif_stmNode) = new ElseIfNode((yystack_[0].value.statementListNode)); }
#line 1249 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 101: // elseif_statment: ELSEIF expression THEN function_body
#line 427 "parser.y"
                                           { (yylhs.value.elseif_stmNode) = new ElseIfNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 1255 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 102: // variable_declaration: scope1 Type var_expression SEMICOLON
#line 432 "parser.y"
                                          { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.pNode),(yystack_[1].value.pNode));}
#line 1261 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 103: // variable_declaration: scope_pers Type var_expression SEMICOLON
#line 433 "parser.y"
                                               { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.pNode),(yystack_[1].value.pNode));}
#line 1267 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 104: // variable_declaration: scope2 Type var_expression SEMICOLON
#line 434 "parser.y"
                                           { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.pNode),(yystack_[1].value.pNode));}
#line 1273 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 105: // variable_for_body: scope2 Type var_expression SEMICOLON
#line 438 "parser.y"
                                         { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.pNode),(yystack_[1].value.pNode));}
#line 1279 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 106: // variable_for_body: scope2 Type Identifier ASS expression SEMICOLON
#line 439 "parser.y"
                                                      { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.variableNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),id,(yystack_[1].value.pNode));}
#line 1285 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 107: // variable_for_body: scope2 Type array_index ASS expression SEMICOLON
#line 440 "parser.y"
                                                         { (yylhs.value.variableNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1291 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 108: // variable_for_body: scope2 Type struct_index ASS expression SEMICOLON
#line 441 "parser.y"
                                                        { (yylhs.value.variableNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1297 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 109: // var_expression: Identifier
#line 445 "parser.y"
               { (yylhs.value.pNode) = new IdentifierNode((yystack_[0].value.sval)); }
#line 1303 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 110: // var_expression: array_index
#line 446 "parser.y"
                  { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1309 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 111: // var_expression: struct_index
#line 447 "parser.y"
                   {(yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1315 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 112: // var_assignment: scope1 Type Identifier ASS expression SEMICOLON
#line 453 "parser.y"
                                                    { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),id,(yystack_[1].value.pNode));}
#line 1321 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 113: // var_assignment: scope2 Type Identifier ASS expression SEMICOLON
#line 454 "parser.y"
                                                      { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),id,(yystack_[1].value.pNode));}
#line 1327 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 114: // var_assignment: scope_pers Type Identifier ASS expression SEMICOLON
#line 455 "parser.y"
                                                          { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),id,(yystack_[1].value.pNode));}
#line 1333 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 115: // var_assignment: scope1 Type array_index ASS expression SEMICOLON
#line 456 "parser.y"
                                                         { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1339 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 116: // var_assignment: scope2 Type array_index ASS expression SEMICOLON
#line 457 "parser.y"
                                                         { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1345 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 117: // var_assignment: scope_pers Type array_index ASS expression SEMICOLON
#line 458 "parser.y"
                                                             { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1351 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 118: // var_assignment: scope1 Type struct_index ASS expression SEMICOLON
#line 459 "parser.y"
                                                        { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1357 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 119: // var_assignment: scope2 Type struct_index ASS expression SEMICOLON
#line 460 "parser.y"
                                                        { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1363 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 120: // var_assignment: scope_pers Type struct_index ASS expression SEMICOLON
#line 461 "parser.y"
                                                            { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1369 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 121: // assignment: var_expression ASS expression
#line 468 "parser.y"
    { 
        (yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.pNode), (yystack_[0].value.pNode));
    }
#line 1377 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 122: // assignment: var_expression ASS expression SEMICOLON
#line 473 "parser.y"
    {
        (yylhs.value.pNode) = new AssignmentNode((yystack_[3].value.pNode), (yystack_[1].value.pNode));
    }
#line 1385 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 123: // dim_num_stm: expression
#line 480 "parser.y"
    {
        (yylhs.value.dim_num_stmNode) = new DimNumsNode((yystack_[0].value.pNode)); 
    }
#line 1393 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 124: // dim_num_stm: dim_num_stm COMMA expression
#line 484 "parser.y"
        {
       (yystack_[2].value.dim_num_stmNode)->push_back((yystack_[0].value.pNode));   
	}
#line 1401 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 125: // struct_index: var_expression DOT Identifier
#line 490 "parser.y"
                                   { IdentifierNode* id = new IdentifierNode((yystack_[0].value.sval));(yylhs.value.pNode) = new StructIndexNode((yystack_[2].value.pNode),id); }
#line 1407 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 126: // array_index: Identifier LBRACE expression RBRACE
#line 494 "parser.y"
                                     {IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new ArrayIndexNode(id, (yystack_[1].value.pNode));}
#line 1413 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 127: // offs_expr: OFFS LC func_call_parameter_list RC
#line 498 "parser.y"
                                     {(yylhs.value.pNode) = new OffsNode((yystack_[1].value.listNode));}
#line 1419 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 128: // reltool_expr: RELTOOl LC func_call_parameter_list RC
#line 502 "parser.y"
                                        {(yylhs.value.pNode) = new RelToolNode((yystack_[1].value.listNode));}
#line 1425 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 129: // op_expr: expression ADD expression
#line 506 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::ADD, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1431 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 130: // op_expr: expression SUB expression
#line 507 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::SUB, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1437 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 131: // op_expr: SUB expression
#line 508 "parser.y"
                               { (yylhs.value.pNode) = new OperatorNode(token::UMINUS, (yystack_[0].value.pNode)); }
#line 1443 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 132: // op_expr: expression MUL expression
#line 509 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::MUL, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1449 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 133: // op_expr: expression LT expression
#line 510 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::LT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1455 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 134: // op_expr: expression GT expression
#line 511 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::GT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1461 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 135: // op_expr: expression GE expression
#line 512 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::GE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1467 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 136: // op_expr: expression LE expression
#line 513 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::LE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1473 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 137: // op_expr: expression NE expression
#line 514 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::NE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1479 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 138: // op_expr: expression EQ expression
#line 515 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::EQ, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1485 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 139: // op_expr: expression AND expression
#line 516 "parser.y"
                             {(yylhs.value.pNode) = new OperatorNode(token::AND, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1491 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 140: // op_expr: expression OR expression
#line 517 "parser.y"
                            {(yylhs.value.pNode) = new OperatorNode(token::OR, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1497 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 141: // op_expr: expression MOD expression
#line 518 "parser.y"
                             {(yylhs.value.pNode) = new OperatorNode(token::MOD, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1503 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 142: // op_expr: expression ASS expression
#line 519 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::ASS, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1509 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 143: // op_expr: NOT expression
#line 521 "parser.y"
                              {(yylhs.value.pNode) = new OperatorNode(token::NOT, (yystack_[0].value.pNode));}
#line 1515 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 144: // op_expr: LC expression RC
#line 522 "parser.y"
                    {(yylhs.value.pNode) = (yylhs.value.pNode) = new OperatorNode(token::LC, (yystack_[1].value.pNode));}
#line 1521 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 145: // inst_expr: inst_modifer
#line 535 "parser.y"
               {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1527 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 146: // inst_expr: var_expression inst_modifer
#line 536 "parser.y"
                               { (yylhs.value.pNode) = new ModifierNode((yystack_[1].value.pNode),(yystack_[0].value.pNode));}
#line 1533 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 147: // expression: String
#line 542 "parser.y"
        { (yylhs.value.pNode) = new StringLiteralNode(true,(yystack_[0].value.sval));}
#line 1539 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 148: // expression: FNULL
#line 543 "parser.y"
         { (yylhs.value.pNode) = new NullNode();}
#line 1545 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 149: // expression: Number
#line 544 "parser.y"
          {(yylhs.value.pNode) = new NumberLiteralNode((yystack_[0].value.dval)); }
#line 1551 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 150: // expression: LNumber
#line 545 "parser.y"
           {(yylhs.value.pNode) = new NumberLiteralNode((yystack_[0].value.ival)); }
#line 1557 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 151: // expression: FTRUE
#line 546 "parser.y"
         {(yylhs.value.pNode) = new NumberLiteralNode(1);}
#line 1563 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 152: // expression: FFALSE
#line 547 "parser.y"
          {(yylhs.value.pNode) = new NumberLiteralNode(0);}
#line 1569 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 153: // expression: var_expression
#line 550 "parser.y"
                  {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1575 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 154: // expression: op_expr
#line 551 "parser.y"
           {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1581 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 155: // expression: offs_expr
#line 552 "parser.y"
            {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1587 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 156: // expression: reltool_expr
#line 553 "parser.y"
                { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1593 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 157: // expression: inst_expr
#line 554 "parser.y"
              {(yylhs.value.pNode)=(yystack_[0].value.pNode);}
#line 1599 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 158: // expression: Identifier LC func_call_parameter_list RC
#line 555 "parser.y"
                                              { (yylhs.value.pNode) = new FunctionCallNode((yystack_[3].value.sval), (yystack_[1].value.listNode));}
#line 1605 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 159: // expression: LR dim_num_stm RR
#line 556 "parser.y"
                      {(yylhs.value.pNode) = (yystack_[1].value.dim_num_stmNode);}
#line 1611 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;


#line 1615 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
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

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short Parser::yypact_ninf_ = -160;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -68,   -47,    61,   -68,  -160,    64,  -160,  -160,  1174,   -46,
    -160,  -160,  -160,   -34,     7,   704,  -160,  -160,  1174,  1174,
    1174,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,   -15,  1174,    81,  -160,
    -160,  -160,    21,    33,    42,   117,    51,   932,  -160,  1204,
     -36,   -44,    66,   133,   -25,    11,   135,   136,   -12,    12,
     137,   138,  1204,   120,  -160,  -160,  1174,    71,    31,  -160,
     471,   471,    72,  -160,   471,   471,   471,  -160,   471,   471,
     471,  -160,   471,   471,    58,  -160,    73,  -160,  1204,   278,
     471,  -160,  -160,   148,   153,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,   471,   471,  -160,   471,
    -160,  -160,  -160,  -160,   -48,  -160,  -160,  1306,  -160,  -160,
    -160,  -160,  -160,  -160,   546,   262,  -160,   556,   567,   577,
     601,   632,   686,   697,   710,   278,  -160,  -160,   471,   421,
     471,   471,    85,    86,   471,    88,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,    91,
      97,   471,   376,  1174,    87,   278,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,    43,  -160,  -160,   471,   471,   -24,
    1231,   720,  -160,   471,  -160,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,  -160,   471,   471,   471,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,   191,   224,
    -160,   742,   780,   833,   163,   164,   -43,  1231,   149,   851,
     861,    37,    39,    62,    84,    89,    90,    92,    93,    94,
      96,   896,   151,   152,   906,  -160,   102,   101,  -160,  -160,
     471,    59,   125,  -160,   471,  -160,   126,    27,    27,    44,
      27,    -3,    -3,  -160,    27,    27,  1231,    95,    95,  -160,
    -160,   278,  -160,  -160,   471,   471,   471,   471,   471,  -160,
     471,   278,   471,    68,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
      -7,    13,   169,   186,   922,  -160,  -160,  1231,  -160,    22,
     976,   987,  1032,  1057,  1231,  1067,   159,  1102,  -160,  -160,
     471,  -160,   471,   471,  -160,   278,   471,  -160,    23,  -160,
    -160,  -160,  -160,  -160,   471,  -160,   278,  1112,  1122,  1147,
    -160,  1177,  -160,  -160,    60,  -160,  -160,  -160,  -160,   278,
     471,  -160,  1197,   278,   171,  -160
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,     2,     3,     0,     1,     4,     0,     0,
      31,    28,    30,     0,     0,     0,     6,    11,     0,     0,
       0,     9,     8,    10,    21,    22,    16,    15,    14,    12,
      13,    17,    18,    19,    20,    23,     0,     0,     0,    29,
       5,     7,     0,     0,     0,     0,     0,     0,    25,    36,
     109,     0,   111,   110,   109,     0,   111,   110,   109,     0,
     111,   110,    36,     0,    24,    26,     0,     0,     0,    34,
       0,     0,     0,   103,     0,     0,     0,   102,     0,     0,
       0,   104,     0,     0,     0,    27,     0,    37,     0,    41,
       0,    55,    47,     0,     0,    52,    53,    54,    56,    57,
      58,    49,    50,    51,    48,    59,     0,     0,   148,     0,
     151,   152,   149,   150,   109,   147,   145,   153,   111,   110,
     155,   156,   154,   157,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,    41,    38,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,    42,    66,    43,    65,    63,
      86,    64,    62,    60,     0,    61,   131,     0,     0,     0,
     123,     0,   143,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,     0,   126,
     120,   117,   112,   118,   115,   113,   119,   116,     0,     0,
      87,     0,     0,     0,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    45,     0,     0,    32,    44,
       0,     0,     0,   159,     0,   144,     0,   135,   136,   138,
     137,   129,   130,   132,   133,   134,   142,   139,   140,   141,
      33,    41,    96,    88,     0,     0,     0,     0,     0,    85,
       0,    41,     0,     0,    91,    68,    74,    69,    70,    71,
      72,    73,    67,    75,    79,    84,    81,    82,    76,    46,
     109,     0,   111,   110,   121,   127,   128,   124,   158,     0,
       0,     0,     0,     0,    40,     0,     0,     0,    90,    92,
       0,   105,     0,     0,   122,    41,     0,    95,     0,    98,
      77,    78,    80,    83,     0,    89,    41,     0,     0,     0,
     100,     0,    97,    99,     0,    93,   106,   108,   107,    41,
       0,   101,     0,    41,     0,    94
  };

  const short
  Parser::yypgoto_[] =
  {
    -160,  -160,  -160,   242,  -160,   232,    18,  -160,  -160,   201,
    -160,  -160,    76,  -160,   188,   165,  1165,  -127,  -160,  -160,
     143,  -159,  -160,  -160,  -160,  -160,   -11,  -160,  -160,  -160,
     -64,  -160,  -160,   -42,  -160,  -160,  -160,   -39,   -19,  -160,
    -160,  -160,  -160,   -61
  };

  const short
  Parser::yydefgoto_[] =
  {
       0,     2,     3,     4,    15,    16,    67,    17,    47,    48,
      18,    19,   163,    21,    68,    69,   216,   164,   165,   166,
     116,   167,   168,   169,   170,   273,   274,   171,   172,   318,
     319,    22,   173,   117,    23,   175,   179,   118,   119,   120,
     121,   122,   123,   217
  };

  const short
  Parser::yytable_[] =
  {
      51,    55,    59,    52,    56,    60,   239,    72,   208,   124,
     125,   191,   183,   127,   128,   129,   268,   130,   131,   132,
      70,   133,   134,    53,    57,    61,    36,   315,   315,   176,
      71,    76,    73,   269,   243,   244,    42,    43,    44,   189,
     190,   191,    71,     1,    80,   180,   181,   174,   182,   310,
     262,   185,   186,    71,   188,    46,   189,   190,   191,   192,
     193,     6,    72,    72,    72,    46,    71,   185,   186,   187,
     188,    71,   189,   190,   191,   192,   193,   209,   211,   212,
     213,    20,     5,    37,    86,   219,   220,    77,    81,   311,
      88,    20,    89,   174,    72,    38,   268,   231,   268,   240,
     234,     8,   185,   186,     9,   188,    39,   189,   190,   191,
     192,   193,   198,   275,    45,   276,   194,    88,   268,   135,
     295,   268,    74,   174,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   299,   257,   258,   259,   277,   316,
     316,    49,   198,   268,   306,    10,   317,   332,   268,   268,
      50,   268,   268,   268,   308,   268,   272,   196,   197,   198,
     278,   268,    54,    11,    12,   279,   280,   174,   281,   282,
     283,    58,   284,   196,   197,   198,    13,    62,   289,   294,
      63,   237,   340,   297,   268,   268,   296,   298,   330,    75,
      14,    78,    79,    82,    83,   291,    85,   238,   292,   335,
      87,   126,   136,   300,   301,   302,   303,   304,   177,   305,
     198,   307,   341,   178,   214,   215,   344,   218,   293,   174,
     232,   260,   266,   267,   270,   312,   233,   286,   287,   174,
     290,   185,   186,   187,   188,   138,   189,   190,   191,   192,
     193,   139,   313,   325,   345,     7,   261,    41,    65,   327,
      84,   328,   329,   137,   333,   331,   140,   141,   142,   143,
     184,     0,   309,   334,     0,     0,   144,     0,     0,   185,
     186,   187,   188,   174,   189,   190,   191,   192,   193,   342,
     194,     0,     0,     0,   174,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,   139,   145,   174,     0,     0,
       0,   174,     0,     0,     0,    10,     0,   146,     0,   147,
     140,   141,   142,   143,     0,     0,     0,     0,   194,     0,
     144,     0,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,     0,     0,     0,     0,   196,   197,   198,
     156,   199,   157,   158,   159,   160,     0,     0,     0,   161,
     145,     0,     0,   162,     0,     0,     0,     0,     0,    10,
       0,   146,     0,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   196,   197,   198,     0,   148,
     149,   150,   151,   152,   153,   154,   155,     0,     0,    90,
       0,     0,     0,     0,   156,     0,   157,   158,   159,   160,
       0,     0,     0,   161,    91,    92,     0,   162,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,   101,     0,   102,   103,
     104,   105,     0,   106,    90,     0,   107,     0,     0,     0,
       0,   108,     0,   109,     0,     0,   110,   111,     0,    91,
      92,     0,   235,     0,    71,     0,     0,    93,     0,     0,
      94,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,     0,   102,   103,   104,   105,     0,   106,     0,
       0,   107,     0,     0,    90,     0,   108,     0,   109,     0,
       0,   110,   111,     0,     0,     0,     0,   210,     0,    91,
      92,     0,     0,   112,   113,   114,   115,    93,     0,     0,
      94,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,     0,   102,   103,   104,   105,     0,   106,     0,
       0,   107,     0,     0,     0,     0,   108,     0,   109,     0,
       0,   110,   111,     0,     0,     0,     0,     0,   112,   113,
     114,   115,     0,   185,   186,   187,   188,     0,   189,   190,
     191,   192,   193,   185,   186,   187,   188,     0,   189,   190,
     191,   192,   193,     0,   185,   186,   187,   188,     0,   189,
     190,   191,   192,   193,   185,   186,   187,   188,     0,   189,
     190,   191,   192,   193,     0,     0,     0,     0,   112,   113,
     114,   115,   194,     0,     0,     0,     0,     0,   185,   186,
     187,   188,   194,   189,   190,   191,   192,   193,     0,     0,
       0,     0,   195,   194,     0,     0,     0,     0,     0,     0,
       0,     0,   200,   194,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   201,   189,   190,   191,   192,   193,     0,
       0,     0,     0,   202,     0,     0,     0,   194,     0,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,   196,
     197,   198,     0,     0,     0,     0,     0,   203,     0,     0,
     196,   197,   198,     0,     0,     0,     0,     0,   194,     0,
     196,   197,   198,   185,   186,   187,   188,     0,   189,   190,
     191,   192,   193,     0,   185,   186,   187,   188,   204,   189,
     190,   191,   192,   193,   196,   197,   198,   185,   186,   187,
     188,     0,   189,   190,   191,   192,   193,   185,   186,   187,
     188,     0,   189,   190,   191,   192,   193,     0,     0,     0,
       0,     8,   194,     0,     9,   196,   197,   198,     0,   185,
     186,   187,   188,   194,   189,   190,   191,   192,   193,     0,
       0,     0,   205,     0,     0,     0,   194,     0,     0,     0,
       0,     0,     0,   206,     0,     0,   194,     0,     0,     0,
       0,   245,     0,     0,     0,    10,   207,   185,   186,   187,
     188,     0,   189,   190,   191,   192,   193,     0,   194,   196,
     197,   198,     0,    11,    12,     0,     0,     0,     0,     0,
     196,   197,   198,    40,     0,     0,    13,     0,   263,     0,
       0,     0,     0,   196,   197,   198,     0,     0,     0,     0,
      14,     0,     0,   196,   197,   198,   194,     0,     0,   264,
     185,   186,   187,   188,     0,   189,   190,   191,   192,   193,
       0,     0,     0,     0,     0,   196,   197,   198,   185,   186,
     187,   188,     0,   189,   190,   191,   192,   193,   185,   186,
     187,   188,     0,   189,   190,   191,   192,   193,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   194,
       0,     0,   265,   196,   197,   198,     0,     0,     0,     0,
       0,     0,     0,   185,   186,   187,   188,   194,   189,   190,
     191,   192,   193,   185,   186,   187,   188,   194,   189,   190,
     191,   192,   193,     0,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   271,   189,   190,   191,   192,   193,     0,
       0,     0,     0,     0,     0,     0,   196,   197,   198,   272,
       0,     0,   194,     0,     0,     0,     0,     0,    24,    25,
       0,     0,   194,     0,   196,   197,   198,     0,     0,     0,
       0,     0,   285,    64,   196,   197,   198,     0,   194,     0,
       0,     0,   288,   185,   186,   187,   188,     0,   189,   190,
     191,   192,   193,     0,   185,   186,   187,   188,   314,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,   196,
     197,   198,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,   194,     0,     0,   196,   197,   198,     0,   185,
     186,   187,   188,   194,   189,   190,   191,   192,   193,     0,
       0,     0,   320,     0,     0,     0,     0,     0,     0,     0,
       0,    35,     0,   321,   185,   186,   187,   188,     0,   189,
     190,   191,   192,   193,   185,   186,   187,   188,     0,   189,
     190,   191,   192,   193,     0,     0,     0,     0,   194,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,     0,
     196,   197,   198,     0,     0,     0,     0,     0,   322,   185,
     186,   187,   188,   194,   189,   190,   191,   192,   193,   185,
     186,   187,   188,   194,   189,   190,   191,   192,   193,   185,
     186,   187,   188,   323,   189,   190,   191,   192,   193,     0,
       0,   324,     0,     0,     0,   196,   197,   198,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   194,   189,
     190,   191,   192,   193,     0,     0,   326,     0,   194,     0,
     196,   197,   198,     0,     0,     0,     0,     0,   194,     0,
     196,   197,   198,     0,   185,   186,   187,   188,   336,   189,
     190,   191,   192,   193,     0,     0,     0,     0,   337,   339,
      24,    25,     0,   194,   185,   186,   187,   188,     0,   189,
     190,   191,   192,   193,     0,   196,   197,   198,     0,     0,
       0,     0,     0,   338,     0,   196,   197,   198,     0,     0,
      24,    25,     0,   194,     0,   196,   197,   198,   185,   186,
     187,   188,    66,   189,   190,   191,   192,   193,     0,     0,
       0,     0,     0,   194,     0,     0,     0,     0,     0,     0,
     196,   197,   198,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,     0,     0,     0,     0,   343,
       0,     0,     0,     0,     0,     0,     0,   194,     0,     0,
     196,   197,   198,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
     196,   197,   198,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,     0,     0,     0,     0,   236,     0,     0,
       0,     0,     0,    35,    91,    92,     0,     0,     0,     0,
       0,     0,   241,   242,   196,   197,   198,     0,   246,     0,
      95,    96,    97,    98,    99,   100,   101,    72,   102,   103,
     104,   105
  };

  const short
  Parser::yycheck_[] =
  {
      42,    43,    44,    42,    43,    44,   165,    51,   135,    70,
      71,    14,    60,    74,    75,    76,    59,    78,    79,    80,
      56,    82,    83,    42,    43,    44,     8,     5,     5,    90,
      78,    56,    76,    76,    58,    59,    18,    19,    20,    12,
      13,    14,    78,   111,    56,   106,   107,    89,   109,    56,
     209,     7,     8,    78,    10,    37,    12,    13,    14,    15,
      16,     0,    51,    51,    51,    47,    78,     7,     8,     9,
      10,    78,    12,    13,    14,    15,    16,   138,   139,   140,
     141,     5,   129,   129,    66,   146,   147,    76,    76,    76,
      59,    15,    61,   135,    51,   129,    59,   158,    59,    56,
     161,    37,     7,     8,    40,    10,    99,    12,    13,    14,
      15,    16,   115,    76,   129,    76,    56,    59,    59,    61,
      61,    59,    56,   165,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   261,   196,   197,   198,    76,   117,
     117,    60,   115,    59,   271,    81,   124,   124,    59,    59,
     129,    59,    59,    59,    86,    59,    88,   113,   114,   115,
      76,    59,   129,    99,   100,    76,    76,   209,    76,    76,
      76,   129,    76,   113,   114,   115,   112,    60,    76,   240,
     129,   163,   122,   244,    59,    59,    61,    61,   315,    56,
     126,    56,    56,    56,    56,   237,    76,   110,   237,   326,
     129,   129,   129,   264,   265,   266,   267,   268,    60,   270,
     115,   272,   339,    60,   129,   129,   343,   129,   237,   261,
     129,    30,    59,    59,    75,    56,   129,    76,    76,   271,
     129,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    56,    84,    73,     3,    22,    15,    47,   310,
      62,   312,   313,    88,   318,   316,    32,    33,    34,    35,
     117,    -1,   273,   324,    -1,    -1,    42,    -1,    -1,     7,
       8,     9,    10,   315,    12,    13,    14,    15,    16,   340,
      56,    -1,    -1,    -1,   326,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    72,   339,    -1,    -1,
      -1,   343,    -1,    -1,    -1,    81,    -1,    83,    -1,    85,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    56,    -1,
      42,    -1,    -1,    -1,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,    79,   118,   119,   120,   121,    -1,    -1,    -1,   125,
      72,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,    -1,    13,
      -1,    -1,    -1,    -1,   116,    -1,   118,   119,   120,   121,
      -1,    -1,    -1,   125,    28,    29,    -1,   129,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    -1,    57,    13,    -1,    60,    -1,    -1,    -1,
      -1,    65,    -1,    67,    -1,    -1,    70,    71,    -1,    28,
      29,    -1,    76,    -1,    78,    -1,    -1,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    -1,    57,    -1,
      -1,    60,    -1,    -1,    13,    -1,    65,    -1,    67,    -1,
      -1,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,    28,
      29,    -1,    -1,   127,   128,   129,   130,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    -1,    57,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    65,    -1,    67,    -1,
      -1,    70,    71,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,    -1,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    -1,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,    56,    -1,    -1,    -1,    -1,    -1,     7,     8,
       9,    10,    56,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    76,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    56,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    76,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    56,    -1,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    56,    -1,
     113,   114,   115,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    -1,     7,     8,     9,    10,    76,    12,
      13,    14,    15,    16,   113,   114,   115,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    37,    56,    -1,    40,   113,   114,   115,    -1,     7,
       8,     9,    10,    56,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    81,    76,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    -1,    56,   113,
     114,   115,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   109,    -1,    -1,   112,    -1,    76,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,
     126,    -1,    -1,   113,   114,   115,    56,    -1,    -1,    59,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     8,     9,    10,    56,    12,    13,
      14,    15,    16,     7,     8,     9,    10,    56,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    82,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,    88,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    56,    -1,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    76,    41,   113,   114,   115,    -1,    56,    -1,
      -1,    -1,    76,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    -1,     7,     8,     9,    10,    76,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,    56,    -1,    -1,   113,   114,   115,    -1,     7,
       8,     9,    10,    56,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    76,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    56,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    76,     7,
       8,     9,    10,    56,    12,    13,    14,    15,    16,     7,
       8,     9,    10,    56,    12,    13,    14,    15,    16,     7,
       8,     9,    10,    76,    12,    13,    14,    15,    16,    -1,
      -1,    74,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,     9,    10,    56,    12,
      13,    14,    15,    16,    -1,    -1,    64,    -1,    56,    -1,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    56,    -1,
     113,   114,   115,    -1,     7,     8,     9,    10,    76,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    76,    22,
      26,    27,    -1,    56,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    76,    -1,   113,   114,   115,    -1,    -1,
      26,    27,    -1,    56,    -1,   113,   114,   115,     7,     8,
       9,    10,    38,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
     113,   114,   115,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,   162,    -1,    -1,
      -1,    -1,    -1,   129,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,   113,   114,   115,    -1,   183,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,   111,   132,   133,   134,   129,     0,   134,    37,    40,
      81,    99,   100,   112,   126,   135,   136,   138,   141,   142,
     143,   144,   162,   165,    26,    27,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   129,   137,   129,   129,    99,
     109,   136,   137,   137,   137,   129,   137,   139,   140,    60,
     129,   164,   168,   169,   129,   164,   168,   169,   129,   164,
     168,   169,    60,   129,    41,   140,    38,   137,   145,   146,
      56,    78,    51,    76,    56,    56,    56,    76,    56,    56,
      56,    76,    56,    56,   145,    76,   137,   129,    59,    61,
      13,    28,    29,    36,    39,    44,    45,    46,    47,    48,
      49,    50,    52,    53,    54,    55,    57,    60,    65,    67,
      70,    71,   127,   128,   129,   130,   151,   164,   168,   169,
     170,   171,   172,   173,   174,   174,   129,   174,   174,   174,
     174,   174,   174,   174,   174,    61,   129,   146,    11,    17,
      32,    33,    34,    35,    42,    72,    83,    85,   101,   102,
     103,   104,   105,   106,   107,   108,   116,   118,   119,   120,
     121,   125,   129,   143,   148,   149,   150,   152,   153,   154,
     155,   158,   159,   163,   164,   166,   174,    60,    60,   167,
     174,   174,   174,    60,   151,     7,     8,     9,    10,    12,
      13,    14,    15,    16,    56,    76,   113,   114,   115,    79,
      76,    76,    76,    76,    76,    76,    76,    76,   148,   174,
      76,   174,   174,   174,   129,   129,   147,   174,   129,   174,
     174,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   174,   129,   129,   174,    76,   147,   137,   110,   152,
      56,   147,   147,    58,    59,    61,   147,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
      30,    22,   152,    76,    59,    59,    59,    59,    59,    76,
      75,    82,    88,   156,   157,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
     129,   164,   168,   169,   174,    61,    61,   174,    61,   148,
     174,   174,   174,   174,   174,   174,   148,   174,    86,   157,
      56,    76,    56,    56,    76,     5,   117,   124,   160,   161,
      76,    76,    76,    76,    74,    84,    64,   174,   174,   174,
     148,   174,   124,   161,   174,   148,    76,    76,    76,    22,
     122,   148,   174,    82,   148,    73
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,   131,   132,   133,   133,   134,   135,   135,   136,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   138,   139,   139,   140,   141,   142,
     142,   143,   144,   144,   145,   145,   145,   146,   146,   147,
     147,   148,   148,   149,   149,   150,   150,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   153,   153,   154,
     155,   156,   156,   157,   158,   159,   159,   159,   160,   160,
     161,   161,   162,   162,   162,   163,   163,   163,   163,   164,
     164,   164,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   166,   166,   167,   167,   168,   169,   170,   171,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   173,   173,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     2,     3,     1,     2,
       1,     1,     7,     8,     1,     3,     0,     2,     3,     1,
       3,     0,     1,     1,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     5,     3,
       5,     3,     3,     5,     3,     3,     1,     2,     3,     5,
       4,     1,     2,     4,    11,     5,     3,     6,     1,     2,
       2,     4,     4,     4,     4,     4,     6,     6,     6,     1,
       1,     1,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     3,     4,     1,     3,     3,     4,     4,     4,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3
  };


#if D_YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "MINUS", "DIVIDE",
  "ELSE", "PREFIX", "GE", "LE", "EQ", "NE", "IF", "ADD", "SUB", "MUL",
  "LT", "GT", "RETURN", "NumberType", "TextType", "VoidType", "SPACE",
  "THEN", "JIN", "DOLAR", "RAPID_NAN", "SEAMDATA", "WELDDATA", "INPOS",
  "CONC", "ENDFUNC", "UMINUS", "ACCSET", "VELSET", "SETDO", "WAITDI",
  "OFFS", "FUNC", "INOUT", "RELTOOl", "RECORD", "ENDRECORD", "PULSEDO",
  "WAITTIME_INPOS", "WOBJ_P", "SEAM_NAME", "ZONE_P", "VEL_P", "TCP_P",
  "NOEOFFS", "PLEN", "DOT", "MAXTIME", "TIMEFLAG", "TOOL_P", "ID_P", "ASS",
  "LR", "RR", "COMMA", "LC", "RC", "LESS", "GREATER", "COLON", "FNULL",
  "DEVCOLON", "NOT", "UNINDENT", "INDENT", "FTRUE", "FFALSE", "FOR",
  "ENDFOR", "TO", "FROM", "SEMICOLON", "SPLASH", "LBRACE", "RBRACE",
  "LMOVE", "VAR", "DO", "WHILE", "ENDWHILE", "TEST", "ENDTEST", "RETRY",
  "CASE", "DEFAULT", "JOINTTARGET", "ROBTARGET", "STRING", "NUM", "BOOL",
  "WOBJDATA", "ZONEDATA", "SPEEDDATA", "TOOLDATA", "PERS", "CONST_L",
  "ACTUNIT", "MOVEABSJ", "ARCLSTART", "ARCL", "ARCC", "ARCEND", "MOVEL",
  "MOVEJ", "ENDMODULE", "ENDPROC", "MODULE", "PROC", "AND", "OR", "MOD",
  "DEACTUNIT", "ELSEIF", "WAITTIME", "WAITUNTIL", "SET", "RESET", "STEP",
  "ARCCEND", "ENDIF", "TPWRITE", "TASK", "Number", "LNumber", "Identifier",
  "String", "$accept", "program", "module_list", "module",
  "declaration_list", "declaration", "Type", "Record_declare",
  "struct_members", "var_decl", "scope_pers", "scope1", "scope2",
  "function_declaration", "parameter_declaration_list",
  "parameter_declaration", "func_call_parameter_list", "function_body",
  "statement_list", "function_call", "inst_modifer", "statement", "return",
  "while_loop", "switch", "switch_case_list", "switch_case_define", "for",
  "if", "elseif_statment_list", "elseif_statment", "variable_declaration",
  "variable_for_body", "var_expression", "var_assignment", "assignment",
  "dim_num_stm", "struct_index", "array_index", "offs_expr",
  "reltool_expr", "op_expr", "inst_expr", "expression", YY_NULLPTR
  };
#endif


#if D_YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   204,   204,   208,   209,   213,   218,   219,   223,   224,
     225,   226,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   244,   248,   249,   252,   256,   260,
     262,   266,   274,   275,   279,   280,   281,   285,   286,   294,
     298,   313,   314,   318,   319,   324,   325,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   375,   376,   380,
     384,   392,   397,   404,   411,   415,   416,   417,   421,   422,
     426,   427,   432,   433,   434,   438,   439,   440,   441,   445,
     446,   447,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   467,   472,   479,   483,   490,   494,   498,   502,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   521,   522,   535,   536,   542,   543,   544,
     545,   546,   547,   550,   551,   552,   553,   554,   555,   556
  };

  void
  Parser::yy_stack_print_ () const
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
  Parser::yy_reduce_print_ (int yyrule) const
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
#endif // D_YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const unsigned char
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130
    };
    // Last valid token kind.
    const int code_max = 385;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 15 "parser.y"
} // Language
#line 2588 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"

#line 561 "parser.y"



static int yylex( Language::Parser::semantic_type *yylval,Language::location* loc,Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval,loc) );
}
void Language::Parser::error( const Language::location& location,const std::string &err_message )
{
    printf("error parsed %s(%s)at %d.%d-%d.%d: %s\n",loc.end.filename->c_str(), err_message.c_str(),loc.begin.line, loc.begin.column, loc.end.line, loc.end.column,cur_yytext.c_str());   
}
