// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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


// First part of user declarations.

#line 37 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "parser.tab.hpp"

// User implementation prologue.

#line 51 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:406
// Unqualified %code blocks.
#line 57 "parser.y" // lalr1.cc:407

    #include "translator.hpp"
    #include "ast.h"

    
    extern int lineNumber;
    static int yylex(Language::Parser::semantic_type *yylval, Language::Lexer  &lexer);

#line 62 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:407


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



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.y" // lalr1.cc:473
namespace Language {
#line 129 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:473

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
        std::string yyr = "";
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
              // Fall through.
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


  /// Build a parser object.
  Parser::Parser (Lexer  &lexer_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
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
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, lexer));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* If YYLEN is nonzero, implement the default value of the action:
       '$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYLHS.VALUE to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yylhs.value = yystack_[yylen - 1].value;
    else
      yylhs.value = yystack_[0].value;


    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    try
      {
        switch (yyn)
          {
  case 2:
#line 130 "parser.y" // lalr1.cc:846
    {}
#line 563 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 3:
#line 134 "parser.y" // lalr1.cc:846
    {(yylhs.value.moduleListNode) = new ListNode<ModuleNode>((yystack_[0].value.moduleNode));}
#line 569 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 4:
#line 135 "parser.y" // lalr1.cc:846
    {(yystack_[1].value.moduleListNode)->push_back((yystack_[0].value.moduleNode));}
#line 575 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 5:
#line 139 "parser.y" // lalr1.cc:846
    {(yylhs.value.moduleNode) = new ModuleNode((yystack_[2].value.sval),(yystack_[1].value.listNode));}
#line 581 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 6:
#line 144 "parser.y" // lalr1.cc:846
    {(yylhs.value.listNode) = new DeclareListNode((yystack_[0].value.pNode));}
#line 587 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 7:
#line 145 "parser.y" // lalr1.cc:846
    {(yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));}
#line 593 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 8:
#line 148 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode)=(yystack_[0].value.variableNode);}
#line 599 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 9:
#line 149 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode)=(yystack_[0].value.functionNode);}
#line 605 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 10:
#line 152 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) = NUM;}
#line 611 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 11:
#line 153 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) = eBOOL;}
#line 617 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 12:
#line 154 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) = eSTRING;}
#line 623 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 13:
#line 155 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) = ROBTARGET;}
#line 629 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 14:
#line 156 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) = JOINTTARGET;}
#line 635 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 15:
#line 157 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) = WOBJDATA;}
#line 641 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 16:
#line 158 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) = ZONEDATA;}
#line 647 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 17:
#line 159 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) = SPEEDDATA;}
#line 653 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 18:
#line 160 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) = TOOLDATA;}
#line 659 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 19:
#line 161 "parser.y" // lalr1.cc:846
    {(yylhs.value.ival) = SEAMDATA;}
#line 665 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 20:
#line 162 "parser.y" // lalr1.cc:846
    {(yylhs.value.ival)= WELDDATA;}
#line 671 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 21:
#line 166 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) =  PERS;}
#line 677 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 22:
#line 168 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) =  TASK_PERS;}
#line 683 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 23:
#line 172 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) = eCONST;}
#line 689 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 24:
#line 174 "parser.y" // lalr1.cc:846
    { (yylhs.value.ival) =  VAR;}
#line 695 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 25:
#line 182 "parser.y" // lalr1.cc:846
    {(yylhs.value.functionNode) = new FunctionNode(token::VoidType, (yystack_[5].value.sval), (yystack_[3].value.parameterListNode), (yystack_[1].value.statementListNode)); }
#line 701 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 26:
#line 186 "parser.y" // lalr1.cc:846
    { (yylhs.value.parameterListNode) = new ListNode<ParameterNode>((yystack_[0].value.parameterNode)); }
#line 707 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 27:
#line 187 "parser.y" // lalr1.cc:846
    {(yystack_[2].value.parameterListNode)->push_back((yystack_[0].value.parameterNode));}
#line 713 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 28:
#line 188 "parser.y" // lalr1.cc:846
    {(yylhs.value.parameterListNode) = new ListNode<ParameterNode>();}
#line 719 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 29:
#line 192 "parser.y" // lalr1.cc:846
    {(yylhs.value.parameterNode) = new ParameterNode((yystack_[0].value.sval));}
#line 725 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 30:
#line 193 "parser.y" // lalr1.cc:846
    {(yylhs.value.parameterNode) = new ParameterNode((yystack_[0].value.sval));}
#line 731 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 31:
#line 197 "parser.y" // lalr1.cc:846
    {(yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.pNode)); }
