%{
 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


/* ----------------------------------------------------------- */
/* --------- Declarations for Syntax-Semantic Analysis ------- */
/* ----------------------------------------------------------- */

#include "Definitions.h"


HashTable methods_table;
HashTable symbols_table[SYM_TABLE_SIZE];
int curMethodID = 0;


AstNode *TreeRoot;


int enableRetStuck = 1;


int TopOfWhileStack=-1;
Symbol *while_stack[30];
int TopOfRetStack=-1;
Symbol *ret_stack[30];
int TopOfStack=-1;
Symbol *vs[30];


Symbol *s,*s1,*s2,*s3,*s4,*s5,*s6,*s7,*s8,*s9,*new;
Symbol *r1,*r2,*r3,*r4,*top;
Symbol *curMethod = NULL;
int tempNumOfActuals;
int numOfActuals = 0;
int numOfFormals = 0;

char paramTypes[100];
char methodCallName[100];


int bytesCountVariables = 0;
int bytesCountParameters = 0;
int countArrays = 0;

%}

%union
{
    int   					yint;
    char  					ystr[100];
    struct AstNode_tag   	*stNode;
}


%token <yint> IF ELSE WHILE BREAK RETURN INT REAL CHAR TRUE FALSE
%token <yint> PRINT PRINTLN READ REPEAT TIMES UNLESS AND OR FOR 

%token <ystr> INT_CONST REAL_CONST TEXT CHAR_CONST
%token <ystr> '*' '/' '+' '-'
%token <ystr> INCREASE_SIGN DECREASE_SIGN NOT_SIGN
%token <ystr> PLUS_EQUALS_SIGN MINUS_EQUALS_SIGN TIMES_EQUALS_SIGN DIVIDE_EQUALS_SIGN
%token <ystr> IS_EQUAL IS_NOT_EQUAL IS_LESS_OR_EQUAL IS_GREATER_OR_EQUAL
%token <ystr> '=' '(' ')' '{' '}' ',' ';'
%token <ystr> ID
 
%type <stNode> Program MethodsList Method Parameters Formals
%type <stNode> Type Body Declarations DeclarationsList Declaration
%type <stNode> Variables Statements Statement Block Assign
%type <stNode> MethodName Location Expression RelationOperator
%type <stNode> AddExpression AddOperator Term MultiplyOperator
%type <stNode> Factor Actuals Arguments Message MoreMessage
%type <stNode> Printable AssignMultiple NestedAssign Code1
%type <stNode> SimpleStatement IncDec RelationExpression
%type <stNode> AndExpression ChangeAssignSymbol ArrayName

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start Program


%%









Program				: MethodsList
					{
					
						s = find_method("main");
						
						if (!s){
							printf("ERROR: Main function not found\n");
							exit(1);
						}
						
                        TreeRoot=MkNode(astProgram,NULL,$1,NULL,NULL,NULL);
						
					}
					| /* EMPTY */
					{
						
                        TreeRoot=MkNode(astEmptyProgram,NULL,NULL,NULL,NULL,NULL);
					
					}
					;
					
MethodsList			: Method MethodsList
					{
                        $$=MkNode(astMethods,NULL,$1,$2,NULL,NULL);
					
					}
					| Method
					{
						
						$$=$1;
					
					}
					;
					
Method				: 	Type ID '(' Parameters ')'
						{
							push_ret(new_symbol("start"));
							
							char temp[200];
							
							int i;
							new = new_symbol("");
							new->genre = VARIABLE;
							//strcpy(new->origName, $2);
							if (strcmp($2, "main") == 0){
								
								strcpy(new->name, "main");
								strcpy(new->MIXname, "_source_main");
								for (i = 0; i < numOfFormals; i++){
									pop_vs(); // Parameter
								}
								
							} else {
								
								for (i = 0; i < numOfFormals; i++){
									s4 = pop_vs(); // Parameter
									switch (s4->type){
										case INT:				
											if (s4->genre!=ARRAY){
												strcpy(temp, "_int");						
												strcat(temp, new->name);
												strcpy(new->name, temp);
											} else {
												strcpy(temp, "_intArr");						
												strcat(temp, new->name);
												strcpy(new->name, temp);
											}						
										break;
										case REAL:					
											if (s4->genre!=ARRAY){
												strcpy(temp, "_real");
												strcat(temp, new->name);
												strcpy(new->name, temp);
											} else {
												strcpy(temp, "_realArr");
												strcat(temp, new->name);
												strcpy(new->name, temp);
											}
										break;
									}
								}				
								strcpy(temp, $2);
								strcat(temp, new->name);
								strcpy(new->name, temp);
								strcpy(new->MIXname, "_");
								strcat(new->MIXname, new->name);
								//createMIXMethod(new->MIXname);
							}
							
							s1 = pop_vs(); // Type
							
							new->type = s1->type;
							new->lvalue = 0;
							new->numOfParams = numOfFormals;
							
							numOfFormals = 0;
							add_method_to_table(new);
							push_vs(new);
							
							
							bytesCountParameters = 0;
							bytesCountVariables = 0;
							
						}
						Body
					{						
						
						if (check_has_return() == 1){		
							enableRetStuck = 1;
						} else {
							printf("ERROR: No return statement in method '%s'\n", $2);
							exit(1);
						}
						
						curMethodID++;
						new = pop_vs();
						
						$$=MkNode(astMethod, new, $1, $4, $7, NULL);
					}
					| 	Type '[' ']' ID '(' Parameters ')'
						{
							push_ret(new_symbol("start"));
							
							char temp[200];
							
							int i;
							new = new_symbol("");
							new->genre = ARRAY;
							//strcpy(new->origName, $4);
							if (strcmp($4, "main") == 0){
								
								strcpy(new->name, "main");
								strcpy(new->MIXname, "_source_main");
								for (i = 0; i < numOfFormals; i++){
									pop_vs(); // Parameter
								}
								
							} else {
								
								for (i = 0; i < numOfFormals; i++){
									s6 = pop_vs(); // Parameter
									switch (s6->type){
										case INT:				
											if (s6->genre!=ARRAY){
												strcpy(temp, "_int");						
												strcat(temp, new->name);
												strcpy(new->name, temp);
											} else {
												strcpy(temp, "_intArr");						
												strcat(temp, new->name);
												strcpy(new->name, temp);
											}						
										break;
										case REAL:					
											if (s6->genre!=ARRAY){
												strcpy(temp, "_real");
												strcat(temp, new->name);
												strcpy(new->name, temp);
											} else {
												strcpy(temp, "_realArr");
												strcat(temp, new->name);
												strcpy(new->name, temp);
											}
										break;
									}
								}				
								strcpy(temp, $4);
								strcat(temp, new->name);
								strcpy(new->name, temp);
								strcpy(new->MIXname, "_");
								strcat(new->MIXname, new->name);
								//createMIXMethod(new->MIXname);
							}
							
							s1 = pop_vs(); // Type
							
							new->type = s1->type;
							new->lvalue = 0;
							new->numOfParams = numOfFormals;
							
							numOfFormals = 0;
							add_method_to_table(new);
							push_vs(new);
							
							
							bytesCountParameters = 0;
							bytesCountVariables = 0;
							
						}
						Body
					{						
						
						if (check_has_return() == 1){		
							enableRetStuck = 1;
						} else {
							printf("ERROR: No return statement in method '%s'\n", $4);
							exit(1);
						}
						
						curMethodID++;
						new = pop_vs();
						
						$$=MkNode(astMethod, new, $1, $6, $9, NULL);
					}
					;
					
