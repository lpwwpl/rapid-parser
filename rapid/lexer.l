%{

#include <QString>
#include "lexer.hpp"
	//eGlobal = 0;
	//eLocal =1;
extern int lineNumber;

typedef Language::Parser::token token;
QString buf;
#define yyterminate() return( token::END )
#define YY_NO_UNISTD_H // For msvc

%}

%option debug
%option yyclass="Lexer"
%option  noyywrap 
%option c++
%x SINGLE_LINE_COMMENT_STATE
%x TRANS_LINES_STATE

SPACE       [ \f\n\r\t\v]+
GAP         [ \f\n\r\t\v]*
PERS        PERS
TOOLDATA    tooldata
SPEEDDATA   SPEEDDATA
ZONEDATA    zonedata
WOBJDATA    wobjdata
BOOL        BOOL
NUM         NUM
STRING      STRING
VAR         VAR
ROBTARGET   robtarget
JOINTTARGET jointtarget
CONST       CONST
SET         SET
WAITTIME    WAITTIME
WAITUNTIL   WAITUNTIL
IF          IF
SEAMDATA    seamdata
ELSE        ELSE
ELSEIF      ELSEIF
ENDIF       ENDIF
THEN        THEN
RETURN      RETURN
ACTUNIT     ActUnit
MOVEABSJ    MoveAbsJ    
ARCLSTART   ArcLStart
WELDDATA    welddata
ARCL        ArcL
ARCC        ArcC
ARCEND      ArcCEnd
MOVEL       MoveL
MOVEJ       MoveJ
DEACTUNIT   DeactUnit
PROC        PROC
ENDPROC     ENDPROC
MODULE      MODULE
ENDMODULE   ENDMODULE

FINE        FINE
AND         AND
OR          OR
NULL        NULL
TRUE        TRUE
FALSE       FALSE
FROM        FROM
DO          DO
ENDFOR      ENDFOR

WHILE       WHILE
ENDWHILE    ENDWHILE
FOR         FOR
TO          TO
MOD         MOD
CASE        CASE
DEFAULT     DEFAULT
TEST        TEST
ENDTEST     ENDTEST
RETRY       RETRY
TASK        TASK
TPWRITE     TPWRITE
RESET       RESET
STEP        STEP

%%

"!"	yy_push_state(SINGLE_LINE_COMMENT_STATE);
<SINGLE_LINE_COMMENT_STATE>{
	[^\n]*	;
	"\n"	{
		yy_pop_state(); 
	}
}                                                 



[\n]            				{ lineNumber++; }

\/\/(.)* ;
\"(\\.|[^"])*\" 				{
                                        yylval->sval = new QString( yytext );
                                        return token::String;
                                }

                         

(-?[0-9]+|(-?[0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)	{
                                                        yylval->dval = atof(yytext);
                                                        return token::Number;
                                                }

^[1-9]\d*$            {
                                      yylval->ival = atoi(yytext);
                                       return token::LNumber;
                     }                                     


"number"					{ return token::NumberType; }
"text"	 					{ return token::TextType; }
"void" 						{ return token::VoidType; }

{IF}						{ return token::IF; }
{WELDDATA}                  {return token::WELDDATA;}
{SEAMDATA}                  {return token::SEAMDATA;}
{ELSE} 						{ return token::ELSE; }
{ELSEIF} 						{ return token::ELSEIF; }
{THEN}                      { return token::THEN; }
{ENDIF} 						{ return token::ENDIF; }
{RETURN}  					{ return token::RETURN; }
{WHILE}                       {return token::WHILE;}
{DO}		                {return token::DO;}   
{ENDWHILE}                       {return token::ENDWHILE;}
{TEST}	                    {return token::TEST;}   	
{ENDTEST}	                    {return token::ENDTEST;}   	
{PROC}	                {return token::PROC;}  
{ENDPROC}                      {return token::ENDPROC;}
{CASE}                       {return token::CASE;}
{DEFAULT}                      {return token::DEFAULT;}
{AND}                       {return token::AND;}
{OR}                        {return token::OR;}
{MOD}                       { return token::MOD;}
{WAITTIME}                      {return token::WAITTIME;}
{SPACE}      {}
{TRUE}   {return token::FTRUE;}
{FALSE}  {return token::FFALSE;}
{RETRY}  {return token::RETRY;}
{FOR}           {return token::FOR;}
{TO}            {return token::TO;}
{FROM}          {return token::FROM;}
{ENDFOR}	                    {return token::ENDFOR;}   


{ACTUNIT}                      {return token::ACTUNIT;}
{MOVEABSJ}                      {return token::MOVEABSJ;}
{ARCLSTART}                      {return token::ARCLSTART;}
{ARCL}                      {return token::ARCL;}
{ARCC}                      {return token::ARCC;}
{ARCEND}                      {return token::ARCEND;}
{MOVEL}                      {return token::MOVEL;}
{MOVEJ}                      {return token::MOVEJ;}
{DEACTUNIT}                      {return token::DEACTUNIT;}



{PERS}                      {return token::PERS;}
{MODULE}                      {return token::MODULE;}
{ENDMODULE}                      {return token::ENDMODULE;}
{TOOLDATA}                      {return token::TOOLDATA;}
{SPEEDDATA}                      {return token::SPEEDDATA;}
{ZONEDATA}                      {return token::ZONEDATA;}
{WOBJDATA}                      {return token::WOBJDATA;}
{BOOL}                      {return token::BOOL;}
{NUM}                      {return token::NUM;}
{STRING}                      {return token::STRING;}
{VAR}                      {return token::VAR;}
{ROBTARGET}                      {return token::ROBTARGET;}
{JOINTTARGET}                      {return token::JOINTTARGET;}
{CONST}                      {return token::CONST;}
{TPWRITE}                      {return token::TPWRITE;}
{NULL}                      {return token::FNULL;}

{WAITTIME}       {return token::WAITTIME;}
{WAITUNTIL}       {return token::WAITUNTIL;}
{SET}       {return token::SET;}
{RESET}       {return token::RESET;}
{TASK}          {return token::TASK;}
{STEP}          {return token::STEP;}
":="                         {return token::ASS;}
"="                         {return token::EQ;}
";" 						{ return token::SEMICOLON; }
">=" 						{ return token::GE; }
"<>" 						{ return token::NE; }
"<=" 						{ return token::LE; }
"["                    { return token::LR; }
"]"                    { return token::RR; }
","                     { return token::COMMA; }
"("                     { return token::LC; }
")"                     { return token::RC; }
"{"                      { return token::LBRACE; }
"}"                      { return token::RBRACE; }
"9E9"                      {return token::RAPID_NAN;}
"\\"                     {return token::SPLASH;}
"#"  {return token::JIN;}
"+"  { return token::ADD; }
"-"  { return token::SUB; }
"%"  { return token::DEVCOLON; }
"*"  { return token::MUL; }
":"    { return token::COLON; }  
"<"     {return token::LT;}
">"     {return token::GT;}
"$"     {return token::DOLAR;}


[.#|$]?[a-z|A-Z]([a-z|A-Z|0-9|_|.]+)?			{
                                                        yylval->sval = new QString( yytext );
                                                        return( token::Identifier );
                                             }

	

%%
