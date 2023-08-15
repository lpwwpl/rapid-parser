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
      class RecordNode;
      class PulseDONode;
      class RelToolNode;
      class StructIndexNode;
      class AccessNode;
      class ModifierNode;
      class VariableDeclareNode;
      class DimNumsNode;
      enum enum_v_type;
      enum enum_v_scope;
      template <class T> class ListNode;
   }
   class QString;

#line 117 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp"


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
#line 261 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp"




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
#line 126 "parser.y"

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
 

#line 301 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp"

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
    MINUS = 258,                   // MINUS
    DIVIDE = 259,                  // DIVIDE
    ELSE = 260,                    // ELSE
    PREFIX = 261,                  // PREFIX
    GE = 262,                      // GE
    LE = 263,                      // LE
    EQ = 264,                      // EQ
    NE = 265,                      // NE
    IF = 266,                      // IF
    ADD = 267,                     // ADD
    SUB = 268,                     // SUB
    MUL = 269,                     // MUL
    LT = 270,                      // LT
    GT = 271,                      // GT
    RETURN = 272,                  // RETURN
    NumberType = 273,              // NumberType
    TextType = 274,                // TextType
    VoidType = 275,                // VoidType
    SPACE = 276,                   // SPACE
    THEN = 277,                    // THEN
    JIN = 278,                     // JIN
    DOLAR = 279,                   // DOLAR
    RAPID_NAN = 280,               // RAPID_NAN
    SEAMDATA = 281,                // SEAMDATA
    WELDDATA = 282,                // WELDDATA
    INPOS = 283,                   // INPOS
    CONC = 284,                    // CONC
    ENDFUNC = 285,                 // ENDFUNC
    UMINUS = 286,                  // UMINUS
    ACCSET = 287,                  // ACCSET
    VELSET = 288,                  // VELSET
    SETDO = 289,                   // SETDO
    WAITDI = 290,                  // WAITDI
    OFFS = 291,                    // OFFS
    FUNC = 292,                    // FUNC
    INOUT = 293,                   // INOUT
    RELTOOl = 294,                 // RELTOOl
    RECORD = 295,                  // RECORD
    ENDRECORD = 296,               // ENDRECORD
    PULSEDO = 297,                 // PULSEDO
    WAITTIME_INPOS = 298,          // WAITTIME_INPOS
    WOBJ_P = 299,                  // WOBJ_P
    SEAM_NAME = 300,               // SEAM_NAME
    ZONE_P = 301,                  // ZONE_P
    VEL_P = 302,                   // VEL_P
    TCP_P = 303,                   // TCP_P
    NOEOFFS = 304,                 // NOEOFFS
    PLEN = 305,                    // PLEN
    DOT = 306,                     // DOT
    MAXTIME = 307,                 // MAXTIME
    TIMEFLAG = 308,                // TIMEFLAG
    TOOL_P = 309,                  // TOOL_P
    ID_P = 310,                    // ID_P
    ASS = 311,                     // ASS
    LR = 312,                      // LR
    RR = 313,                      // RR
    COMMA = 314,                   // COMMA
    LC = 315,                      // LC
    RC = 316,                      // RC
    LESS = 317,                    // LESS
    GREATER = 318,                 // GREATER
    COLON = 319,                   // COLON
    FNULL = 320,                   // FNULL
    DEVCOLON = 321,                // DEVCOLON
    NOT = 322,                     // NOT
    UNINDENT = 323,                // UNINDENT
    INDENT = 324,                  // INDENT
    FTRUE = 325,                   // FTRUE
    FFALSE = 326,                  // FFALSE
    FOR = 327,                     // FOR
    ENDFOR = 328,                  // ENDFOR
    TO = 329,                      // TO
    FROM = 330,                    // FROM
    SEMICOLON = 331,               // SEMICOLON
    SPLASH = 332,                  // SPLASH
    LBRACE = 333,                  // LBRACE
    RBRACE = 334,                  // RBRACE
    LMOVE = 335,                   // LMOVE
    VAR = 336,                     // VAR
    DO = 337,                      // DO
    WHILE = 338,                   // WHILE
    ENDWHILE = 339,                // ENDWHILE
    TEST = 340,                    // TEST
    ENDTEST = 341,                 // ENDTEST
    RETRY = 342,                   // RETRY
    CASE = 343,                    // CASE
    DEFAULT = 344,                 // DEFAULT
    JOINTTARGET = 345,             // JOINTTARGET
    ROBTARGET = 346,               // ROBTARGET
    STRING = 347,                  // STRING
    NUM = 348,                     // NUM
    BOOL = 349,                    // BOOL
    WOBJDATA = 350,                // WOBJDATA
    ZONEDATA = 351,                // ZONEDATA
    SPEEDDATA = 352,               // SPEEDDATA
    TOOLDATA = 353,                // TOOLDATA
    PERS = 354,                    // PERS
    CONST_L = 355,                 // CONST_L
    ACTUNIT = 356,                 // ACTUNIT
    MOVEABSJ = 357,                // MOVEABSJ
    ARCLSTART = 358,               // ARCLSTART
    ARCL = 359,                    // ARCL
    ARCC = 360,                    // ARCC
    ARCEND = 361,                  // ARCEND
    MOVEL = 362,                   // MOVEL
    MOVEJ = 363,                   // MOVEJ
    ENDMODULE = 364,               // ENDMODULE
    ENDPROC = 365,                 // ENDPROC
    MODULE = 366,                  // MODULE
    PROC = 367,                    // PROC
    AND = 368,                     // AND
    OR = 369,                      // OR
    MOD = 370,                     // MOD
    DEACTUNIT = 371,               // DEACTUNIT
    ELSEIF = 372,                  // ELSEIF
    WAITTIME = 373,                // WAITTIME
    WAITUNTIL = 374,               // WAITUNTIL
    SET = 375,                     // SET
    RESET = 376,                   // RESET
    STEP = 377,                    // STEP
    ARCCEND = 378,                 // ARCCEND
    ENDIF = 379,                   // ENDIF
    TPWRITE = 380,                 // TPWRITE
    TASK = 381,                    // TASK
    Number = 382,                  // Number
    LNumber = 383,                 // LNumber
    Identifier = 384,              // Identifier
    String = 385                   // String
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
        YYNTOKENS = 131, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_MINUS = 3,                             // MINUS
        S_DIVIDE = 4,                            // DIVIDE
        S_ELSE = 5,                              // ELSE
        S_PREFIX = 6,                            // PREFIX
        S_GE = 7,                                // GE
        S_LE = 8,                                // LE
        S_EQ = 9,                                // EQ
        S_NE = 10,                               // NE
        S_IF = 11,                               // IF
        S_ADD = 12,                              // ADD
        S_SUB = 13,                              // SUB
        S_MUL = 14,                              // MUL
        S_LT = 15,                               // LT
        S_GT = 16,                               // GT
        S_RETURN = 17,                           // RETURN
        S_NumberType = 18,                       // NumberType
        S_TextType = 19,                         // TextType
        S_VoidType = 20,                         // VoidType
        S_SPACE = 21,                            // SPACE
        S_THEN = 22,                             // THEN
        S_JIN = 23,                              // JIN
        S_DOLAR = 24,                            // DOLAR
        S_RAPID_NAN = 25,                        // RAPID_NAN
        S_SEAMDATA = 26,                         // SEAMDATA
        S_WELDDATA = 27,                         // WELDDATA
        S_INPOS = 28,                            // INPOS
        S_CONC = 29,                             // CONC
        S_ENDFUNC = 30,                          // ENDFUNC
        S_UMINUS = 31,                           // UMINUS
        S_ACCSET = 32,                           // ACCSET
        S_VELSET = 33,                           // VELSET
        S_SETDO = 34,                            // SETDO
        S_WAITDI = 35,                           // WAITDI
        S_OFFS = 36,                             // OFFS
        S_FUNC = 37,                             // FUNC
        S_INOUT = 38,                            // INOUT
        S_RELTOOl = 39,                          // RELTOOl
        S_RECORD = 40,                           // RECORD
        S_ENDRECORD = 41,                        // ENDRECORD
        S_PULSEDO = 42,                          // PULSEDO
        S_WAITTIME_INPOS = 43,                   // WAITTIME_INPOS
        S_WOBJ_P = 44,                           // WOBJ_P
        S_SEAM_NAME = 45,                        // SEAM_NAME
        S_ZONE_P = 46,                           // ZONE_P
        S_VEL_P = 47,                            // VEL_P
        S_TCP_P = 48,                            // TCP_P
        S_NOEOFFS = 49,                          // NOEOFFS
        S_PLEN = 50,                             // PLEN
        S_DOT = 51,                              // DOT
        S_MAXTIME = 52,                          // MAXTIME
        S_TIMEFLAG = 53,                         // TIMEFLAG
        S_TOOL_P = 54,                           // TOOL_P
        S_ID_P = 55,                             // ID_P
        S_ASS = 56,                              // ASS
        S_LR = 57,                               // LR
        S_RR = 58,                               // RR
        S_COMMA = 59,                            // COMMA
        S_LC = 60,                               // LC
        S_RC = 61,                               // RC
        S_LESS = 62,                             // LESS
        S_GREATER = 63,                          // GREATER
        S_COLON = 64,                            // COLON
        S_FNULL = 65,                            // FNULL
        S_DEVCOLON = 66,                         // DEVCOLON
        S_NOT = 67,                              // NOT
        S_UNINDENT = 68,                         // UNINDENT
        S_INDENT = 69,                           // INDENT
        S_FTRUE = 70,                            // FTRUE
        S_FFALSE = 71,                           // FFALSE
        S_FOR = 72,                              // FOR
        S_ENDFOR = 73,                           // ENDFOR
        S_TO = 74,                               // TO
        S_FROM = 75,                             // FROM
        S_SEMICOLON = 76,                        // SEMICOLON
        S_SPLASH = 77,                           // SPLASH
        S_LBRACE = 78,                           // LBRACE
        S_RBRACE = 79,                           // RBRACE
        S_LMOVE = 80,                            // LMOVE
        S_VAR = 81,                              // VAR
        S_DO = 82,                               // DO
        S_WHILE = 83,                            // WHILE
        S_ENDWHILE = 84,                         // ENDWHILE
        S_TEST = 85,                             // TEST
        S_ENDTEST = 86,                          // ENDTEST
        S_RETRY = 87,                            // RETRY
        S_CASE = 88,                             // CASE
        S_DEFAULT = 89,                          // DEFAULT
        S_JOINTTARGET = 90,                      // JOINTTARGET
        S_ROBTARGET = 91,                        // ROBTARGET
        S_STRING = 92,                           // STRING
        S_NUM = 93,                              // NUM
        S_BOOL = 94,                             // BOOL
        S_WOBJDATA = 95,                         // WOBJDATA
        S_ZONEDATA = 96,                         // ZONEDATA
        S_SPEEDDATA = 97,                        // SPEEDDATA
        S_TOOLDATA = 98,                         // TOOLDATA
        S_PERS = 99,                             // PERS
        S_CONST_L = 100,                         // CONST_L
        S_ACTUNIT = 101,                         // ACTUNIT
        S_MOVEABSJ = 102,                        // MOVEABSJ
        S_ARCLSTART = 103,                       // ARCLSTART
        S_ARCL = 104,                            // ARCL
        S_ARCC = 105,                            // ARCC
        S_ARCEND = 106,                          // ARCEND
        S_MOVEL = 107,                           // MOVEL
        S_MOVEJ = 108,                           // MOVEJ
        S_ENDMODULE = 109,                       // ENDMODULE
        S_ENDPROC = 110,                         // ENDPROC
        S_MODULE = 111,                          // MODULE
        S_PROC = 112,                            // PROC
        S_AND = 113,                             // AND
        S_OR = 114,                              // OR
        S_MOD = 115,                             // MOD
        S_DEACTUNIT = 116,                       // DEACTUNIT
        S_ELSEIF = 117,                          // ELSEIF
        S_WAITTIME = 118,                        // WAITTIME
        S_WAITUNTIL = 119,                       // WAITUNTIL
        S_SET = 120,                             // SET
        S_RESET = 121,                           // RESET
        S_STEP = 122,                            // STEP
        S_ARCCEND = 123,                         // ARCCEND
        S_ENDIF = 124,                           // ENDIF
        S_TPWRITE = 125,                         // TPWRITE
        S_TASK = 126,                            // TASK
        S_Number = 127,                          // Number
        S_LNumber = 128,                         // LNumber
        S_Identifier = 129,                      // Identifier
        S_String = 130,                          // String
        S_YYACCEPT = 131,                        // $accept
        S_program = 132,                         // program
        S_module_list = 133,                     // module_list
        S_module = 134,                          // module
        S_declaration_list = 135,                // declaration_list
        S_declaration = 136,                     // declaration
        S_Type = 137,                            // Type
        S_Record_declare = 138,                  // Record_declare
        S_struct_members = 139,                  // struct_members
        S_var_decl = 140,                        // var_decl
        S_scope_pers = 141,                      // scope_pers
        S_scope1 = 142,                          // scope1
        S_scope2 = 143,                          // scope2
        S_function_declaration = 144,            // function_declaration
        S_parameter_declaration_list = 145,      // parameter_declaration_list
        S_parameter_declaration = 146,           // parameter_declaration
        S_func_call_parameter_list = 147,        // func_call_parameter_list
        S_function_body = 148,                   // function_body
        S_statement_list = 149,                  // statement_list
        S_function_call = 150,                   // function_call
        S_inst_modifer = 151,                    // inst_modifer
        S_statement = 152,                       // statement
        S_return = 153,                          // return
        S_while_loop = 154,                      // while_loop
        S_switch = 155,                          // switch
        S_switch_case_list = 156,                // switch_case_list
        S_switch_case_define = 157,              // switch_case_define
        S_for = 158,                             // for
        S_if = 159,                              // if
        S_elseif_statment_list = 160,            // elseif_statment_list
        S_elseif_statment = 161,                 // elseif_statment
        S_variable_declaration = 162,            // variable_declaration
        S_variable_for_body = 163,               // variable_for_body
        S_var_expression = 164,                  // var_expression
        S_var_assignment = 165,                  // var_assignment
        S_assignment = 166,                      // assignment
        S_dim_num_stm = 167,                     // dim_num_stm
        S_struct_index = 168,                    // struct_index
        S_array_index = 169,                     // array_index
        S_offs_expr = 170,                       // offs_expr
        S_reltool_expr = 171,                    // reltool_expr
        S_op_expr = 172,                         // op_expr
        S_inst_expr = 173,                       // inst_expr
        S_expression = 174                       // expression
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
      yylast_ = 1361,     ///< Last index in yytable_.
      yynnts_ = 44,  ///< Number of nonterminal symbols.
      yyfinal_ = 6 ///< Termination state number.
    };


    // User arguments.
    Lexer  &lexer;

  };


#line 15 "parser.y"
} // Language
#line 1184 "D:\\source\\repos\\rapid\\\\rapid\\parser.tab.hpp"




#endif // !YY_D_YY_D_SOURCE_REPOS_RAPID_RAPID_PARSER_TAB_HPP_INCLUDED