Parameters			: Formals Type ID
					{
						
						s2 = pop_vs(); // Type
						
						new = new_symbol($3);
						new->type = s2->type;
						new->is_char = s2->is_char;
						new->is_param = 1;
						
						createMIXParameter(new->MIXname, new->type);						
						
						add_variable_to_table(new);
						push_vs(new);
						
						numOfFormals++;						
						
						$$=MkNode(astFormalParameters, new, $1, $2, NULL, NULL);
					}
					| Formals Type ID '[' ']'
					{
						
						s2 = pop_vs(); // Type
						
						new = new_symbol($3);
						new->type = s2->type;
						new->is_char = s2->is_char;
						new->genre = ARRAY;
						new->is_param = 1;
						
						//new->numOfElements = atoi($4);
						
						createMIXParameter(new->MIXname, INT);						
						
						add_variable_to_table(new);
						push_vs(new);
						
						numOfFormals++;						
						
						$$=MkNode(astFormalArrayParameters, new, $1, $2, NULL, NULL);
					}
					| /* EMPTY */
					{
						$$=MkNode(astNoFormalParameters, NULL, NULL, NULL, NULL, NULL);
					}
					;
					
Formals				: Formals Type ID ','
					{
						s2 = pop_vs(); // Type
						
						new = new_symbol($3);
						new->type = s2->type;
						new->is_char = s2->is_char;
						new->is_param = 1;
						
						createMIXParameter(new->MIXname, new->type);
						
						add_variable_to_table(new);
						push_vs(new);
						
						numOfFormals++;						
						
						$$=MkNode(astMoreFormalParameters, new, $1, $2, NULL, NULL);
					}
					| Formals Type ID '[' ']' ','
					{
						
						s2 = pop_vs(); // Type
						
						new = new_symbol($3);
						new->type = s2->type;
						new->is_char = s2->is_char;
						new->genre = ARRAY;
						new->is_param = 1;
						
						//new->numOfElements = atoi($4);
						
						createMIXParameter(new->MIXname, INT);						
						
						add_variable_to_table(new);
						push_vs(new);
						
						numOfFormals++;						
						
						$$=MkNode(astFormalArrayParameters, new, $1, $2, NULL, NULL);
					}
					| /* EMPTY */
					{
						$$=MkNode(astNoMoreFormalParameters, NULL, NULL, NULL, NULL, NULL);
					}
					;
					
Type				: INT
					{
						
						new = new_symbol("");
						new->type = INT;
						new->lvalue = 0;
						
						push_vs(new);
						
						$$=MkNode(astTypeInt, new, NULL, NULL, NULL, NULL);
						
					}
					| REAL
					{
						
						new = new_symbol("");
						new->type = REAL;
						new->lvalue = 0;
						
						push_vs(new);
						
						$$=MkNode(astTypeReal, new, NULL, NULL, NULL, NULL);
						
					}
					| CHAR
					{
						
						new = new_symbol("");
						new->type = INT;
						new->lvalue = 0;
						new->is_char = 1;
						
						push_vs(new);
						
						$$=MkNode(astTypeReal, new, NULL, NULL, NULL, NULL);
						
					}
					;
					
Body				: '{' Declarations Statements '}'
					{

						$$=MkNode(astBody, NULL, $2, $3, NULL, NULL);
					}
					;
					
Declarations		: DeclarationsList Declaration
					{
						$$=MkNode(astDeclarations, NULL, $1, $2, NULL, NULL);
					}
					| /* EMPTY */
					{
						$$=MkNode(astNoDeclarations, NULL, NULL, NULL, NULL, NULL);					
					}
					;
					
DeclarationsList	: DeclarationsList Declaration
					{
						$$=MkNode(astMoreDeclarations, NULL, $1, $2, NULL, NULL);
					}
					| /* EMPTY */
					{
						$$=MkNode(astNoMoreDeclarations, NULL, NULL, NULL, NULL, NULL);
					
					}
					;
					
Declaration			: 	Type ID
						{
							s1 = pop_vs(); // Type
							new = new_symbol($2);							
							new->type = s1->type;
							new->is_char = s1->is_char;
							new->genre = VARIABLE;
							
							createMIXVariable(new->MIXname, new->type);
							
							add_variable_to_table(new);							
							push_vs(new);							
							push_vs(s1);
						}
						Variables ';'
					{
						new = pop_vs();
						$$=MkNode(astDeclaration, new, $1, $4, NULL, NULL);
					}
					| 	Type ID '[' INT_CONST ']'
						{
							s1 = pop_vs(); // Type
							new = new_symbol($2);							
							new->type = s1->type;
							new->is_char = s1->is_char;
							new->genre = ARRAY;
							new->numOfElements = atoi($4);
							
							createMIXVariable(new->MIXname, INT);
							createMIXArray(new->ArrayName, new->type);
							
							add_variable_to_table(new);							
							push_vs(new);							
							push_vs(s1);
						}
						Variables ';'
					{
						new = pop_vs();
						$$=MkNode(astArrayDeclaration, new, $1, $7, NULL, NULL);
					}
					| 	Type ID '=' Expression
						{
							s4 = pop_vs(); 	// Expression
							s1 = pop_vs(); 	// Type
							new = new_symbol($2);
							new->type = s1->type;
							new->is_char = s1->is_char;
							new->genre = VARIABLE;
							new->value = s4->value;
							new->dvalue = s4->dvalue;
							
							createMIXVariable(new->MIXname, new->type);
							
							add_variable_to_table(new);
							push_vs(new);							
							push_vs(s1);
						}
						Variables ';'
					{
						new = pop_vs();
						$$=MkNode(astDeclarationExtended, new, $1, $4, $6, NULL);
					}
					;
					
