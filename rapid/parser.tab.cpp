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
#line 87 "parser.y"

    #include "translator.hpp"
    #include "ast.h"
    #include <stack>
    #include "astnode.h"
    static int yylex(Language::Parser::semantic_type *yylval, Language::location* loc,Language::Lexer  &lexer);

    std::string err;
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


#line 81 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"


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
#line 174 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"

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
#line 207 "parser.y"
                {}
#line 647 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 3: // module_list: module
#line 211 "parser.y"
                {(yylhs.value.moduleListNode) = new ListNode<ModuleNode>((yystack_[0].value.moduleNode));}
#line 653 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 4: // module_list: module_list module
#line 212 "parser.y"
                         {(yystack_[1].value.moduleListNode)->push_back((yystack_[0].value.moduleNode));}
#line 659 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 5: // module: MODULE Identifier declaration_list ENDMODULE
#line 216 "parser.y"
                                                     {(yylhs.value.moduleNode) = new ModuleNode((yystack_[2].value.sval),(yystack_[1].value.listNode));}
#line 665 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 6: // declaration_list: declaration
#line 221 "parser.y"
                 {(yylhs.value.listNode) = new DeclareListNode((yystack_[0].value.pNode));}
#line 671 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 7: // declaration_list: declaration_list declaration
#line 222 "parser.y"
                                     {(yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));}
#line 677 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 8: // declaration: variable_declaration
#line 226 "parser.y"
                           {(yylhs.value.pNode)=(yystack_[0].value.variableNode);}
#line 683 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 9: // declaration: function_declaration
#line 227 "parser.y"
                               {(yylhs.value.pNode)=(yystack_[0].value.functionNode);}
#line 689 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 10: // declaration: var_assignment
#line 228 "parser.y"
                    {(yylhs.value.pNode)=(yystack_[0].value.pNode);}
#line 695 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 11: // declaration: Record_declare
#line 229 "parser.y"
                     {(yylhs.value.pNode)=(yystack_[0].value.pNode);}
#line 701 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 12: // Type: NUM
#line 232 "parser.y"
            { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("NUM")); (yylhs.value.idenNode) = id;}
#line 707 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 13: // Type: BOOL
#line 233 "parser.y"
                { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("BOOL")); (yylhs.value.idenNode) = id;}
#line 713 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 14: // Type: STRING
#line 234 "parser.y"
                  { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("STRING")); (yylhs.value.idenNode) = id;}
#line 719 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 15: // Type: ROBTARGET
#line 235 "parser.y"
                     { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("ROBTARGET")); (yylhs.value.idenNode) = id;}
#line 725 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 16: // Type: JOINTTARGET
#line 236 "parser.y"
                        {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("JOINTTARGET")); (yylhs.value.idenNode) = id;}
#line 731 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 17: // Type: WOBJDATA
#line 237 "parser.y"
               {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("WOBJDATA")); (yylhs.value.idenNode) = id;}
#line 737 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 18: // Type: ZONEDATA
#line 238 "parser.y"
               {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("ZONEDATA")); (yylhs.value.idenNode) = id;}
#line 743 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 19: // Type: SPEEDDATA
#line 239 "parser.y"
                { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("SPEEDDATA")); (yylhs.value.idenNode) = id;}
#line 749 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 20: // Type: TOOLDATA
#line 240 "parser.y"
               {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("TOOLDATA")); (yylhs.value.idenNode) = id;}
#line 755 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 21: // Type: SEAMDATA
#line 241 "parser.y"
               {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("SEAMDATA")); (yylhs.value.idenNode) = id;}
#line 761 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 22: // Type: WELDDATA
#line 242 "parser.y"
               {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("WELDDATA")); (yylhs.value.idenNode) = id;}
#line 767 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 23: // Type: Identifier
#line 243 "parser.y"
                 {(yylhs.value.idenNode) = new IdentifierNode((yystack_[0].value.sval)); /*$$ = $1;*/ }
#line 773 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 24: // Record_declare: RECORD Identifier struct_members ENDRECORD
#line 247 "parser.y"
                                               { IdentifierNode* id = new IdentifierNode((yystack_[2].value.sval));(yylhs.value.pNode) = new StructDescNode(id, (yystack_[1].value.listNode)); }
#line 779 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 25: // struct_members: var_decl
#line 251 "parser.y"
              { (yylhs.value.listNode) = new  ListNode<ASTNode>(); (yylhs.value.listNode)->push_back((yystack_[0].value.pNode)); }
#line 785 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 26: // struct_members: struct_members var_decl
#line 252 "parser.y"
                              { (yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode)); }
#line 791 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 27: // var_decl: Type Identifier SEMICOLON
#line 255 "parser.y"
                              {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval)); (yylhs.value.pNode) = new VariableNode(VAR,(yystack_[2].value.idenNode),id,loc); }
#line 797 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 28: // scope_pers: PERS
#line 259 "parser.y"
       { (yylhs.value.ival) =  PERS;}
#line 803 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 29: // scope1: TASK PERS
#line 263 "parser.y"
              { (yylhs.value.ival) =  TASK_PERS;}
#line 809 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 30: // scope1: CONST_L
#line 265 "parser.y"
            { (yylhs.value.ival) = eCONST;}
#line 815 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 31: // scope2: VAR
#line 269 "parser.y"
        { (yylhs.value.ival) =  VAR;}
#line 821 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 32: // function_declaration: PROC Identifier LC parameter_declaration_list RC function_body ENDPROC
#line 277 "parser.y"
                                                                           {(yylhs.value.functionNode) = new FunctionNode(nullptr, (yystack_[5].value.sval), (yystack_[3].value.parameterListNode), (yystack_[1].value.statementListNode)); }
#line 827 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 33: // function_declaration: FUNC Type Identifier LC parameter_declaration_list RC function_body ENDFUNC
#line 278 "parser.y"
                                                                                 {(yylhs.value.functionNode) = new FunctionNode((yystack_[6].value.idenNode), (yystack_[5].value.sval), (yystack_[3].value.parameterListNode), (yystack_[1].value.statementListNode)); }
#line 833 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 34: // parameter_declaration_list: parameter_declaration
#line 282 "parser.y"
                          { (yylhs.value.parameterListNode) = new ListNode<ParameterNode>((yystack_[0].value.parameterNode)); }
#line 839 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 35: // parameter_declaration_list: parameter_declaration_list COMMA parameter_declaration
#line 283 "parser.y"
                                                             {(yystack_[2].value.parameterListNode)->push_back((yystack_[0].value.parameterNode));}
#line 845 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 36: // parameter_declaration_list: %empty
#line 284 "parser.y"
      {(yylhs.value.parameterListNode) = new ListNode<ParameterNode>();}
