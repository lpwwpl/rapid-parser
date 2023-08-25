// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file D:\source\repos\rapid\\rapid\parser.tab.hpp
 ** Define the Language::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_D_YY_D_SOURCE_REPOS_RAPID_RAPID_PARSER_TAB_HPP_INCLUDED
# define YY_D_YY_D_SOURCE_REPOS_RAPID_RAPID_PARSER_TAB_HPP_INCLUDED
// "%code requires" blocks.
#line 1 "parser.y"


# define YYLTYPE_IS_DECLARED 1 /* alert the parser that we have our own definition */

#line 20 "parser.y"


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
      class ForNode;
      class ElseIfNode;
      class ZoneDataNode;
      class SpeedDataNode;
      class ModuleNode;
      class WobjDataNode;
      class ToolDataNode;
      class ArrayDataNode;
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
      class AccSetNode;
      class VelSetNode;
      class WaitUntilNode;
      class WaitDiNode;
      class WaitTimeNode;
      class TPWriteNode;
      class StructDescNode;
      class OffsNode;
      class SetNode;
      class SetDONode;
      class ReSetNode;
      class PulseDONode;
      class RelToolNode;
      class StructIndexNode;
      class AccessNode;
      class ModifierNode;
      class DimNumsNode;
      class IdentifierNode;
      class ParamWithModifierNode;
      template <class T> class ListNode;
   }
   class QString;

#line 114 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef D_YYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define D_YYDEBUG 1
#  else
#   define D_YYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define D_YYDEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined D_YYDEBUG */

#line 15 "parser.y"
namespace Language {
#line 258 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp"




  /// A Bison parser.
  class Parser
  {
  public:
#ifdef D_YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define D_YYSTYPE in C++, use %define api.value.type"
# endif
    typedef D_YYSTYPE value_type;
#else
    /// Symbol semantic values.
    union value_type
    {
#line 124 "parser.y"

   QString *sval;
   double dval;
   int ival;
   ASTNode * pNode;
   ParameterNode * parameterNode;
   FunctionNode * functionNode;
   VariableNode* variableNode;
   ListNode<ASTNode> * listNode;
   ListNode<ParameterNode> * parameterListNode;
   ListNode<ElseIfNode>* elseifListNode;
   ListNode<ModuleNode>* moduleListNode;
   ModuleNode* moduleNode;
   StatementListNode * statementListNode;

   ElseIfNode* elseif_stmNode;
   IdentifierNode* idenNode;
   DimNumsNode*     dim_num_stmNode;

