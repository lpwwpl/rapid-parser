%code requires {

# define YYLTYPE_IS_DECLARED 1 /* alert the parser that we have our own definition */

}
%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%start program
%verbose 
%locations /* track locations: @n of component N; @$ of entire range */

%define api.prefix {D_yy}
%define api.namespace {Language}
%define parser_class_name {Parser}
%define parse.error verbose


%code requires{

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
}


%lex-param   { Lexer  &lexer  }

%parse-param { Lexer  &lexer  }



%code{
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

}




/* token types */
%union {
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
 
}
%right ASS

%left EQ 
%left AND OR 
%left GE LE  NE GT LT
%left  ADD SUB 
%left MUL DIVIDE MOD 
%left LBRACE RBRACE LC RC  
/// -d --report="cex" 
%nonassoc IF 
%nonassoc ELSE
%nonassoc NOT 
%nonassoc UMINUS
%nonassoc PREFIX

//DIV
%token GE LE EQ NE IF ADD SUB MUL LT GT RETURN NumberType TextType VoidType SPACE THEN JIN DOLAR RAPID_NAN SEAMDATA WELDDATA INPOS CONC ENDFUNC UMINUS 
%token ACCSET VELSET SETDO WAITDI OFFS FUNC INOUT RELTOOl RECORD ENDRECORD PULSEDO WAITTIME_INPOS WOBJ_P SEAM_NAME ZONE_P VEL_P TCP_P NOEOFFS PLEN DOT MAXTIME TIMEFLAG TOOL_P ID_P
%token ASS LR RR COMMA LC RC LESS GREATER COLON FNULL DEVCOLON NOT UNINDENT INDENT
%token FTRUE FFALSE FOR ENDFOR TO FROM SEMICOLON  LBRACE RBRACE
%token LMOVE VAR DO WHILE ENDWHILE TEST ENDTEST RETRY CASE DEFAULT JOINTTARGET ROBTARGET STRING NUM BOOL WOBJDATA ZONEDATA SPEEDDATA TOOLDATA PERS CONST_L
%token ACTUNIT MOVEABSJ ARCLSTART ARCL ARCC ARCEND MOVEL MOVEJ ENDMODULE ENDPROC MODULE PROC AND OR MOD
%token DEACTUNIT ELSEIF WAITTIME WAITUNTIL SET RESET STEP ARCCEND ENDIF TPWRITE TASK 
%token  END    0     "end of file"
%token <dval> Number 
%token <ival> LNumber 
%token <sval> Identifier
%token <sval> String 

//struct_index splash_func_call_parameter
%type<pNode>  ACTUNIT MOVEABSJ ARCLSTART ARCL ARCC ARCEND MOVEL MOVEJ DEACTUNIT  switch_case_define Record_declare  var_decl  array_index  var_assignment inst_modifer 
%type<pNode>  program  expression assignment statement if while_loop return for  switch    declaration   function_call    var_expression  struct_index basic_expr
%type<idenNode> Type
%type<pNode>  offs_expr  reltool_expr  op_expr inst_expr 
//inst_expr_ass
%type <parameterNode> parameter_declaration 
%type <parameterListNode> parameter_declaration_list 

%type <ival> /*type*/ NumberType TextType VoidType  scope1 scope2 scope_pers
%type <functionNode> function_declaration
%type <listNode>  switch_case_list   declaration_list struct_members 
%type <dim_num_stmNode> dim_num_stm
%type<paramWithModifi> paramWithMod_stm
%type <variableNode> variable_declaration variable_for_body
%type <statementListNode> statement_list function_body
%type <listNode> func_call_parameter_list   
%type <listNode> inst_expr_list
//inst_expr_ass_list
%type <elseifListNode> elseif_statment_list
%type <elseif_stmNode> elseif_statment

%type <moduleNode> module
%type <moduleListNode> module_list




%%


program:
    module_list {}
    ;

module_list: 	
	module  {$$ = new ListNode<ModuleNode>($1);}
    | module_list module {$1->push_back($2);}
	;