#line 737 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 32:
#line 198 "parser.y" // lalr1.cc:846
    {(yystack_[2].value.listNode)->push_back((yystack_[0].value.pNode));}
#line 743 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 33:
#line 199 "parser.y" // lalr1.cc:846
    {(yylhs.value.listNode) = new ListNode<ASTNode>();}
#line 749 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 34:
#line 203 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ParamNode((yystack_[0].value.sval));}
#line 755 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 35:
#line 204 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ParamNode((yystack_[1].value.sval),(yystack_[0].value.listNode));}
#line 761 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 36:
#line 207 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 767 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 37:
#line 211 "parser.y" // lalr1.cc:846
    { (yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.pNode)); }
#line 773 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 38:
#line 212 "parser.y" // lalr1.cc:846
    { (yylhs.value.listNode)->push_back((yystack_[0].value.pNode)); }
#line 779 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 39:
#line 213 "parser.y" // lalr1.cc:846
    {(yylhs.value.listNode) = new ListNode<ASTNode>();}
#line 785 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 40:
#line 216 "parser.y" // lalr1.cc:846
    {(yylhs.value.statementListNode)=NULL;}
#line 791 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 41:
#line 217 "parser.y" // lalr1.cc:846
    {(yylhs.value.statementListNode) = (yystack_[0].value.statementListNode);}
#line 797 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 42:
#line 221 "parser.y" // lalr1.cc:846
    {(yylhs.value.statementListNode) = new StatementListNode((yystack_[0].value.pNode));}
#line 803 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 43:
#line 222 "parser.y" // lalr1.cc:846
    {(yystack_[1].value.statementListNode)->push_back((yystack_[0].value.pNode));}
#line 809 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 44:
#line 227 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new FunctionCallNode((yystack_[4].value.sval), (yystack_[2].value.listNode));}
#line 815 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 45:
#line 228 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new FunctionCallNode((yystack_[1].value.sval), new ListNode<ASTNode>());}
#line 821 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 46:
#line 232 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.parameterNode);}
#line 827 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 47:
#line 233 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 833 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 48:
#line 234 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 839 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 49:
#line 235 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 845 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 50:
#line 236 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 851 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 51:
#line 237 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 857 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 52:
#line 238 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 863 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 53:
#line 239 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new MoveJNode((yystack_[1].value.listNode));}
#line 869 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 54:
#line 240 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ActUnitNode((yystack_[1].value.listNode));}
#line 875 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 55:
#line 241 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ArcLStartNode((yystack_[1].value.listNode));}
#line 881 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 56:
#line 242 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ArcLNode((yystack_[1].value.listNode));}
#line 887 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 57:
#line 243 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ArccNode((yystack_[1].value.listNode));}
#line 893 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 58:
#line 244 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ArcEndNode((yystack_[1].value.listNode));}
#line 899 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 59:
#line 245 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new MoveLNode((yystack_[1].value.listNode));}
#line 905 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 60:
#line 246 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new MoveABSJNode((yystack_[1].value.listNode));}
#line 911 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 61:
#line 247 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new DeActUnitNode((yystack_[1].value.listNode));}
#line 917 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 62:
#line 248 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new TpWriteNode((yystack_[1].value.pNode));}
#line 923 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 63:
#line 249 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 929 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 64:
#line 253 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ReturnNode(NULL); }
#line 935 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 65:
#line 257 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new WhileNode((yystack_[3].value.pNode), (yystack_[1].value.statementListNode)); }
#line 941 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 66:
#line 262 "parser.y" // lalr1.cc:846
    {
        (yylhs.value.pNode) = new SWitchNode((yystack_[2].value.pNode),(yystack_[1].value.listNode),NULL);
    }
#line 949 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 67:
#line 270 "parser.y" // lalr1.cc:846
    {
        (yylhs.value.listNode) = new SWitchCaseListNode((yystack_[0].value.pNode));
	}
#line 957 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 68:
#line 275 "parser.y" // lalr1.cc:846
    {
        (yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));   
	}