#line 851 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 37: // parameter_declaration: Type Identifier
#line 288 "parser.y"
                    {IdentifierNode* id = new IdentifierNode((yystack_[0].value.sval));(yylhs.value.parameterNode) = new ParameterNode((yystack_[1].value.idenNode),id,nullptr);}
#line 857 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 38: // parameter_declaration: INOUT Type Identifier
#line 290 "parser.y"
    {
        IdentifierNode* inout = new IdentifierNode(&QString::fromLatin1("INOUT"));
        IdentifierNode* id = new IdentifierNode((yystack_[0].value.sval));
        (yylhs.value.parameterNode) = new ParameterNode(inout,(yystack_[1].value.idenNode),id,nullptr);
    }
#line 867 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 39: // func_call_parameter_list: expression
#line 299 "parser.y"
    {
        (yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.pNode)); 
    }
#line 875 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 40: // func_call_parameter_list: func_call_parameter_list COMMA expression
#line 303 "parser.y"
        {
        (yystack_[2].value.listNode)->push_back((yystack_[0].value.pNode));   
	}
#line 883 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 41: // function_body: %empty
#line 317 "parser.y"
  {(yylhs.value.statementListNode)=NULL;}
#line 889 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 42: // function_body: statement_list
#line 318 "parser.y"
                     {(yylhs.value.statementListNode) = (yystack_[0].value.statementListNode);}
#line 895 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 43: // statement_list: statement
#line 322 "parser.y"
              {(yylhs.value.statementListNode) = new StatementListNode((yystack_[0].value.pNode));}
#line 901 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 44: // statement_list: statement_list statement
#line 323 "parser.y"
                               {(yystack_[1].value.statementListNode)->push_back((yystack_[0].value.pNode));}
#line 907 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 45: // function_call: Identifier SEMICOLON
#line 328 "parser.y"
                           { (yylhs.value.pNode) = new FunctionCallNode((yystack_[1].value.sval), new ListNode<ASTNode>());}
#line 913 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 46: // function_call: Identifier func_call_parameter_list SEMICOLON
#line 329 "parser.y"
                                                     { (yylhs.value.pNode) = new FunctionCallNode((yystack_[2].value.sval), (yystack_[1].value.listNode));}