Variables			: 	',' ID
						{	
							s = pop_vs(); // Type
							new = new_symbol($2);
							new->type = s->type;
							new->is_char = s->is_char;
							new->genre = VARIABLE;
							
							createMIXVariable(new->MIXname, new->type);	
							
							add_variable_to_table(new);
							push_vs(new);
							push_vs(s);
						}
					Variables
					{	
						new = pop_vs();				
						$$=MkNode(astVariable, new, $4, NULL, NULL, NULL);
					}
					| 	',' ID '[' INT_CONST ']'
						{
							s = pop_vs(); // Type
							new = new_symbol($2);							
							new->type = s->type;
							new->is_char = s->is_char;
							new->genre = ARRAY;
							new->numOfElements = atoi($4);
							
							createMIXVariable(new->MIXname, INT);
							createMIXArray(new->ArrayName, new->type);
							
							add_variable_to_table(new);							
							push_vs(new);
							push_vs(s);
						}
					Variables
					{
						new = pop_vs();
						$$=MkNode(astArrayVariable, new, $7, NULL, NULL, NULL);
					}
					|	',' ID '=' Expression
						{							
							s4 = pop_vs(); 	// Expression
							s = pop_vs(); 	// Type
							new = new_symbol($2);
							new->type = s->type;
							new->is_char = s->is_char;
							new->genre = VARIABLE;
							new->value = s4->value;
							new->dvalue = s4->dvalue;
							
							createMIXVariable(new->MIXname, new->type);
							
							add_variable_to_table(new);
							push_vs(new);
							push_vs(s);
						}
					Variables
					{	
						new = pop_vs();					
						$$=MkNode(astVariableExtended, new, $4, $6, NULL, NULL);
					}
					| /* EMPTY */
					{
						pop_vs(); // Type
						$$=MkNode(astNoVariable, NULL, NULL, NULL, NULL, NULL);
					}
					;
					
Statements			: Statements Statement
					{
						//s2 = pop_vs(); // Statement
						$$=MkNode(astStatements, NULL, $1, $2, NULL, NULL);
					}
					| /* EMPTY */
					{
						
						$$=MkNode(astNoStatements, NULL, NULL, NULL, NULL, NULL);
					}
					;
					
IncDec				: Location INCREASE_SIGN
					{
						$$=MkNode(astIncreaseAfter, NULL, $1, NULL, NULL, NULL);
					}
					| ArrayName INCREASE_SIGN
					{
						$$=MkNode(astIncreaseAfter, NULL, $1, NULL, NULL, NULL);
					}
					| INCREASE_SIGN Location
					{
						$$=MkNode(astIncreaseBefore, NULL, $2, NULL, NULL, NULL);
					}
					| INCREASE_SIGN ArrayName
					{
						$$=MkNode(astIncreaseBefore, NULL, $2, NULL, NULL, NULL);
					}
					| Location DECREASE_SIGN
					{
						$$=MkNode(astDecreaseAfter, NULL, $1, NULL, NULL, NULL);
						
					}
					| ArrayName DECREASE_SIGN
					{
						$$=MkNode(astDecreaseAfter, NULL, $1, NULL, NULL, NULL);
					}
					| DECREASE_SIGN Location
					{
						$$=MkNode(astDecreaseBefore, NULL, $2, NULL, NULL, NULL);
					}
					| DECREASE_SIGN ArrayName
					{
						$$=MkNode(astDecreaseBefore, NULL, $2, NULL, NULL, NULL);
					}
					;
					
ChangeAssignSymbol	: PLUS_EQUALS_SIGN
					{
						$$=MkNode(astPlusEquals, NULL, NULL, NULL, NULL, NULL);
					}
					| MINUS_EQUALS_SIGN
					{
						$$=MkNode(astMinusEquals, NULL, NULL, NULL, NULL, NULL);
					}
					| TIMES_EQUALS_SIGN
					{
						$$=MkNode(astTimesEquals, NULL, NULL, NULL, NULL, NULL);						
					}
					| DIVIDE_EQUALS_SIGN
					{
						$$=MkNode(astDivideEquals, NULL, NULL, NULL, NULL, NULL);			
					}
					;
					
SimpleStatement		: Assign
					{
						$$=MkNode(astStartAssignStatement, NULL, $1, NULL, NULL, NULL);
					}
					|  AssignMultiple
					{
						$$=$1;
					}
					| IncDec
					{
						s1 = pop_vs(); // IncDec
						$$=MkNode(astIncDecStatement, NULL, $1, NULL, NULL, NULL);						
					}
					| Location ChangeAssignSymbol Expression
					{
						s3 = pop_vs(); // Expression
						s1 = pop_vs(); // Location
						
						$$=MkNode(astChangeAssignStatement, NULL, $1, $2, $3, NULL);
						
					}
					| ArrayName ChangeAssignSymbol Expression
					{
						s3 = pop_vs(); // Expression
						s1 = pop_vs(); // Location
						
						$$=MkNode(astChangeAssignStatement, NULL, $1, $2, $3, NULL);
						
					}
					| BREAK
					{
						s = pop_while();
						
						if (s){
							push_while(new_symbol(""));
						} else {
							printf("ERROR: Break must be in a while loop\n");
							exit(1);
						}
						
						$$=MkNode(astBreakStatement, NULL, NULL, NULL, NULL, NULL);
					}
					
					| READ Location
					{
						s2 = pop_vs();	// Location
						
						if (s2->genre == ARRAY){
							printf("ERROR Can't read arrays ('%s').\n", s2->name);
							exit(1);
						}
						
						$$=MkNode(astReadStatement, NULL, $2, NULL, NULL, NULL);
					}
					| READ TEXT ',' Location
					{
						s2 = pop_vs();	// Location
						
						if (s2->genre == ARRAY){
							printf("ERROR Can't read arrays ('%s').\n", s2->name);
							exit(1);
						}
						
						new = new_symbol($2);
						
						$$=MkNode(astReadWithPrintStatement, new, $4, NULL, NULL, NULL);
					}					
					| PRINT Message
					{						
						$$=MkNode(astPrintStatement, NULL, $2, NULL, NULL, NULL);
					}					
					| PRINTLN Message
					{						
						$$=MkNode(astPrintlnStatement, NULL, $2, NULL, NULL, NULL);
					}
					;
					
