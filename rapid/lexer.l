%{
#include <QString>
#include <string>
#include <stack>
#include <iostream>
#include <cerrno>
#include <climits>
#include <stdio.h>
#include <fstream>
#include "lexer.hpp"
typedef Language::Parser::token token;
#define yyterminate() return( token::END )
#define YY_NO_UNISTD_H // For msvc



using namespace Language;

#define YYERROR_VERBOSE 1
Language::location loc;//ÉùÃ÷Î»ÖÃÊµÀý

std::string cur_yytext;
std::string g_str;
int yycolumn = 1;
int yylineno = 1;
int current_line_indent = 0;   /* indentation of the current line */
int indent_level = 0;          /* indentation level passed to the parser */
std::stack<int> curr_indents;
int first_time = 1 ;

int parsing_error = 0;

std::stack<std::string> fileNames;
std::stack<int> lineNo;
std::vector<std::string> libPaths;



#define YY_USER_ACTION do { \
    if( loc.end.line < yylineno ) yycolumn = 1 ; \
    loc.begin.line = loc.end.line = yylineno; \
    loc.begin.column = yycolumn; loc.end.column = yycolumn + (int)yyleng - 1; \
    yycolumn += (int)yyleng; \
    loc.end.filename = &(fileNames.top()); \
    } while(0) ;

int yyerror(char const * s )
{
    printf("ERROR %s  at line %d col %d\n", s,  yylineno, yycolumn);
    printf("parsed %s %d.%d-%d.%d\n", loc.end.filename->c_str(), loc.begin.line, loc.begin.column, loc.end.line, loc.end.column);
    return 1;
}

%}



%option debug
%option yyclass="Lexer"
%option noyywrap 
%option caseless c++
%option yylineno 
%option prefix="D_yy"

%x indent 
%s normal 
%x str qstr
%x comment
%x incl




dig     [0-9]
lnum    {dig}+([eE][-+]?{dig}+)?
num1    {dig}+\.([eE][-+]?{dig}+)?
num2    {dig}*\.{dig}+([eE][-+]?{dig}+)?
number  {num1}|{num2}|{lnum}



PERS        PERS
TOOLDATA    tooldata
SPEEDDATA   SPEEDDATA
ZONEDATA    zonedata
NOT NOT
WOBJDATA    wobjdata
BOOL        BOOL
NUM         NUM
STRING      STRING
VAR         VAR
ROBTARGET   robtarget
JOINTTARGET jointtarget
CONST_L       CONST
SET         SET
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
TPWRITE     TPWrite
RESET       RESET
STEP        STEP

ACCSET AccSet
VELSET VelSet
WAITTIME WaitTime
SETDO SetDO
WAITDI WaitDI
WAITUNTIL WaitUntil
OFFS Offs
FUNC FUNC
ENDFUNC ENDFUNC
INOUT INOUT
RELTOOl RelTool
RECORD RECORD
ENDRECORD ENDRECORD
PULSEDO PulseDO



%%



            if( first_time ) {
                first_time = 0;
                curr_indents.push(0);
                lineNo.push(yylineno);
                BEGIN normal;
            }

            
import              BEGIN(incl);
<incl>[ \t]*        /* eat the whitespace */
<incl>[^ \t\n\r]+   { /* got the include file name */
                    std::string fileName = yytext;
                    std::size_t pos = fileName.find(".liq");
                    if( pos == std::string::npos ) {
                        fileName += ".liq";
                    }
                    std::string filePath="";
                    for( auto libpath : libPaths ) {
                       filePath = libpath + fileName;
                       std::ifstream file(filePath.c_str());
                       if(file.good())
                          break;
                    }
                    std::filebuf fb;
                    if (fb.open (filePath,std::ios::in))
                    {
                         std::istream is(&fb);
                         //yyin = is;
                         fileNames.push(std::string(yytext));
                         lineNo.push(yylineno);
                         yylineno = yycolumn = 1;
                         loc.begin.line = loc.begin.column = loc.end.line = loc.end.column = 1;
                         yypush_buffer_state(yy_create_buffer( is, YY_BUF_SIZE ));
                         fb.close();
                    }
                    else
                    {
                         printf( "%s in %s line %d\n", (std::string("Failed to load import file ") + fileName).c_str(), fileNames.top().c_str(), yylineno );
                         parsing_error = 1;
                         yyterminate();
                    }

                    BEGIN(normal);
                    }