#line 919 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 47: // inst_modifer: CONC
#line 333 "parser.y"
            { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\Conc")); (yylhs.value.pNode) = id;}
#line 925 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 48: // inst_modifer: TOOL_P
#line 334 "parser.y"
             { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\Tool")); (yylhs.value.pNode) = id;}
#line 931 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 49: // inst_modifer: PLEN
#line 335 "parser.y"
           { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\PLength")); (yylhs.value.pNode) = id;}
#line 937 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 50: // inst_modifer: MAXTIME
#line 336 "parser.y"
              { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\MaxTime")); (yylhs.value.pNode) = id;}
#line 943 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 51: // inst_modifer: TIMEFLAG
#line 337 "parser.y"
               { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\TimeFlag")); (yylhs.value.pNode) = id;}
#line 949 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 52: // inst_modifer: WOBJ_P
#line 338 "parser.y"
              { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\WObj")); (yylhs.value.pNode) = id;}
#line 955 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 53: // inst_modifer: SEAM_NAME
#line 339 "parser.y"
                { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\SeamName")); (yylhs.value.pNode) = id;}
#line 961 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 54: // inst_modifer: ZONE_P
#line 340 "parser.y"
             { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\Z")); (yylhs.value.pNode) = id;}
#line 967 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 55: // inst_modifer: INPOS
#line 341 "parser.y"
            { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\InPos")); (yylhs.value.pNode) = id;}
#line 973 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 56: // inst_modifer: VEL_P
#line 342 "parser.y"
            { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\V")); (yylhs.value.pNode) = id;}
#line 979 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 57: // inst_modifer: TCP_P
#line 343 "parser.y"
            { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\T")); (yylhs.value.pNode) = id;}
#line 985 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 58: // inst_modifer: NOEOFFS
#line 344 "parser.y"
              { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\NoEOffs")); (yylhs.value.pNode) = id;}
#line 991 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 59: // inst_modifer: ID_P
#line 345 "parser.y"
           { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\ID")); (yylhs.value.pNode) = id;}
#line 997 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 60: // statement: variable_for_body
#line 349 "parser.y"
                      {(yylhs.value.pNode) = (yystack_[0].value.variableNode);}
#line 1003 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 61: // statement: assignment
#line 350 "parser.y"
                  {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1009 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 62: // statement: if
#line 351 "parser.y"
         { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1015 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 63: // statement: while_loop
#line 352 "parser.y"
                 { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1021 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 64: // statement: for
#line 353 "parser.y"
          { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1027 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 65: // statement: return
#line 354 "parser.y"
              { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1033 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 66: // statement: function_call
#line 355 "parser.y"
                    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1039 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 67: // statement: MOVEJ func_call_parameter_list SEMICOLON
#line 356 "parser.y"
                                               {(yylhs.value.pNode) = new MoveJNode((yystack_[1].value.listNode));}
#line 1045 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 68: // statement: ACTUNIT func_call_parameter_list SEMICOLON
#line 357 "parser.y"
                                                {(yylhs.value.pNode) = new ActUnitNode((yystack_[1].value.listNode));}
#line 1051 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 69: // statement: ARCLSTART func_call_parameter_list SEMICOLON
#line 358 "parser.y"
                                                  {(yylhs.value.pNode) = new ArcLStartNode((yystack_[1].value.listNode));}
#line 1057 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 70: // statement: ARCL func_call_parameter_list SEMICOLON
#line 359 "parser.y"
                                             {(yylhs.value.pNode) = new ArcLNode((yystack_[1].value.listNode));}
#line 1063 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 71: // statement: ARCC func_call_parameter_list SEMICOLON
#line 360 "parser.y"
                                             {(yylhs.value.pNode) = new ArccNode((yystack_[1].value.listNode));}
#line 1069 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 72: // statement: ARCEND func_call_parameter_list SEMICOLON
#line 361 "parser.y"
                                               {(yylhs.value.pNode) = new ArcEndNode((yystack_[1].value.listNode));}
#line 1075 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 73: // statement: MOVEL func_call_parameter_list SEMICOLON
#line 362 "parser.y"
                                              { (yylhs.value.pNode) = new MoveLNode((yystack_[1].value.listNode));}
#line 1081 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 74: // statement: MOVEABSJ func_call_parameter_list SEMICOLON
#line 363 "parser.y"
                                                 {(yylhs.value.pNode) = new MoveABSJNode((yystack_[1].value.listNode));}
#line 1087 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 75: // statement: DEACTUNIT func_call_parameter_list SEMICOLON
#line 364 "parser.y"
                                                  { (yylhs.value.pNode) = new DeActUnitNode((yystack_[1].value.listNode));}
#line 1093 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 76: // statement: TPWRITE expression SEMICOLON
#line 365 "parser.y"
                                  {(yylhs.value.pNode) = new TpWriteNode((yystack_[1].value.pNode));}
#line 1099 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 77: // statement: ACCSET expression COMMA expression SEMICOLON
#line 366 "parser.y"
                                                   {(yylhs.value.pNode) = new AccSetNode((yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1105 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 78: // statement: VELSET expression COMMA expression SEMICOLON
#line 367 "parser.y"
                                                  {(yylhs.value.pNode) = new VelSetNode((yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1111 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 79: // statement: WAITTIME func_call_parameter_list SEMICOLON
#line 368 "parser.y"
                                                  {(yylhs.value.pNode) = new WaitTimeNode((yystack_[1].value.listNode));}
#line 1117 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 80: // statement: SETDO Identifier COMMA expression SEMICOLON
#line 369 "parser.y"
                                                   {IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new SetDoNode(id,(yystack_[1].value.pNode));}
#line 1123 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 81: // statement: SET Identifier SEMICOLON
#line 370 "parser.y"
                               {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval));(yylhs.value.pNode) = new SetNode(id);}
#line 1129 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 82: // statement: RESET Identifier SEMICOLON
#line 371 "parser.y"
                                 {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval));(yylhs.value.pNode) = new ReSetNode(id);}
#line 1135 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 83: // statement: WAITDI Identifier COMMA expression SEMICOLON
#line 372 "parser.y"
                                                   {(yylhs.value.pNode) = new WaitDiNode((yystack_[3].value.sval),(yystack_[1].value.pNode));}
#line 1141 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 84: // statement: WAITUNTIL expression SEMICOLON
#line 373 "parser.y"
                                     {(yylhs.value.pNode) = new WaitUntilNode((yystack_[1].value.pNode));}
#line 1147 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 85: // statement: PULSEDO func_call_parameter_list SEMICOLON
#line 374 "parser.y"
                                                 {  (yylhs.value.pNode) = new PulseDONode((yystack_[1].value.listNode));}
#line 1153 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 86: // statement: switch
#line 375 "parser.y"
             {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1159 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 87: // return: RETURN SEMICOLON
#line 379 "parser.y"
                 {(yylhs.value.pNode) = new ReturnNode(NULL); }
#line 1165 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 88: // return: RETURN expression SEMICOLON
#line 380 "parser.y"
                                {(yylhs.value.pNode) = new ReturnNode((yystack_[1].value.pNode)); }
#line 1171 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 89: // while_loop: WHILE expression DO function_body ENDWHILE
#line 384 "parser.y"
                                                            { (yylhs.value.pNode) = new WhileNode((yystack_[3].value.pNode), (yystack_[1].value.statementListNode)); }
#line 1177 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 90: // switch: TEST expression switch_case_list ENDTEST
#line 389 "parser.y"
    {
        (yylhs.value.pNode) = new SWitchNode((yystack_[2].value.pNode),(yystack_[1].value.listNode),NULL);
    }
#line 1185 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 91: // switch_case_list: switch_case_define
#line 397 "parser.y"
        {
        (yylhs.value.listNode) = new SWitchCaseListNode((yystack_[0].value.pNode));
	}
#line 1193 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 92: // switch_case_list: switch_case_list switch_case_define
#line 402 "parser.y"
        {
        (yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));   
	}
#line 1201 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 93: // switch_case_define: CASE expression COLON function_body
#line 409 "parser.y"
        {
        (yylhs.value.pNode) = new CaseNode((yystack_[2].value.pNode),(yystack_[0].value.statementListNode)); //$$->dimListType->push_back($1);
	}
#line 1209 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 94: // for: FOR Identifier FROM expression TO expression STEP expression DO function_body ENDFOR
#line 415 "parser.y"
                                                                                         {  IdentifierNode* id = new IdentifierNode((yystack_[9].value.sval));(yylhs.value.pNode) = new ForNode(id,(yystack_[7].value.pNode),(yystack_[5].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.statementListNode));}
#line 1215 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 95: // if: IF expression THEN function_body ENDIF
#line 419 "parser.y"
                                             { (yylhs.value.pNode) = new IfNode((yystack_[3].value.pNode), (yystack_[1].value.statementListNode)); }
#line 1221 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 96: // if: IF expression statement
#line 420 "parser.y"
                               { (yylhs.value.pNode) = new IfNode((yystack_[1].value.pNode), (yystack_[0].value.pNode)); }
#line 1227 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 97: // if: IF expression THEN function_body elseif_statment_list ENDIF
#line 421 "parser.y"
                                                                  { (yylhs.value.pNode) = new IfNode((yystack_[4].value.pNode), (yystack_[2].value.statementListNode), (yystack_[1].value.elseifListNode)); }
#line 1233 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 98: // elseif_statment_list: elseif_statment
#line 425 "parser.y"
                     {(yylhs.value.elseifListNode) = new ListNode<ElseIfNode>((yystack_[0].value.elseif_stmNode));}
#line 1239 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 99: // elseif_statment_list: elseif_statment_list elseif_statment
#line 426 "parser.y"
                                           {(yystack_[1].value.elseifListNode)->push_back((yystack_[0].value.elseif_stmNode));}
#line 1245 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 100: // elseif_statment: ELSE function_body
#line 430 "parser.y"
                        { (yylhs.value.elseif_stmNode) = new ElseIfNode((yystack_[0].value.statementListNode)); }
#line 1251 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 101: // elseif_statment: ELSEIF expression THEN function_body
#line 431 "parser.y"
                                           { (yylhs.value.elseif_stmNode) = new ElseIfNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 1257 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 102: // variable_declaration: scope1 Type var_expression SEMICOLON
#line 436 "parser.y"
                                          { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.idenNode),(yystack_[1].value.pNode),loc);}
#line 1263 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 103: // variable_declaration: scope_pers Type var_expression SEMICOLON
#line 437 "parser.y"
                                               { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.idenNode),(yystack_[1].value.pNode),loc);}
#line 1269 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 104: // variable_declaration: scope2 Type var_expression SEMICOLON
#line 438 "parser.y"
                                           { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.idenNode),(yystack_[1].value.pNode),loc);}
#line 1275 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 105: // variable_for_body: scope2 Type var_expression SEMICOLON
#line 442 "parser.y"
                                         { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.idenNode),(yystack_[1].value.pNode),loc);}
#line 1281 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 106: // variable_for_body: scope2 Type Identifier ASS expression SEMICOLON
#line 443 "parser.y"
                                                      { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.variableNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),id,(yystack_[1].value.pNode),loc);}
#line 1287 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 107: // variable_for_body: scope2 Type array_index ASS expression SEMICOLON
#line 444 "parser.y"
                                                         { (yylhs.value.variableNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode),loc);}
#line 1293 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 108: // variable_for_body: scope2 Type struct_index ASS expression SEMICOLON
#line 445 "parser.y"
                                                        { (yylhs.value.variableNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode),loc);}
#line 1299 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 109: // var_expression: Identifier
#line 449 "parser.y"
               { (yylhs.value.pNode) = new IdentifierNode((yystack_[0].value.sval)); }
#line 1305 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 110: // var_expression: array_index
#line 450 "parser.y"
                  { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1311 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 111: // var_expression: struct_index
#line 451 "parser.y"
                   {(yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1317 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 112: // var_assignment: scope1 Type Identifier ASS expression SEMICOLON
#line 457 "parser.y"
                                                    { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),id,(yystack_[1].value.pNode),loc);}
#line 1323 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 113: // var_assignment: scope2 Type Identifier ASS expression SEMICOLON
#line 458 "parser.y"
                                                      { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),id,(yystack_[1].value.pNode),loc);}
#line 1329 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 114: // var_assignment: scope_pers Type Identifier ASS expression SEMICOLON
#line 459 "parser.y"
                                                          { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),id,(yystack_[1].value.pNode),loc);}
#line 1335 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 115: // var_assignment: scope1 Type array_index ASS expression SEMICOLON
#line 460 "parser.y"
                                                         { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode),loc);}
#line 1341 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 116: // var_assignment: scope2 Type array_index ASS expression SEMICOLON
#line 461 "parser.y"
                                                         { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode),loc);}
#line 1347 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 117: // var_assignment: scope_pers Type array_index ASS expression SEMICOLON
#line 462 "parser.y"
                                                             { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode),loc);}