Statement			: SimpleStatement ';'
					{
						$$ = $1;
					}
					| RETURN Expression ';'
					{
						
						if (enableRetStuck == 1){
							top = pop_ret();
							if (strcmp(top->name, "start") == 0){								
								enableRetStuck = 0;
								push_ret(top);
								push_ret(new_symbol("return"));
							} else if (strcmp(top->name, "no_ret") == 0 || strcmp(top->name, "return") == 0){
								push_ret(new_symbol("return"));
							} else {
								push_ret(top);
								push_ret(new_symbol("return"));
							}
						}
						
						s2 = pop_vs(); // Expression
						
						if (s2->genre == ARRAY && curMethod->genre == ARRAY && s2->type != curMethod->type){
							printf("ERROR: Method type and return type are arrays of different type.\n");
							exit(1);							
						}
						
						
						
						if (s2->genre == ARRAY && curMethod->genre != ARRAY){
							printf("ERROR: Return type is array but method type is not.\n");
							exit(1);
						} else if (s2->genre != ARRAY && curMethod->genre == ARRAY){
							printf("ERROR: Return type is variable but method type is array.\n");
							exit(1);
						}
						
						/*
						
						if (curMethod->type== INT && s2->type == REAL){
							printf("ERROR: In method '%s', return and method types don't match.\n", curMethod->origName);
							printf("Method is of type int and return is of type real.\n");
							exit(1);
						}
						*/
						
						$$=MkNode(astReturn, curMethod, $2, NULL, NULL, NULL);
					}
					| IF Code1 '(' Expression ')' Statement %prec LOWER_THAN_ELSE
					{
						if (enableRetStuck == 1){
							if (strcmp(ret_stack[TopOfRetStack]->name, "if") != 0){
								pop_ret(); // return or no-ret
							}
							pop_ret(); // if
						}
						
						//s6 = pop_vs(); // Statement (if)
						s4 = pop_vs(); // Expression						
						
						$$=MkNode(astIfStatement, NULL, $4, $6, NULL, NULL);
						
						////push_vs(NULL);
					}
					| 	IF Code1 '(' Expression ')' Statement ELSE
						{
							if (enableRetStuck == 1){
								
								if (strcmp(ret_stack[TopOfRetStack]->name, "return") !=0 && strcmp(ret_stack[TopOfRetStack]->name, "no_ret") !=0){
									push_ret(new_symbol("no_ret"));
								}
								
								push_ret(new_symbol("else"));
							}
						} 
						Statement
					{
						
						if (enableRetStuck == 1){							
							
							if (strcmp(ret_stack[TopOfRetStack]->name, "return") !=0 && strcmp(ret_stack[TopOfRetStack]->name, "no_ret") !=0){
								push_ret(new_symbol("no_ret"));
							}
							
							r4 = pop_ret(); // return or no_ret
							r3 = pop_ret(); // else
							r2 = pop_ret(); // return or no_ret
							r1 = pop_ret(); // if
							
							if (strcmp(r4->name, "return") == 0 && strcmp(r2->name, "return") ==0){
								push_ret(new_symbol("return"));
							} else if (strcmp(ret_stack[TopOfRetStack]->name, "no_ret") !=0){
								push_ret(new_symbol("no_ret"));
							}
							
						}
						
						//s9 = pop_vs(); // Statement (else)
						//s6 = pop_vs(); // Statement (if)
						s4 = pop_vs(); // Expression						
						
						$$=MkNode(astIfElseStatement, NULL, $4, $6, $9, NULL);
						
						////push_vs(NULL);
					}
					| 	WHILE
						{	
							enableRetStuck = 0;
							push_while(new_symbol(""));
						}
						'(' Expression ')' Statement
					{
						
						pop_while();
						if (TopOfWhileStack <0){
							enableRetStuck = 1;
						}
						
						
						//s6 = pop_vs(); // Statement
						s4 = pop_vs(); // Expression
						
						//push_vs(NULL);
						
						$$=MkNode(astWhileStatement, NULL, $4, $6, NULL, NULL);
						
					
					}
					| 	REPEAT
						{	
							enableRetStuck = 0;
							push_while(new_symbol(""));
						}
						Expression TIMES Statement
					{
						
						pop_while();
						if (TopOfWhileStack <0){
							enableRetStuck = 1;
						}
						
						
						//s6 = pop_vs(); // Statement
						s4 = pop_vs(); // Expression
						
						if (s4->type == REAL){
							printf("ERROR: Repeat times must be with an integer.\n");
							exit(1);
						}
						
						//push_vs(NULL);
						
						$$=MkNode(astRepeatStatement, NULL, $3, $5, NULL, NULL);
						
					
					}
					| 	FOR
						{	
							enableRetStuck = 0;
							push_while(new_symbol(""));
						}
						'(' SimpleStatement ';' Expression ';' SimpleStatement ')' Statement
					{
						
						pop_while();
						if (TopOfWhileStack <0){
							enableRetStuck = 1;
						}
						
						
						//s6 = pop_vs(); // Statement
						s4 = pop_vs(); // Expression
						
						//push_vs(NULL);
						
						$$=MkNode(astForStatement, NULL, $4, $6, $8, $10);
						
					
					}
					| SimpleStatement UNLESS Expression ';'
					{
						s3 = pop_vs(); // Expression
						//push_vs(NULL);
						$$=MkNode(astUnlessStatement, NULL, $1, $3, NULL, NULL);
					}
					| Block
					{						
						//push_vs(NULL);
						$$=$1;
					}
					| ';'
					{
						//push_vs(NULL);
						$$=MkNode(astEmptyStatement, NULL, NULL, NULL, NULL, NULL);					
					}
					;
					