   ParamWithModifierNode* paramWithModifi;
 

#line 299 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp"

    };
#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        D_YYEMPTY = -2,
    END = 0,                       // "end of file"
    D_YYerror = 256,               // error
    D_YYUNDEF = 257,               // "invalid token"
    DIVIDE = 258,                  // DIVIDE
    ELSE = 259,                    // ELSE
    PREFIX = 260,                  // PREFIX
    GE = 261,                      // GE
    LE = 262,                      // LE
    EQ = 263,                      // EQ
    NE = 264,                      // NE
    IF = 265,                      // IF
    ADD = 266,                     // ADD
    SUB = 267,                     // SUB
    MUL = 268,                     // MUL
    LT = 269,                      // LT
    GT = 270,                      // GT
    RETURN = 271,                  // RETURN
    NumberType = 272,              // NumberType
    TextType = 273,                // TextType
    VoidType = 274,                // VoidType
    SPACE = 275,                   // SPACE
    THEN = 276,                    // THEN
    JIN = 277,                     // JIN
    DOLAR = 278,                   // DOLAR
    RAPID_NAN = 279,               // RAPID_NAN
    SEAMDATA = 280,                // SEAMDATA
    WELDDATA = 281,                // WELDDATA
    INPOS = 282,                   // INPOS
    CONC = 283,                    // CONC
    ENDFUNC = 284,                 // ENDFUNC
    UMINUS = 285,                  // UMINUS
    ACCSET = 286,                  // ACCSET
    VELSET = 287,                  // VELSET
    SETDO = 288,                   // SETDO
    WAITDI = 289,                  // WAITDI
    OFFS = 290,                    // OFFS
    FUNC = 291,                    // FUNC
    INOUT = 292,                   // INOUT
    RELTOOl = 293,                 // RELTOOl
    RECORD = 294,                  // RECORD
    ENDRECORD = 295,               // ENDRECORD
    PULSEDO = 296,                 // PULSEDO
    WAITTIME_INPOS = 297,          // WAITTIME_INPOS
    WOBJ_P = 298,                  // WOBJ_P
    SEAM_NAME = 299,               // SEAM_NAME
    ZONE_P = 300,                  // ZONE_P
    VEL_P = 301,                   // VEL_P
    TCP_P = 302,                   // TCP_P
    NOEOFFS = 303,                 // NOEOFFS
    PLEN = 304,                    // PLEN
    DOT = 305,                     // DOT
    MAXTIME = 306,                 // MAXTIME
    TIMEFLAG = 307,                // TIMEFLAG
    TOOL_P = 308,                  // TOOL_P
    ID_P = 309,                    // ID_P
    ASS = 310,                     // ASS
    LR = 311,                      // LR
    RR = 312,                      // RR
    COMMA = 313,                   // COMMA
    LC = 314,                      // LC
    RC = 315,                      // RC
    LESS = 316,                    // LESS
    GREATER = 317,                 // GREATER
    COLON = 318,                   // COLON
    FNULL = 319,                   // FNULL
    DEVCOLON = 320,                // DEVCOLON
    NOT = 321,                     // NOT
    UNINDENT = 322,                // UNINDENT
    INDENT = 323,                  // INDENT
    FTRUE = 324,                   // FTRUE
    FFALSE = 325,                  // FFALSE
    FOR = 326,                     // FOR
    ENDFOR = 327,                  // ENDFOR
    TO = 328,                      // TO
    FROM = 329,                    // FROM
    SEMICOLON = 330,               // SEMICOLON
    LBRACE = 331,                  // LBRACE
    RBRACE = 332,                  // RBRACE
    LMOVE = 333,                   // LMOVE
    VAR = 334,                     // VAR
    DO = 335,                      // DO
    WHILE = 336,                   // WHILE
    ENDWHILE = 337,                // ENDWHILE
    TEST = 338,                    // TEST
    ENDTEST = 339,                 // ENDTEST
    RETRY = 340,                   // RETRY
    CASE = 341,                    // CASE
    DEFAULT = 342,                 // DEFAULT
    JOINTTARGET = 343,             // JOINTTARGET
    ROBTARGET = 344,               // ROBTARGET
    STRING = 345,                  // STRING
    NUM = 346,                     // NUM
    BOOL = 347,                    // BOOL
    WOBJDATA = 348,                // WOBJDATA
    ZONEDATA = 349,                // ZONEDATA
    SPEEDDATA = 350,               // SPEEDDATA
    TOOLDATA = 351,                // TOOLDATA
    PERS = 352,                    // PERS
    CONST_L = 353,                 // CONST_L
    ACTUNIT = 354,                 // ACTUNIT
    MOVEABSJ = 355,                // MOVEABSJ
    ARCLSTART = 356,               // ARCLSTART
    ARCL = 357,                    // ARCL
    ARCC = 358,                    // ARCC
    ARCEND = 359,                  // ARCEND
    MOVEL = 360,                   // MOVEL
    MOVEJ = 361,                   // MOVEJ
    ENDMODULE = 362,               // ENDMODULE
    ENDPROC = 363,                 // ENDPROC
    MODULE = 364,                  // MODULE
    PROC = 365,                    // PROC
    AND = 366,                     // AND
    OR = 367,                      // OR
    MOD = 368,                     // MOD
    DEACTUNIT = 369,               // DEACTUNIT
    ELSEIF = 370,                  // ELSEIF
    WAITTIME = 371,                // WAITTIME
    WAITUNTIL = 372,               // WAITUNTIL
    SET = 373,                     // SET
    RESET = 374,                   // RESET
    STEP = 375,                    // STEP
    ARCCEND = 376,                 // ARCCEND
    ENDIF = 377,                   // ENDIF
    TPWRITE = 378,                 // TPWRITE
    TASK = 379,                    // TASK
    Number = 380,                  // Number
    LNumber = 381,                 // LNumber
    Identifier = 382,              // Identifier
    String = 383                   // String
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 129, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_DIVIDE = 3,                            // DIVIDE
        S_ELSE = 4,                              // ELSE
        S_PREFIX = 5,                            // PREFIX
        S_GE = 6,                                // GE
        S_LE = 7,                                // LE
        S_EQ = 8,                                // EQ
        S_NE = 9,                                // NE
        S_IF = 10,                               // IF
        S_ADD = 11,                              // ADD
        S_SUB = 12,                              // SUB
        S_MUL = 13,                              // MUL
        S_LT = 14,                               // LT
        S_GT = 15,                               // GT
        S_RETURN = 16,                           // RETURN
        S_NumberType = 17,                       // NumberType
        S_TextType = 18,                         // TextType
        S_VoidType = 19,                         // VoidType
        S_SPACE = 20,                            // SPACE
        S_THEN = 21,                             // THEN
        S_JIN = 22,                              // JIN
        S_DOLAR = 23,                            // DOLAR
        S_RAPID_NAN = 24,                        // RAPID_NAN
        S_SEAMDATA = 25,                         // SEAMDATA
        S_WELDDATA = 26,                         // WELDDATA
        S_INPOS = 27,                            // INPOS
        S_CONC = 28,                             // CONC
        S_ENDFUNC = 29,                          // ENDFUNC
        S_UMINUS = 30,                           // UMINUS
        S_ACCSET = 31,                           // ACCSET
        S_VELSET = 32,                           // VELSET
        S_SETDO = 33,                            // SETDO
        S_WAITDI = 34,                           // WAITDI
        S_OFFS = 35,                             // OFFS
        S_FUNC = 36,                             // FUNC
        S_INOUT = 37,                            // INOUT
        S_RELTOOl = 38,                          // RELTOOl
        S_RECORD = 39,                           // RECORD
        S_ENDRECORD = 40,                        // ENDRECORD
        S_PULSEDO = 41,                          // PULSEDO
        S_WAITTIME_INPOS = 42,                   // WAITTIME_INPOS
        S_WOBJ_P = 43,                           // WOBJ_P
        S_SEAM_NAME = 44,                        // SEAM_NAME
        S_ZONE_P = 45,                           // ZONE_P
        S_VEL_P = 46,                            // VEL_P
        S_TCP_P = 47,                            // TCP_P
        S_NOEOFFS = 48,                          // NOEOFFS
        S_PLEN = 49,                             // PLEN
        S_DOT = 50,                              // DOT
        S_MAXTIME = 51,                          // MAXTIME
        S_TIMEFLAG = 52,                         // TIMEFLAG
        S_TOOL_P = 53,                           // TOOL_P
        S_ID_P = 54,                             // ID_P
        S_ASS = 55,                              // ASS
        S_LR = 56,                               // LR
        S_RR = 57,                               // RR
        S_COMMA = 58,                            // COMMA
        S_LC = 59,                               // LC
        S_RC = 60,                               // RC
        S_LESS = 61,                             // LESS
        S_GREATER = 62,                          // GREATER
        S_COLON = 63,                            // COLON
        S_FNULL = 64,                            // FNULL
        S_DEVCOLON = 65,                         // DEVCOLON
        S_NOT = 66,                              // NOT
        S_UNINDENT = 67,                         // UNINDENT
        S_INDENT = 68,                           // INDENT
        S_FTRUE = 69,                            // FTRUE
        S_FFALSE = 70,                           // FFALSE
        S_FOR = 71,                              // FOR
        S_ENDFOR = 72,                           // ENDFOR
        S_TO = 73,                               // TO
        S_FROM = 74,                             // FROM
        S_SEMICOLON = 75,                        // SEMICOLON
        S_LBRACE = 76,                           // LBRACE
        S_RBRACE = 77,                           // RBRACE
        S_LMOVE = 78,                            // LMOVE
        S_VAR = 79,                              // VAR
        S_DO = 80,                               // DO
        S_WHILE = 81,                            // WHILE
        S_ENDWHILE = 82,                         // ENDWHILE
        S_TEST = 83,                             // TEST
        S_ENDTEST = 84,                          // ENDTEST
        S_RETRY = 85,                            // RETRY
        S_CASE = 86,                             // CASE
        S_DEFAULT = 87,                          // DEFAULT
        S_JOINTTARGET = 88,                      // JOINTTARGET
        S_ROBTARGET = 89,                        // ROBTARGET
        S_STRING = 90,                           // STRING
        S_NUM = 91,                              // NUM
        S_BOOL = 92,                             // BOOL
        S_WOBJDATA = 93,                         // WOBJDATA
        S_ZONEDATA = 94,                         // ZONEDATA
        S_SPEEDDATA = 95,                        // SPEEDDATA
        S_TOOLDATA = 96,                         // TOOLDATA
        S_PERS = 97,                             // PERS
        S_CONST_L = 98,                          // CONST_L
        S_ACTUNIT = 99,                          // ACTUNIT
        S_MOVEABSJ = 100,                        // MOVEABSJ
        S_ARCLSTART = 101,                       // ARCLSTART
        S_ARCL = 102,                            // ARCL
        S_ARCC = 103,                            // ARCC
        S_ARCEND = 104,                          // ARCEND
        S_MOVEL = 105,                           // MOVEL
        S_MOVEJ = 106,                           // MOVEJ
        S_ENDMODULE = 107,                       // ENDMODULE
        S_ENDPROC = 108,                         // ENDPROC
        S_MODULE = 109,                          // MODULE
        S_PROC = 110,                            // PROC
        S_AND = 111,                             // AND
        S_OR = 112,                              // OR
        S_MOD = 113,                             // MOD
        S_DEACTUNIT = 114,                       // DEACTUNIT
        S_ELSEIF = 115,                          // ELSEIF
        S_WAITTIME = 116,                        // WAITTIME
        S_WAITUNTIL = 117,                       // WAITUNTIL
        S_SET = 118,                             // SET
        S_RESET = 119,                           // RESET
        S_STEP = 120,                            // STEP
        S_ARCCEND = 121,                         // ARCCEND
        S_ENDIF = 122,                           // ENDIF
        S_TPWRITE = 123,                         // TPWRITE
        S_TASK = 124,                            // TASK
        S_Number = 125,                          // Number
        S_LNumber = 126,                         // LNumber
        S_Identifier = 127,                      // Identifier
        S_String = 128,                          // String
        S_YYACCEPT = 129,                        // $accept
        S_program = 130,                         // program
        S_module_list = 131,                     // module_list
        S_module = 132,                          // module
        S_declaration_list = 133,                // declaration_list
        S_declaration = 134,                     // declaration
        S_Type = 135,                            // Type
        S_Record_declare = 136,                  // Record_declare
        S_struct_members = 137,                  // struct_members
        S_var_decl = 138,                        // var_decl
        S_scope_pers = 139,                      // scope_pers
        S_scope1 = 140,                          // scope1
        S_scope2 = 141,                          // scope2
        S_function_declaration = 142,            // function_declaration
        S_parameter_declaration_list = 143,      // parameter_declaration_list
        S_parameter_declaration = 144,           // parameter_declaration
        S_func_call_parameter_list = 145,        // func_call_parameter_list
        S_function_body = 146,                   // function_body
        S_statement_list = 147,                  // statement_list
        S_function_call = 148,                   // function_call
        S_inst_modifer = 149,                    // inst_modifer
        S_statement = 150,                       // statement
        S_return = 151,                          // return
        S_while_loop = 152,                      // while_loop
        S_switch = 153,                          // switch
        S_switch_case_list = 154,                // switch_case_list
        S_switch_case_define = 155,              // switch_case_define
        S_for = 156,                             // for
        S_if = 157,                              // if
        S_elseif_statment_list = 158,            // elseif_statment_list
        S_elseif_statment = 159,                 // elseif_statment
        S_variable_declaration = 160,            // variable_declaration
        S_variable_for_body = 161,               // variable_for_body
        S_var_expression = 162,                  // var_expression
        S_var_assignment = 163,                  // var_assignment
        S_assignment = 164,                      // assignment
        S_dim_num_stm = 165,                     // dim_num_stm
        S_struct_index = 166,                    // struct_index
        S_array_index = 167,                     // array_index
        S_offs_expr = 168,                       // offs_expr
        S_reltool_expr = 169,                    // reltool_expr
        S_op_expr = 170,                         // op_expr
        S_inst_expr = 171,                       // inst_expr
        S_inst_expr_list = 172,                  // inst_expr_list
        S_basic_expr = 173,                      // basic_expr
        S_expression = 174,                      // expression
        S_paramWithMod_stm = 175                 // paramWithMod_stm
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value (std::move (that.value))
        , location (std::move (that.location))
      {}
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);
      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t,
                    YY_MOVE_REF (location_type) l);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    YY_RVREF (value_type) v,
                    YY_RVREF (location_type) l);

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {};

    /// Build a parser object.
    Parser (Lexer  &lexer_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if D_YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);



    class context
    {
    public:
      context (const Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const unsigned char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if D_YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 1317,     ///< Last index in yytable_.
      yynnts_ = 47,  ///< Number of nonterminal symbols.
      yyfinal_ = 6 ///< Termination state number.
    };


    // User arguments.
    Lexer  &lexer;

  };


#line 15 "parser.y"
} // Language
#line 1181 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp"




#endif // !YY_D_YY_D_SOURCE_REPOS_RAPID_RAPID_PARSER_TAB_HPP_INCLUDED