#line 1353 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 118: // var_assignment: scope1 Type struct_index ASS expression SEMICOLON
#line 463 "parser.y"
                                                        { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode),loc);}
#line 1359 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 119: // var_assignment: scope2 Type struct_index ASS expression SEMICOLON
#line 464 "parser.y"
                                                        { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode),loc);}
#line 1365 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 120: // var_assignment: scope_pers Type struct_index ASS expression SEMICOLON
#line 465 "parser.y"
                                                            { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.idenNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode),loc);}
#line 1371 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 121: // assignment: var_expression ASS expression
#line 472 "parser.y"
    { 
        (yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.pNode), (yystack_[0].value.pNode));
    }
#line 1379 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 122: // assignment: var_expression ASS expression SEMICOLON
#line 477 "parser.y"
    {
        (yylhs.value.pNode) = new AssignmentNode((yystack_[3].value.pNode), (yystack_[1].value.pNode));
    }
#line 1387 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 123: // dim_num_stm: expression
#line 485 "parser.y"
    {
        (yylhs.value.dim_num_stmNode) = new DimNumsNode((yystack_[0].value.pNode)); 
    }
#line 1395 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 124: // dim_num_stm: dim_num_stm COMMA expression
#line 489 "parser.y"
        {
       (yystack_[2].value.dim_num_stmNode)->push_back((yystack_[0].value.pNode));   
	}
#line 1403 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 125: // struct_index: var_expression DOT Identifier
#line 495 "parser.y"
                                   { IdentifierNode* id = new IdentifierNode((yystack_[0].value.sval));(yylhs.value.pNode) = new StructIndexNode((yystack_[2].value.pNode),id); }
#line 1409 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 126: // array_index: Identifier LBRACE expression RBRACE
#line 499 "parser.y"
                                     {IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new ArrayIndexNode(id, (yystack_[1].value.pNode));}
#line 1415 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 127: // offs_expr: OFFS LC func_call_parameter_list RC
#line 503 "parser.y"
                                     {(yylhs.value.pNode) = new OffsNode((yystack_[1].value.listNode));}
#line 1421 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 128: // reltool_expr: RELTOOl LC func_call_parameter_list RC
#line 507 "parser.y"
                                        {(yylhs.value.pNode) = new RelToolNode((yystack_[1].value.listNode));}
#line 1427 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 129: // op_expr: expression ADD expression
#line 511 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::ADD, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1433 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 130: // op_expr: expression SUB expression
#line 512 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::SUB, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1439 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 131: // op_expr: SUB expression
#line 513 "parser.y"
                               { (yylhs.value.pNode) = new OperatorNode(token::UMINUS, (yystack_[0].value.pNode)); }