Message				: Printable MoreMessage
					{						
					
						$$=MkNode(astMessage, NULL, $1, $2, NULL, NULL);
						
					}
					;
					
MoreMessage			: ',' Printable MoreMessage
					{
						
						$$=MkNode(astMoreMessage, NULL, $2, $3, NULL, NULL);	
						
					}
					| /* EMPTY */
					{
						$$=MkNode(astNoMoreMessage, NULL, NULL, NULL, NULL, NULL);	
						
					}
					;
					
Printable			: TEXT
					{
						new = new_symbol($1);
						
						$$=MkNode(astTextToPrint, new, NULL, NULL, NULL, NULL);	
						
					}
					| Expression
					{
						s1 = pop_vs(); // Expression
						
						$$=MkNode(astExpressionToPrint, NULL, $1, NULL, NULL, NULL);	
					}
					;

Block				: '{' Statements '}'
					{		
						$$=$2;
					}
					;
					
Assign				: Location '=' Expression
					{
						s3 = pop_vs();	// Expression
						s1 = pop_vs();	// Location
						
						$$=MkNode(astAssignStatement, NULL, $1, $3, NULL, NULL);
					}
					| Location '=' Assign
					{
						s1 = pop_vs();	// Location
						
						$$=MkNode(astMoreAssignStatement, NULL, $1, $3, NULL, NULL);
						
					}
					| ArrayName '=' Expression
					{
						s3 = pop_vs();	// Expression
						s1 = pop_vs();	// ArrayName
						
						$$=MkNode(astAssignStatement, NULL, $1, $3, NULL, NULL);
					}
					| ArrayName '=' Assign
					{
						s1 = pop_vs();	// ArrayName
						
						$$=MkNode(astMoreAssignStatement, NULL, $1, $3, NULL, NULL);
						
					}
					;

AssignMultiple		: Location ',' NestedAssign ',' Expression
					{
						s5 = pop_vs();	// Expression
						s1 = pop_vs();	// Location
						
						$$=MkNode(astAssignMultipleStatement, NULL, $1, $3, $5, NULL);
						
					}
					| ArrayName ',' NestedAssign ',' Expression
					{
						s5 = pop_vs();	// Expression
						s1 = pop_vs();	// ArrayName
						
						$$=MkNode(astAssignMultipleStatement, NULL, $1, $3, $5, NULL);
						
					}
					;
					
NestedAssign		: Location ',' NestedAssign ',' Expression
					{
						s5 = pop_vs();	// Expression
						s1 = pop_vs();	// Location
						
						$$=MkNode(astNestedAssignStatement, NULL, $1, $3, $5, NULL);
						
					}
					| ArrayName ',' NestedAssign ',' Expression
					{
						s5 = pop_vs();	// Expression
						s1 = pop_vs();	// ArrayName
						
						$$=MkNode(astNestedAssignStatement, NULL, $1, $3, $5, NULL);
						
					}
					| Location '=' Expression
					{
						s3 = pop_vs();	// Expression
						s1 = pop_vs();	// Location
						
						$$=MkNode(astLastNestedAssignStatement, NULL, $1, $3, NULL, NULL);
						
					}
					| ArrayName '=' Expression
					{
						s3 = pop_vs();	// Expression
						s1 = pop_vs();	// ArrayName
						
						$$=MkNode(astLastNestedAssignStatement, NULL, $1, $3, NULL, NULL);
						
					}
					;
					
					
MethodName			: ID
					{
						new = new_symbol($1);				
						
						push_vs(new);
						
						$$=MkNode(astMethodName, new, NULL, NULL, NULL, NULL);
					}
					;

Location			: ID
					{
						new = find_variable($1);
						//printf("Found variable %s\n", new);
						if (!new){							
							printf("ERROR: Undeclared variable '%s'\n", $1);
							exit(1);
						}
						
						
						push_vs(new);
						
						$$=MkNode(astLocation, new, NULL, NULL, NULL, NULL);
					}
					;

ArrayName			: ID '[' Expression ']'
					{
						
						s3 = pop_vs(); // Expression
						
						if (s3->type != INT){
							printf("ERROR: Array ('%s') index is not an integer.\n", $1);
							exit(1);
						}
						
						new = find_variable($1);
						//printf("Found variable %s\n", new);
						if (!new){							
							printf("ERROR: Undeclared array '%s'\n", $1);
							exit(1);
						}
						
						if (new->genre != ARRAY){
							printf("ERROR: Expected array but found variable '%s'.\n",  $1);
							exit(1);
						}
						
						push_vs(new);
						
						$$=MkNode(astArrayName, new, $3, NULL, NULL, NULL);
					}
					;
					
					
Expression			: Expression OR AndExpression
					{
						
						s3 = pop_vs(); // AndExpression
						s1 = pop_vs(); // Expression
						
						new = new_symbol("");
						new->lvalue = 0;
						
						new->type = INT;
						
						if (s1->has_value == CONST_VAL && s3->has_value == CONST_VAL){
							new->has_value = CONST_VAL;								
						}
						
						/*
						if (s1->sclass == CONSTANT && s3->sclass == CONSTANT){
							new->sclass = CONSTANT;
						}
						*/
						
						push_vs(new);
						
						$$=MkNode(astOrExpression, NULL, $1, $3, NULL, NULL);
					}
					| AndExpression
					{
						
						$$=$1;
						
					}
					;
					
AndExpression		: AndExpression AND RelationExpression
					{						
						s3 = pop_vs(); // RelOperation
						s1 = pop_vs(); // AndExpression
						
						new = new_symbol("");
						new->lvalue = 0;
						
						new->type = INT;
						
						if (s1->has_value == CONST_VAL && s3->has_value == CONST_VAL){
							new->has_value = CONST_VAL;								
						}
						
						/*
						if (s1->sclass == CONSTANT && s3->sclass == CONSTANT){
							new->sclass = CONSTANT;
						}
						*/
						
						push_vs(new);							
							
						
						$$=MkNode(astAndExpression, NULL, $1, $3, NULL, NULL);
					}
					| RelationExpression
					{
						
						$$=$1;
						
					}
					;
				
