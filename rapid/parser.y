%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
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
}

%lex-param   { Lexer  &lexer  }
%parse-param { Lexer  &lexer  }

%code{
    #include "translator.hpp"
    #include "ast.h"

    
    extern int lineNumber;
    static int yylex(Language::Parser::semantic_type *yylval, Language::Lexer  &lexer);
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
   ListNode<ParamNode>* paramListNode;
   ListNode<ElseIfNode>* elseifListNode;
   ListNode<ModuleNode>* moduleListNode;
   ModuleNode* moduleNode;
   StatementListNode * statementListNode;

   ElseIfNode* elseif_stmNode;
   DimNumsNode*     dim_num_stmNode;
  
}

%left GE LE EQ NE GREATER LESS
%left MINUS ADD SUB
%left MULTIP DEVIDE
%nonassoc UMINUS
%nonassoc IFX
%nonassoc ELSE

//DIV
%token GE LE EQ NE IF ADD SUB MUL LT GT RETURN NumberType TextType VoidType SPACE THEN JIN DOLAR RAPID_NAN SEAMDATA WELDDATA
%token ASS LR RR COMMA LC RC LESS GREATER COLON FNULL DEVCOLON
%token FTRUE FFALSE FOR ENDFOR TO FROM SEMICOLON SPLASH LBRACE RBRACE
%token LMOVE VAR DO WHILE ENDWHILE TEST ENDTEST RETRY CASE DEFAULT JOINTTARGET ROBTARGET STRING NUM BOOL WOBJDATA ZONEDATA SPEEDDATA TOOLDATA PERS CONST
%token ACTUNIT MOVEABSJ ARCLSTART ARCL ARCC ARCEND MOVEL MOVEJ ENDMODULE ENDPROC MODULE PROC AND OR MOD
%token DEACTUNIT ELSEIF WAITTIME WAITUNTIL SET RESET STEP ARCCEND ENDIF TPWRITE TASK
%token  END    0     "end of file"
%token <dval> Number 
%token <ival> LNumber 
%token <sval> Identifier
%token <sval> String 


%type<pNode>  ACTUNIT MOVEABSJ ARCLSTART ARCL ARCC ARCEND MOVEL MOVEJ DEACTUNIT  switch_case_define     
%type<pNode>  program  expression assignment statement if while_loop return for  switch    declaration   function_call func_call_parameter splash_func_call_parameter
%type <parameterNode> parameter_declaration 
%type <parameterListNode> parameter_declaration_list 

%type <ival> /*type*/ NumberType TextType VoidType Type modifiability scope
%type <functionNode> function_declaration
%type <listNode>  switch_case_list   declaration_list
%type <variableNode> variable_declaration
%type <statementListNode> statement_list function_body
%type <dim_num_stmNode> dim_num_stm
%type <listNode> func_call_parameter_list splash_func_call_parameter_list
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

declaration: variable_declaration  {$$=$1;}
	| function_declaration {$$=$1;} 
	;

Type: NUM   { $$ = NUM;}
	| BOOL  { $$ = eBOOL;}
	| STRING  { $$ = eSTRING;}
	| ROBTARGET  { $$ = ROBTARGET;}
	| JOINTTARGET   { $$ = JOINTTARGET;}
    | WOBJDATA { $$ = WOBJDATA;}
    | ZONEDATA { $$ = ZONEDATA;}
    | SPEEDDATA { $$ = SPEEDDATA;}
    | TOOLDATA { $$ = TOOLDATA;}
    | SEAMDATA {$$ = SEAMDATA;}
    | WELDDATA {$$= WELDDATA;}
	;

scope:
     PERS { $$ =  PERS;}
     |
     TASK PERS { $$ =  TASK_PERS;}
     ;

modifiability:
    CONST { $$ = eCONST;}
    |
    VAR { $$ =  VAR;}
    ;





function_declaration:
    PROC Identifier LC parameter_declaration_list RC function_body ENDPROC {$$ = new FunctionNode(token::VoidType, $2, $4, $6); }
    ;

parameter_declaration_list:
    parameter_declaration { $$ = new ListNode<ParameterNode>($1); }
    | parameter_declaration_list COMMA parameter_declaration {$1->push_back($3);}
    | {$$ = new ListNode<ParameterNode>();}
    ;

parameter_declaration:
    Type Identifier {$$ = new ParameterNode($2);}
    | VAR Type Identifier  {$$ = new ParameterNode($3);}
    ;