module: 	
	MODULE Identifier declaration_list ENDMODULE {$$ = new ModuleNode($2,$3);}
	;


declaration_list:
     declaration {$$ = new DeclareListNode($1);}
     | declaration_list declaration  {$1->push_back($2);}
	 ;

declaration: 
     variable_declaration  {$$=$1;}
	| function_declaration {$$=$1;} 
    | var_assignment{$$=$1;} 
    | Record_declare {$$=$1;}
	;

Type: NUM   { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("NUM")); $$ = id;}
	| BOOL  { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("BOOL")); $$ = id;}
	| STRING  { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("STRING")); $$ = id;}
	| ROBTARGET  { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("ROBTARGET")); $$ = id;}
	| JOINTTARGET   {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("JOINTTARGET")); $$ = id;}
    | WOBJDATA {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("WOBJDATA")); $$ = id;}
    | ZONEDATA {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("ZONEDATA")); $$ = id;}
    | SPEEDDATA { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("SPEEDDATA")); $$ = id;}
    | TOOLDATA {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("TOOLDATA")); $$ = id;}
    | SEAMDATA {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("SEAMDATA")); $$ = id;}
    | WELDDATA {IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("WELDDATA")); $$ = id;}
    | Identifier {$$ = new IdentifierNode($1); /*$$ = $1;*/ }
	;

Record_declare:
    RECORD Identifier struct_members ENDRECORD { IdentifierNode* id = new IdentifierNode($2);$$ = new StructDescNode(id, $3); }
    ;

struct_members:
     var_decl { $$ = new  ListNode<ASTNode>(); $$->push_back($1); }
    | struct_members var_decl { $1->push_back($2); }

var_decl:
    Type Identifier SEMICOLON {IdentifierNode* id = new IdentifierNode($2); $$ = new VariableNode(VAR,$1,id,loc); } 
    ;

scope_pers:
  PERS { $$ =  PERS;}
  ;

scope1:   
    TASK PERS { $$ =  TASK_PERS;}
    |
    CONST_L { $$ = eCONST;}
    ;

scope2:
    VAR { $$ =  VAR;}
    ;





function_declaration:
    PROC Identifier LC parameter_declaration_list RC function_body ENDPROC {$$ = new FunctionNode(nullptr, $2, $4, $6); }
    | FUNC Type Identifier LC parameter_declaration_list RC function_body ENDFUNC{$$ = new FunctionNode($2, $3, $5, $7); }
    ;

parameter_declaration_list:
    parameter_declaration { $$ = new ListNode<ParameterNode>($1); }
    | parameter_declaration_list COMMA parameter_declaration {$1->push_back($3);}
    | {$$ = new ListNode<ParameterNode>();}
    ;

parameter_declaration:
    Type Identifier {IdentifierNode* id = new IdentifierNode($2);$$ = new ParameterNode($1,id,nullptr);}
    | INOUT Type Identifier 
    {
        IdentifierNode* inout = new IdentifierNode(&QString::fromLatin1("INOUT"));
        IdentifierNode* id = new IdentifierNode($3);
        $$ = new ParameterNode(inout,$2,id,nullptr);
    }
    ;

func_call_parameter_list:
    expression 	
    {
        $$ = new ListNode<ASTNode>($1); 
    }
    | func_call_parameter_list  COMMA  expression 
	{
        $1->push_back($3);   
	}
	;


//splash_func_call_parameter:
//  {$$=NULL;}
//    |  inst_modifer ASS expression { $$ = new ModifierNode($1,$3);}
//    | inst_modifer {$$ = new ModifierNode($1); }
//    ;


function_body:
  {$$=NULL;}
   | statement_list  {$$ = $1;}
   ;

statement_list:
    statement {$$ = new StatementListNode($1);}
    | statement_list statement {$1->push_back($2);}
    ;

function_call:
    //Identifier LC func_call_parameter_list RC SEMICOLON {$$ = new FunctionCallNode($1, $3);}
      Identifier SEMICOLON { $$ = new FunctionCallNode($1, new ListNode<ASTNode>());}
    |  Identifier func_call_parameter_list SEMICOLON { $$ = new FunctionCallNode($1, $2);}
    ;

