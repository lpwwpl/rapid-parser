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





#include "parser.tab.hpp"


// Unqualified %code blocks.
#line 75 "parser.y"

    #include "translator.hpp"
    #include "ast.h"

    
    extern int lineNumber;
    static int yylex(Language::Parser::semantic_type *yylval, Language::Lexer  &lexer);

#line 55 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"


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

#line 5 "parser.y"
namespace Language {
#line 129 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"

  /// Build a parser object.
  Parser::Parser (Lexer  &lexer_yyarg)
#if YYDEBUG
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
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v)
    : Base (t)
    , value (YY_MOVE (v))
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
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
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
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
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
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
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
            << ' ' << yysym.name () << " (";
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
  case 2: // program: module_list
#line 158 "parser.y"
                {}
#line 586 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 3: // module_list: module
#line 162 "parser.y"
                {(yylhs.value.moduleListNode) = new ListNode<ModuleNode>((yystack_[0].value.moduleNode));}
#line 592 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 4: // module_list: module_list module
#line 163 "parser.y"
                         {(yystack_[1].value.moduleListNode)->push_back((yystack_[0].value.moduleNode));}
#line 598 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 5: // module: MODULE Identifier declaration_list ENDMODULE
#line 167 "parser.y"
                                                     {(yylhs.value.moduleNode) = new ModuleNode((yystack_[2].value.sval),(yystack_[1].value.listNode));}
#line 604 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 6: // declaration_list: declaration
#line 172 "parser.y"
                 {(yylhs.value.listNode) = new DeclareListNode((yystack_[0].value.pNode));}
#line 610 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 7: // declaration_list: declaration_list declaration
#line 173 "parser.y"
                                     {(yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));}
#line 616 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 8: // declaration: variable_declaration
#line 177 "parser.y"
                           {(yylhs.value.pNode)=(yystack_[0].value.variableNode);}
#line 622 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 9: // declaration: function_declaration
#line 178 "parser.y"
                               {(yylhs.value.pNode)=(yystack_[0].value.functionNode);}
#line 628 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 10: // declaration: var_assignment
#line 179 "parser.y"
                    {(yylhs.value.pNode)=(yystack_[0].value.pNode);}
#line 634 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 11: // declaration: Record_declare
#line 180 "parser.y"
                     {(yylhs.value.pNode)=(yystack_[0].value.pNode);}
#line 640 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 12: // Type: NUM
#line 183 "parser.y"
            { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"NUM\"")); (yylhs.value.pNode) = id;}
#line 646 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 13: // Type: BOOL
#line 184 "parser.y"
                { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"BOOL\"")); (yylhs.value.pNode) = id;}
#line 652 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 14: // Type: STRING
#line 185 "parser.y"
                  { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"STRING\"")); (yylhs.value.pNode) = id;}
#line 658 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 15: // Type: ROBTARGET
#line 186 "parser.y"
                     { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"ROBTARGET\"")); (yylhs.value.pNode) = id;}
#line 664 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 16: // Type: JOINTTARGET
#line 187 "parser.y"
                        {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"JOINTTARGET\"")); (yylhs.value.pNode) = id;}
#line 670 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 17: // Type: WOBJDATA
#line 188 "parser.y"
               {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"WOBJDATA\"")); (yylhs.value.pNode) = id;}
#line 676 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 18: // Type: ZONEDATA
#line 189 "parser.y"
               {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"ZONEDATA\"")); (yylhs.value.pNode) = id;}
#line 682 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 19: // Type: SPEEDDATA
#line 190 "parser.y"
                { StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"SPEEDDATA\"")); (yylhs.value.pNode) = id;}
#line 688 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 20: // Type: TOOLDATA
#line 191 "parser.y"
               {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"TOOLDATA\"")); (yylhs.value.pNode) = id;}
#line 694 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 21: // Type: SEAMDATA
#line 192 "parser.y"
               {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"SEAMDATA\"")); (yylhs.value.pNode) = id;}
#line 700 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 22: // Type: WELDDATA
#line 193 "parser.y"
               {StringLiteralNode* id = new StringLiteralNode(&QString::fromLatin1("\"WELDDATA\"")); (yylhs.value.pNode) = id;}
#line 706 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 23: // Type: Identifier
#line 194 "parser.y"
                 {(yylhs.value.pNode) = new StringLiteralNode(true,(yystack_[0].value.sval)); /*$$ = $1;*/ }
#line 712 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 24: // Record_declare: RECORD Identifier struct_members ENDRECORD
#line 198 "parser.y"
                                               { (yylhs.value.pNode) = new StructDescNode((yystack_[2].value.sval), (yystack_[1].value.listNode)); }
#line 718 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 25: // struct_members: var_decl
#line 202 "parser.y"
             { (yylhs.value.listNode) = new  ListNode<ASTNode>(); (yylhs.value.listNode)->push_back((yystack_[0].value.pNode)); }
#line 724 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 26: // struct_members: struct_members var_decl
#line 203 "parser.y"
                              { (yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode)); }
#line 730 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 27: // var_decl: Type Identifier SEMICOLON
#line 206 "parser.y"
                              {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval)); (yylhs.value.pNode) = new VariableDeclareNode((yystack_[2].value.pNode),id); }
#line 736 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 28: // scope_pers: PERS
#line 210 "parser.y"
       { (yylhs.value.ival) =  PERS;}
#line 742 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 29: // scope1: TASK PERS
#line 214 "parser.y"
              { (yylhs.value.ival) =  TASK_PERS;}
#line 748 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 30: // scope1: CONST_L
#line 216 "parser.y"
            { (yylhs.value.ival) = eCONST;}
#line 754 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 31: // scope2: VAR
#line 220 "parser.y"
        { (yylhs.value.ival) =  VAR;}
#line 760 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 32: // function_declaration: PROC Identifier LC parameter_declaration_list RC function_body ENDPROC
#line 228 "parser.y"
                                                                           {(yylhs.value.functionNode) = new FunctionNode(nullptr, (yystack_[5].value.sval), (yystack_[3].value.parameterListNode), (yystack_[1].value.statementListNode)); }
#line 766 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 33: // function_declaration: FUNC Type Identifier LC parameter_declaration_list RC function_body ENDFUNC
#line 229 "parser.y"
                                                                                 {(yylhs.value.functionNode) = new FunctionNode((yystack_[6].value.pNode), (yystack_[5].value.sval), (yystack_[3].value.parameterListNode), (yystack_[1].value.statementListNode)); }