#line 965 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 69:
#line 282 "parser.y" // lalr1.cc:846
    {
        (yylhs.value.pNode) = new CaseNode((yystack_[2].value.pNode),(yystack_[0].value.statementListNode)); //$$->dimListType->push_back($1);
	}
#line 973 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 70:
#line 288 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new ForNode((yystack_[9].value.sval),(yystack_[7].value.pNode),(yystack_[5].value.pNode),(yystack_[3].value.pNode));}
#line 979 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 71:
#line 292 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IfNode((yystack_[3].value.pNode), (yystack_[1].value.statementListNode)); }
#line 985 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 72:
#line 293 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IfNode((yystack_[4].value.pNode), (yystack_[2].value.statementListNode), (yystack_[1].value.elseifListNode)); }
#line 991 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 73:
#line 297 "parser.y" // lalr1.cc:846
    {(yylhs.value.elseifListNode) = new ListNode<ElseIfNode>((yystack_[0].value.elseif_stmNode));}
#line 997 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 74:
#line 298 "parser.y" // lalr1.cc:846
    {(yystack_[1].value.elseifListNode)->push_back((yystack_[0].value.elseif_stmNode));}
#line 1003 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 75:
#line 302 "parser.y" // lalr1.cc:846
    { (yylhs.value.elseif_stmNode) = new ElseIfNode((yystack_[0].value.statementListNode)); }
#line 1009 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 76:
#line 303 "parser.y" // lalr1.cc:846
    { (yylhs.value.elseif_stmNode) = new ElseIfNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 1015 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 77:
#line 307 "parser.y" // lalr1.cc:846
    {(yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.ival),(yystack_[1].value.pNode));}
#line 1021 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 78:
#line 308 "parser.y" // lalr1.cc:846
    {(yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.ival),(yystack_[1].value.pNode));}
#line 1027 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 79:
#line 309 "parser.y" // lalr1.cc:846
    {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval)); (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.ival),id);}
#line 1033 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 80:
#line 310 "parser.y" // lalr1.cc:846
    {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval)); (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.ival),id);}
#line 1039 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 81:
#line 311 "parser.y" // lalr1.cc:846
    {IdentifierNode* id = new IdentifierNode((yystack_[4].value.sval)); (yylhs.value.variableNode) = new VariableNode((yystack_[6].value.ival),(yystack_[5].value.ival),id,(yystack_[2].value.dim_num_stmNode));}
#line 1045 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 82:
#line 312 "parser.y" // lalr1.cc:846
    {IdentifierNode* id = new IdentifierNode((yystack_[4].value.sval)); (yylhs.value.variableNode) = new VariableNode((yystack_[6].value.ival),(yystack_[5].value.ival),id,(yystack_[2].value.dim_num_stmNode));}
#line 1051 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 83:
#line 318 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.sval), (yystack_[0].value.pNode));}
#line 1057 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 84:
#line 321 "parser.y" // lalr1.cc:846
    { 
        (yylhs.value.pNode) = new AssignmentNode((yystack_[5].value.sval), (yystack_[0].value.pNode), (yystack_[3].value.dim_num_stmNode));
    }
#line 1065 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 85:
#line 325 "parser.y" // lalr1.cc:846
    { 
        (yylhs.value.pNode) = new AssignmentNode((yystack_[4].value.sval), (yystack_[1].value.dim_num_stmNode));
    }
#line 1073 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 86:
#line 330 "parser.y" // lalr1.cc:846
    { 
        (yylhs.value.pNode) = new AssignmentNode((yystack_[7].value.sval), (yystack_[1].value.dim_num_stmNode) , (yystack_[5].value.dim_num_stmNode));
    }
#line 1081 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 87:
#line 336 "parser.y" // lalr1.cc:846
    {
        (yylhs.value.dim_num_stmNode) = new DimNumsNode((yystack_[0].value.pNode)); 
    }
#line 1089 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 88:
#line 340 "parser.y" // lalr1.cc:846
    {
        (yystack_[2].value.dim_num_stmNode)->push_back((yystack_[0].value.pNode));   
	}