RelationExpression	: AddExpression RelationOperator AddExpression
					{
						s3 = pop_vs(); // AddExpression
						s1 = pop_vs(); // AddExpression
						
						new = new_symbol("");
						new->lvalue = 0;
						
						new->type = INT;
						
						if (s1->sclass == CONSTANT && s3->sclass == CONSTANT){
							new->sclass = CONSTANT;								
						}
						
						/*
						if (s1->has_value == CONST_VAL && s3->has_value == CONST_VAL){
							new->has_value = CONST_VAL;								
						}
						*/
						
						
						push_vs(new);
						
						
						$$=MkNode(astRelationExpression, NULL, $1, $2, $3, NULL);
					}
					| AddExpression
					{
						
						$$=$1;					
					}
					;
					
RelationOperator	: IS_LESS_OR_EQUAL
					{
						$$=MkNode(astLessOrEqualOperator, NULL, NULL, NULL, NULL, NULL);	
					}
					| '<'
					{
						$$=MkNode(astLessOperator, NULL, NULL, NULL, NULL, NULL);	
					}
					| '>'
					{
						$$=MkNode(astGreaterOperator, NULL, NULL, NULL, NULL, NULL);	
					}
					| IS_GREATER_OR_EQUAL
					{
						$$=MkNode(astGreaterOrEqualOperator, NULL, NULL, NULL, NULL, NULL);	
					}
					| IS_EQUAL
					{
						$$=MkNode(astEqualOperator, NULL, NULL, NULL, NULL, NULL);	
					}
					| IS_NOT_EQUAL
					{
						$$=MkNode(astNotEqualOperator, NULL, NULL, NULL, NULL, NULL);	
					}
					;
					
AddExpression		: AddExpression AddOperator Term
					{
						s3 = pop_vs(); // Term
						s1 = pop_vs(); // AddExpression
						
						new = new_symbol("");
						new->lvalue = 0;
						
						switch (s1->type){
							case INT:
								if (s3->type == INT){
									new->type = INT;
								} else if (s3->type == REAL){
									new->type = REAL;
								}
							break;
							case REAL:
								new->type = REAL;
							break;
						}
						
						if (s1->sclass == CONSTANT && s3->sclass == CONSTANT){
							new->sclass = CONSTANT;								
						}
						
						/*
						if (s1->has_value == CONST_VAL && s3->has_value == CONST_VAL){
							new->has_value = CONST_VAL;								
						}
						*/
						
						
						push_vs(new);
						
						$$=MkNode(astAddExpression, NULL, $1, $2, $3, NULL);	
					}
					| Term
					{
						$$=$1;	
					}
					;
					
AddOperator			: '+'
					{
						$$=MkNode(astAddOperator, NULL, NULL, NULL, NULL, NULL);	
					}
					| '-'
					{
						$$=MkNode(astSubtractOperator, NULL, NULL, NULL, NULL, NULL);	
					}
					;
					
Term				: Term MultiplyOperator Factor
					{
						s3 = pop_vs(); // Factor
						s2 = pop_vs(); // MultiplyOperator
						s1 = pop_vs(); // Term
						
						if (strcmp(s2->name, "%") == 0 && (s1->type!= INT || s3->type!= INT)){
							printf("ERROR: Modulo (%%) operation can only be between integers.\n");
							exit(1);							
						}
						
						new = new_symbol("");
						new->lvalue = 0;
						
						switch (s1->type){
							case INT:
								if (s3->type == INT){
									new->type = INT;
								} else if (s3->type == REAL){
									new->type = REAL;
								}
							break;
							case REAL:
								new->type = REAL;
							break;
						}
						
						if (s1->sclass == CONSTANT && s3->sclass == CONSTANT){
							new->sclass = CONSTANT;								
						}
						
						/*
						if (s1->has_value == CONST_VAL && s3->has_value == CONST_VAL){
							new->has_value = CONST_VAL;								
						}
						*/
						
						
						push_vs(new);
						
						
						$$=MkNode(astTerm, NULL, $1, $2, $3, NULL);	
					}
					| Factor
					{
						$$=$1;
					}
					| NOT_SIGN Factor
					{
						$$=MkNode(astNotOperator, NULL, $2, NULL, NULL, NULL);
					}
					;
					
MultiplyOperator	: '*'
					{
						push_vs(new_symbol("*"));
						$$=MkNode(astMultiplyOperator, NULL, NULL, NULL, NULL, NULL);	
					}
					| '/'
					{
						push_vs(new_symbol("/"));
						$$=MkNode(astDivideOperator, NULL, NULL, NULL, NULL, NULL);
					}
					| '%'
					{
						push_vs(new_symbol("%"));
						$$=MkNode(astModuloOperator, NULL, NULL, NULL, NULL, NULL);
					}
					;
					