#line 772 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 34: // parameter_declaration_list: parameter_declaration
#line 233 "parser.y"
                          { (yylhs.value.parameterListNode) = new ListNode<ParameterNode>((yystack_[0].value.parameterNode)); }
#line 778 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 35: // parameter_declaration_list: parameter_declaration_list COMMA parameter_declaration
#line 234 "parser.y"
                                                             {(yystack_[2].value.parameterListNode)->push_back((yystack_[0].value.parameterNode));}
#line 784 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 36: // parameter_declaration_list: %empty
#line 235 "parser.y"
      {(yylhs.value.parameterListNode) = new ListNode<ParameterNode>();}
#line 790 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 37: // parameter_declaration: Type Identifier
#line 239 "parser.y"
                    {(yylhs.value.parameterNode) = new ParameterNode((yystack_[0].value.sval));}
#line 796 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 38: // func_call_parameter_list: expression
#line 244 "parser.y"
    {
        (yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.pNode)); 
    }
#line 804 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 39: // func_call_parameter_list: func_call_parameter_list COMMA expression
#line 248 "parser.y"
        {
        (yystack_[2].value.listNode)->push_back((yystack_[0].value.pNode));   
	}
#line 812 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 40: // function_body: %empty
#line 262 "parser.y"
  {(yylhs.value.statementListNode)=NULL;}
#line 818 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 41: // function_body: statement_list
#line 263 "parser.y"
                     {(yylhs.value.statementListNode) = (yystack_[0].value.statementListNode);}
#line 824 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 42: // statement_list: statement
#line 267 "parser.y"
              {(yylhs.value.statementListNode) = new StatementListNode((yystack_[0].value.pNode));}
#line 830 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 43: // statement_list: statement_list statement
#line 268 "parser.y"
                               {(yystack_[1].value.statementListNode)->push_back((yystack_[0].value.pNode));}
#line 836 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 44: // function_call: Identifier SEMICOLON
#line 273 "parser.y"
                           { (yylhs.value.pNode) = new FunctionCallNode((yystack_[1].value.sval), new ListNode<ASTNode>());}
#line 842 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 45: // function_call: Identifier func_call_parameter_list SEMICOLON
#line 274 "parser.y"
                                                     { (yylhs.value.pNode) = new FunctionCallNode((yystack_[2].value.sval), (yystack_[1].value.listNode));}
#line 848 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 46: // inst_modifer: SPLASH CONC
#line 278 "parser.y"
                  { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("Conc")); (yylhs.value.pNode) = id;}
#line 854 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 47: // inst_modifer: SPLASH TOOL_P
#line 279 "parser.y"
                    { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("Tool")); (yylhs.value.pNode) = id;}
#line 860 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 48: // inst_modifer: SPLASH PLEN
#line 280 "parser.y"
                  { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("PLength")); (yylhs.value.pNode) = id;}
#line 866 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 49: // inst_modifer: SPLASH MAXTIME
#line 281 "parser.y"
                     { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("MaxTime")); (yylhs.value.pNode) = id;}
#line 872 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 50: // inst_modifer: SPLASH TIMEFLAG
#line 282 "parser.y"
                      { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("TimeFlag")); (yylhs.value.pNode) = id;}
#line 878 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 51: // inst_modifer: SPLASH WOBJ_P
#line 283 "parser.y"
                     { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("WObj")); (yylhs.value.pNode) = id;}
#line 884 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 52: // inst_modifer: SPLASH SEAM_NAME
#line 284 "parser.y"
                       { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("SeamName")); (yylhs.value.pNode) = id;}
#line 890 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 53: // inst_modifer: SPLASH ZONE_P
#line 285 "parser.y"
                    { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("Z")); (yylhs.value.pNode) = id;}
#line 896 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 54: // inst_modifer: SPLASH INPOS
#line 286 "parser.y"
                   { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("InPos")); (yylhs.value.pNode) = id;}
#line 902 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 55: // inst_modifer: SPLASH VEL_P
#line 287 "parser.y"
                   { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("V")); (yylhs.value.pNode) = id;}
#line 908 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 56: // inst_modifer: SPLASH TCP_P
#line 288 "parser.y"
                   { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("T")); (yylhs.value.pNode) = id;}
#line 914 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 57: // inst_modifer: SPLASH NOEOFFS
#line 289 "parser.y"
                     { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("NoEOffs")); (yylhs.value.pNode) = id;}
#line 920 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 58: // inst_modifer: SPLASH ID_P
#line 290 "parser.y"
                  { StringLiteralNode* id = new StringLiteralNode(true,&QString::fromLatin1("ID")); (yylhs.value.pNode) = id;}
#line 926 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 59: // statement: variable_for_body
#line 294 "parser.y"
                      {(yylhs.value.pNode) = (yystack_[0].value.variableNode);}