#line 1097 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 89:
#line 346 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode)=NULL;}
#line 1103 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 90:
#line 347 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IdentifierNode((yystack_[0].value.sval)); }
#line 1109 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 91:
#line 348 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new NumberLiteralNode(9e9);}
#line 1115 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 92:
#line 349 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new StringLiteralNode((yystack_[0].value.sval));}
#line 1121 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 93:
#line 350 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new NullNode();}
#line 1127 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 94:
#line 351 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new NumberLiteralNode((yystack_[0].value.dval)); }
#line 1133 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 95:
#line 352 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new NumberLiteralNode(1);}
#line 1139 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 96:
#line 353 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new NumberLiteralNode(0);}
#line 1145 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 97:
#line 354 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::ADD, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1151 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 98:
#line 355 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::SUB, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1157 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 99:
#line 356 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::MUL, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1163 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 100:
#line 357 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::LT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1169 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 101:
#line 358 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::GT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1175 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 102:
#line 359 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::GE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1181 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 103:
#line 360 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::LE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1187 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 104:
#line 361 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::NE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1193 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 105:
#line 362 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::EQ, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1199 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 106:
#line 363 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new OperatorNode(token::AND, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1205 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 107:
#line 364 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new OperatorNode(token::OR, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1211 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 108:
#line 365 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new OperatorNode(token::MOD, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1217 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 109:
#line 366 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::UMINUS, (yystack_[0].value.pNode)); }
#line 1223 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 110:
#line 367 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ArrayDataNode((yystack_[1].value.pNode));}
#line 1229 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 111:
#line 368 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ArrayDataNode((yystack_[1].value.dim_num_stmNode));}
#line 1235 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
    break;