Factor				: '(' Expression ')'
					{
						$$=$2;
					}	
					| Location
					{
						$$=$1;
					}
					| ArrayName
					{
						$$=MkNode(astArrayCall, NULL, $1, NULL, NULL, NULL);
					}
					| INT_CONST
					{
						new = new_symbol("");
						new->type = INT;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->value = atoi($1);
						new->dvalue = new->value;
						push_vs(new);
						
						$$=MkNode(astIntConstant, new, NULL, NULL, NULL, NULL);	
					}
					| '-' INT_CONST
					{
						new = new_symbol("");
						new->type = INT;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->value = -atoi($2);
						new->dvalue = new->value;
						push_vs(new);
						
						$$=MkNode(astIntConstant, new, NULL, NULL, NULL, NULL);	
					}
					| REAL_CONST
					{
						new = new_symbol("");
						new->type = REAL;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->dvalue = atof($1);
						new->value = new->dvalue;// -------- REMOVE ME ------------- //
						push_vs(new);
						
						$$=MkNode(astRealConstant, new, NULL, NULL, NULL, NULL);	
					}
					| '-' REAL_CONST
					{
						new = new_symbol("");
						new->type = REAL;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->dvalue = -atof($2);
						new->value = new->dvalue;// -------- REMOVE ME ------------- //
						push_vs(new);
						
						$$=MkNode(astRealConstant, new, NULL, NULL, NULL, NULL);	
					}
					| TRUE
					{
						new = new_symbol("");						
						new->type = INT;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->value = 1;
						new->dvalue = 1;
						push_vs(new);
						
						$$=MkNode(astTrue, new, NULL, NULL, NULL, NULL);	
					}
					| FALSE
					{
						new = new_symbol("");
						new->type = INT;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->value = 0;
						new->dvalue = 0;
						push_vs(new);
						
						$$=MkNode(astFalse, new, NULL, NULL, NULL, NULL);	
					}
					| CHAR_CONST
					{
						new = new_symbol("");
						new->type = INT;
						new->sclass = CONSTANT;
						new->is_char = 1;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						if ($1[0] != '\\'){
							new->value = $1[0];
						} else {
							switch ($1[1]){
								case '0':
									new->value = '\0';
								break;
								case 'n':
									new->value = '\n';							
								break;
								case '\\':
									new->value = '\\';								
								break;
								default:
									printf("IMPOSSIBLE (in CHAR_CONST)\n");
								break;
							}
						}
						new->dvalue = 0;
						push_vs(new);
						
						$$=MkNode(astFalse, new, NULL, NULL, NULL, NULL);	
					}
					| 	MethodName '(' Actuals ')'
					{				
					
						char temp[200];
						
						new = new_symbol("");
						strcpy(paramTypes, "");
						int i;
						for (i = 0; i < numOfActuals; i++){
							s4 = pop_vs(); // Actual
							switch (s4->type){
								case INT:
									if (s4->genre!=ARRAY){
										strcpy(temp, "_int");
										strcat(temp, new->name);
										strcpy(new->name, temp);
										
										strcpy(temp, "int");
										if (i != 0){
											strcat(temp, ", ");								
										}
										strcat(temp, paramTypes);
										strcpy(paramTypes, temp);
									} else {
										strcpy(temp, "_intArr");
										strcat(temp, new->name);
										strcpy(new->name, temp);
										
										strcpy(temp, "int[]");
										if (i != 0){
											strcat(temp, ", ");								
										}
										strcat(temp, paramTypes);
										strcpy(paramTypes, temp);
									}
								break;
								case REAL:
									if (s4->genre!=ARRAY){
										strcpy(temp, "_real");
										strcat(temp, new->name);
										strcpy(new->name, temp);
										
										strcpy(temp, "real");
										if (i != 0){
											strcat(temp, ", ");								
										}
										strcat(temp, paramTypes);
										strcpy(paramTypes, temp);		
									} else {
										strcpy(temp, "_realArr");
										strcat(temp, new->name);
										strcpy(new->name, temp);
										
										strcpy(temp, "real[]");
										if (i != 0){
											strcat(temp, ", ");								
										}
										strcat(temp, paramTypes);
										strcpy(paramTypes, temp);		
									}									
								break;
							}
						}
						
						numOfActuals = tempNumOfActuals;
						
						s1 = pop_vs();	// 	MethodName	
						
						strcpy(methodCallName, s1->name);
						strcat(methodCallName, new->name);
						
						
						new = find_method(methodCallName);
						
						if (!new){
							printf("ERROR: Method '%s' with parameter type(s) '%s' not found\n", s1->name, paramTypes);
							exit(1);
						}	
						
						
						
						/*
						if (s1->numOfParams == numOfActuals){
							numOfActuals = 0;
						} else {
							printf("ERROR: Number of parameters in method '%s' don't match\n", s1->name);
							printf("Number of Actuals: %d\nNumber Of Formals: %d\n", numOfActuals, s1->numOfParams);
							exit(1);
						}
						*/
						
						
						
						$$=MkNode(astMethodCall, new, $1, $3, NULL, NULL);
						push_vs(new);
					
					}
					| IncDec
					{
						$$=$1;
					}
					;
					
Actuals				: {tempNumOfActuals = numOfActuals; numOfActuals = 0;} Arguments Expression
					{
						numOfActuals++;
						$$=MkNode(astActualParameters, NULL, $2, $3, NULL, NULL);	
					}
					| /* EMPTY */
					{
						$$=MkNode(astNoActualParameters, NULL, NULL, NULL, NULL, NULL);						
					}
					;
					
Arguments			: Arguments Expression ','
					{						
						numOfActuals++;
						$$=MkNode(astMoreActualParameters, NULL, $1, $2, NULL, NULL);
					}
					| /* EMPTY */
					{
						$$=MkNode(astNoMoreActualParameters, NULL, NULL, NULL, NULL, NULL);	
					
					}
					;



Code1				: 
					{
						if (enableRetStuck == 1){
							push_ret(new_symbol("if"));
						}
					}
					
					
					
					
					
					
					
					
%%





// ---------- Stacks ---------- //


void Show_VStack(){
	printf("\n--- VARIABLE STACK ---\n");
	for (int i=TopOfStack; i>=0; i--){
		printf("%s\n", vs[i]);
	}
	printf("--- END ---\n");
}

void push_vs(Symbol *p)
{
   vs[++TopOfStack]=p;
}

Symbol *pop_vs()
{
   return(vs[TopOfStack--]);
}




void Show_Ret_Stack(){
	printf("\n--- RETURN STACK ---\n");
	for (int i=TopOfRetStack; i>=0; i--){
		printf("%s\n", ret_stack[i]);
	}
	printf("--- END ---\n");
}

void push_ret(Symbol *p)
{
	ret_stack[++TopOfRetStack]=p;
}

Symbol *pop_ret()
{
	return(ret_stack[TopOfRetStack--]);
}


int check_has_return(){
	
	Symbol *first, *second;
	
	first = ret_stack[0];
	second = ret_stack[1];
	
	
	if (TopOfRetStack > 0 && first && second && strcmp(first->name, "start") == 0 && strcmp(second->name, "return") == 0){
		pop_ret();
		pop_ret();
		return 1;
	} else {
		return 0;
	}
	
}




Symbol* peek_while()
{
   return while_stack[TopOfWhileStack];
}

void push_while(Symbol* whileSym)
{
   while_stack[++TopOfWhileStack]=whileSym;
}

Symbol *pop_while()
{
	if(TopOfWhileStack<0){
		return(NULL);
	}
	
	Symbol * temp;
	temp = while_stack[TopOfWhileStack--];
	while_stack[TopOfWhileStack+1] = NULL;   
	return(temp);
}