#line 932 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 60: // statement: assignment
#line 295 "parser.y"
                  {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 938 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 61: // statement: if
#line 296 "parser.y"
         { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 944 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 62: // statement: while_loop
#line 297 "parser.y"
                 { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 950 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 63: // statement: for
#line 298 "parser.y"
          { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 956 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 64: // statement: return
#line 299 "parser.y"
              { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 962 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 65: // statement: function_call
#line 300 "parser.y"
                    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 968 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 66: // statement: MOVEJ func_call_parameter_list SEMICOLON
#line 301 "parser.y"
                                               {(yylhs.value.pNode) = new MoveJNode((yystack_[1].value.listNode));}
#line 974 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 67: // statement: ACTUNIT func_call_parameter_list SEMICOLON
#line 302 "parser.y"
                                                {(yylhs.value.pNode) = new ActUnitNode((yystack_[1].value.listNode));}
#line 980 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 68: // statement: ARCLSTART func_call_parameter_list SEMICOLON
#line 303 "parser.y"
                                                  {(yylhs.value.pNode) = new ArcLStartNode((yystack_[1].value.listNode));}
#line 986 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 69: // statement: ARCL func_call_parameter_list SEMICOLON
#line 304 "parser.y"
                                             {(yylhs.value.pNode) = new ArcLNode((yystack_[1].value.listNode));}
#line 992 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 70: // statement: ARCC func_call_parameter_list SEMICOLON
#line 305 "parser.y"
                                             {(yylhs.value.pNode) = new ArccNode((yystack_[1].value.listNode));}
#line 998 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 71: // statement: ARCEND func_call_parameter_list SEMICOLON
#line 306 "parser.y"
                                               {(yylhs.value.pNode) = new ArcEndNode((yystack_[1].value.listNode));}
#line 1004 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 72: // statement: MOVEL func_call_parameter_list SEMICOLON
#line 307 "parser.y"
                                              { (yylhs.value.pNode) = new MoveLNode((yystack_[1].value.listNode));}
#line 1010 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 73: // statement: MOVEABSJ func_call_parameter_list SEMICOLON
#line 308 "parser.y"
                                                 {(yylhs.value.pNode) = new MoveABSJNode((yystack_[1].value.listNode));}
#line 1016 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 74: // statement: DEACTUNIT func_call_parameter_list SEMICOLON
#line 309 "parser.y"
                                                  { (yylhs.value.pNode) = new DeActUnitNode((yystack_[1].value.listNode));}
#line 1022 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 75: // statement: TPWRITE expression SEMICOLON
#line 310 "parser.y"
                                  {(yylhs.value.pNode) = new TpWriteNode((yystack_[1].value.pNode));}
#line 1028 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 76: // statement: ACCSET expression COMMA expression SEMICOLON
#line 311 "parser.y"
                                                   {(yylhs.value.pNode) = new AccSetNode((yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1034 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 77: // statement: VELSET expression COMMA expression SEMICOLON
#line 312 "parser.y"
                                                  {(yylhs.value.pNode) = new VelSetNode((yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1040 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 78: // statement: WAITTIME func_call_parameter_list SEMICOLON
#line 313 "parser.y"
                                                  {(yylhs.value.pNode) = new WaitTimeNode((yystack_[1].value.listNode));}
#line 1046 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 79: // statement: SETDO Identifier COMMA expression SEMICOLON
#line 314 "parser.y"
                                                   {IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new SetDoNode(id,(yystack_[1].value.pNode));}
#line 1052 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 80: // statement: SET Identifier SEMICOLON
#line 315 "parser.y"
                               {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval));(yylhs.value.pNode) = new SetNode(id);}
#line 1058 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 81: // statement: RESET Identifier SEMICOLON
#line 316 "parser.y"
                                 {IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval));(yylhs.value.pNode) = new ReSetNode(id);}
#line 1064 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 82: // statement: WAITDI Identifier COMMA expression SEMICOLON
#line 317 "parser.y"
                                                   {(yylhs.value.pNode) = new WaitDiNode((yystack_[3].value.sval),(yystack_[1].value.pNode));}
#line 1070 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 83: // statement: WAITUNTIL expression SEMICOLON
#line 318 "parser.y"
                                     {(yylhs.value.pNode) = new WaitUntilNode((yystack_[1].value.pNode));}
#line 1076 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 84: // statement: PULSEDO func_call_parameter_list SEMICOLON
#line 319 "parser.y"
                                                 {  (yylhs.value.pNode) = new PulseDONode((yystack_[1].value.listNode));}
#line 1082 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 85: // statement: switch
#line 320 "parser.y"
             {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1088 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 86: // return: RETURN SEMICOLON
#line 324 "parser.y"
                 {(yylhs.value.pNode) = new ReturnNode(NULL); }
#line 1094 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 87: // return: RETURN expression SEMICOLON
#line 325 "parser.y"
                                {(yylhs.value.pNode) = new ReturnNode((yystack_[1].value.pNode)); }
#line 1100 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 88: // while_loop: WHILE expression DO function_body ENDWHILE
#line 329 "parser.y"
                                                            { (yylhs.value.pNode) = new WhileNode((yystack_[3].value.pNode), (yystack_[1].value.statementListNode)); }
#line 1106 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 89: // switch: TEST expression switch_case_list ENDTEST
#line 334 "parser.y"
    {
        (yylhs.value.pNode) = new SWitchNode((yystack_[2].value.pNode),(yystack_[1].value.listNode),NULL);
    }
#line 1114 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 90: // switch_case_list: switch_case_define
#line 342 "parser.y"
        {
        (yylhs.value.listNode) = new SWitchCaseListNode((yystack_[0].value.pNode));
	}
#line 1122 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 91: // switch_case_list: switch_case_list switch_case_define
#line 347 "parser.y"
        {
        (yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));   
	}
#line 1130 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 92: // switch_case_define: CASE expression COLON function_body
#line 354 "parser.y"
        {
        (yylhs.value.pNode) = new CaseNode((yystack_[2].value.pNode),(yystack_[0].value.statementListNode)); //$$->dimListType->push_back($1);
	}
#line 1138 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 93: // for: FOR Identifier FROM expression TO expression STEP expression DO function_body ENDFOR
#line 360 "parser.y"
                                                                                         {  IdentifierNode* id = new IdentifierNode((yystack_[9].value.sval));(yylhs.value.pNode) = new ForNode(id,(yystack_[7].value.pNode),(yystack_[5].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.statementListNode));}
#line 1144 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 94: // if: IF expression THEN function_body ENDIF
#line 364 "parser.y"
                                             { (yylhs.value.pNode) = new IfNode((yystack_[3].value.pNode), (yystack_[1].value.statementListNode)); }
#line 1150 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 95: // if: IF expression statement
#line 365 "parser.y"
                               { (yylhs.value.pNode) = new IfNode((yystack_[1].value.pNode), (yystack_[0].value.pNode)); }
#line 1156 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 96: // if: IF expression THEN function_body elseif_statment_list ENDIF
#line 366 "parser.y"
                                                                  { (yylhs.value.pNode) = new IfNode((yystack_[4].value.pNode), (yystack_[2].value.statementListNode), (yystack_[1].value.elseifListNode)); }
#line 1162 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 97: // elseif_statment_list: elseif_statment
#line 370 "parser.y"
                     {(yylhs.value.elseifListNode) = new ListNode<ElseIfNode>((yystack_[0].value.elseif_stmNode));}
#line 1168 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 98: // elseif_statment_list: elseif_statment_list elseif_statment
#line 371 "parser.y"
                                           {(yystack_[1].value.elseifListNode)->push_back((yystack_[0].value.elseif_stmNode));}
#line 1174 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 99: // elseif_statment: ELSE function_body
#line 375 "parser.y"
                        { (yylhs.value.elseif_stmNode) = new ElseIfNode((yystack_[0].value.statementListNode)); }
#line 1180 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 100: // elseif_statment: ELSEIF expression THEN function_body
#line 376 "parser.y"
                                           { (yylhs.value.elseif_stmNode) = new ElseIfNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 1186 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 101: // variable_declaration: scope1 Type var_expression SEMICOLON
#line 381 "parser.y"
                                          { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.pNode),(yystack_[1].value.pNode));}
#line 1192 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 102: // variable_declaration: scope_pers Type var_expression SEMICOLON
#line 382 "parser.y"
                                               { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.pNode),(yystack_[1].value.pNode));}
#line 1198 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 103: // variable_declaration: scope2 Type var_expression SEMICOLON
#line 383 "parser.y"
                                           { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.pNode),(yystack_[1].value.pNode));}
#line 1204 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 104: // variable_for_body: scope2 Type var_expression SEMICOLON
#line 387 "parser.y"
                                         { (yylhs.value.variableNode) = new VariableNode((yystack_[3].value.ival),(yystack_[2].value.pNode),(yystack_[1].value.pNode));}
#line 1210 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 105: // variable_for_body: scope2 Type Identifier ASS expression SEMICOLON
#line 388 "parser.y"
                                                      { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.variableNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),id,(yystack_[1].value.pNode));}