inst_modifer:
       CONC { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\Conc")); $$ = id;}
    | TOOL_P { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\Tool")); $$ = id;}
    | PLEN { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\PLength")); $$ = id;}
    | MAXTIME { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\MaxTime")); $$ = id;}
    | TIMEFLAG { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\TimeFlag")); $$ = id;}
    | WOBJ_P  { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\WObj")); $$ = id;}
    | SEAM_NAME { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\SeamName")); $$ = id;}
    | ZONE_P { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\Z")); $$ = id;}
    | INPOS { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\InPos")); $$ = id;}
    | VEL_P { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\V")); $$ = id;}
    | TCP_P { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\T")); $$ = id;}
    | NOEOFFS { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\NoEOffs")); $$ = id;}
    | ID_P { IdentifierNode* id = new IdentifierNode(&QString::fromLatin1("\\ID")); $$ = id;}
    ;

statement:
    variable_for_body {$$ = $1;}
    | assignment  {$$ = $1;}
    | if { $$ = $1; }
    | while_loop { $$ = $1; }
    | for { $$ = $1; }
    | return  { $$ = $1;}
    | function_call {$$ = $1;}
    | MOVEJ func_call_parameter_list SEMICOLON {$$ = new MoveJNode($2);}
    | ACTUNIT func_call_parameter_list SEMICOLON{$$ = new ActUnitNode($2);}
    | ARCLSTART func_call_parameter_list SEMICOLON{$$ = new ArcLStartNode($2);}
    | ARCL func_call_parameter_list SEMICOLON{$$ = new ArcLNode($2);}
    | ARCC func_call_parameter_list SEMICOLON{$$ = new ArccNode($2);}
    | ARCEND func_call_parameter_list SEMICOLON{$$ = new ArcEndNode($2);}
    | MOVEL func_call_parameter_list SEMICOLON{ $$ = new MoveLNode($2);}
    | MOVEABSJ func_call_parameter_list SEMICOLON{$$ = new MoveABSJNode($2);} 
    | DEACTUNIT func_call_parameter_list SEMICOLON{ $$ = new DeActUnitNode($2);}
    | TPWRITE expression SEMICOLON{$$ = new TpWriteNode($2);}
    | ACCSET  expression COMMA expression SEMICOLON{$$ = new AccSetNode($2,$4);} 
    | VELSET expression COMMA expression SEMICOLON{$$ = new VelSetNode($2,$4);} 
    | WAITTIME func_call_parameter_list SEMICOLON {$$ = new WaitTimeNode($2);} 
    | SETDO Identifier COMMA expression SEMICOLON  {IdentifierNode* id = new IdentifierNode($2);$$ = new SetDoNode(id,$4);} 
    | SET Identifier SEMICOLON {IdentifierNode* id = new IdentifierNode($2);$$ = new SetNode(id);} 
    | RESET Identifier SEMICOLON {IdentifierNode* id = new IdentifierNode($2);$$ = new ReSetNode(id);} 
    | WAITDI Identifier COMMA expression SEMICOLON {$$ = new WaitDiNode($2,$4);} 
    | WAITUNTIL expression SEMICOLON {$$ = new WaitUntilNode($2);} 
    | PULSEDO func_call_parameter_list SEMICOLON {  $$ = new PulseDONode($2);}
    | switch {$$ = $1;}
    ;

return:
 RETURN SEMICOLON{$$ = new ReturnNode(NULL); }
|    RETURN expression SEMICOLON{$$ = new ReturnNode($2); }
;

while_loop:
    WHILE /*LC*/ expression /*RC*/ DO function_body ENDWHILE{ $$ = new WhileNode($2, $4); }
    ;

switch:
    TEST expression switch_case_list ENDTEST
    {
        $$ = new SWitchNode($2,$3,NULL);
    }
    ;

    
switch_case_list:
	switch_case_define
	{
        $$ = new SWitchCaseListNode($1);
	}
	|
	switch_case_list switch_case_define
	{
        $1->push_back($2);   
	}
	;

switch_case_define:
	CASE expression COLON function_body
	{
        $$ = new CaseNode($2,$4); //$$->dimListType->push_back($1);
	}
	;

for:
    FOR Identifier FROM expression TO expression STEP expression DO function_body ENDFOR {  IdentifierNode* id = new IdentifierNode($2);$$ = new ForNode(id,$4,$6,$8,$10);}
    ;

if:
    IF  expression  THEN function_body ENDIF { $$ = new IfNode($2, $4); }
    | IF  expression statement { $$ = new IfNode($2, $3); }
    | IF expression THEN function_body elseif_statment_list ENDIF { $$ = new IfNode($2, $4, $5); }
;

elseif_statment_list:
     elseif_statment {$$ = new ListNode<ElseIfNode>($1);}
    | elseif_statment_list elseif_statment {$1->push_back($2);}
    ;     

elseif_statment:
    ELSE  function_body { $$ = new ElseIfNode($2); }
    | ELSEIF expression THEN function_body { $$ = new ElseIfNode($2, $4); }
    ;


variable_declaration:
     scope1 Type var_expression SEMICOLON { $$ = new VariableNode($1,$2,$3,loc);}
    | scope_pers Type var_expression SEMICOLON { $$ = new VariableNode($1,$2,$3,loc);}
    | scope2 Type var_expression SEMICOLON { $$ = new VariableNode($1,$2,$3,loc);}
    ;

variable_for_body:
    scope2 Type var_expression SEMICOLON { $$ = new VariableNode($1,$2,$3,loc);}
    | scope2 Type Identifier ASS expression SEMICOLON { IdentifierNode* id = new IdentifierNode($3);$$ = new VariableNode($1,$2,id,$5,loc);}
    | scope2 Type  array_index ASS expression  SEMICOLON { $$ = new VariableNode($1,$2,$3,$5,loc);}
    | scope2 Type struct_index ASS expression SEMICOLON { $$ = new VariableNode($1,$2,$3,$5,loc);}
    ;

var_expression:
    Identifier { $$ = new IdentifierNode($1); }
    | array_index { $$ = $1; }
    | struct_index {$$ = $1; }
    //| inst_modifer { $$ = $1;}

    ;

var_assignment:
    scope1 Type Identifier ASS expression SEMICOLON { IdentifierNode* id = new IdentifierNode($3);$$ = new VariableNode($1,$2,id,$5,loc);}
    | scope2 Type Identifier ASS expression SEMICOLON { IdentifierNode* id = new IdentifierNode($3);$$ = new VariableNode($1,$2,id,$5,loc);}
    | scope_pers Type Identifier ASS expression SEMICOLON { IdentifierNode* id = new IdentifierNode($3);$$ = new VariableNode($1,$2,id,$5,loc);}
    | scope1 Type  array_index ASS expression  SEMICOLON { $$ = new VariableNode($1,$2,$3,$5,loc);}
    | scope2 Type  array_index ASS expression  SEMICOLON { $$ = new VariableNode($1,$2,$3,$5,loc);}
    | scope_pers Type  array_index ASS expression  SEMICOLON { $$ = new VariableNode($1,$2,$3,$5,loc);}
    | scope1 Type struct_index ASS expression SEMICOLON { $$ = new VariableNode($1,$2,$3,$5,loc);}
    | scope2 Type struct_index ASS expression SEMICOLON { $$ = new VariableNode($1,$2,$3,$5,loc);}
    | scope_pers Type struct_index ASS expression SEMICOLON { $$ = new VariableNode($1,$2,$3,$5,loc);}
    ;

assignment:
    //var_expression ASS expression SEMICOLON {IdentifierNode* id = new IdentifierNode($1); $$ = new AssignmentNode(id, $3);}
    //|
    var_expression ASS expression 
    { 
        $$ = new AssignmentNode($1, $3);
    }
    | 
    var_expression ASS expression SEMICOLON
    {
        $$ = new AssignmentNode($1, $3);
    }

    ;

dim_num_stm:
	expression 	
    {
        $$ = new DimNumsNode($1); 
    }
	| dim_num_stm  COMMA  expression 
	{
       $1->push_back($3);   
	}
	;

struct_index:
    var_expression DOT Identifier  { IdentifierNode* id = new IdentifierNode($3);$$ = new StructIndexNode($1,id); }
   ;

array_index: 
 Identifier LBRACE expression RBRACE {IdentifierNode* id = new IdentifierNode($1);$$ = new ArrayIndexNode(id, $3);}
 ;

offs_expr:
 OFFS LC func_call_parameter_list RC {$$ = new OffsNode($3);}
 ;

reltool_expr:
RELTOOl LC func_call_parameter_list RC  {$$ = new RelToolNode($3);}
;

op_expr:
   expression ADD expression { $$ = new OperatorNode(token::ADD, $1, $3); }
 | expression SUB expression { $$ = new OperatorNode(token::SUB, $1, $3); }
 | SUB expression  %prec UMINUS{ $$ = new OperatorNode(token::UMINUS, $2); }
 | expression MUL expression { $$ = new OperatorNode(token::MUL, $1, $3); }
 | expression LT expression { $$ = new OperatorNode(token::LT, $1, $3); }
 | expression GT expression { $$ = new OperatorNode(token::GT, $1, $3); }
 | expression GE expression { $$ = new OperatorNode(token::GE, $1, $3); }
 | expression LE expression { $$ = new OperatorNode(token::LE, $1, $3); }
 | expression NE expression { $$ = new OperatorNode(token::NE, $1, $3); }
 | expression EQ expression { $$ = new OperatorNode(token::EQ, $1, $3); }
 | expression AND expression {$$ = new OperatorNode(token::AND, $1, $3);}
 | expression OR expression {$$ = new OperatorNode(token::OR, $1, $3);}
 | expression MOD expression {$$ = new OperatorNode(token::MOD, $1, $3);}
 //| expression ASS expression { $$ = new OperatorNode(token::ASS, $1, $3); }
 //| ADD expression  %prec PREFIX{ $$ = new OperatorNode(token::UMINUS, $2); }
 | NOT expression %prec PREFIX{$$ = new OperatorNode(token::NOT, $2);}  
 | LC expression RC {$$ = $$ = new OperatorNode(token::LC, $2);}
 ;

 inst_expr:
  inst_modifer {$$ = $1;}
  | inst_modifer  ASS basic_expr 
  {
        $$ = new AssignmentNode($1, $3);
   }
 //| inst_modifer  ASS  String { StringLiteralNode* str = new StringLiteralNode($3);$$ = new AssignmentNode($1,str);} 
 // | inst_modifer  ASS var_expression 
 //{
 //       $$ = new AssignmentNode($1, $3);
// }
 ;

inst_expr_list:
  inst_expr {$$ = new ListNode<ASTNode>($1); }
  | inst_expr_list inst_expr { $1->push_back($2);   }
  ;


basic_expr:
 //RAPID_NAN { $$ = new StringLiteralNode(true,&QString::fromLatin1("9E+09"));}
 String { $$ = new StringLiteralNode($1);}
 | FNULL { $$ = new NullNode();}
 | Number {$$ = new NumberLiteralNode($1); }
 | LNumber {$$ = new Integer($1); }
 | FTRUE {$$ = new Boolean(1);}
 | FFALSE {$$ = new Boolean(0);}
 | var_expression {$$ = $1;}

 | offs_expr{$$ = $1;}
 | reltool_expr { $$ = $1;}
  | Identifier LC func_call_parameter_list RC  { $$ = new FunctionCallNode($1, $3);}
 |  LR dim_num_stm RR {$$ = $2;}
 ;

expression:
    basic_expr {$$=$1;}
 | paramWithMod_stm {$$=$1;}
 | inst_expr_list {$$=$1;}
 |  op_expr {$$ = $1;}
 ;

 paramWithMod_stm:
  var_expression inst_expr_list {$$ = new  ParamWithModifierNode($1,$2); }
  ;

%%


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