#line 1239 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:846
          default:
            break;
          }
      }
    catch (const syntax_error& yyexc)
      {
        error (yyexc);
        YYERROR;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yylhs);
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    // Shift the result of the reduction.
    yypush_ (YY_NULL, yylhs);
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -73;

  const signed char Parser::yytable_ninf_ = -112;

  const short int
  Parser::yypact_[] =
  {
     -72,   -58,    49,   -72,   -73,   356,   -73,   -73,   -73,   -73,
     -73,    -3,    36,    69,   -73,   432,   432,   -73,   -73,    19,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,    20,    53,   419,     1,    77,    24,
     109,   432,    71,    88,   -73,    -7,   -73,    43,   -73,   -73,
      43,   -73,    76,   -73,   419,   116,    43,   -73,    43,   -73,
     -73,   -73,   -73,   -73,   -73,   375,    43,    40,   375,    48,
     -73,   -73,    43,   -73,    86,    43,    43,   102,   102,   102,
     102,   102,   102,   102,   102,   102,    43,   235,   -73,   106,
     116,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,    27,
     -15,   195,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    -6,    43,    83,    95,   214,   158,
     232,   243,   159,   -29,   -73,   -23,    34,    42,    87,   101,
     122,   161,   162,   254,   102,   -73,    43,   -73,   -73,   393,
     -73,    89,    89,    89,    89,    27,    27,   375,   375,   375,
     375,   375,   375,   -73,   375,    63,   -73,   -73,   116,    43,
     116,    43,    21,   -73,   110,   -73,   159,   102,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   125,   115,
      43,   375,    -9,   285,   156,   303,   -73,   -73,   -24,   -73,
     -73,   -73,   174,   190,    94,   116,    43,   -73,     0,   -73,
      43,   -73,   116,   -73,   393,   -73,   339,   -73,   -73,    33,
     -73,   116,    43,   -73,   357,   116,   179,   -73
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,     2,     3,     0,     1,     4,    24,    21,
      23,     0,     0,     0,     6,     0,     0,     9,     8,     0,
      22,     5,     7,    19,    20,    14,    13,    12,    10,    11,
      15,    16,    17,    18,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,    26,    89,    79,    89,    77,    80,
      89,    78,     0,    29,     0,    40,    89,    91,    89,    93,
      95,    96,    94,    90,    92,    83,    89,     0,    87,     0,
      30,    27,    89,    64,     0,    89,    89,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    89,     0,    46,     0,
      41,    52,    42,    51,    49,    63,    50,    48,    47,   109,
       0,    87,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,     0,    89,     0,     0,     0,     0,
       0,     0,    34,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    45,    89,    25,    43,    85,
     110,   102,   103,   105,   104,    97,    98,    99,   100,   101,
     106,   107,   108,   111,    88,    89,    81,    82,    40,    89,
      40,    89,     0,    67,     0,    37,    35,     0,    54,    60,
      55,    56,    57,    58,    59,    53,    61,    62,     0,     0,
      89,    84,     0,     0,     0,     0,    66,    68,     0,    36,
      38,    32,     0,     0,     0,    40,    89,    71,     0,    73,
      89,    65,    40,    44,    86,    75,     0,    72,    74,     0,
      69,    40,    89,    76,     0,    40,     0,    70
  };

  const short int
  Parser::yypgoto_[] =
  {
     -73,   -73,   -73,   223,   -73,   215,    -1,   -73,   -73,   -73,
     -73,   -31,   336,    60,    64,   -73,   -57,   -73,   -73,   141,
     -73,   -73,   -73,   -73,    79,   -73,   -73,   -73,    41,   -73,
     -32,   -49,   -45
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    13,    14,    42,    15,    16,    17,
      43,    88,   123,   124,   165,   166,    89,    90,    91,    92,
      93,    94,    95,   162,   163,    96,    97,   198,   199,    18,
      98,    67,    68
  };

  const short int
  Parser::yytable_[] =
  {
      65,    69,    38,    40,    56,    44,   167,   195,    45,   100,
       1,    99,   167,   101,    34,    35,   195,   114,   168,   139,
     115,   101,    57,    71,   169,   136,    58,   118,   153,   115,
     120,   121,    59,    45,    60,    61,   102,   103,   104,   105,
      52,   133,     5,   106,   107,   108,   109,   110,    46,     6,
      47,   108,   109,   110,    56,    36,    45,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   167,
     154,    49,    57,    50,    56,   115,    66,   167,   186,   196,
     161,   170,    59,   115,    60,    61,   197,   179,   196,   171,
     116,    62,    57,    63,    64,   207,   180,    19,   117,   106,
     107,   182,    59,   184,    60,    61,    20,   108,   109,   110,
     181,   111,   112,   113,   183,   155,   185,   111,   112,   113,
      37,     8,   167,    54,    48,    55,   212,   155,   204,   115,
     156,   194,   189,    72,   172,   101,   167,    73,   205,     9,
      10,    62,   157,    63,    64,   210,    23,    24,   173,    21,
     115,   206,    11,    39,   213,   209,    51,   167,   216,    74,
     167,    62,   192,    63,    64,   193,    12,   214,    41,   174,
      75,    53,    76,   111,   112,   113,    70,    25,    26,    27,
      28,    29,    30,    31,    32,    33,   119,   137,    77,    78,
      79,    80,    81,    82,    83,    84,   167,   167,   102,   103,
     104,   105,   122,    85,   159,   106,   107,   164,   175,   176,
     188,   201,    86,   108,   109,   110,    87,   102,   103,   104,
     105,   203,   155,   217,   106,   107,     7,   191,    22,   140,
     190,   138,   108,   109,   110,   102,   103,   104,   105,   208,
     158,   187,   106,   107,     0,     0,   102,   103,   104,   105,
     108,   109,   110,   106,   107,     0,     0,   102,   103,   104,
     105,   108,   109,   110,   106,   107,     0,    45,     0,     0,
       0,   134,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   135,     0,   136,   160,     0,     0,   102,   103,
     104,   105,     0,     0,     0,   106,   107,     0,   111,   112,
     113,   177,   161,   108,   109,   110,   102,   103,   104,   105,
       0,     0,     0,   106,   107,     0,   111,   112,   113,     0,
       0,   108,   109,   110,     0,     0,     0,   111,   112,   113,
     200,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   202,   102,   103,   104,   105,     0,     0,     0,   106,
     107,     0,     0,     0,     0,     0,     0,   108,   109,   110,
     102,   103,   104,   105,     0,   211,     0,   106,   107,   111,
     112,   113,     0,     0,     0,   108,   109,   110,   102,   103,
     104,   105,     0,     0,     0,   106,   107,   111,   112,   113,
       0,     0,     0,   108,   109,   110,  -111,  -111,  -111,  -111,
       0,     0,     0,  -111,  -111,     0,     0,     0,     8,     0,
     215,  -111,  -111,  -111,   125,   126,   127,   128,   129,   130,
     131,   132,     0,   111,   112,   113,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,   111,   112,   113,     0,     0,     0,     0,     0,    23,
      24,     0,     0,    12,     0,     0,     0,     0,     0,   111,
     112,   113,    23,    24,     0,     0,     0,     0,     0,     0,
     178,    41,     0,     0,     0,     0,     0,  -111,  -111,  -111,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,     0,     0,    25,    26,    27,    28,    29,    30,    31,
      32,    33
  };

  const short int
  Parser::yycheck_[] =
  {
      45,    50,    34,    35,    11,    36,    35,    16,    32,    58,
      82,    56,    35,    58,    15,    16,    16,    66,    47,    34,
      35,    66,    29,    54,    47,    49,    33,    72,    34,    35,
      75,    76,    39,    32,    41,    42,     3,     4,     5,     6,
      41,    86,   100,    10,    11,    18,    19,    20,    47,     0,
      49,    18,    19,    20,    11,    36,    32,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    35,
     115,    47,    29,    49,    11,    35,    33,    35,    57,    88,
      59,    47,    39,    35,    41,    42,    95,   136,    88,    47,
      50,    98,    29,   100,   101,    95,    33,   100,    50,    10,
      11,   158,    39,   160,    41,    42,    70,    18,    19,    20,
     155,    84,    85,    86,   159,    32,   161,    84,    85,    86,
     100,    52,    35,    35,    47,    37,    93,    32,    34,    35,
      47,   180,   164,    17,    47,   180,    35,    21,   195,    70,
      71,    98,    47,   100,   101,   202,    30,    31,    47,    80,
      35,   196,    83,   100,   211,   200,    47,    35,   215,    43,
      35,    98,    37,   100,   101,    50,    97,   212,    52,    47,
      54,   100,    56,    84,    85,    86,   100,    61,    62,    63,
      64,    65,    66,    67,    68,    69,   100,    81,    72,    73,
      74,    75,    76,    77,    78,    79,    35,    35,     3,     4,
       5,     6,   100,    87,    46,    10,    11,    48,    47,    47,
     100,    55,    96,    18,    19,    20,   100,     3,     4,     5,
       6,    47,    32,    44,    10,    11,     3,   167,    13,    34,
     166,    90,    18,    19,    20,     3,     4,     5,     6,   198,
      26,   162,    10,    11,    -1,    -1,     3,     4,     5,     6,
      18,    19,    20,    10,    11,    -1,    -1,     3,     4,     5,
       6,    18,    19,    20,    10,    11,    -1,    32,    -1,    -1,
      -1,    36,    18,    19,    20,    -1,    -1,    -1,    -1,    84,
      85,    86,    47,    -1,    49,    53,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    11,    -1,    84,    85,
      86,    47,    59,    18,    19,    20,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    11,    -1,    84,    85,    86,    -1,
      -1,    18,    19,    20,    -1,    -1,    -1,    84,    85,    86,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    38,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
       3,     4,     5,     6,    -1,    26,    -1,    10,    11,    84,
      85,    86,    -1,    -1,    -1,    18,    19,    20,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    11,    84,    85,    86,
      -1,    -1,    -1,    18,    19,    20,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    11,    -1,    -1,    -1,    52,    -1,
      53,    18,    19,    20,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    84,    85,    86,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
     134,    52,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    82,   103,   104,   105,   100,     0,   105,    52,    70,
      71,    83,    97,   106,   107,   109,   110,   111,   131,   100,
      70,    80,   107,    30,    31,    61,    62,    63,    64,    65,
      66,    67,    68,    69,   108,   108,    36,   100,   132,   100,
     132,    52,   108,   112,   113,    32,    47,    49,    47,    47,
      49,    47,   108,   100,    35,    37,    11,    29,    33,    39,
      41,    42,    98,   100,   101,   134,    33,   133,   134,   133,
     100,   113,    17,    21,    43,    54,    56,    72,    73,    74,
      75,    76,    77,    78,    79,    87,    96,   100,   113,   118,
     119,   120,   121,   122,   123,   124,   127,   128,   132,   134,
     133,   134,     3,     4,     5,     6,    10,    11,    18,    19,
      20,    84,    85,    86,   133,    35,    50,    50,   134,   100,
     134,   134,   100,   114,   115,   114,   114,   114,   114,   114,
     114,   114,   114,   134,    36,    47,    49,    81,   121,    34,
      34,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,    34,   134,    32,    47,    47,    26,    46,
      53,    59,   125,   126,    48,   116,   117,    35,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,   114,   133,
      33,   134,   118,   134,   118,   134,    57,   126,   100,   132,
     116,   115,    37,    50,   133,    16,    88,    95,   129,   130,
      45,    55,    38,    47,    34,   118,   134,    95,   130,   134,
     118,    26,    93,   118,   134,    53,   118,    44
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,   102,   103,   104,   104,   105,   106,   106,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   110,   110,   111,   112,   112,   112,   113,
     113,   114,   114,   114,   115,   115,   116,   117,   117,   117,
     118,   118,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   122,   123,   124,   125,   125,   126,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   131,
     131,   131,   131,   132,   132,   132,   132,   133,   133,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     7,     1,     3,     0,     2,
       3,     1,     3,     0,     1,     2,     2,     1,     2,     0,
       0,     1,     1,     2,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     5,     4,     1,     2,     4,
      11,     5,     6,     1,     2,     2,     4,     4,     4,     4,
       4,     7,     7,     3,     6,     5,     8,     1,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "GE", "LE", "EQ", "NE",
  "GREATER", "LESS", "MINUS", "ADD", "SUB", "MULTIP", "DEVIDE", "UMINUS",
  "IFX", "ELSE", "IF", "MUL", "LT", "GT", "RETURN", "NumberType",
  "TextType", "VoidType", "SPACE", "THEN", "JIN", "DOLAR", "RAPID_NAN",
  "SEAMDATA", "WELDDATA", "ASS", "LR", "RR", "COMMA", "LC", "RC", "COLON",
  "FNULL", "DEVCOLON", "FTRUE", "FFALSE", "FOR", "ENDFOR", "TO", "FROM",
  "SEMICOLON", "SPLASH", "LBRACE", "RBRACE", "LMOVE", "VAR", "DO", "WHILE",
  "ENDWHILE", "TEST", "ENDTEST", "RETRY", "CASE", "DEFAULT", "JOINTTARGET",
  "ROBTARGET", "STRING", "NUM", "BOOL", "WOBJDATA", "ZONEDATA",
  "SPEEDDATA", "TOOLDATA", "PERS", "CONST", "ACTUNIT", "MOVEABSJ",
  "ARCLSTART", "ARCL", "ARCC", "ARCEND", "MOVEL", "MOVEJ", "ENDMODULE",
  "ENDPROC", "MODULE", "PROC", "AND", "OR", "MOD", "DEACTUNIT", "ELSEIF",
  "WAITTIME", "WAITUNTIL", "SET", "RESET", "STEP", "ARCCEND", "ENDIF",
  "TPWRITE", "TASK", "Number", "LNumber", "Identifier", "String",
  "$accept", "program", "module_list", "module", "declaration_list",
  "declaration", "Type", "scope", "modifiability", "function_declaration",
  "parameter_declaration_list", "parameter_declaration",
  "func_call_parameter_list", "func_call_parameter",
  "splash_func_call_parameter", "splash_func_call_parameter_list",
  "function_body", "statement_list", "function_call", "statement",
  "return", "while_loop", "switch", "switch_case_list",
  "switch_case_define", "for", "if", "elseif_statment_list",
  "elseif_statment", "variable_declaration", "assignment", "dim_num_stm",
  "expression", YY_NULL
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   130,   130,   134,   135,   139,   144,   145,   148,   149,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   166,   168,   172,   174,   182,   186,   187,   188,   192,
     193,   197,   198,   199,   203,   204,   207,   211,   212,   213,
     216,   217,   221,   222,   227,   228,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   253,   257,   261,   269,   274,   281,
     288,   292,   293,   297,   298,   302,   303,   307,   308,   309,
     310,   311,   312,   318,   320,   325,   329,   336,   339,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
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
      95,    96,    97,    98,    99,   100,   101
    };
    const unsigned int user_token_number_max_ = 356;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "parser.y" // lalr1.cc:1156
} // Language
#line 1876 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.cpp" // lalr1.cc:1156
#line 372 "parser.y" // lalr1.cc:1157




void Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: Line:" << lineNumber << "' - " << err_message << "\n";
}

static int yylex( Language::Parser::semantic_type *yylval, Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval) );
}