#line 1216 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 106: // variable_for_body: scope2 Type array_index ASS expression SEMICOLON
#line 389 "parser.y"
                                                         { (yylhs.value.variableNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1222 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 107: // variable_for_body: scope2 Type struct_index ASS expression SEMICOLON
#line 390 "parser.y"
                                                        { (yylhs.value.variableNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1228 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 108: // var_expression: Identifier
#line 394 "parser.y"
               { (yylhs.value.pNode) = new IdentifierNode((yystack_[0].value.sval)); }
#line 1234 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 109: // var_expression: array_index
#line 395 "parser.y"
                  { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1240 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 110: // var_expression: struct_index
#line 396 "parser.y"
                   {(yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 1246 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 111: // var_assignment: scope1 Type Identifier ASS expression SEMICOLON
#line 402 "parser.y"
                                                    { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),id,(yystack_[1].value.pNode));}
#line 1252 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 112: // var_assignment: scope2 Type Identifier ASS expression SEMICOLON
#line 403 "parser.y"
                                                      { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),id,(yystack_[1].value.pNode));}
#line 1258 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 113: // var_assignment: scope_pers Type Identifier ASS expression SEMICOLON
#line 404 "parser.y"
                                                          { IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),id,(yystack_[1].value.pNode));}
#line 1264 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 114: // var_assignment: scope1 Type array_index ASS expression SEMICOLON
#line 405 "parser.y"
                                                         { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1270 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 115: // var_assignment: scope2 Type array_index ASS expression SEMICOLON
#line 406 "parser.y"
                                                         { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1276 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 116: // var_assignment: scope_pers Type array_index ASS expression SEMICOLON
#line 407 "parser.y"
                                                             { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1282 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 117: // var_assignment: scope1 Type struct_index ASS expression SEMICOLON
#line 408 "parser.y"
                                                        { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1288 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 118: // var_assignment: scope2 Type struct_index ASS expression SEMICOLON
#line 409 "parser.y"
                                                        { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1294 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 119: // var_assignment: scope_pers Type struct_index ASS expression SEMICOLON
#line 410 "parser.y"
                                                            { (yylhs.value.pNode) = new VariableNode((yystack_[5].value.ival),(yystack_[4].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));}
#line 1300 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 120: // assignment: var_expression ASS expression SEMICOLON
#line 422 "parser.y"
    {
        (yylhs.value.pNode) = new AssignmentNode((yystack_[3].value.pNode), (yystack_[1].value.pNode));
    }
#line 1308 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 121: // dim_num_stm: expression
#line 429 "parser.y"
    {
        (yylhs.value.dim_num_stmNode) = new DimNumsNode((yystack_[0].value.pNode)); 
    }
#line 1316 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 122: // dim_num_stm: dim_num_stm COMMA expression
#line 433 "parser.y"
        {
        (yystack_[2].value.dim_num_stmNode)->push_back((yystack_[0].value.pNode));   
	}
#line 1324 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 123: // struct_index: var_expression DOT Identifier
#line 439 "parser.y"
                                   { IdentifierNode* id = new IdentifierNode((yystack_[0].value.sval));(yylhs.value.pNode) = new StructIndexNode((yystack_[2].value.pNode),id); }
#line 1330 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 124: // array_index: Identifier LBRACE expression RBRACE
#line 443 "parser.y"
                                     {(yylhs.value.pNode) = new AccessNode((yystack_[3].value.sval), (yystack_[1].value.pNode));}
#line 1336 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 125: // offs_expr: OFFS LC func_call_parameter_list RC
#line 447 "parser.y"
                                     {(yylhs.value.pNode) = new OffsNode((yystack_[1].value.listNode));}
#line 1342 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 126: // reltool_expr: RELTOOl LC func_call_parameter_list RC
#line 451 "parser.y"
                                        {(yylhs.value.pNode) = new RelToolNode((yystack_[1].value.listNode));}
#line 1348 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 127: // op_expr: expression ADD expression
#line 455 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::ADD, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1354 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 128: // op_expr: expression SUB expression
#line 456 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::SUB, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1360 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 129: // op_expr: SUB expression
#line 457 "parser.y"
                               { (yylhs.value.pNode) = new OperatorNode(token::UMINUS, (yystack_[0].value.pNode)); }
#line 1366 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 130: // op_expr: expression MUL expression
#line 458 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::MUL, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1372 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 131: // op_expr: expression LT expression
#line 459 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::LT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1378 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 132: // op_expr: expression GT expression
#line 460 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::GT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1384 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 133: // op_expr: expression GE expression
#line 461 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::GE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1390 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 134: // op_expr: expression LE expression
#line 462 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::LE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1396 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 135: // op_expr: expression NE expression
#line 463 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::NE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1402 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 136: // op_expr: expression EQ expression
#line 464 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::EQ, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1408 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 137: // op_expr: expression AND expression
#line 465 "parser.y"
                             {(yylhs.value.pNode) = new OperatorNode(token::AND, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1414 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 138: // op_expr: expression OR expression
#line 466 "parser.y"
                            {(yylhs.value.pNode) = new OperatorNode(token::OR, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1420 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 139: // op_expr: expression MOD expression
#line 467 "parser.y"
                             {(yylhs.value.pNode) = new OperatorNode(token::MOD, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1426 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 140: // op_expr: expression ASS expression
#line 468 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::ASS, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1432 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 141: // op_expr: NOT expression
#line 470 "parser.y"
                              {(yylhs.value.pNode) = new OperatorNode(token::NOT, (yystack_[0].value.pNode));}
#line 1438 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 142: // op_expr: LC expression RC
#line 471 "parser.y"
                    {(yylhs.value.pNode) = (yylhs.value.pNode) = new OperatorNode(token::LC, (yystack_[1].value.pNode));}
#line 1444 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 143: // inst_expr: inst_modifer
#line 483 "parser.y"
               {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1450 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 144: // inst_expr: var_expression inst_modifer
#line 484 "parser.y"
                               { (yylhs.value.pNode) = new ModifierNode((yystack_[1].value.pNode),(yystack_[0].value.pNode));}
#line 1456 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 145: // expression: LR dim_num_stm RR
#line 489 "parser.y"
                    {(yylhs.value.pNode) = (yystack_[1].value.dim_num_stmNode);}
#line 1462 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 146: // expression: RAPID_NAN
#line 490 "parser.y"
             { (yylhs.value.pNode) = new StringLiteralNode(true,&QString::fromLatin1("9E+09"));}
#line 1468 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 147: // expression: String
#line 491 "parser.y"
          { (yylhs.value.pNode) = new StringLiteralNode((yystack_[0].value.sval));}
#line 1474 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 148: // expression: FNULL
#line 492 "parser.y"
         { (yylhs.value.pNode) = new NullNode();}
#line 1480 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 149: // expression: Number
#line 493 "parser.y"
          {(yylhs.value.pNode) = new NumberLiteralNode((yystack_[0].value.dval)); }
#line 1486 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 150: // expression: FTRUE
#line 494 "parser.y"
         {(yylhs.value.pNode) = new NumberLiteralNode(1);}
#line 1492 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 151: // expression: FFALSE
#line 495 "parser.y"
          {(yylhs.value.pNode) = new NumberLiteralNode(0);}
#line 1498 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 152: // expression: var_expression
#line 498 "parser.y"
                  {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1504 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 153: // expression: op_expr
#line 499 "parser.y"
           {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1510 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 154: // expression: offs_expr
#line 500 "parser.y"
            {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1516 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 155: // expression: reltool_expr
#line 501 "parser.y"
                { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1522 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 156: // expression: inst_expr
#line 502 "parser.y"
              {(yylhs.value.pNode)=(yystack_[0].value.pNode);}
#line 1528 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;

  case 157: // expression: Identifier LC func_call_parameter_list RC
#line 503 "parser.y"
                                              { (yylhs.value.pNode) = new FunctionCallNode((yystack_[3].value.sval), (yystack_[1].value.listNode));}
#line 1534 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"
    break;


#line 1538 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"

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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
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


  const short Parser::yypact_ninf_ = -146;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -95,  -121,    55,   -95,  -146,   178,  -146,  -146,   890,   -45,
    -146,  -146,  -146,   -37,    15,    70,  -146,  -146,   890,   890,
     890,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,     6,   890,   104,  -146,
    -146,  -146,    36,    44,    47,   115,    68,   532,  -146,   890,
     -22,   -18,    94,   125,    -9,    -3,   145,   149,     5,     1,
     150,   151,   890,   134,  -146,  -146,    82,    54,  -146,   415,
     415,    86,  -146,   415,   415,   415,  -146,   415,   415,   415,
    -146,   415,   415,   101,  -146,  -146,   890,   303,   415,  -146,
     154,   159,   415,   415,  -146,   415,  -146,  -146,   845,  -146,
       9,  -146,  -146,    -5,  -146,  -146,  -146,  -146,  -146,  -146,
      79,   381,  -146,   496,   506,   521,   541,   574,   628,   648,
     658,   303,  -146,   415,   399,   415,   415,    93,    98,   415,
     106,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   108,   109,   415,   374,   890,   114,
     303,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,   122,
    -146,  -146,   415,   415,    14,  1194,   681,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,   415,  -146,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,  -146,   415,   415,   415,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,   181,   251,  -146,   711,
     739,   774,   180,   182,    37,  1194,   164,   792,   802,    40,
      42,    73,    77,    78,    83,    84,    85,    87,    95,   827,
     166,   169,   852,  -146,    96,   119,  -146,  -146,   415,   123,
     124,  -146,   415,  -146,   127,    18,    18,   216,    18,    -4,
      -4,  -146,    18,    18,  1194,    90,    90,  -146,  -146,   303,
    -146,  -146,   415,   415,   415,   415,   415,  -146,   415,   303,
     415,   103,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,     7,     2,
     191,   193,   915,  -146,  -146,  1194,  -146,    12,   934,   944,
     960,  1023,  1194,   997,   168,  1051,  -146,  -146,   415,  -146,
     415,   415,  -146,   303,   415,  -146,    23,  -146,  -146,  -146,
    -146,  -146,   415,  -146,   303,  1068,  1104,  1131,  -146,  1143,
    -146,  -146,    28,  -146,  -146,  -146,  -146,   303,   415,  -146,
    1181,   303,   183,  -146
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,     2,     3,     0,     1,     4,     0,     0,
      31,    28,    30,     0,     0,     0,     6,    11,     0,     0,
       0,     9,     8,    10,    21,    22,    16,    15,    14,    12,
      13,    17,    18,    19,    20,    23,     0,     0,     0,    29,
       5,     7,     0,     0,     0,     0,     0,     0,    25,    36,
     108,     0,   110,   109,   108,     0,   110,   109,   108,     0,
     110,   109,    36,     0,    24,    26,     0,     0,    34,     0,
       0,     0,   102,     0,     0,     0,   101,     0,     0,     0,
     103,     0,     0,     0,    27,    37,     0,    40,     0,   146,
       0,     0,     0,     0,   148,     0,   150,   151,     0,   149,
     108,   147,   143,   152,   110,   109,   154,   155,   153,   156,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,    40,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
      41,    65,    42,    64,    62,    85,    63,    61,    59,     0,
      60,   129,     0,     0,     0,   121,     0,   141,    54,    46,
      51,    52,    53,    55,    56,    57,    48,    49,    50,    47,
      58,     0,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,   124,   119,   116,
     111,   117,   114,   112,   118,   115,     0,     0,    86,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,     0,    32,    43,     0,     0,
       0,   145,     0,   142,     0,   133,   134,   136,   135,   127,
     128,   130,   131,   132,   140,   137,   138,   139,    33,    40,
      95,    87,     0,     0,     0,     0,     0,    84,     0,    40,
       0,     0,    90,    67,    73,    68,    69,    70,    71,    72,
      66,    74,    78,    83,    80,    81,    75,    45,   108,     0,
     110,   109,     0,   125,   126,   122,   157,     0,     0,     0,
       0,     0,    39,     0,     0,     0,    89,    91,     0,   104,
       0,     0,   120,    40,     0,    94,     0,    97,    76,    77,
      79,    82,     0,    88,    40,     0,     0,     0,    99,     0,
      96,    98,     0,    92,   105,   107,   106,    40,     0,   100,
       0,    40,     0,    93
  };

  const short
  Parser::yypgoto_[] =
  {
    -146,  -146,  -146,   248,  -146,   237,    31,  -146,  -146,   206,
    -146,  -146,    59,  -146,   207,   184,  1085,  -103,  -146,  -146,
     152,  -145,  -146,  -146,  -146,  -146,     3,  -146,  -146,  -146,
     -39,  -146,  -146,   -42,  -146,  -146,  -146,   -23,   -19,  -146,
    -146,  -146,  -146,   -66
  };

  const short
  Parser::yydefgoto_[] =
  {
       0,     2,     3,     4,    15,    16,    66,    17,    47,    48,
      18,    19,   148,    21,    67,    68,   214,   149,   150,   151,
     102,   152,   153,   154,   155,   271,   272,   156,   157,   316,
     317,    22,   158,   103,    23,   160,   164,   104,   105,   106,
     107,   108,   109,   215
  };

  const short
  Parser::yytable_[] =
  {
      51,    55,    59,   110,   111,   237,     5,   113,   114,   115,
     189,   116,   117,   118,     1,   119,   120,   313,   206,    52,
      56,    60,   161,    53,    57,    61,   165,   166,   313,   167,
     187,   188,   189,    71,    69,   183,   184,   185,   186,    36,
     187,   188,   189,   190,   191,   159,    71,    75,    71,    42,
      43,    44,    71,    71,    70,     6,    72,   207,   209,   210,
     211,    79,   260,   308,    20,   217,   218,    70,    46,   181,
      98,    76,   241,   242,    20,    80,   309,   229,    46,   159,
     232,    70,    37,    70,   192,    70,   183,   184,   185,   186,
      38,   187,   188,   189,   190,   191,   266,   183,   184,   266,
     186,   266,   187,   188,   189,   190,   191,     8,   159,   196,
       9,   267,    39,    86,   273,    87,   274,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   314,   255,   256,
     257,   196,   266,    45,   315,   192,   266,   266,   314,   194,
     195,   196,   266,   266,   266,   330,   266,   275,   338,    10,
      73,   276,   277,   193,   266,   266,   297,   278,   279,   280,
      86,   281,   121,    50,    49,   159,   304,    11,    12,   282,
     287,    54,   292,    71,    58,    62,   295,    40,   238,   235,
      13,    74,   266,   266,   293,   294,   266,   306,   296,   270,
     194,   195,   196,   289,    14,    63,   298,   299,   300,   301,
     302,    77,   303,   196,   305,    78,    81,    82,    84,    85,
     328,   258,   290,   112,   162,     8,   291,   159,     9,   163,
     212,   333,   236,   183,   184,   213,   186,   159,   187,   188,
     189,   190,   191,   216,   339,   230,   231,   268,   342,   264,
     284,   265,   325,   285,   326,   327,   288,   310,   329,   311,
     323,     7,    41,    65,   343,   182,   332,    10,   183,   184,
     185,   186,   123,   187,   188,   189,   190,   191,   124,    83,
     122,   159,   340,   259,   307,    11,    12,   331,     0,     0,
       0,     0,   159,   125,   126,   127,   128,     0,    13,     0,
       0,     0,     0,   129,     0,   159,     0,     0,     0,   159,
       0,     0,    14,     0,     0,     0,     0,   192,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
     124,   130,     0,     0,     0,     0,     0,   194,   195,   196,
      10,     0,   131,     0,   132,   125,   126,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,     0,     0,     0,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,   194,   195,   196,   141,     0,   142,   143,   144,
     145,     0,     0,   130,   146,     0,     0,     0,   147,     0,
       0,     0,    10,     0,   131,     0,   132,    88,   183,   184,
     185,   186,     0,   187,   188,   189,   190,   191,     0,    89,
       0,     0,   133,   134,   135,   136,   137,   138,   139,   140,
      90,     0,    88,    91,     0,     0,     0,   141,     0,   142,
     143,   144,   145,     0,    89,     0,   146,     0,    88,     0,
     147,    92,     0,     0,    93,    90,     0,   192,    91,    94,
      89,    95,    96,    97,     0,     0,     0,     0,   233,    98,
      70,    90,     0,     0,    91,     0,    92,     0,   197,    93,
       0,     0,     0,     0,    94,     0,    95,    96,    97,     0,
       0,     0,    92,   208,    98,    93,     0,     0,     0,     0,
      94,     0,    95,    96,    97,     0,     0,     0,     0,     0,
      98,     0,   194,   195,   196,     0,     0,     0,     0,    99,
       0,   100,   101,   183,   184,   185,   186,     0,   187,   188,
     189,   190,   191,   183,   184,   185,   186,     0,   187,   188,
     189,   190,   191,     0,    99,     0,   100,   101,   183,   184,
     185,   186,     0,   187,   188,   189,   190,   191,     0,     0,
      99,     0,   100,   101,     0,     0,     0,     0,   183,   184,
     185,   186,   192,   187,   188,   189,   190,   191,    24,    25,
       0,     0,   192,     0,     0,     0,     0,     0,     0,     0,
     198,     0,     0,    64,     0,     0,     0,   192,     0,     0,
     199,   183,   184,   185,   186,     0,   187,   188,   189,   190,
     191,     0,     0,     0,     0,   200,     0,   192,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,   195,   196,
       0,     0,     0,     0,     0,   201,     0,   194,   195,   196,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
     192,     0,   194,   195,   196,   183,   184,   185,   186,     0,
     187,   188,   189,   190,   191,     0,     0,     0,   202,     0,
       0,     0,   194,   195,   196,   183,   184,   185,   186,    35,
     187,   188,   189,   190,   191,   183,   184,   185,   186,     0,
     187,   188,   189,   190,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,   194,   195,   196,   183,   184,
     185,   186,     0,   187,   188,   189,   190,   191,     0,     0,
       0,     0,   203,     0,   192,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,     0,   183,   184,
     185,   186,   204,   187,   188,   189,   190,   191,     0,     0,
       0,     0,   205,     0,     0,     0,     0,   192,     0,   194,
     195,   196,   243,     0,     0,     0,   183,   184,   185,   186,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   194,
     195,   196,     0,     0,     0,     0,     0,   192,     0,   194,
     195,   196,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   261,   187,   188,   189,   190,
     191,     0,   194,   195,   196,   192,     0,     0,   262,   183,
     184,   185,   186,     0,   187,   188,   189,   190,   191,   183,
     184,   185,   186,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   194,   195,   196,     0,     0,     0,     0,     0,
     192,     0,     0,   263,   183,   184,   185,   186,     0,   187,
     188,   189,   190,   191,     0,     0,     0,     0,   192,     0,
     194,   195,   196,     0,     0,     0,     0,     0,   192,   183,
     184,   185,   186,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   269,   168,   169,     0,     0,     0,     0,     0,
       0,     0,     0,   192,     0,   194,   195,   196,   270,   170,
     171,   172,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   283,     0,   194,   195,   196,     0,     0,   192,     0,
       0,     0,     0,   194,   195,   196,    24,    25,     0,     0,
       0,     0,   183,   184,   185,   186,   286,   187,   188,   189,
     190,   191,     0,     0,     0,     0,     0,     0,   194,   195,
     196,   183,   184,   185,   186,     0,   187,   188,   189,   190,
     191,   183,   184,   185,   186,     0,   187,   188,   189,   190,
     191,     0,     0,   194,   195,   196,     0,   183,   184,   185,
     186,   192,   187,   188,   189,   190,   191,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,   312,
     192,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,     0,     0,     0,   183,   184,   185,   186,   318,   187,
     188,   189,   190,   191,     0,     0,   192,    35,   319,     0,
       0,     0,     0,     0,     0,     0,   194,   195,   196,     0,
     183,   184,   185,   186,   320,   187,   188,   189,   190,   191,
       0,     0,     0,     0,     0,   194,   195,   196,     0,     0,
       0,     0,     0,   192,     0,   194,   195,   196,   183,   184,
     185,   186,     0,   187,   188,   189,   190,   191,     0,   322,
       0,   194,   195,   196,     0,   183,   184,   185,   186,   192,
     187,   188,   189,   190,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   321,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   194,   195,
     196,   183,   184,   185,   186,   324,   187,   188,   189,   190,
     191,     0,     0,     0,   192,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   195,   196,     0,   183,   184,
     185,   186,   334,   187,   188,   189,   190,   191,     0,     0,
     183,   184,   185,   186,     0,   187,   188,   189,   190,   191,
     192,     0,   194,   195,   196,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   335,   194,
     195,   196,     0,     0,     0,     0,     0,   192,   183,   184,
     185,   186,     0,   187,   188,   189,   190,   191,     0,   192,
       0,   183,   184,   185,   186,   336,   187,   188,   189,   190,
     191,     0,     0,     0,     0,   194,   195,   196,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,   234,     0,     0,     0,     0,   192,     0,     0,
       0,     0,   194,   195,   196,     0,     0,   239,   240,     0,
     192,     0,     0,     0,   194,   195,   196,     0,     0,     0,
       0,   341,     0,     0,     0,     0,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,   195,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,   195,   196
  };

  const short
  Parser::yycheck_[] =
  {
      42,    43,    44,    69,    70,   150,   127,    73,    74,    75,
      14,    77,    78,    79,   109,    81,    82,     5,   121,    42,
      43,    44,    88,    42,    43,    44,    92,    93,     5,    95,
      12,    13,    14,    51,    56,     7,     8,     9,    10,     8,
      12,    13,    14,    15,    16,    87,    51,    56,    51,    18,
      19,    20,    51,    51,    76,     0,    74,   123,   124,   125,
     126,    56,   207,    56,     5,   131,   132,    76,    37,    60,
      75,    74,    58,    59,    15,    74,    74,   143,    47,   121,
     146,    76,   127,    76,    56,    76,     7,     8,     9,    10,
     127,    12,    13,    14,    15,    16,    59,     7,     8,    59,
      10,    59,    12,    13,    14,    15,    16,    37,   150,   113,
      40,    74,    97,    59,    74,    61,    74,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   115,   194,   195,
     196,   113,    59,   127,   122,    56,    59,    59,   115,   111,
     112,   113,    59,    59,    59,   122,    59,    74,   120,    79,
      56,    74,    74,    74,    59,    59,   259,    74,    74,    74,
      59,    74,    61,   127,    60,   207,   269,    97,    98,    74,
      74,   127,   238,    51,   127,    60,   242,   107,    56,   148,
     110,    56,    59,    59,    61,    61,    59,    84,    61,    86,
     111,   112,   113,   235,   124,   127,   262,   263,   264,   265,
     266,    56,   268,   113,   270,    56,    56,    56,    74,   127,
     313,    30,   235,   127,    60,    37,   235,   259,    40,    60,
     127,   324,   108,     7,     8,   127,    10,   269,    12,    13,
      14,    15,    16,   127,   337,   127,   127,    73,   341,    59,
      74,    59,   308,    74,   310,   311,   127,    56,   314,    56,
      82,     3,    15,    47,    71,   103,   322,    79,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    62,
      86,   313,   338,    22,   271,    97,    98,   316,    -1,    -1,
      -1,    -1,   324,    32,    33,    34,    35,    -1,   110,    -1,
      -1,    -1,    -1,    42,    -1,   337,    -1,    -1,    -1,   341,
      -1,    -1,   124,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    70,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
      79,    -1,    81,    -1,    83,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,    -1,   116,   117,   118,
     119,    -1,    -1,    70,   123,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    79,    -1,    81,    -1,    83,    13,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    -1,    25,
      -1,    -1,    99,   100,   101,   102,   103,   104,   105,   106,
      36,    -1,    13,    39,    -1,    -1,    -1,   114,    -1,   116,
     117,   118,   119,    -1,    25,    -1,   123,    -1,    13,    -1,
     127,    57,    -1,    -1,    60,    36,    -1,    56,    39,    65,
      25,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    75,
      76,    36,    -1,    -1,    39,    -1,    57,    -1,    77,    60,
      -1,    -1,    -1,    -1,    65,    -1,    67,    68,    69,    -1,
      -1,    -1,    57,    74,    75,    60,    -1,    -1,    -1,    -1,
      65,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      75,    -1,   111,   112,   113,    -1,    -1,    -1,    -1,   125,
      -1,   127,   128,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    -1,   125,    -1,   127,   128,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    -1,    -1,
     125,    -1,   127,   128,    -1,    -1,    -1,    -1,     7,     8,
       9,    10,    56,    12,    13,    14,    15,    16,    26,    27,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    41,    -1,    -1,    -1,    56,    -1,    -1,
      74,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    74,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    74,    -1,   111,   112,   113,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      56,    -1,   111,   112,   113,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    74,    -1,
      -1,    -1,   111,   112,   113,     7,     8,     9,    10,   127,
      12,    13,    14,    15,    16,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,   111,   112,   113,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    74,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,     7,     8,
       9,    10,    74,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    56,    -1,   111,
     112,   113,    61,    -1,    -1,    -1,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    56,    -1,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,     8,     9,    10,    74,    12,    13,    14,    15,
      16,    -1,   111,   112,   113,    56,    -1,    -1,    59,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    59,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    56,    -1,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    56,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    80,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,   111,   112,   113,    86,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    74,    -1,   111,   112,   113,    -1,    -1,    56,    -1,
      -1,    -1,    -1,   111,   112,   113,    26,    27,    -1,    -1,
      -1,    -1,     7,     8,     9,    10,    74,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    -1,    -1,   111,   112,   113,    -1,     7,     8,     9,
      10,    56,    12,    13,    14,    15,    16,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    74,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,     7,     8,     9,    10,    74,    12,
      13,    14,    15,    16,    -1,    -1,    56,   127,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,
       7,     8,     9,    10,    74,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    56,    -1,   111,   112,   113,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    -1,    72,
      -1,   111,   112,   113,    -1,     7,     8,     9,    10,    56,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,   111,   112,
     113,     7,     8,     9,    10,    64,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,    -1,     7,     8,
       9,    10,    74,    12,    13,    14,    15,    16,    -1,    -1,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      56,    -1,   111,   112,   113,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    56,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    -1,    56,
      -1,     7,     8,     9,    10,    74,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,   111,   112,   113,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,   162,   163,    -1,
      56,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,   109,   130,   131,   132,   127,     0,   132,    37,    40,
      79,    97,    98,   110,   124,   133,   134,   136,   139,   140,
     141,   142,   160,   163,    26,    27,    88,    89,    90,    91,
      92,    93,    94,    95,    96,   127,   135,   127,   127,    97,
     107,   134,   135,   135,   135,   127,   135,   137,   138,    60,
     127,   162,   166,   167,   127,   162,   166,   167,   127,   162,
     166,   167,    60,   127,    41,   138,   135,   143,   144,    56,
      76,    51,    74,    56,    56,    56,    74,    56,    56,    56,
      74,    56,    56,   143,    74,   127,    59,    61,    13,    25,
      36,    39,    57,    60,    65,    67,    68,    69,    75,   125,
     127,   128,   149,   162,   166,   167,   168,   169,   170,   171,
     172,   172,   127,   172,   172,   172,   172,   172,   172,   172,
     172,    61,   144,    11,    17,    32,    33,    34,    35,    42,
      70,    81,    83,    99,   100,   101,   102,   103,   104,   105,
     106,   114,   116,   117,   118,   119,   123,   127,   141,   146,
     147,   148,   150,   151,   152,   153,   156,   157,   161,   162,
     164,   172,    60,    60,   165,   172,   172,   172,    28,    29,
      44,    45,    46,    47,    48,    49,    50,    52,    53,    54,
      55,    60,   149,     7,     8,     9,    10,    12,    13,    14,
      15,    16,    56,    74,   111,   112,   113,    77,    74,    74,
      74,    74,    74,    74,    74,    74,   146,   172,    74,   172,
     172,   172,   127,   127,   145,   172,   127,   172,   172,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   172,
     127,   127,   172,    74,   145,   135,   108,   150,    56,   145,
     145,    58,    59,    61,   145,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,    30,    22,
     150,    74,    59,    59,    59,    59,    59,    74,    73,    80,
      86,   154,   155,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,   127,   162,
     166,   167,   172,    61,    61,   172,    61,   146,   172,   172,
     172,   172,   172,   172,   146,   172,    84,   155,    56,    74,
      56,    56,    74,     5,   115,   122,   158,   159,    74,    74,
      74,    74,    72,    82,    64,   172,   172,   172,   146,   172,
     122,   159,   172,   146,    74,    74,    74,    22,   120,   146,
     172,    80,   146,    71
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,   129,   130,   131,   131,   132,   133,   133,   134,   134,
     134,   134,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   136,   137,   137,   138,   139,   140,
     140,   141,   142,   142,   143,   143,   143,   144,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   151,   151,   152,   153,
     154,   154,   155,   156,   157,   157,   157,   158,   158,   159,
     159,   160,   160,   160,   161,   161,   161,   161,   162,   162,
     162,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     164,   165,   165,   166,   167,   168,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   171,   171,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     2,     3,     1,     2,
       1,     1,     7,     8,     1,     3,     0,     2,     1,     3,
       0,     1,     1,     2,     2,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     5,     3,     5,
       3,     3,     5,     3,     3,     1,     2,     3,     5,     4,
       1,     2,     4,    11,     5,     3,     6,     1,     2,     2,
       4,     4,     4,     4,     4,     6,     6,     6,     1,     1,
       1,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       4,     1,     3,     3,     4,     4,     4,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4
  };


#if YYDEBUG || 1
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
  "DEVCOLON", "NOT", "FTRUE", "FFALSE", "FOR", "ENDFOR", "TO", "FROM",
  "SEMICOLON", "SPLASH", "LBRACE", "RBRACE", "LMOVE", "VAR", "DO", "WHILE",
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
  "reltool_expr", "op_expr", "inst_expr", "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   158,   158,   162,   163,   167,   172,   173,   177,   178,
     179,   180,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   198,   202,   203,   206,   210,   214,
     216,   220,   228,   229,   233,   234,   235,   239,   243,   247,
     262,   263,   267,   268,   273,   274,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   324,   325,   329,   333,
     341,   346,   353,   360,   364,   365,   366,   370,   371,   375,
     376,   381,   382,   383,   387,   388,   389,   390,   394,   395,
     396,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     421,   428,   432,   439,   443,   447,   451,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   470,   471,   483,   484,   489,   490,   491,   492,   493,
     494,   495,   498,   499,   500,   501,   502,   503
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
#endif // YYDEBUG

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

#line 5 "parser.y"
} // Language
#line 2495 "D:\\source\\repos\\rapid\\\\parser.tab.cpp"

#line 508 "parser.y"




void Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: Line:" << lineNumber << "' - " << err_message << "\n";
}

static int yylex( Language::Parser::semantic_type *yylval, Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval) );
}