void Init_While_Stack(){
	int i;
	for(i=0; i<30; i++){
		while_stack[i] = NULL;
	}
	
}

void Show_While_Stack(){
	printf("\n--- WHILE STACK ---\n");
	for (int i=TopOfWhileStack; i>=0; i--){
		printf("%d\n", while_stack[i]->value);
	}
	printf("--- END ---\n");
}




// ---------- Syntax Tree ---------- //

AstNode *MkNode(int tipos,Symbol *sn,
              AstNode *z0,AstNode *z1,AstNode *z2,AstNode *z3)
{  

	//printf("%d\n", tipos);

	AstNode *p;

	p=(AstNode *)malloc(sizeof(AstNode));
	if(!p)
	{
		printf("Out of memory\n");
		exit(1);
	}
	else
	{
		p->NodeType=tipos;
		p->SymbolNode=sn;
		p->pAstNode[0]=z0;
		p->pAstNode[1]=z1;
		p->pAstNode[2]=z2;
		p->pAstNode[3]=z3;
		
		return(p);
	}
}




// ---------- MIX Names ---------- //


void createMIXVariable(char* MIXname, int type){

	char newName[20];
	switch (type){
		case INT:
			bytesCountVariables += 4;
		break;
		case REAL:
			bytesCountVariables += 8;
		break;
			
	}
	sprintf(newName, "ebp - %d", bytesCountVariables);
	strcpy(MIXname, newName);
	
	
}

void createMIXParameter(char* MIXname, int type){

	char newName[20];
	sprintf(newName, "ebp + %d", bytesCountParameters + 8);
	strcpy(MIXname, newName);
	switch (type){
		case INT:
			bytesCountParameters += 4;
		break;
		case REAL:
			bytesCountParameters += 8;
		break;
	}
	
}



void createMIXArray(char* ArrayName, int type){

	char newName[20];
	countArrays++;
	sprintf(newName, "array_%d", countArrays);
	strcpy(ArrayName, newName);
	
	
}



// ---------- Symbol Table ---------- //


void Init_Hash_Table()
{  
	int i,j;

	for(i=0; i<SYM_TABLE_SIZE; i++){
		methods_table.table[i]=NULL;		
		for (j=0; j<SYM_TABLE_SIZE; j++){
			symbols_table[i].table[j]=NULL;
		}
	}
  
}


void Show_Hash_Table()
{  
	int i,j;

	printf("\n------------- METHODS ---------\n");
	for(i=0; i<SYM_TABLE_SIZE; i++){		
		printf("%s ",methods_table.table[i]);	
	}		
	printf("\n------------- VARIABLES ---------\n");
		
	for (i=0; i<SYM_TABLE_SIZE ;i++){
		for (j=0; j<SYM_TABLE_SIZE; j++){
			printf("%s ",symbols_table[i].table[j]);
		}		
		printf("\n");
	}
	
  
}

// Check and Add
void add_variable_to_table(Symbol *symbp)
{  
    Symbol *exists, *neo;

    neo=symbp;
   
	exists=find_variable(neo->name);
	if( !exists )
	{
		add_variable(neo);
		//printf("\nAdded Variable %s\n", neo->name);
		//Show_Hash_Table();
    }
    /* -- exists -- */
    else
    {
        printf("%s redeclaration.\n",neo->name);
        exit(1);
    }
}

// Check and Add
void add_method_to_table(Symbol *symbp)
{  
    Symbol *exists, *neo;

    neo=symbp;
   
	exists=find_method(neo->name);
	if( !exists )
	{
		add_method(neo);
		//printf("\nAdded Method %s\n", neo->name);
    }
    /* -- exists -- */
    else
    {
        printf("%s redeclaration.\n",neo->name);
        exit(1);
    }
}


int mkkey(char *s)
{  char *p;
   int athr=0;

   for(p=s; *p; p++) athr=athr+(*p);
   return (athr % SYM_TABLE_SIZE);
}


void add_variable(Symbol *symbp)
{  
   int i;
   Symbol *p;

   HashTable cur_table = symbols_table[curMethodID];
   
   i=mkkey(symbp->name);
   
   p=symbols_table[curMethodID].table[i];
   symbp->NextSymbol=p;
   symbp->PrevSymbol=NULL;
   
   if(p) p->PrevSymbol=symbp;
   symbols_table[curMethodID].table[i]=symbp;
   symbols_table[curMethodID].numbSymbols++;
   
   
   
}

Symbol *find_variable(char *onoma)
{  
   int i;
   Symbol *p;
   
   HashTable cur_table = symbols_table[curMethodID];

   i=mkkey(onoma);
   p=cur_table.table[i];
   
   
   while(p && (strcmp(p->name,onoma) !=0))
      p=p->NextSymbol;
   return(p);
}

void add_method(Symbol *symbp)
{  int i;
   Symbol *p;

   i=mkkey(symbp->name);
   p=methods_table.table[i];
   symbp->NextSymbol=p;
   symbp->PrevSymbol=NULL;
   symbp->symbols_table_of_method = &symbols_table[curMethodID];
   if(p) p->PrevSymbol=symbp;
   methods_table.table[i]=symbp;
   methods_table.numbSymbols++;
   
   curMethod = symbp;
   
}

Symbol *find_method(char *onoma)
{  int i;
   Symbol *p;

   i=mkkey(onoma);
   p=methods_table.table[i];
   
   while(p && (strcmp(p->name,onoma) !=0))
      p=p->NextSymbol;
   return(p);
}


Symbol *new_symbol(char *name)
{  

   Symbol *symbp;
   symbp = (Symbol *) malloc(sizeof(Symbol));
   memset(symbp,0,sizeof(Symbol));
   
   strncpy(symbp->name,name,(strlen(name)>NAME_MAX)?NAME_MAX:strlen(name));
   
   
   
   symbp->value=0;   
   symbp->lvalue=1;
   symbp->is_param=0;
   symbp->is_char=0;
   symbp->has_value=0;
   symbp->NextSymbol=NULL;
   symbp->PrevSymbol=NULL;
   symbp->symbols_table_of_method=NULL;
   return(symbp);
}


// ---------------------------------------------- //

void yyerror(char *s)
{
   fputs(s,stderr); putc('\n',stderr);   
}
