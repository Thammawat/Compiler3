
%option noyywrap

%{
#include <stdio.h>

#define YY_DECL int yylex()
#include "calc.tab.h"
%}

%%

[ \t]	; // ignore all whitespace
[0-9]+\.[0-9]+ 	{yylval.fval = atof(yytext); return T_FLOAT;}
[0-9]+		{yylval.ival = atoi(yytext); return T_INT;}
[a-f0-9]+"h" {yylval.ival = strtol(yytext, 0, 16); return T_INT;}
"$r"+[A-Z]    {yylval.id = yytext[2]-65; return identifier;}
"$acc"  {return Answer;}
"showhex"  {return ShowHex;} //แสดงค่าเลขฐาน 16
"show"  {return Show;} //แสดง string char เลขฐานทั่วไป
"load"  {return Load;}
"Push"  {return Push;}
"push"  {return Push;}
"Pop"   {return Pop;}
"pop"   {return Pop;}
"Top"   {return Top;}
"top"   {return Top;}
"size"  {return Size;}
"Size"  {return Size;}
"is"    {return IS;}
([\r\n]+[\t]+)+?[\r\n]+	{return T_NEWLINE;} 
"="     {return EQUAL;} //รับค่าเครื่องหมายทางคณิตศาสตร์
"+"		{return T_PLUS;}
"-"		{return T_MINUS;}
"*"		{return T_MULTIPLY;}
"/"		{return T_DIVIDE;}
"("		{return T_LEFT;}
")"		{return T_RIGHT;}
"^"     {return T_RAISED;}
"%"     {return T_MOD;}
"exit"	{return T_QUIT;} 
"quit"	{return T_QUIT;}
"and"    {return AND;}
"or"     {return OR;}
"!"      {return NOT;}
"!="     {return Not_EQUAL;}
"'"      {return Single_Quotes;}
"\""     {return Double_Quotes;}
"loop"   {return For;} //ใช้ทำลูป
"if"    {return IF;}  //ใช้ทำเงื่อนไข
">"      {return MoreThan;}
"<"      {return LessThan;}
">="     {return MoreThan_EQUAL;}
"<="     {return LessThan_EQUAL;}
"{"      {return OPENLOOP;}
"}"      {return ENDLOOP;}
"else"   {return ELSE;}      

[a-zA-Z]     {yylval.id= yytext[0]; return Char;}        //รับค่าสติงเปลี่ยนเป็น Char
[a-zA-Z,$+]+ {yylval.s=strdup(yytext); return(String); } //รับค่า Stringเป็นสายอักษรa-z,A-Zและ$

%%