#line 1445 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 132: // op_expr: expression MUL expression
#line 514 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::MUL, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1451 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 133: // op_expr: expression LT expression
#line 515 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::LT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1457 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 134: // op_expr: expression GT expression
#line 516 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::GT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1463 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 135: // op_expr: expression GE expression
#line 517 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::GE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1469 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 136: // op_expr: expression LE expression
#line 518 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::LE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1475 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 137: // op_expr: expression NE expression
#line 519 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::NE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1481 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 138: // op_expr: expression EQ expression
#line 520 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::EQ, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1487 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 139: // op_expr: expression AND expression
#line 521 "parser.y"
                             {(yylhs.value.pNode) = new OperatorNode(token::AND, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1493 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 140: // op_expr: expression OR expression
#line 522 "parser.y"
                            {(yylhs.value.pNode) = new OperatorNode(token::OR, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1499 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 141: // op_expr: expression MOD expression
#line 523 "parser.y"
                             {(yylhs.value.pNode) = new OperatorNode(token::MOD, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1505 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 142: // op_expr: NOT expression
#line 526 "parser.y"
                              {(yylhs.value.pNode) = new OperatorNode(token::NOT, (yystack_[0].value.pNode));}
#line 1511 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 143: // op_expr: LC expression RC
#line 527 "parser.y"
                    {(yylhs.value.pNode) = (yylhs.value.pNode) = new OperatorNode(token::LC, (yystack_[1].value.pNode));}
#line 1517 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 144: // inst_expr: inst_modifer
#line 531 "parser.y"
               {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1523 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 145: // inst_expr: inst_modifer ASS String
#line 532 "parser.y"
                             { StringLiteralNode* str = new StringLiteralNode((yystack_[0].value.sval));(yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.pNode),str);}
#line 1529 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 146: // inst_expr: inst_modifer ASS var_expression
#line 534 "parser.y"
 {
        (yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.pNode), (yystack_[0].value.pNode));
 }
#line 1537 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 147: // inst_expr_list: inst_expr
#line 540 "parser.y"
            {(yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.pNode)); }
#line 1543 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 148: // inst_expr_list: inst_expr_list inst_expr
#line 541 "parser.y"
                             { (yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));   }
#line 1549 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 149: // expression: String
#line 546 "parser.y"
        { (yylhs.value.pNode) = new StringLiteralNode((yystack_[0].value.sval));}
#line 1555 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 150: // expression: FNULL
#line 547 "parser.y"
         { (yylhs.value.pNode) = new NullNode();}
#line 1561 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 151: // expression: Number
#line 548 "parser.y"
          {(yylhs.value.pNode) = new NumberLiteralNode((yystack_[0].value.dval)); }
#line 1567 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 152: // expression: LNumber
#line 549 "parser.y"
           {(yylhs.value.pNode) = new Integer((yystack_[0].value.ival)); }
#line 1573 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 153: // expression: FTRUE
#line 550 "parser.y"
         {(yylhs.value.pNode) = new Boolean(1);}
#line 1579 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 154: // expression: FFALSE
#line 551 "parser.y"
          {(yylhs.value.pNode) = new Boolean(0);}
#line 1585 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 155: // expression: var_expression
#line 552 "parser.y"
                  {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1591 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 156: // expression: op_expr
#line 553 "parser.y"
           {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1597 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 157: // expression: offs_expr
#line 554 "parser.y"
            {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1603 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 158: // expression: reltool_expr
#line 555 "parser.y"
                { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1609 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 159: // expression: paramWithMod_stm
#line 557 "parser.y"
                    {(yylhs.value.pNode)=(yystack_[0].value.paramWithModifi);}
#line 1615 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 160: // expression: inst_expr_list
#line 558 "parser.y"
                  {(yylhs.value.pNode)=(yystack_[0].value.listNode);}
#line 1621 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 161: // expression: Identifier LC func_call_parameter_list RC
#line 559 "parser.y"
                                              { (yylhs.value.pNode) = new FunctionCallNode((yystack_[3].value.sval), (yystack_[1].value.listNode));}
#line 1627 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 162: // expression: LR dim_num_stm RR
#line 560 "parser.y"
                      {(yylhs.value.pNode) = (yystack_[1].value.dim_num_stmNode);}
#line 1633 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;

  case 163: // paramWithMod_stm: var_expression inst_expr_list
#line 564 "parser.y"
                                {(yylhs.value.paramWithModifi) = new  ParamWithModifierNode((yystack_[1].value.pNode),(yystack_[0].value.listNode)); }
#line 1639 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"
    break;


#line 1643 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"

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


  const short Parser::yypact_ninf_ = -143;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -91,  -101,    30,   -91,  -143,   193,  -143,  -143,  1147,   -90,
    -143,  -143,  -143,   -82,   -49,   149,  -143,  -143,  1147,  1147,
    1147,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,   -52,  1147,    29,  -143,
    -143,  -143,   -43,   -13,    -8,    98,    31,  1051,  -143,  1063,
      17,    19,   112,   117,    26,    21,   128,   141,    34,    33,
     147,   160,  1063,   143,  -143,  -143,  1147,    60,    90,  -143,
     473,   473,    96,  -143,   473,   473,   473,  -143,   473,   473,
     473,  -143,   473,   473,    91,  -143,    99,  -143,  1063,   282,
     473,  -143,  -143,   166,   168,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,   473,   473,  -143,   473,
    -143,  -143,  -143,  -143,   -45,  -143,   175,   323,  -143,  -143,
    -143,  -143,  -143,  -143,  1201,   547,  -143,   109,  -143,   557,
     567,   577,   596,   606,   622,   687,   714,   282,  -143,  -143,
     473,   424,   473,   473,   122,   126,   473,   138,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   142,   144,   473,   379,  1147,   169,   282,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,   -17,  -143,  -143,   473,
     473,    95,  1121,    53,  -143,   473,   -36,  1201,  -143,   473,
     473,   473,   473,   473,   473,   473,   473,   473,  -143,   473,
     473,   473,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,   222,   229,  -143,   730,   743,   757,   218,   221,    84,
    1121,   212,   767,   779,    85,   103,   104,   124,   136,   158,
     173,   199,   206,   209,   822,   205,   208,   887,  -143,   210,
     161,  -143,  -143,   473,   132,   133,  -143,   473,  -143,   137,
     211,  -143,   243,    28,    28,    92,    28,    -4,    -4,  -143,
      28,    28,   162,   162,  -143,  -143,   282,  -143,  -143,   473,
     473,   473,   473,   473,  -143,   473,   282,   473,   -10,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,    35,    37,   239,   240,   897,
    -143,  -143,  1121,  -143,    24,   907,   917,   930,   940,  1121,
     952,   214,   972,  -143,  -143,   473,  -143,   473,   473,  -143,
     282,   473,  -143,    25,  -143,  -143,  -143,  -143,  -143,   473,
    -143,   282,   962,   982,  1090,  -143,  1100,  -143,  -143,    43,
    -143,  -143,  -143,  -143,   282,   473,  -143,  1111,   282,   225,
    -143
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
      58,    49,    50,    51,    48,    59,     0,     0,   150,     0,
     153,   154,   151,   152,   109,   149,   144,   155,   111,   110,
     157,   158,   156,   147,   160,     0,   159,     0,   125,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    38,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,    42,    66,    43,
      65,    63,    86,    64,    62,    60,     0,    61,   131,     0,
       0,     0,   123,     0,   142,     0,     0,   163,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,   126,   120,   117,   112,   118,   115,   113,   119,
     116,     0,     0,    87,     0,     0,     0,     0,     0,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,    32,    44,     0,     0,     0,   162,     0,   143,     0,
     109,   145,   146,   135,   136,   138,   137,   129,   130,   132,
     133,   134,   139,   140,   141,    33,    41,    96,    88,     0,
       0,     0,     0,     0,    85,     0,    41,     0,     0,    91,
      68,    74,    69,    70,    71,    72,    73,    67,    75,    79,
      84,    81,    82,    76,    46,   109,     0,   111,   110,   121,
     127,   128,   124,   161,     0,     0,     0,     0,     0,    40,
       0,     0,     0,    90,    92,     0,   105,     0,     0,   122,
      41,     0,    95,     0,    98,    77,    78,    80,    83,     0,
      89,    41,     0,     0,     0,   100,     0,    97,    99,     0,
      93,   106,   108,   107,    41,     0,   101,     0,    41,     0,
      94
  };

  const short
  Parser::yypgoto_[] =
  {
    -143,  -143,  -143,   296,  -143,   286,    16,  -143,  -143,   257,
    -143,  -143,    27,  -143,   245,   217,  1029,  -131,  -143,  -143,
    -143,  -142,  -143,  -143,  -143,  -143,    40,  -143,  -143,  -143,
     -14,  -143,  -143,   -42,  -143,  -143,  -143,   -39,   -21,  -143,
    -143,  -143,  -114,   194,   -63,  -143
  };

  const short
  Parser::yydefgoto_[] =
  {
       0,     2,     3,     4,    15,    16,    67,    17,    47,    48,
      18,    19,   165,    21,    68,    69,   219,   166,   167,   168,
     116,   169,   170,   171,   172,   278,   279,   173,   174,   323,
     324,    22,   175,   117,    23,   177,   181,   118,   119,   120,
     121,   122,   123,   124,   220,   126
  };

  const short
  Parser::yytable_[] =
  {
      51,    55,    59,    52,    56,    60,   211,   125,   127,   195,
     188,   129,   130,   131,   185,   132,   133,   134,     1,   135,
     136,    53,    57,    61,    36,   242,     5,   178,   320,   320,
       6,    71,    20,    72,    42,    43,    44,    37,   243,   193,
     194,   195,    20,   182,   183,    38,   184,   176,    39,   189,
     190,   191,   192,    46,   193,   194,   195,   196,   197,   189,
     190,   191,   192,    46,   193,   194,   195,   196,   197,    72,
     267,    72,    70,   188,   313,    45,   277,   212,   214,   215,
     216,    76,    86,    72,    50,   222,   223,    72,    49,    80,
     315,   250,   251,    71,    73,   176,    77,   234,   189,   190,
     237,   192,    71,   193,   194,   195,   196,   197,    81,   201,
      71,    71,   316,   248,    54,   189,   190,   191,   192,    58,
     193,   194,   195,   196,   197,   176,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   304,   262,   263,   264,   321,
     321,   201,   273,   273,   252,   311,   322,   337,    88,    88,
      89,   137,   246,   247,   199,   200,   201,    62,    63,   274,
     280,   273,   273,   345,   199,   200,   201,    74,   189,   190,
     176,   192,    75,   193,   194,   195,   196,   197,   281,   282,
     299,   240,   273,    78,   302,     8,   202,    87,     9,   335,
     273,   273,   300,   301,   273,   273,    79,   303,   296,   283,
     340,   297,    82,   199,   200,   201,   305,   306,   307,   308,
     309,   284,   310,   346,   312,    83,   273,   349,    85,   298,
     199,   200,   201,   128,   176,   179,   138,   180,    10,     8,
     186,   273,     9,   285,   176,   189,   190,   191,   192,   140,
     193,   194,   195,   196,   197,   141,    11,    12,   286,   217,
     266,   265,   332,   218,   333,   334,    40,   273,   336,    13,
     142,   143,   144,   145,   273,   221,   339,   273,   273,   235,
     146,   236,    10,    14,   287,   201,   271,   241,   176,   272,
     291,   288,   347,   292,   289,   294,   275,    71,   295,   176,
      11,    12,   140,    72,   317,   318,   330,   350,   141,     7,
     147,    41,   176,    13,    65,   139,   176,    84,    10,   338,
     148,   187,   149,   142,   143,   144,   145,    14,   314,     0,
       0,     0,     0,   146,     0,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
     199,   200,   201,   158,     0,   159,   160,   161,   162,     0,
      91,    92,   163,   147,     0,     0,   164,     0,     0,     0,
       0,    10,     0,   148,     0,   149,    95,    96,    97,    98,
      99,   100,   101,    72,   102,   103,   104,   105,     0,     0,
       0,   150,   151,   152,   153,   154,   155,   156,   157,     0,
       0,    90,     0,     0,     0,     0,   158,     0,   159,   160,
     161,   162,     0,     0,     0,   163,    91,    92,     0,   164,
       0,     0,     0,     0,    93,     0,     0,    94,     0,     0,
       0,     0,    95,    96,    97,    98,    99,   100,   101,     0,
     102,   103,   104,   105,     0,   106,    90,     0,   107,     0,
       0,     0,     0,   108,     0,   109,     0,     0,   110,   111,
       0,    91,    92,     0,   238,    71,     0,     0,     0,    93,
       0,     0,    94,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,     0,   102,   103,   104,   105,     0,
     106,     0,     0,   107,     0,    90,     0,     0,   108,     0,
     109,     0,     0,   110,   111,     0,     0,     0,     0,   213,
      91,    92,     0,     0,   112,   113,   114,   115,    93,     0,
       0,    94,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,     0,   102,   103,   104,   105,     0,   106,
       0,     0,   107,     0,     0,     0,     0,   108,     0,   109,
       0,     0,   110,   111,     0,     0,     0,     0,     0,   112,
     113,   114,   115,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,     0,     0,     0,     0,     0,   112,   113,
     114,   115,   189,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   189,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   203,   193,   194,   195,   196,   197,     0,     0,
       0,     0,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,     0,     0,     0,     0,     0,   199,   200,
     201,     0,     0,     0,     0,     0,     0,     0,   199,   200,
     201,   206,     0,     0,     0,     0,     0,     0,   199,   200,
     201,   207,     0,     0,     0,     0,     0,     0,   199,   200,
     201,     0,     0,   189,   190,   191,   192,   208,   193,   194,
     195,   196,   197,     0,     0,     0,     0,   199,   200,   201,
       0,     0,     0,     0,     0,     0,     0,   199,   200,   201,
     189,   190,   191,   192,     0,   193,   194,   195,   196,   197,
       0,     0,     0,   199,   200,   201,   189,   190,   191,   192,
       0,   193,   194,   195,   196,   197,     0,     0,     0,   189,
     190,   191,   192,     0,   193,   194,   195,   196,   197,     0,
       0,     0,   209,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,     0,     0,   189,   190,   191,   192,   210,
     193,   194,   195,   196,   197,     0,     0,     0,   199,   200,
     201,   269,     0,     0,     0,   268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   200,   201,   189,   190,
     191,   192,     0,   193,   194,   195,   196,   197,     0,     0,
       0,   199,   200,   201,     0,     0,     0,   276,     0,     0,
       0,     0,     0,     0,   199,   200,   201,     0,     0,     0,
       0,     0,     0,     0,     0,   277,     0,     0,   199,   200,
     201,     0,     0,     0,     0,     0,     0,     0,   199,   200,
     201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,   200,   201,   189,   190,   191,   192,   290,   193,   194,
     195,   196,   197,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   199,   200,   201,   189,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   189,   190,   191,   192,
       0,   193,   194,   195,   196,   197,     0,     0,   189,   190,
     191,   192,   293,   193,   194,   195,   196,   197,   189,   190,
     191,   192,   319,   193,   194,   195,   196,   197,   189,   190,
     191,   192,   325,   193,   194,   195,   196,   197,   189,   190,
     191,   192,   326,   193,   194,   195,   196,   197,   199,   200,
     201,     0,     0,     0,     0,   327,     0,     0,   199,   200,
     201,     0,     0,     0,     0,   328,     0,     0,   199,   200,
     201,     0,     0,     0,     0,   329,     0,     0,   199,   200,
     201,     0,     0,     0,     0,   331,     0,   341,     0,     0,
       0,   199,   200,   201,     0,     0,     0,     0,     0,     0,
       0,   199,   200,   201,     0,     0,     0,   342,     0,     0,
       0,     0,     0,   199,   200,   201,     0,     0,     0,     0,
       0,     0,     0,   199,   200,   201,    24,    25,     0,     0,
       0,     0,     0,   199,   200,   201,     0,     0,    24,    25,
       0,    64,     0,   199,   200,   201,   189,   190,   191,   192,
      66,   193,   194,   195,   196,   197,   189,   190,   191,   192,
       0,   193,   194,   195,   196,   197,     0,   189,   190,   191,
     192,   344,   193,   194,   195,   196,   197,   189,   190,   191,
     192,     0,   193,   194,   195,   196,   197,     0,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,     0,     0,     0,   343,     0,     0,     0,     0,
       0,     0,    24,    25,     0,     0,     0,     0,    35,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,     0,
      35,   348,     0,   239,     0,     0,     0,     0,     0,     0,
       0,   199,   200,   201,     0,     0,     0,     0,   244,   245,
       0,   199,   200,   201,   249,     0,     0,     0,     0,     0,
       0,     0,   199,   200,   201,     0,     0,     0,    91,    92,
       0,     0,   199,   200,   201,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    95,    96,    97,    98,    99,   100,
     101,     0,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35
  };

  const short
  Parser::yycheck_[] =
  {
      42,    43,    44,    42,    43,    44,   137,    70,    71,    13,
     124,    74,    75,    76,    59,    78,    79,    80,   109,    82,
      83,    42,    43,    44,     8,   167,   127,    90,     4,     4,
       0,    76,     5,    50,    18,    19,    20,   127,    55,    11,
      12,    13,    15,   106,   107,   127,   109,    89,    97,     6,
       7,     8,     9,    37,    11,    12,    13,    14,    15,     6,
       7,     8,     9,    47,    11,    12,    13,    14,    15,    50,
     212,    50,    55,   187,    84,   127,    86,   140,   141,   142,
     143,    55,    66,    50,   127,   148,   149,    50,    59,    55,
      55,   127,   128,    76,    75,   137,    75,   160,     6,     7,
     163,     9,    76,    11,    12,    13,    14,    15,    75,   113,
      76,    76,    75,    60,   127,     6,     7,     8,     9,   127,
      11,    12,    13,    14,    15,   167,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   266,   199,   200,   201,   115,
     115,   113,    58,    58,   186,   276,   122,   122,    58,    58,
      60,    60,    57,    58,   111,   112,   113,    59,   127,    75,
      75,    58,    58,   120,   111,   112,   113,    55,     6,     7,
     212,     9,    55,    11,    12,    13,    14,    15,    75,    75,
     243,   165,    58,    55,   247,    36,    77,   127,    39,   320,
      58,    58,    60,    60,    58,    58,    55,    60,   240,    75,
     331,   240,    55,   111,   112,   113,   269,   270,   271,   272,
     273,    75,   275,   344,   277,    55,    58,   348,    75,   240,
     111,   112,   113,   127,   266,    59,   127,    59,    79,    36,
      55,    58,    39,    75,   276,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    97,    98,    75,   127,
      21,    29,   315,   127,   317,   318,   107,    58,   321,   110,
      31,    32,    33,    34,    58,   127,   329,    58,    58,   127,
      41,   127,    79,   124,    75,   113,    58,   108,   320,    58,
      75,    75,   345,    75,    75,    75,    74,    76,   127,   331,
      97,    98,    10,    50,    55,    55,    82,    72,    16,     3,
      71,    15,   344,   110,    47,    88,   348,    62,    79,   323,
      81,   117,    83,    31,    32,    33,    34,   124,   278,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,    -1,   116,   117,   118,   119,    -1,
      27,    28,   123,    71,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    79,    -1,    81,    -1,    83,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    99,   100,   101,   102,   103,   104,   105,   106,    -1,
      -1,    12,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    27,    28,    -1,   127,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    52,    53,    54,    -1,    56,    12,    -1,    59,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    69,    70,
      -1,    27,    28,    -1,    75,    76,    -1,    -1,    -1,    35,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    -1,
      56,    -1,    -1,    59,    -1,    12,    -1,    -1,    64,    -1,
      66,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    75,
      27,    28,    -1,    -1,   125,   126,   127,   128,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    52,    53,    54,    -1,    56,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    66,
      -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    75,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    75,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    75,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    75,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,    -1,     6,     7,     8,     9,    75,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    -1,   111,   112,   113,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    75,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    -1,    -1,     6,     7,     8,     9,    75,
      11,    12,    13,    14,    15,    -1,    -1,    -1,   111,   112,
     113,    58,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    -1,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,     6,     7,     8,     9,    75,    11,    12,
      13,    14,    15,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,   111,   112,   113,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,    -1,     6,     7,
       8,     9,    75,    11,    12,    13,    14,    15,     6,     7,
       8,     9,    75,    11,    12,    13,    14,    15,     6,     7,
       8,     9,    75,    11,    12,    13,    14,    15,     6,     7,
       8,     9,    75,    11,    12,    13,    14,    15,   111,   112,
     113,    -1,    -1,    -1,    -1,    75,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    75,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    73,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    63,    -1,    75,    -1,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    25,    26,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    -1,    -1,    25,    26,
      -1,    40,    -1,   111,   112,   113,     6,     7,     8,     9,
      37,    11,    12,    13,    14,    15,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,     6,     7,     8,
       9,    21,    11,    12,    13,    14,    15,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,   127,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    -1,
     127,    80,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    -1,   179,   180,
      -1,   111,   112,   113,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,    -1,    27,    28,
      -1,    -1,   111,   112,   113,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,   109,   130,   131,   132,   127,     0,   132,    36,    39,
      79,    97,    98,   110,   124,   133,   134,   136,   139,   140,
     141,   142,   160,   163,    25,    26,    88,    89,    90,    91,
      92,    93,    94,    95,    96,   127,   135,   127,   127,    97,
     107,   134,   135,   135,   135,   127,   135,   137,   138,    59,
     127,   162,   166,   167,   127,   162,   166,   167,   127,   162,
     166,   167,    59,   127,    40,   138,    37,   135,   143,   144,
      55,    76,    50,    75,    55,    55,    55,    75,    55,    55,
      55,    75,    55,    55,   143,    75,   135,   127,    58,    60,
      12,    27,    28,    35,    38,    43,    44,    45,    46,    47,
      48,    49,    51,    52,    53,    54,    56,    59,    64,    66,
      69,    70,   125,   126,   127,   128,   149,   162,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   173,   127,   173,
     173,   173,   173,   173,   173,   173,   173,    60,   127,   144,
      10,    16,    31,    32,    33,    34,    41,    71,    81,    83,
      99,   100,   101,   102,   103,   104,   105,   106,   114,   116,
     117,   118,   119,   123,   127,   141,   146,   147,   148,   150,
     151,   152,   153,   156,   157,   161,   162,   164,   173,    59,
      59,   165,   173,   173,   173,    59,    55,   172,   171,     6,
       7,     8,     9,    11,    12,    13,    14,    15,    75,   111,
     112,   113,    77,    75,    75,    75,    75,    75,    75,    75,
      75,   146,   173,    75,   173,   173,   173,   127,   127,   145,
     173,   127,   173,   173,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   173,   127,   127,   173,    75,   145,
     135,   108,   150,    55,   145,   145,    57,    58,    60,   145,
     127,   128,   162,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,    29,    21,   150,    75,    58,
      58,    58,    58,    58,    75,    74,    80,    86,   154,   155,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,   127,   162,   166,   167,   173,
      60,    60,   173,    60,   146,   173,   173,   173,   173,   173,
     173,   146,   173,    84,   155,    55,    75,    55,    55,    75,
       4,   115,   122,   158,   159,    75,    75,    75,    75,    73,
      82,    63,   173,   173,   173,   146,   173,   122,   159,   173,
     146,    75,    75,    75,    21,   120,   146,   173,    80,   146,
      72
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,   129,   130,   131,   131,   132,   133,   133,   134,   134,
     134,   134,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   136,   137,   137,   138,   139,   140,
     140,   141,   142,   142,   143,   143,   143,   144,   144,   145,
     145,   146,   146,   147,   147,   148,   148,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   151,   151,   152,
     153,   154,   154,   155,   156,   157,   157,   157,   158,   158,
     159,   159,   160,   160,   160,   161,   161,   161,   161,   162,
     162,   162,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   164,   164,   165,   165,   166,   167,   168,   169,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   171,   171,   171,   172,   172,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   174
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
       3,     3,     2,     3,     1,     3,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     2
  };


#if D_YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "DIVIDE", "ELSE",
  "PREFIX", "GE", "LE", "EQ", "NE", "IF", "ADD", "SUB", "MUL", "LT", "GT",
  "RETURN", "NumberType", "TextType", "VoidType", "SPACE", "THEN", "JIN",
  "DOLAR", "RAPID_NAN", "SEAMDATA", "WELDDATA", "INPOS", "CONC", "ENDFUNC",
  "UMINUS", "ACCSET", "VELSET", "SETDO", "WAITDI", "OFFS", "FUNC", "INOUT",
  "RELTOOl", "RECORD", "ENDRECORD", "PULSEDO", "WAITTIME_INPOS", "WOBJ_P",
  "SEAM_NAME", "ZONE_P", "VEL_P", "TCP_P", "NOEOFFS", "PLEN", "DOT",
  "MAXTIME", "TIMEFLAG", "TOOL_P", "ID_P", "ASS", "LR", "RR", "COMMA",
  "LC", "RC", "LESS", "GREATER", "COLON", "FNULL", "DEVCOLON", "NOT",
  "UNINDENT", "INDENT", "FTRUE", "FFALSE", "FOR", "ENDFOR", "TO", "FROM",
  "SEMICOLON", "LBRACE", "RBRACE", "LMOVE", "VAR", "DO", "WHILE",
  "ENDWHILE", "TEST", "ENDTEST", "RETRY", "CASE", "DEFAULT", "JOINTTARGET",
  "ROBTARGET", "STRING", "NUM", "BOOL", "WOBJDATA", "ZONEDATA",
  "SPEEDDATA", "TOOLDATA", "PERS", "CONST_L", "ACTUNIT", "MOVEABSJ",
  "ARCLSTART", "ARCL", "ARCC", "ARCEND", "MOVEL", "MOVEJ", "ENDMODULE",
  "ENDPROC", "MODULE", "PROC", "AND", "OR", "MOD", "DEACTUNIT", "ELSEIF",
  "WAITTIME", "WAITUNTIL", "SET", "RESET", "STEP", "ARCCEND", "ENDIF",
  "TPWRITE", "TASK", "Number", "LNumber", "Identifier", "String",
  "$accept", "program", "module_list", "module", "declaration_list",
  "declaration", "Type", "Record_declare", "struct_members", "var_decl",
  "scope_pers", "scope1", "scope2", "function_declaration",
  "parameter_declaration_list", "parameter_declaration",
  "func_call_parameter_list", "function_body", "statement_list",
  "function_call", "inst_modifer", "statement", "return", "while_loop",
  "switch", "switch_case_list", "switch_case_define", "for", "if",
  "elseif_statment_list", "elseif_statment", "variable_declaration",
  "variable_for_body", "var_expression", "var_assignment", "assignment",
  "dim_num_stm", "struct_index", "array_index", "offs_expr",
  "reltool_expr", "op_expr", "inst_expr", "inst_expr_list", "expression",
  "paramWithMod_stm", YY_NULLPTR
  };
#endif


#if D_YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   207,   207,   211,   212,   216,   221,   222,   226,   227,
     228,   229,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   247,   251,   252,   255,   259,   263,
     265,   269,   277,   278,   282,   283,   284,   288,   289,   298,
     302,   317,   318,   322,   323,   328,   329,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   379,   380,   384,
     388,   396,   401,   408,   415,   419,   420,   421,   425,   426,
     430,   431,   436,   437,   438,   442,   443,   444,   445,   449,
     450,   451,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   471,   476,   484,   488,   495,   499,   503,   507,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   526,   527,   531,   532,   533,   540,   541,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   557,
     558,   559,   560,   564
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
     125,   126,   127,   128
    };
    // Last valid token kind.
    const int code_max = 383;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 15 "parser.y"
} // Language
#line 2605 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp"

#line 567 "parser.y"



static int yylex( Language::Parser::semantic_type *yylval,Language::location* loc,Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval,loc) );
}
void Language::Parser::error( const Language::location& location,const std::string &err_message )
{

    char format_str[128] = { 0 };
	snprintf(format_str, sizeof(format_str) - 1, "error parsed %s(%s)at %d.%d-%d.%d: %s\n",loc.end.filename->c_str(), err_message.c_str(),loc.begin.line, loc.begin.column, loc.end.line, loc.end.column,cur_yytext.c_str());
    
    err=std::string(format_str);
    printf("%s",format_str);   
}
