%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

#define N 19


int id_or_keyword(char *s);

%}

%%


"*"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('*');
                            }
"/"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('/');
                            }
"+"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('+');
                            }
"-"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('-');
                            }
"%"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('%');
                            }							
"++"                        {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(INCREASE_SIGN);
                            }						
"--"                        {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(DECREASE_SIGN);
                            }
"=="                        {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(IS_EQUAL);
                            }
"!="                        {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(IS_NOT_EQUAL);
                            }
"!"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(NOT_SIGN);
                            }
">"                        	{
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('>');
                            }
"<"                       	{
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('<');
                            }
"<="                        {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(IS_LESS_OR_EQUAL);
                            }
">="                        {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(IS_GREATER_OR_EQUAL);
                            }
"="                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('=');
                            }
"+="                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(PLUS_EQUALS_SIGN);
                            }
"-="                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(MINUS_EQUALS_SIGN);
                            }
"*="                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(TIMES_EQUALS_SIGN);
                            }
"/="                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(DIVIDE_EQUALS_SIGN);
                            }
"("                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('(');
                            }
")"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(')');
                            }
"["                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('[');
                            }
"]"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(']');
                            }
"{"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('{');
                            }
"}"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return('}');
                            }
","                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(',');
                            }
";"                         {
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(';');
                            }	
"//".*						{
                               //printf("COMMENT: %s",yytext);
                               //strcpy(yylval.ystr,yytext);					
							}
'([^'\\\n]|\\0|\\n|\\\\)'	{
								yytext++; // remove first character (')
								yytext[strlen(yytext)-1] = 0; // remove last character (')
								//printf("STRING %s", yytext);
								strcpy(yylval.ystr,yytext);
								return(CHAR_CONST);
							}	
'							{								
								printf("Unaccepted char literal\n");
								exit(1);
							}
\"(\\.|[^"])*\"				{
								yytext++; // remove first character (")
								yytext[strlen(yytext)-1] = 0; // remove last character (")
								//printf("STRING %s", yytext);
								strcpy(yylval.ystr,yytext);
								return(TEXT);
							}
[0-9][0-9]*					{
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(INT_CONST);
                            }	
[0-9]+"."[0-9]+				{
                               //printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(REAL_CONST);
                            }							
[a-zA-Z]([a-zA-Z0-9_])*  	{  
								int i;

                               //printf("%s",yytext);
                               i=id_or_keyword(yytext);
                               if(i==ID) 
                                  strcpy(yylval.ystr,yytext);
                               else 
                                  yylval.yint=i;
                               return(i);
                            }
[ \f\n\r\t]+                {
								//printf("%s",yytext);
								/*int i;
								for (i=0; i<strlen(yytext); i++){
									//printf("%d",yytext[i]); 
								}*/
							}
.                           {
								printf("Unkown character: %s\n",yytext);
								exit(1);
                            }    

%%

static char *kid[N]={"if", "else", "while", "break", "return", "int", "real", "char", "true", "false", "print", "read", "repeat", "times", "unless", "and", "or", "for", "println"};
static int kval[N]={IF, ELSE, WHILE, BREAK, RETURN, INT, REAL, CHAR, TRUE, FALSE, PRINT, READ, REPEAT, TIMES, UNLESS, AND, OR, FOR, PRINTLN};

int id_or_keyword(char *s)
{  
	int i;

	for(i=0; (i < N) && (strcmp(s,kid[i]) != 0); i++);
	
	if(i < N)
		return kval[i];
	else
		return ID;
}