<normal>"\n"     { current_line_indent = 0; /*BEGIN( indent);*/ yycolumn = 1; }
<<EOF>>          {
                   if( curr_indents.size() > 1 ) {
                        curr_indents.pop();
                        return token::UNINDENT;
                   }
                   if(lineNo.size() > 1 ) {
                       yypop_buffer_state();
                       fileNames.pop();
                       yylineno = lineNo.top();
                       lineNo.pop();
                   } else {
                        yyterminate();
                   }
                 }			 
				 



\"      g_str = ""; BEGIN(str);
'       g_str = ""; BEGIN(qstr);

<str>\" {   BEGIN(normal);
            yylval->sval = new QString(QString::fromStdString(g_str));
            return token::String;
        }
<qstr>' {   BEGIN(normal);
            yylval->sval = new QString(QString::fromStdString(g_str));
            return token::String;
        }

<str,qstr>\\n   {g_str += "\n";}
<str,qstr>\\t   g_str += "\t";
<str,qstr>\\r   g_str += "\r";
<str>\\\"       g_str += "\"";
<qstr>\\\'      g_str += "'";

<str,qstr>\\(.|\n)  {g_str += yytext[1]; cur_yytext=yytext[1];}

<str>[^\\\"]+  {g_str += std::string(yytext);cur_yytext=yytext;}
<qstr>[^\\']+  {g_str += std::string(yytext);cur_yytext=yytext;}






{number}	{
                                                        yylval->dval = atof(yytext);
                                                        cur_yytext=yytext;
                                                        return token::Number;
                                                }

                                


"number"					{ return token::NumberType; }
"text"	 					{ return token::TextType; }
"void" 						{ return token::VoidType; }

"\\WObj"             { return token::WOBJ_P; }
"\\SeamName"             { return token::SEAM_NAME; }
"\\Z"             { return token::ZONE_P; }
"\\V"             { return token::VEL_P; }
"\\T"             { return token::TCP_P; }
"\\NoEOffs"        { return token::NOEOFFS; }
"\\Tool"           { return token::TOOL_P; }
"\\PLength"       { return token::PLEN; }
"\\MaxTime"       { return token::MAXTIME; }
"\\TimeFlag"       { return token::TIMEFLAG; }
"\\InPos"       { return token::INPOS; }
"\\Conc"         { return token::CONC; }
"\\ID"         { return token::ID_P; }

{NOT}           { return token::NOT; }
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


SPACE       [ \f\n\r\t\v]+
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
{CONST_L}                      {return token::CONST_L;}
{TPWRITE}                      {return token::TPWRITE;}
{NULL}                      {return token::FNULL;}

{WAITTIME}       {return token::WAITTIME;}
{SET}       {return token::SET;}
{RESET}       {return token::RESET;}
{TASK}          {return token::TASK;}
{STEP}          {return token::STEP;}


{ACCSET}          {return token::ACCSET;}
{VELSET}          {return token::VELSET;}
{SETDO}          {return token::SETDO;}
{WAITDI}          {return token::WAITDI;}
{WAITUNTIL}          {return token::WAITUNTIL;}
{OFFS}          {return token::OFFS;}
{FUNC}          {return token::FUNC;}
{ENDFUNC}						{ return token::ENDFUNC; }
{INOUT}          {return token::INOUT;}
{RELTOOl}          {return token::RELTOOl;}
{RECORD}          {return token::RECORD;}
{ENDRECORD}          {return token::ENDRECORD;}
{PULSEDO}          {return token::PULSEDO;}



"\."                          {return token::DOT;}
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
"\\"                     {return token::SPLASH;}
"#"  {return token::JIN;}
"+"  { return token::ADD; }
"-"  { return token::SUB; }
"/"  { return token::DIVIDE; }
"*"  { return token::MUL; }
":"    { return token::COLON; }  
"<"     {return token::LT;}
">"     {return token::GT;}
"$"     {return token::DOLAR;}
!.*                     /* comments one line til nl */

[a-z|A-Z]([a-z|A-Z|0-9|_]+)?			{
                                                        yylval->sval = new QString( yytext );
                                                        cur_yytext=yytext;
                                                        return( token::Identifier );
                                             }





%%