func_call_parameter_list:
        func_call_parameter {$$ = new ListNode<ASTNode>($1); }
        | func_call_parameter_list COMMA func_call_parameter {$1->push_back($3);}
        | {$$ = new ListNode<ASTNode>();}
        ;

func_call_parameter:
        Identifier {$$ = new ParamNode($1);}
        | Identifier splash_func_call_parameter_list {$$ = new ParamNode($1,$2);};

splash_func_call_parameter:
    SPLASH assignment {$$ = $2; }
    ;

 splash_func_call_parameter_list:
    splash_func_call_parameter { $$ = new ListNode<ASTNode>($1); }
    | splash_func_call_parameter_list splash_func_call_parameter { $$->push_back($2); }
    | {$$ = new ListNode<ASTNode>();}
    ;
function_body:
   {$$=NULL;}
   | statement_list  {$$ = $1;}
   ;

statement_list:
    statement {$$ = new StatementListNode($1);}
    | statement_list statement {$1->push_back($2);}
    ;


function_call:
    Identifier LC func_call_parameter_list RC SEMICOLON {$$ = new FunctionCallNode($1, $3);}
    |  Identifier SEMICOLON { $$ = new FunctionCallNode($1, new ListNode<ASTNode>());}
    ;

statement:
    parameter_declaration  { $$ = $1;}
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
    | switch {$$ = $1;}
    ;

return:
    RETURN /*expression*/ {$$ = new ReturnNode(NULL); }
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
    FOR Identifier FROM expression TO expression STEP expression DO function_body ENDFOR { $$ = new ForNode($2,$4,$6,$8);}
    ;

if:
    IF  expression  THEN function_body ENDIF { $$ = new IfNode($2, $4); }
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
      scope Type assignment SEMICOLON {$$ = new VariableNode($1,$2,$3);}
    | modifiability Type assignment SEMICOLON {$$ = new VariableNode($1,$2,$3);}
    | scope Type Identifier SEMICOLON {IdentifierNode* id = new IdentifierNode($3); $$ = new VariableNode($1,$2,id);}
    | modifiability Type Identifier SEMICOLON {IdentifierNode* id = new IdentifierNode($3); $$ = new VariableNode($1,$2,id);}
    | scope Type Identifier LBRACE dim_num_stm RBRACE SEMICOLON {IdentifierNode* id = new IdentifierNode($3); $$ = new VariableNode($1,$2,id,$5);}
    | modifiability Type Identifier LBRACE dim_num_stm RBRACE SEMICOLON {IdentifierNode* id = new IdentifierNode($3); $$ = new VariableNode($1,$2,id,$5);}
    ;



assignment:
    Identifier ASS expression { $$ = new AssignmentNode($1, $3);}
    |
    Identifier LBRACE dim_num_stm RBRACE ASS expression 
    { 
        $$ = new AssignmentNode($1, $6, $3);
    }
    | 
    Identifier ASS LR dim_num_stm RR { 
        $$ = new AssignmentNode($1, $4);
    }
    |
    Identifier LBRACE dim_num_stm RBRACE ASS LR dim_num_stm RR
    { 
        $$ = new AssignmentNode($1, $7 , $3);
    }
    ;

dim_num_stm:
	expression 	{
        $$ = new DimNumsNode($1); 
    }
	| dim_num_stm  COMMA  expression 
	{
        $1->push_back($3);   
	}
	;

expression:
 {$$=NULL;}
 | Identifier { $$ = new IdentifierNode($1); }
 | RAPID_NAN { $$ = new NumberLiteralNode(9e9);}
 | String { $$ = new StringLiteralNode($1);}
 | FNULL { $$ = new NullNode();}
 | Number {$$ = new NumberLiteralNode($1); }
 | FTRUE {$$ = new NumberLiteralNode(1);}
 | FFALSE {$$ = new NumberLiteralNode(0);}
 | expression ADD expression { $$ = new OperatorNode(token::ADD, $1, $3); }
 | expression SUB expression { $$ = new OperatorNode(token::SUB, $1, $3); }
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
 | SUB expression %prec UMINUS { $$ = new OperatorNode(token::UMINUS, $2); }
 | LR expression RR {$$ = new ArrayDataNode($2);}
 | LR dim_num_stm RR {$$ = new ArrayDataNode($2);}
 ;


%%



void Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: Line:" << lineNumber << "' - " << err_message << "\n";
}

static int yylex( Language::Parser::semantic_type *yylval, Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval) );
}

