// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file D:\source\repos\rapid\\rapid\parser.tab.hpp
 ** Define the Language::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_D_SOURCE_REPOS_RAPID_RAPID_PARSER_TAB_HPP_INCLUDED
# define YY_YY_D_SOURCE_REPOS_RAPID_RAPID_PARSER_TAB_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 9 "parser.y" // lalr1.cc:371

   namespace Language {
      class Translator;
      class Lexer;
      class ASTNode;
      class ParameterNode;
      class FunctionNode;
      class OperatorNode;
      class StatementListNode;
      class ActUnitNode;
      class MoveABSJNode;
      class DeActUnitNode;
      class DimNumsNode;
      class ForNode;
      class ElseIfNode;
      class ZoneDataNode;
      class SpeedDataNode;
      class ModuleNode;
      class WobjDataNode;
      class ToolDataNode;
      class ArrayDataNode;
      class ParamNode;
      class ArcLStartNode;
      class DeclareNode;
      class ArcLNode;
      class FunctionCallNode;
      class ArccNode;
      class ArcEndNode;
      class MoveLNode;
      class VariableNode;
      class DeclareListNode;
      class ModeJNode;
      class RobtargetNode;
      class JointtargetNode;
      class TpWriteNode;
      class NullNode;
      class SWitchNode;
      class ActUnitNode;
      enum enum_v_type;
      enum enum_v_scope;
      template <class T> class ListNode;
   }
   class QString;

#line 89 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp" // lalr1.cc:371


# include <vector>
# include <iostream>
# include <stdexcept>
# include <string>
# include "stack.hh"



/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 5 "parser.y" // lalr1.cc:371
namespace Language {
#line 107 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp" // lalr1.cc:371





  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 67 "parser.y" // lalr1.cc:371

   QString *sval;
   double dval;
   int ival;
   ASTNode * pNode;
   ParameterNode * parameterNode;
   FunctionNode * functionNode;
   VariableNode* variableNode;
   ListNode<ASTNode> * listNode;
   ListNode<ParameterNode> * parameterListNode;
   ListNode<ParamNode>* paramListNode;
   ListNode<ElseIfNode>* elseifListNode;
   ListNode<ModuleNode>* moduleListNode;
   ModuleNode* moduleNode;
   StatementListNode * statementListNode;

   ElseIfNode* elseif_stmNode;
   DimNumsNode*     dim_num_stmNode;
  

#line 142 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp" // lalr1.cc:371
    };
#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m);
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        GE = 258,
        LE = 259,
        EQ = 260,
        NE = 261,
        GREATER = 262,
        LESS = 263,
        MINUS = 264,
        ADD = 265,
        SUB = 266,
        MULTIP = 267,
        DEVIDE = 268,
        UMINUS = 269,
        IFX = 270,
        ELSE = 271,
        IF = 272,
        MUL = 273,
        LT = 274,
        GT = 275,
        RETURN = 276,
        NumberType = 277,
        TextType = 278,
        VoidType = 279,
        SPACE = 280,
        THEN = 281,
        JIN = 282,
        DOLAR = 283,
        RAPID_NAN = 284,
        SEAMDATA = 285,
        WELDDATA = 286,
        ASS = 287,
        LR = 288,
        RR = 289,
        COMMA = 290,
        LC = 291,
        RC = 292,
        COLON = 293,
        FNULL = 294,
        DEVCOLON = 295,
        FTRUE = 296,
        FFALSE = 297,
        FOR = 298,
        ENDFOR = 299,
        TO = 300,
        FROM = 301,
        SEMICOLON = 302,
        SPLASH = 303,
        LBRACE = 304,
        RBRACE = 305,
        LMOVE = 306,
        VAR = 307,
        DO = 308,
        WHILE = 309,
        ENDWHILE = 310,
        TEST = 311,
        ENDTEST = 312,
        RETRY = 313,
        CASE = 314,
        DEFAULT = 315,
        JOINTTARGET = 316,
        ROBTARGET = 317,
        STRING = 318,
        NUM = 319,
        BOOL = 320,
        WOBJDATA = 321,
        ZONEDATA = 322,
        SPEEDDATA = 323,
        TOOLDATA = 324,
        PERS = 325,
        CONST = 326,
        ACTUNIT = 327,
        MOVEABSJ = 328,
        ARCLSTART = 329,
        ARCL = 330,
        ARCC = 331,
        ARCEND = 332,
        MOVEL = 333,
        MOVEJ = 334,
        ENDMODULE = 335,
        ENDPROC = 336,
        MODULE = 337,
        PROC = 338,
        AND = 339,
        OR = 340,
        MOD = 341,
        DEACTUNIT = 342,
        ELSEIF = 343,
        WAITTIME = 344,
        WAITUNTIL = 345,
        SET = 346,
        RESET = 347,
        STEP = 348,
        ARCCEND = 349,
        ENDIF = 350,
        TPWRITE = 351,
        TASK = 352,
        Number = 353,
        LNumber = 354,
        Identifier = 355,
        String = 356
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Internal symbol number.
    typedef int symbol_number_type;

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v);

      ~basic_symbol ();

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// -1 when this symbol is empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      enum { empty = 0 };

      /// The symbol type.
      /// -1 when this symbol is empty.
      token_number_type type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;


    /// Build a parser object.
    Parser (Lexer  &lexer_yyarg);
    virtual ~Parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    Parser (const Parser&);
    Parser& operator= (const Parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yytoken   the lookahead token type, or yyempty_.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         symbol_number_type yytoken) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yylhs     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yylhs);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (int t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param s         The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// "empty" when empty.
      symbol_number_type type_get () const;

      enum { empty = 0 };

      /// The state.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    // Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 501,           //< Last index in yytable_.
      yynnts_ = 33,  //< Number of nonterminal symbols.
      yyempty_ = -2,
      yyfinal_ = 6, //< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 102    //< Number of tokens.
    };


    // User arguments.
    Lexer  &lexer;
  };


#line 5 "parser.y" // lalr1.cc:371
} // Language
#line 560 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp" // lalr1.cc:371




#endif // !YY_YY_D_SOURCE_REPOS_RAPID_RAPID_PARSER_TAB_HPP_INCLUDED
