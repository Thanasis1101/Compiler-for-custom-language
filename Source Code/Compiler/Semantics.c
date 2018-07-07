#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Definitions.h"
#include "y.tab.h"

extern AstNode *TreeRoot;


/* ----------------------------------------------------------- */
/* ---------------------- FUNCTIONS -------------------------- */
/* ----------------------------------------------------------- */

void kena(int n)
{  
	int i;   
	for(i=0; i<n; i++) printf(" ");
}

void traverse(AstNode *p,int n)
{  
	int i;

    n=n+3;
    if(p)
    {
		switch (p->NodeType)
		{
			case astEmptyProgram: 
				kena(n); printf("astEmptyProgram\n"); 
				break;
			case astProgram: 
				kena(n); printf("astProgram\n"); 
				break;
			case astMethods: 
				kena(n); printf("astMethods\n"); 
				break;
			case astMethod: 
				kena(n); printf("astMethod\n"); 
				break;
			case astFormalParameters: 
				kena(n); printf("astFormalParameters\n"); 
				break;
			case astFormalArrayParameters: 
				kena(n); printf("astFormalArrayParameters\n"); 
				break;
			case astNoFormalParameters: 
				kena(n); printf("astNoFormalParameters\n"); 
				break;
			case astMoreFormalParameters: 
				kena(n); printf("astMoreFormalParameters\n"); 
				break;
			case astNoMoreFormalParameters: 
				kena(n); printf("astNoMoreFormalParameters\n"); 
				break;
			case astTypeInt: 
				kena(n); printf("astTypeInt\n"); 
				break;  
			case astTypeReal: 
				kena(n); printf("astTypeReal\n"); 
				break;   
			case astBody: 
				kena(n); printf("astBody\n"); 
				break;
			case astDeclarations: 
				kena(n); printf("astDeclarations\n"); 
				break;
			case astNoDeclarations: 
				kena(n); printf("astNoDeclarations\n"); 
				break;
			case astMoreDeclarations: 
				kena(n); printf("astMoreDeclarations\n"); 
				break;
			case astNoMoreDeclarations:
				kena(n); printf("astNoMoreDeclarations\n"); 
				break;
			case astDeclaration: 
				kena(n); printf("astDeclaration\n"); 
				break;
			case astArrayDeclaration: 
				kena(n); printf("astArrayDeclaration\n"); 
				break;
			case astArrayVariable: 
				kena(n); printf("astArrayVariable\n"); 
				break;
			case astDeclarationExtended: 
				kena(n); printf("astDeclarationExtended\n"); 
				break;
			case astVariable: 
				kena(n); printf("astVariable\n"); 
				break;
			case astVariableExtended: 
				kena(n); printf("astVariableExtended\n"); 
				break;
			case astNoVariable:
				kena(n); printf("astNoVariable\n"); 
				break;
			case astIncreaseAfter: 
				kena(n); printf("astIncreaseAfter\n"); 
				break;
			case astIncreaseBefore: 
				kena(n); printf("astIncreaseBefore\n"); 
				break;
			case astDecreaseAfter: 
				kena(n); printf("astDecreaseAfter\n"); 
				break;
			case astDecreaseBefore: 
				kena(n); printf("astDecreaseBefore\n"); 
				break;
			case astPlusEquals: 
				kena(n); printf("astPlusEquals\n"); 
				break;
			case astMinusEquals: 
				kena(n); printf("astMinusEquals\n"); 
				break;
			case astTimesEquals: 
				kena(n); printf("astTimesEquals\n"); 
				break;
			case astDivideEquals: 
				kena(n); printf("astDivideEquals\n"); 
				break;
			case astStatements: 
				kena(n); printf("astStatements\n"); 
				break;
			case astNoStatements: 
				kena(n); printf("astNoStatements\n"); 
				break;
			case astIncDecStatement: 
				kena(n); printf("astIncDecStatement\n"); 
				break;
			case astChangeAssignStatement: 
				kena(n); printf("astChangeAssignStatement\n"); 
				break;
			case astReturn: 
				kena(n); printf("astReturn\n"); 
				break;
			case astUnlessStatement: 
				kena(n); printf("astUnlessStatement\n"); 
				break;
			case astIfStatement: 
				kena(n); printf("astIfStatement\n"); 
				break;
			case astIfElseStatement: 
				kena(n); printf("astIfElseStatement\n"); 
				break;
			case astWhileStatement:
				kena(n); printf("astWhileStatement\n"); 
				break;
			case astRepeatStatement:
				kena(n); printf("astRepeatStatement\n"); 
				break;
			case astForStatement:
				kena(n); printf("astForStatement\n"); 
				break;
			case astBreakStatement: 
				kena(n); printf("astBreakStatement\n"); 
				break;
			case astPrintStatement: 
				kena(n); printf("astPrintStatement\n"); 
				break;
			case astPrintlnStatement: 
				kena(n); printf("astPrintlnStatement\n"); 
				break;
			case astMessage: 
				kena(n); printf("astMessage\n"); 
				//kena(n); printf("astMessage:%s\n", p->SymbolNode->name); 
				break;
			case astMoreMessage: 
				kena(n); printf("astMoreMessage\n"); 
				break;
			case astNoMoreMessage: 
				kena(n); printf("astNoMoreMessage\n"); 
				break;
			case astTextToPrint: 
				kena(n); printf("astTextToPrint\n"); 
				break;
			case astExpressionToPrint: 
				kena(n); printf("astExpressionToPrint\n"); 
				break;
			case astReadStatement: 
				kena(n); printf("astReadStatement\n"); 
				break;
			case astReadWithPrintStatement: 
				kena(n); printf("astReadWithPrintStatement\n"); 
				break;
			case astEmptyStatement: 
				kena(n); printf("astEmptyStatement\n"); 
				break;
			case astStartAssignStatement: 
				kena(n); printf("astStartAssignStatement\n"); 
				break;
			case astAssignStatement: 
				kena(n); printf("astAssignStatement\n"); 
				break;
			case astMoreAssignStatement: 
				kena(n); printf("astMoreAssignStatement\n"); 
				break;
			case astAssignMultipleStatement: 
				kena(n); printf("astAssignMultipleStatement\n"); 
				break;
			case astNestedAssignStatement: 
				kena(n); printf("astNestedAssignStatement\n"); 
				break;
			case astLastNestedAssignStatement: 
				kena(n); printf("astLastNestedAssignStatement\n"); 
				break;
			case astLocation: 
				kena(n); printf("astLocation\n"); 
				break;
			case astMethodName: 
				kena(n); printf("astMethodName\n"); 
				break;
			case astArrayName: 
				kena(n); printf("astArrayName\n"); 
				break;
			case astArrayCall: 
				kena(n); printf("astArrayCall\n"); 
				break;
			case astOrExpression: 
				kena(n); printf("astOrExpression\n"); 
				break;
			case astAndExpression: 
				kena(n); printf("astAndExpression\n"); 
				break;
			case astRelationExpression: 
				kena(n); printf("astRelationExpression\n"); 
				break;
			case astLessOrEqualOperator: 
				kena(n); printf("astLessOrEqualOperator\n"); 
				break;
			case astLessOperator: 
				kena(n); printf("astLessOperator\n"); 
				break;
			case astGreaterOperator: 
				kena(n); printf("astGreaterOperator\n"); 
				break;
			case astGreaterOrEqualOperator: 
				kena(n); printf("astGreaterOrEqualOperator\n"); 
				break;
			case astEqualOperator: 
				kena(n); printf("astEqualOperator\n"); 
				break;
			case astNotEqualOperator: 
				kena(n); printf("astNotEqualOperator\n"); 
				break;
			case astAddExpression: 
				kena(n); printf("astAddExpression\n"); 
				break;
			case astAddOperator: 
				kena(n); printf("astAddOperator\n"); 
				break;
			case astSubtractOperator: 
				kena(n); printf("astSubtractOperator\n"); 
				break;
			case astTerm: 
				kena(n); printf("astTerm\n"); 
				break;
			case astNotOperator: 
				kena(n); printf("astNotOperator\n"); 
				break;
			case astMultiplyOperator: 
				kena(n); printf("astMultiplyOperator\n"); 
				break;
			case astDivideOperator: 
				kena(n); printf("astDivideOperator\n"); 
				break;
			case astModuloOperator: 
				kena(n); printf("astModuloOperator\n"); 
				break;	
			case astIntConstant: 
				kena(n); printf("astIntConstant\n"); 
				break;
			case astRealConstant: 
				kena(n); printf("astRealConstant\n"); 
				break;
			case astTrue: 
				kena(n); printf("astTrue\n"); 
				break;
			case astFalse: 
				kena(n); printf("astFalse\n"); 
				break;
			case astMethodCall: 
				kena(n); printf("astMethodCall\n"); 
				break;
			case astActualParameters: 
				kena(n); printf("astActualParameters\n"); 
				break;
			case astNoActualParameters: 
				kena(n); printf("astNoActualParameters\n"); 
				break;
			case astMoreActualParameters: 
				kena(n); printf("astMoreActualParameters\n"); 
				break;
			case astNoMoreActualParameters: 
				kena(n); printf("astNoMoreActualParameters\n"); 
				break;
			default: 
				printf("AGNOSTO=%d\n",p->NodeType);
		}
		for(i=0; i<4; i++) traverse(p->pAstNode[i],n);
	}
}

// ------------------------------------------------------------------------//

FILE *asmData, *asmCode;

int numIfs = 0;
int numWhiles = 0;

int bytesForParams = 0;

int countRealConsts = 0;
int countIntForConversions = 0;

Symbol* mulAssignLocations[50];
Symbol* mulAssignExpressions[50];
int countLocations = 0;
int countExpressions = 0;
int countAddressVars = 0;


void fkena(int n)
{  
	int i;   
	for(i=0; i<n; i++) fprintf(asmCode, " ");
}


/* ------------------------------------------------------------------------ */
/* CodeGeneration */


void ProcessProgram(AstNode*p, int lev){	
	CodeGeneration(p->pAstNode[0],lev+1,0,0);
}

void ProcessMethods(AstNode*p, int lev){	
	CodeGeneration(p->pAstNode[0],lev+1,0,0);
	CodeGeneration(p->pAstNode[1],lev+1,0,0);
}


void ProcessMethod(AstNode*p, int lev){	
	
	bytesForParams = 0;
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Parameters
	
	fprintf(asmCode, "%s:\n", p->SymbolNode->MIXname);
	fprintf(asmCode, "    push ebp\n");
	fprintf(asmCode, "    mov  ebp, esp\n");
	
	CodeGeneration(p->pAstNode[2],lev+1,0,0); // Body
   
	fprintf(asmCode, "\n; ----------------------- ;\n\n");
   
}


void ProcessReturn(AstNode *p,int lev,int lvalue,int leftChild){
	
	Symbol *lhs, *currentMethod;	
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0);
	lhs = pop_vs();
	
	currentMethod = p->SymbolNode;
	
	switch (currentMethod->type){
		case INT:
			switch (lhs->type){
				case INT:						// ---- return int on int method ---- //
					switch(lhs->sclass){
						case MEMORY:	
							fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
						break;
						case CONSTANT:
							fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
						break;
						case REGISTER:
							fprintf(asmCode, "    mov  eax, [REG_INT]\n");
						break;
						case STACK:
							printf("IMPOSSIBLE (STACK in return)\n");
						break;
						
					}
				break;
				
				case REAL:						// ---- return real on int method ---- //
					switch(lhs->sclass){
						case MEMORY:						
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							fprintf(asmData, "int_for_conversion_%d dd 0\n", ++countIntForConversions);
							fprintf(asmCode, "    fistp dword [int_for_conversion_%d]\n", countIntForConversions);			
							fprintf(asmCode, "    mov  eax, [int_for_conversion_%d]\n", countIntForConversions);	
						break;
						case CONSTANT:
							fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
							fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
							fprintf(asmData, "int_for_conversion_%d dd 0\n", ++countIntForConversions);
							fprintf(asmCode, "    fistp dword [int_for_conversion_%d]\n", countIntForConversions);			
							fprintf(asmCode, "    mov  eax, [int_for_conversion_%d]\n", countIntForConversions);	
						break;
						case REGISTER:
							fprintf(asmCode, "    fld  qword [REG_REAL]\n");
							fprintf(asmData, "int_for_conversion_%d dd 0\n", ++countIntForConversions);
							fprintf(asmCode, "    fistp dword [int_for_conversion_%d]\n", countIntForConversions);			
							fprintf(asmCode, "    mov  eax, [int_for_conversion_%d]\n", countIntForConversions);	
						break;
						case STACK:
							printf("IMPOSSIBLE (STACK in return)\n");
						break;
						
					}

				break;
				
			}
		break;
		
		case REAL:
			switch (lhs->type){
				case INT:						// ---- return int on real method ---- //
					switch(lhs->sclass){
						case MEMORY:	
							fprintf(asmCode, "    fild dword [%s]\n", lhs->MIXname);
						break;
						case CONSTANT:
							fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, lhs->value);
							fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
						break;
						case REGISTER:
							fprintf(asmCode, "    fild dword [REG_INT]\n");
						break;
						case STACK:
							printf("IMPOSSIBLE (STACK in return)\n");
						break;
						
					}
				break;
				
				case REAL:						// ---- return real on real method ---- //
					switch(lhs->sclass){
						case MEMORY:	
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
						break;
						case CONSTANT:
							fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
							fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
						break;
						case REGISTER:
							fprintf(asmCode, "    fld  qword [REG_REAL]\n");
						break;
						case STACK:
							printf("IMPOSSIBLE (STACK in return)\n");
						break;
						
					}

				break;
				
			}
		break;
	}
	
	fprintf(asmCode, "    mov  esp, ebp\n");
	fprintf(asmCode, "    pop  ebp\n");
	fprintf(asmCode, "    ret  %d\n", bytesForParams);
	
	
}

void ProcessBody(AstNode*p, int lev){	
	CodeGeneration(p->pAstNode[0],lev+1,0,0);
	CodeGeneration(p->pAstNode[1],lev+1,0,0);
}


void ProcessStatements(AstNode*p, int lev){	
	CodeGeneration(p->pAstNode[0],lev+1,0,0);
	CodeGeneration(p->pAstNode[1],lev+1,0,0);
}


void ProcessStartAssignStatement(AstNode*p, int lev){	

	Symbol *lhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Assign
	lhs = pop_vs();
	
	if (lhs->type == REAL){
		// pop the expression from fp stack
		fprintf(asmCode, "    ffreep\n");
	}
	
}

void ProcessAssignStatement(AstNode*p, int lev){
	
	Symbol *lhs, *rhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location or ArrayName
	lhs = pop_vs();
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Expression
	rhs = pop_vs();
		
	if (lhs->genre == ARRAY){		
		fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
		strcpy(lhs->MIXname, "ecx");
	}
   
	switch (lhs->type){
		case INT:
			switch (rhs->type){
				case INT:				// ---- INT = INT ---- //
					switch (rhs->sclass){						
						case MEMORY:		
							fprintf(asmCode, "    mov  eax, [%s]\n", rhs->MIXname);
						break;
						case CONSTANT:
							fprintf(asmCode, "    mov  eax, %d\n", rhs->value);	
						break;
						case REGISTER:
							fprintf(asmCode, "    mov  eax, [REG_INT]\n");
						break;
						case STACK:
							printf("IMPOSSIBLE (LOCATION=STACK)");
						break;
					}
					
					fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
			
				break;
				case REAL:				// ---- INT = REAL ---- //
					switch (rhs->sclass){						
						case MEMORY:		
							fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);	
						break;
						case CONSTANT:					
							fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
							fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
						break;
						case REGISTER:
							fprintf(asmCode, "    fld  qword [REG_REAL]\n");
						break;	
						case STACK:
							printf("IMPOSSIBLE (LOCATION=STACK)");
						break;
					}
					
					fprintf(asmCode, "    fist dword [%s]\n", lhs->MIXname);	
			
				break;
			}
		break;
		
		case REAL:
			switch (rhs->type){
				case INT:				// ---- REAL = INT ---- //
					switch (rhs->sclass){
						case MEMORY:		
							fprintf(asmCode, "    fild dword [%s]\n", rhs->MIXname);	
						break;
						case CONSTANT:	
							fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
							fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
						break;
						case REGISTER:
							fprintf(asmCode, "    fild dword [REG_REAL]\n");
						break;	
						case STACK:
							printf("IMPOSSIBLE (LOCATION=STACK)");
						break;
					}
					
					fprintf(asmCode, "    fst  qword [%s]\n", lhs->MIXname);	
			
				break;
				case REAL:				// ---- REAL = REAL ---- //	
					switch (rhs->sclass){
						case MEMORY:		
							fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);	
						break;
						case CONSTANT:					
							fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
							fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
						break;
						case REGISTER:
							fprintf(asmCode, "    fld  qword [REG_REAL]\n");
						break;	
						case STACK:
							printf("IMPOSSIBLE (LOCATION=STACK)");
						break;
					}
					
					fprintf(asmCode, "    fst  qword [%s]\n", lhs->MIXname);		
			
				break;
			}
		break;
	}
	
	push_vs(rhs);
	
   
}



void ProcessMoreAssignStatement(AstNode*p, int lev){
	
	Symbol *lhs, *rhs;
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Assign
	rhs = pop_vs();
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location or ArrayName
	lhs = pop_vs();
	
	if (lhs->genre == ARRAY){		
		fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
		strcpy(lhs->MIXname, "ecx");
	}
	
	switch (lhs->type){
		case INT:
			switch (rhs->type){
				case INT:				// ---- INT = INT ---- //					
					fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);			
				break;
				case REAL:				// ---- INT = REAL ---- //				
					fprintf(asmCode, "    fist dword [%s]\n", lhs->MIXname);			
				break;
			}
		break;
		
		case REAL:
			switch (rhs->type){
				case INT:				// ---- REAL = INT ---- //					
					fprintf(asmCode, "    fst  qword [%s]\n", lhs->MIXname);			
				break;
				case REAL:				// ---- REAL = REAL ---- //				
					fprintf(asmCode, "    fst  qword [%s]\n", lhs->MIXname);			
				break;
			}
		break;
	}
   
	push_vs(rhs);
	
}


void ProcessAssignMultipleStatement(AstNode*p, int lev){

	Symbol *lhs, *rhs, *locationToAssign, *expressionToAssign;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location or ArrayName
	lhs = pop_vs();
	mulAssignLocations[countLocations++] = lhs;
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // NestedAssign	
	
	
	CodeGeneration(p->pAstNode[2],lev+1,0,0); // Expression
	rhs = pop_vs();
	mulAssignExpressions[countExpressions++] = rhs;
	
	
	switch (rhs->type){
		case INT:
			switch (rhs->sclass){

				case MEMORY:
					fprintf(asmCode, "    push dword [%s]\n", rhs->MIXname);	
				break;
				case CONSTANT:
					fprintf(asmCode, "    push %d\n", rhs->value);		
				break;
				case REGISTER:
					fprintf(asmCode, "    push dword [REG_INT]\n");	
				break;
				case STACK:
					printf("IMPOSSIBLE (LOCATION=STACK)");
				break;		
				
			}
		break;
		case REAL:
			switch (rhs->sclass){

				case MEMORY:
					fprintf(asmCode, "    sub  esp, 8\n");		
					fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case CONSTANT:	
					
					fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
					fprintf(asmCode, "    sub  esp, 8\n");
					fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case REGISTER:
					fprintf(asmCode, "    sub  esp, 8\n");		
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case STACK:
					printf("IMPOSSIBLE (LOCATION=STACK)");
				break;		
				
			}
		break;
	}
	
	// Assign value of rhs to the variable locationToAssign	
	
	int i;
	for (i = countLocations-1; i >= 0; i--){
		
		locationToAssign = mulAssignLocations[i];	
		expressionToAssign = mulAssignExpressions[i];
		
		if (locationToAssign->genre == ARRAY){		
			fprintf(asmCode, "    mov  ecx, [%s]\n", locationToAssign->MIXname);
			strcpy(locationToAssign->MIXname, "ecx");
		}
		
		switch (locationToAssign->type){
			case INT:
				switch (expressionToAssign->type){
					case INT:
						fprintf(asmCode, "    pop  eax\n");
						fprintf(asmCode, "    mov  dword [%s], eax\n", locationToAssign->MIXname);
					break;
					case REAL:
						fprintf(asmCode, "    fld  qword [esp]\n");
						fprintf(asmCode, "    add  esp, 8\n");
						fprintf(asmCode, "    fistp dword [%s]\n", locationToAssign->MIXname);	
					break;
				}
			break;
			case REAL:
				switch (expressionToAssign->type){
					case INT:
						fprintf(asmData, "int_for_conversion_%d dd 0\n", ++countIntForConversions);
						fprintf(asmCode, "    pop  dword [int_for_conversion_%d]\n", countIntForConversions);
						fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
						fprintf(asmCode, "    fstp  qword [%s]\n", locationToAssign->MIXname);	
					break;
					case REAL:
						fprintf(asmCode, "    fld  qword [esp]\n");
						fprintf(asmCode, "    add  esp, 8\n");
						fprintf(asmCode, "    fstp qword [%s]\n", locationToAssign->MIXname);
					break;
				}				
			break;
		}
	}
	
	
	
	countLocations = 0;
	countExpressions = 0;
	
}

void ProcessNestedAssignStatement(AstNode*p, int lev){
	
	Symbol *lhs, *rhs, *locationToAssign;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location or ArrayName
	lhs = pop_vs();
	mulAssignLocations[countLocations++] = lhs;
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // NestedAssign	
	
	
	CodeGeneration(p->pAstNode[2],lev+1,0,0); // Expression
	rhs = pop_vs();	
	mulAssignExpressions[countExpressions++] = rhs;
	

	switch (rhs->type){
		case INT:
			switch (rhs->sclass){

				case MEMORY:
					fprintf(asmCode, "    push dword [%s]\n", rhs->MIXname);	
				break;
				case CONSTANT:
					fprintf(asmCode, "    push %d\n", rhs->value);		
				break;
				case REGISTER:
					fprintf(asmCode, "    push dword [REG_INT]\n");	
				break;
				case STACK:
					printf("IMPOSSIBLE (LOCATION=STACK)");
				break;		
				
			}
		break;
		case REAL:
			switch (rhs->sclass){

				case MEMORY:
					fprintf(asmCode, "    sub  esp, 8\n");		
					fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case CONSTANT:	
					
					fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
					fprintf(asmCode, "    sub  esp, 8\n");
					fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case REGISTER:
					fprintf(asmCode, "    sub  esp, 8\n");		
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case STACK:
					printf("IMPOSSIBLE (LOCATION=STACK)");
				break;		
				
			}
		break;
	}
	
	
}

void ProcessLastNestedAssignStatement(AstNode*p, int lev){
	Symbol *lhs, *rhs, *locationToAssign;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location or ArrayName
	lhs = pop_vs();
	mulAssignLocations[countLocations++] = lhs;

	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Expression
	rhs = pop_vs();
	mulAssignExpressions[countExpressions++] = rhs;
	
	
	
	
	switch (rhs->type){
		case INT:
			switch (rhs->sclass){

				case MEMORY:
					fprintf(asmCode, "    push dword [%s]\n", rhs->MIXname);	
				break;
				case CONSTANT:
					fprintf(asmCode, "    push %d\n", rhs->value);		
				break;
				case REGISTER:
					fprintf(asmCode, "    push dword [REG_INT]\n");	
				break;
				case STACK:
					printf("IMPOSSIBLE (LOCATION=STACK)");
				break;		
				
			}
		break;
		case REAL:
			switch (rhs->sclass){

				case MEMORY:
					fprintf(asmCode, "    sub  esp, 8\n");		
					fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case CONSTANT:	
					
					fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
					fprintf(asmCode, "    sub  esp, 8\n");
					fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case REGISTER:
					fprintf(asmCode, "    sub  esp, 8\n");		
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case STACK:
					printf("IMPOSSIBLE (LOCATION=STACK)");
				break;		
				
			}
		break;
	}
	
}


void ProcessAddExpression(AstNode* p, int lev, int lvalue, int leftChild){
	
	Symbol *lhs, *rhs, *new;
	
	CodeGeneration(p->pAstNode[0],lev+1,lvalue,1); // Expression   
	lhs=pop_vs();
	CodeGeneration(p->pAstNode[2],lev+1,lvalue,0); // Term
	rhs=pop_vs();
		
	new = new_symbol("");
	new->lvalue = 0;
	//new->type = INT;
	new->sclass = REGISTER;
	
	if (p->pAstNode[1]->NodeType == astAddOperator){
		
		/* -------- Add -------- */
		
		switch (lhs->type){
			case INT:
				switch (rhs->type){
					case INT:				// ----  INT + INT ---- //
						new->type = INT;
						switch (lhs->sclass){
							case MEMORY:
								
								fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    add  eax, [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmCode, "    add  eax, %d\n", rhs->value);
									break;
									case REGISTER:
										fprintf(asmCode, "    add  eax, [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
										fprintf(asmCode, "    add  eax, [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->value = lhs->value + rhs->value;
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
										fprintf(asmCode, "    add  eax, [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    pop  eax\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    add  eax, [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmCode, "    add  eax, %d\n", rhs->value);
									break;
									case REGISTER:
										fprintf(asmCode, "    add  eax, [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;			
					case REAL:				// ----  INT + REAL ---- //	
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fild dword [%s]\n", lhs->MIXname);
							
								switch (rhs->sclass){								
									case MEMORY:
										fprintf(asmCode, "    fadd qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fadd qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fadd qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fadd qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->value + rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fadd qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    fild dword [esp]\n");
								fprintf(asmCode, "    add  esp, 4\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fadd qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fadd  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fadd qword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;	
				}
			break;			
			case REAL:
				switch (rhs->type){
					case INT:				// ----  REAL + INT ---- //
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fiadd dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
										fprintf(asmCode, "    fiadd dword [int_for_conversion_%d]\n", countIntForConversions);
									break;
									case REGISTER:
										fprintf(asmCode, "    fiadd dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
										fprintf(asmCode, "    fiadd dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->value + rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
										fprintf(asmCode, "    fiadd dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    fld  qword [esp]\n");
								fprintf(asmCode, "    add  esp, 8\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fiadd dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
										fprintf(asmCode, "    fiadd dword [int_for_conversion_%d]\n", countIntForConversions);
									break;
									case REGISTER:
										fprintf(asmCode, "    fiadd dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;			
					case REAL:				// ----  REAL + REAL ---- //	
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fadd qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fadd  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fadd  qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fadd qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->value + rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fadd qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    fld  qword [esp]\n");
								fprintf(asmCode, "    add  esp, 8\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fadd qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fadd qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fadd qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;	
				}
			break;			
		}
		
		
	   
	} else { /* -------- Subtract -------- */	   
	   
		switch (lhs->type){
			case INT:
				switch (rhs->type){
					case INT:				// ----  INT - INT ---- //
						new->type = INT;
						switch (lhs->sclass){
							case MEMORY:
								
								fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    sub  eax, [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmCode, "    sub  eax, %d\n", rhs->value);
									break;
									case REGISTER:
										fprintf(asmCode, "    sub  eax, [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
										fprintf(asmCode, "    sub  eax, [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->value = lhs->value - rhs->value;
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
										fprintf(asmCode, "    sub  eax, [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    pop  eax\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    sub  eax, [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmCode, "    sub  eax, %d\n", rhs->value);
									break;
									case REGISTER:
										fprintf(asmCode, "    sub  eax, [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;			
					case REAL:				// ----  INT - REAL ---- //	
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fild dword [%s]\n", lhs->MIXname);
							
								switch (rhs->sclass){								
									case MEMORY:
										fprintf(asmCode, "    fsub qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fsub  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fsub  qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fsub qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->value - rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fsub qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    fild dword [esp]\n");
								fprintf(asmCode, "    add  esp, 4\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fsub qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fsub  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fsub qword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;	
				}
			break;			
			case REAL:
				switch (rhs->type){
					case INT:				// ----  REAL - INT ---- //
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fisub dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
										fprintf(asmCode, "    fisub dword [int_for_conversion_%d]\n", countIntForConversions);
									break;
									case REGISTER:
										fprintf(asmCode, "    fisub dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
										fprintf(asmCode, "    fisub dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->value - rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
										fprintf(asmCode, "    fisub dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    fld  qword [esp]\n");
								fprintf(asmCode, "    add  esp, 8\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fisub dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
										fprintf(asmCode, "    fisub dword [int_for_conversion_%d]\n", countIntForConversions);
									break;
									case REGISTER:
										fprintf(asmCode, "    fisub dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;			
					case REAL:				// ----  REAL - REAL ---- //	
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fsub qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fsub  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fsub  qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fsub qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->value - rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fsub qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
								
								fprintf(asmCode, "    fld  qword [esp]\n");
								fprintf(asmCode, "    add  esp, 8\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fsub qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fsub qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fsub qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;	
				}
			break;			
		}
		
		
	   
	   
	   
	}
	
	
	if (new->sclass == REGISTER){	
		switch (new->type){
			case INT:
				if (leftChild == 1){	
					new->sclass = STACK;			
					fprintf(asmCode, "    push eax\n");		
				} else {			
					fprintf(asmCode, "    mov  dword [REG_INT], eax\n");
				}
			break;
			case REAL:
				if (leftChild == 1){	
					new->sclass = STACK;			
					fprintf(asmCode, "    sub  esp,8\n");
					fprintf(asmCode, "    fstp qword [esp]\n");
				} else {			
					fprintf(asmCode, "    fstp qword [REG_REAL]\n");
				}
			break;
		}		
	}
	
	
	push_vs(new);
   
	
}

void ProcessTerm(AstNode* p, int lev, int lvalue, int leftChild){
	
	Symbol *lhs, *rhs, *new;
	
	CodeGeneration(p->pAstNode[0],lev+1,lvalue,1); // Term   
	lhs=pop_vs();
	CodeGeneration(p->pAstNode[2],lev+1,lvalue,0); // Factor
	rhs=pop_vs();
		
	new = new_symbol("");
	new->lvalue = 0;
	new->type = INT;
	new->sclass = REGISTER;
	
	if (p->pAstNode[1]->NodeType == astMultiplyOperator){
		
		/* -------- Multiply -------- */
		
		switch (lhs->type){
			case INT:
				switch (rhs->type){
					case INT:				// ----  INT * INT ---- //
						new->type = INT;
						switch (lhs->sclass){
							case MEMORY:
								
								fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    imul eax, [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmCode, "    imul eax, %d\n", rhs->value);
									break;
									case REGISTER:
										fprintf(asmCode, "    imul eax, [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
										fprintf(asmCode, "    imul  eax, [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->value = lhs->value * rhs->value;
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
										fprintf(asmCode, "    imul eax, [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    pop  eax\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    imul eax, [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmCode, "    imul eax, %d\n", rhs->value);
									break;
									case REGISTER:
										fprintf(asmCode, "    imul eax, [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;			
					case REAL:				// ----  INT * REAL ---- //	
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fild dword [%s]\n", lhs->MIXname);
							
								switch (rhs->sclass){								
									case MEMORY:
										fprintf(asmCode, "    fmul qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fmul  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fmul  qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fmul qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->value * rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fmul qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    fild dword [esp]\n");
								fprintf(asmCode, "    add  esp, 4\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fmul qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fmul  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fmul qword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;	
				}
			break;			
			case REAL:
				switch (rhs->type){
					case INT:				// ----  REAL * INT ---- //
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fimul dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
										fprintf(asmCode, "    fimul dword [int_for_conversion_%d]\n", countIntForConversions);
									break;
									case REGISTER:
										fprintf(asmCode, "    fimul dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
										fprintf(asmCode, "    fimul dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->value * rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
										fprintf(asmCode, "    fimul dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    fld  qword [esp]\n");
								fprintf(asmCode, "    add  esp, 8\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fimul dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
										fprintf(asmCode, "    fimul dword [int_for_conversion_%d]\n", countIntForConversions);
									break;
									case REGISTER:
										fprintf(asmCode, "    fimul dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;			
					case REAL:				// ----  REAL * REAL ---- //	
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fmul qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fmul  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fmul  qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fmul qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->value * rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fmul qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
								
								fprintf(asmCode, "    fld  qword [esp]\n");
								fprintf(asmCode, "    add  esp, 8\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fmul qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fmul qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fmul qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;	
				}
			break;			
		}
		
	   
	} else if (p->pAstNode[1]->NodeType == astDivideOperator){

		/* -------- Divide -------- */
	   
	   switch (lhs->type){
			case INT:
				switch (rhs->type){
					case INT:				// ----  INT / INT ---- //
						new->type = INT;
						switch (lhs->sclass){
							case MEMORY:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
										fprintf(asmCode, "    cdq\n");
										fprintf(asmCode, "    mov  ebx, [%s]\n", rhs->MIXname);
										fprintf(asmCode, "    idiv ebx\n");
									break;
									case CONSTANT:
										fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
										fprintf(asmCode, "    cdq\n");
										fprintf(asmCode, "    mov  ebx, %d\n", rhs->value);
										fprintf(asmCode, "    idiv ebx\n");
									break;
									case REGISTER:				
										fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
										fprintf(asmCode, "    cdq\n");
										fprintf(asmCode, "    mov  ebx, [REG_INT]\n");
										fprintf(asmCode, "    idiv ebx\n");	
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}
								
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
										fprintf(asmCode, "    cdq\n");
										fprintf(asmCode, "    mov  ebx, [%s]\n", rhs->MIXname);
										fprintf(asmCode, "    idiv ebx\n");
									break;
									case CONSTANT:
										new->value = lhs->value / rhs->value;
										new->sclass=CONSTANT;
									break;
									case REGISTER:	
										fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
										fprintf(asmCode, "    cdq\n");
										fprintf(asmCode, "    mov  ebx, [REG_INT]\n");
										fprintf(asmCode, "    idiv ebx\n");			
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;				
								}
							break;
							case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
								
								fprintf(asmCode, "    pop  eax\n");
								fprintf(asmCode, "    cdq\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    mov  ebx, [%s]\n", rhs->MIXname);
										fprintf(asmCode, "    idiv ebx\n");	
									break;
									case CONSTANT:
										fprintf(asmCode, "    mov  ebx, %d\n", rhs->value);
										fprintf(asmCode, "    idiv ebx\n");							
									break;
									case REGISTER:	
										fprintf(asmCode, "    mov  ebx, [REG_INT]\n");
										fprintf(asmCode, "    idiv ebx\n");		
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;									
								}
							
							break;
						}
					break;	
					
					case REAL:				// ----  INT / REAL ---- //	
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fild dword [%s]\n", lhs->MIXname);
							
								switch (rhs->sclass){								
									case MEMORY:
										fprintf(asmCode, "    fdiv qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fdiv  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fdiv  qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fdiv qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->value / rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fdiv qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    fild dword [esp]\n");
								fprintf(asmCode, "    add  esp, 4\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fdiv qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fdiv  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fdiv qword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;	
				}
			break;			
			case REAL:
				switch (rhs->type){
					case INT:				// ----  REAL / INT ---- //
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fidiv dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "int_for_conversion_%d dd %dd\n", ++countIntForConversions, rhs->value);
										fprintf(asmCode, "    fidiv dword [int_for_conversion_%d]\n", countIntForConversions);
									break;
									case REGISTER:
										fprintf(asmCode, "    fidiv dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
										fprintf(asmCode, "    fidiv dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->dvalue / rhs->value;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
										fprintf(asmCode, "    fidiv dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
							
								fprintf(asmCode, "    fld  qword [esp]\n");
								fprintf(asmCode, "    add  esp, 8\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fidiv dword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
										fprintf(asmCode, "    fidiv dword [int_for_conversion_%d]\n", countIntForConversions);
									break;
									case REGISTER:
										fprintf(asmCode, "    fidiv dword [REG_INT]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;			
					case REAL:				// ----  REAL / REAL ---- //	
						new->type = REAL;
						switch (lhs->sclass){
							case MEMORY:
							
								fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fdiv qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fdiv  qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fdiv  qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (MEMORY-STACK)\n");
									break;
								}	
							break;
							case CONSTANT:
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fdiv qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										new->dvalue = lhs->dvalue / rhs->dvalue;
										new->value = new->dvalue; // -------- REMOVE ME ------------- //
										new->sclass=CONSTANT;
									break;
									case REGISTER:
										fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, (int) lhs->dvalue);
										fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
										fprintf(asmCode, "    fdiv qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (CONSTANT-STACK)\n");
									break;
								}
							break;
							case REGISTER:
									printf("IMPOSSIBLE (REGISTER-*)\n");
							break;
							case STACK:
								
								fprintf(asmCode, "    fld  qword [esp]\n");
								fprintf(asmCode, "    add  esp, 8\n");
								
								switch (rhs->sclass){
									case MEMORY:
										fprintf(asmCode, "    fdiv qword [%s]\n", rhs->MIXname);
									break;
									case CONSTANT:
										fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
										fprintf(asmCode, "    fdiv qword [real_constant_%d]\n", countRealConsts);
									break;
									case REGISTER:
										fprintf(asmCode, "    fdiv qword [REG_REAL]\n");
									break;
									case STACK:
										printf("IMPOSSIBLE (STACK-STACK)\n");
									break;
								}
							
							break;					
						}
					break;	
				}
			break;			
		}
	   
	   
	} else {

		/* -------- Modulo -------- */
	   
	   
		switch (lhs->sclass){
			case MEMORY:
				if(rhs->sclass == MEMORY){
					fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    cdq\n");
					fprintf(asmCode, "    mov  ebx, [%s]\n", rhs->MIXname);
					fprintf(asmCode, "    idiv ebx\n");
				} else if (rhs->sclass == CONSTANT){
					fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    cdq\n");
					fprintf(asmCode, "    mov  ebx, %d\n", rhs->value);
					fprintf(asmCode, "    idiv ebx\n");
				} else if (rhs->sclass == REGISTER){
					fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    cdq\n");
					fprintf(asmCode, "    mov  ebx, [REG_INT]\n");
					fprintf(asmCode, "    idiv ebx\n");		
				} else { /* -- STACK -- */
					printf("IMPOSSIBLE (MEMORY-STACK)\n");
				}
				
			break;
			case CONSTANT:
				if(rhs->sclass == MEMORY){
					fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
					fprintf(asmCode, "    cdq\n");
					fprintf(asmCode, "    mov  ebx, [%s]\n", rhs->MIXname);
					fprintf(asmCode, "    idiv ebx\n");
				} else if(rhs->sclass == CONSTANT){
					new->value = lhs->value % rhs->value;
					new->sclass=CONSTANT;
				} else if (rhs->sclass == REGISTER){
					fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
					fprintf(asmCode, "    cdq\n");
					fprintf(asmCode, "    mov  ebx, [REG_INT]\n");
					fprintf(asmCode, "    idiv ebx\n");		
				} else { /* -- STACK -- */
					printf("IMPOSSIBLE (CONSTANT-STACK)\n");				
				}
			break;
			case REGISTER:
				printf("IMPOSSIBLE (REGISTER-*)\n");
			break;
			case STACK:
			
				fprintf(asmCode, "    pop  eax\n");
				fprintf(asmCode, "    cdq\n");
				
				if(rhs->sclass == MEMORY){
					fprintf(asmCode, "    mov  ebx, [%s]\n", rhs->MIXname);
					fprintf(asmCode, "    idiv ebx\n");		
				} else if(rhs->sclass == CONSTANT){	
					fprintf(asmCode, "    mov  ebx, %d\n", rhs->value);
					fprintf(asmCode, "    idiv ebx\n");							
				} else if (rhs->sclass == REGISTER){
					fprintf(asmCode, "    mov  ebx, [REG_INT]\n");
					fprintf(asmCode, "    idiv ebx\n");							
				} else { /* -- STACK -- */
					printf("IMPOSSIBLE (STACK-STACK)\n");					
				}
			
			break;
		}
	   
	   
	}
	
	
	if (new->sclass == REGISTER){

		switch (new->type){
			case INT:		
				if (leftChild == 1){					
					new->sclass = STACK;					
					if (p->pAstNode[1]->NodeType != astModuloOperator){
						fprintf(asmCode, "    push eax\n");
					} else {
						fprintf(asmCode, "    push edx\n");				
					}
				} else {
					if (p->pAstNode[1]->NodeType != astModuloOperator){
						fprintf(asmCode, "    mov  dword [REG_INT], eax\n");
					} else {
						fprintf(asmCode, "    mov  dword [REG_INT], edx\n");		
					}
				}
			break;
			
			case REAL:
				if (leftChild == 1){					
					new->sclass = STACK;					
					if (p->pAstNode[1]->NodeType != astModuloOperator){
						fprintf(asmCode, "    sub  esp, 8\n");
						fprintf(asmCode, "    fstp qword [esp]\n");
					} else {
						fprintf(asmCode, "    push edx\n");				
					}
				} else {
					if (p->pAstNode[1]->NodeType != astModuloOperator){
						fprintf(asmCode, "    fstp qword [REG_REAL]\n");
					} else {
						fprintf(asmCode, "    mov  dword [REG_INT], edx\n");		
					}
				}
			break;
		}
		
	}
	
	
	push_vs(new);
	
}

void ProcessOrExpression(AstNode*p, int lev, int lvalue, int leftChild){
	
	Symbol *lhs, *rhs, *new;
	
	CodeGeneration(p->pAstNode[0],lev+1,lvalue,1); // Expression   
	lhs=pop_vs();
	CodeGeneration(p->pAstNode[1],lev+1,lvalue,0); // AndExpression
	rhs=pop_vs();
	
	
	new = new_symbol("");
	new->lvalue = 0;
	new->type = INT;
	new->sclass = REGISTER;
	
	

	switch (lhs->type){
		case INT:
			switch (rhs->type){
				case INT:					// ---- INT OR INT ---- //
					switch (lhs->sclass){ 
						
						case MEMORY:
						
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
							fprintf(asmCode, "    cmp  ecx, 0\n");
							
							switch (rhs->sclass){
								case  MEMORY:
									fprintf(asmCode, "    jne  $ + 10\n"); // jump 4 statements later (2+3+3+2=10)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    jne  $ + 12\n"); // jump 4 statements later (2+5+3+2=12)
									fprintf(asmCode, "    mov  ecx, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 4 statements later (2+6+3+2=13)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");							
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case  MEMORY:			
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmCode, "    mov  ecx, %d\n", lhs->value);
									fprintf(asmCode, "    cmp  ecx, 0\n");
									fprintf(asmCode, "    jne  $ + 10\n"); // jump 4 statements later (2+3+3+2=10)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									new->value = (lhs->value || rhs->value);								
									new->sclass=CONSTANT;				
								break;
								case REGISTER:
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmCode, "    mov  ecx, %d\n", lhs->value);
									fprintf(asmCode, "    cmp  ecx, 0\n");
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 4 statements later (2+6+3+2=13)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");						
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");
								break;			
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
					
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    pop  ecx\n");
							fprintf(asmCode, "    cmp  ecx, 0\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    jne  $ + 10\n"); // jump 4 statements later (2+3+3+2=10)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    jne  $ + 12\n"); // jump 4 statements later (2+5+3+2=12)
									fprintf(asmCode, "    mov  ecx, %d\n", rhs->value);			
								break;
								case REGISTER:
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 4 statements later (2+6+3+2=13)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");					
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");					
								break;		
							}
							
						break;
					}					
					
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   $ + 7\n"); // jump 2 statements later (2+5=7)
					fprintf(asmCode, "    mov  eax, 1\n");
					
				break;
				
				case REAL:					// ---- INT OR REAL ---- //
				
					switch (lhs->sclass){ 				
						case MEMORY:
						
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
							fprintf(asmCode, "    cmp  ecx, 0\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 6 statements later (2+3+2+2+2+2=13)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    jne  $ + 16\n"); // jump 6 statements later (2+6+2+2+2+2=16)
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);	
								break;
								case REGISTER:
									fprintf(asmCode, "    jne  $ + 16\n"); // jump 6 statements later (2+6+2+2+2+2=16)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");				
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case  MEMORY:					
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmCode, "    mov  ecx, %d\n", lhs->value);
									fprintf(asmCode, "    cmp  ecx, 0\n");
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 6 statements later (2+3+2+2+2+2=13)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:								
									new->value = (lhs->value || rhs->dvalue);								
									new->sclass=CONSTANT;				
								break;
								case REGISTER:
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmCode, "    mov  ecx, %d\n", lhs->value);
									fprintf(asmCode, "    cmp  ecx, 0\n");
									fprintf(asmCode, "    jne  $ + 16\n"); // jump 6 statements later (2+6+2+2+2+2=16)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");	
								break;		
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
					
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    pop  ecx\n");
							fprintf(asmCode, "    cmp  ecx, 0\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 6 statements later (2+3+2+2+2+2=13)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    jne  $ + 16\n"); // jump 6 statements later (2+6+2+2+2+2=16)
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);	
								break;
								case REGISTER:
									fprintf(asmCode, "    jne  $ + 16\n"); // jump 6 statements later (2+6+2+2+2+2=16)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");	
								break;								
							}
							
						break;
					}		
					
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   $ + 7\n"); // jump 2 statements later (2+5=7)					
					fprintf(asmCode, "    mov  eax, 1\n");
					
				break;
			}
		break;
		
		case REAL:
			switch (rhs->type){
				case INT:					// ---- REAL OR INT ---- //
					switch (lhs->sclass){ 
						
						case MEMORY:
						
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							fprintf(asmCode, "    fldz\n");
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    jne  $ + 10\n"); // jump 3 statements later (2+3+3+2=10)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    jne  $ + 12\n"); // jump 3 statements later (2+5+3+2=12)
									fprintf(asmCode, "    mov  ecx, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 3 statements later (2+6+3+2=13)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");	
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case  MEMORY:			
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    fldz\n");
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");
									fprintf(asmCode, "    jne  $ + 10\n"); // jump 3 statements later (2+3+3+2=10)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									new->value = (lhs->dvalue || rhs->value);								
									new->sclass=CONSTANT;
								break;
								case REGISTER:
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    fldz\n");
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 3 statements later (2+6+3+2=13)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");	
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");
								break;		
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
					
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    fld  qword [esp]\n");
							fprintf(asmCode, "    add  esp, 8]\n");
							fprintf(asmCode, "    fldz\n");
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
							switch (rhs->sclass){
								case  MEMORY:
									fprintf(asmCode, "    jne  $ + 10\n"); // jump 3 statements later (2+3+3+2=10)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    jne  $ + 12\n"); // jump 3 statements later (2+5+3+2=12)
									fprintf(asmCode, "    mov  ecx, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 3 statements later (2+6+3+2=13)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");		
								break;
							}
							
						break;
					}					
					
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   $ + 7\n"); // jump 2 statements later (2+5=7)
					fprintf(asmCode, "    mov  eax, 1\n");
					
				break;
				
				case REAL:					// ---- REAL OR REAL ---- //
				
					switch (lhs->sclass){ 				
						case MEMORY:
						
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							fprintf(asmCode, "    fldz\n");
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
							switch (rhs->sclass){
								case  MEMORY:
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 6 statements later (2+3+2+2+2+2=13)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    jne  $ + 16\n"); // jump 6 statements later (2+6+2+2+2+2=16)
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    jne  $ + 16\n"); // jump 6 statements later (2+6+2+2+2+2=16)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");	
								break;
							}
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case  MEMORY:			
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    fldz\n");
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 6 statements later (2+3+2+2+2+2=13)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									new->value = (lhs->dvalue || rhs->dvalue);								
									new->sclass=CONSTANT;
								break;
								case REGISTER:
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    fldz\n");
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");
									fprintf(asmCode, "    jne  $ + 16\n"); // jump 6 statements later (2+6+2+2+2+2=16)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");	
								break;		
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
					
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    fld  qword [esp]\n");
							fprintf(asmCode, "    add  esp, 8]\n");
							fprintf(asmCode, "    fldz\n");
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    jne  $ + 13\n"); // jump 6 statements later (2+3+2+2+2+2=13)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    jne  $ + 16\n"); // jump 6 statements later (2+6+2+2+2+2=16)
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    jne  $ + 16\n"); // jump 6 statements later (2+6+2+2+2+2=16)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");		
								break;			
							}
							
						break;
					}		
					
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   $ + 7\n"); // jump 2 statements later (2+5=7)					
					fprintf(asmCode, "    mov  eax, 1\n");
					
				break;
			}
		break;
	}
	
	if (new->sclass == REGISTER){
	
		if (leftChild == 1){				
			new->sclass = STACK;
			fprintf(asmCode, "    push eax\n");		
		} else {			
			fprintf(asmCode, "    mov  dword [REG_INT], eax\n");			
		}
		
		
	}	
	
	push_vs(new);
	
	
}

void ProcessAndExpression(AstNode*p, int lev, int lvalue, int leftChild){
		
	Symbol *lhs, *rhs, *new;
	
	CodeGeneration(p->pAstNode[0],lev+1,lvalue,1); // Expression   
	lhs=pop_vs();
	CodeGeneration(p->pAstNode[1],lev+1,lvalue,0); // AndExpression
	rhs=pop_vs();
	
	
	new = new_symbol("");
	new->lvalue = 0;
	new->type = INT;
	new->sclass = REGISTER;
	
	
	switch (lhs->type){
		case INT:
			switch (rhs->type){
				case INT:					// ---- INT AND INT ---- //
					switch (lhs->sclass){
						
						case MEMORY:
						
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
							fprintf(asmCode, "    cmp  ecx, 0\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    je   $ + 15\n"); // jump 4 statements later (2+3+3+2+5=15)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    je   $ + 17\n"); // jump 4 statements later (2+5+3+2+5=17)
									fprintf(asmCode, "    mov  ecx, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    je   $ + 18\n"); // jump 4 statements later (2+6+3+2+5=18)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");	
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");		
								break;
							}
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case  MEMORY:				
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmCode, "    mov  ecx, %d\n", lhs->value);
									fprintf(asmCode, "    cmp  ecx, 0\n");
									fprintf(asmCode, "    je   $ + 15\n"); // jump 4 statements later (2+3+3+2+5=15)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:				
									new->value = (lhs->value && rhs->value);				
									new->sclass=CONSTANT;
								break;
								case REGISTER:
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmCode, "    mov  ecx, %d\n", lhs->value);
									fprintf(asmCode, "    cmp  ecx, 0\n");
									fprintf(asmCode, "    je   $ + 18\n"); // jump 4 statements later (2+6+3+2+5=18)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");	
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");		
								break;
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
					
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    pop  ecx\n");
							fprintf(asmCode, "    cmp  ecx, 0\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    je   $ + 15\n"); // jump 4 statements later (2+3+3+2+5=15)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:				
									fprintf(asmCode, "    je   $ + 17\n"); // jump 4 statements later (2+5+3+2+5=17)
									fprintf(asmCode, "    mov  ecx, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    je   $ + 18\n"); // jump 4 statements later (2+6+3+2+5=18)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");	
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");			
								break;			
							}
							
						break;
					}
					
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   $ + 7\n"); // jump 2 statements later (2+5=7)
					fprintf(asmCode, "    mov  eax, 1\n");
					
				break;
				
				case REAL:					// ---- INT AND REAL ---- //
					switch (lhs->sclass){
						
						case MEMORY:
						
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
							fprintf(asmCode, "    cmp  ecx, 0\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    je   $ + 18\n"); // jump 7 statements later (2+3+2+2+2+2+5=18)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    je   $ + 21\n"); // jump 7 statements later (2+6+2+2+2+2+5=21)
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    je   $ + 21\n"); // jump 7 statements later (2+6+2+2+2+2+5=21)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");		
								break;
							}
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case  MEMORY:				
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmCode, "    mov  ecx, %d\n", lhs->value);
									fprintf(asmCode, "    cmp  ecx, 0\n");
									fprintf(asmCode, "    je   $ + 18\n"); // jump 7 statements later (2+3+2+2+2+2+5=18)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:				
									new->value = (lhs->value && rhs->dvalue);				
									new->sclass=CONSTANT;
								break;
								case REGISTER:
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmCode, "    mov  ecx, %d\n", lhs->value);
									fprintf(asmCode, "    cmp  ecx, 0\n");
									fprintf(asmCode, "    je   $ + 21\n"); // jump 7 statements later (2+6+2+2+2+2+5=21)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");		
								break;
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
					
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    pop  ecx\n");
							fprintf(asmCode, "    cmp  ecx, 0\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    je   $ + 18\n"); // jump 7 statements later (2+3+2+2+2+2+5=18)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:				
									fprintf(asmCode, "    je   $ + 21\n"); // jump 7 statements later (2+6+2+2+2+2+5=21)
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    je   $ + 21\n"); // jump 7 statements later (2+6+2+2+2+2+5=21)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");			
								break;			
							}
							
						break;
					}
					
					
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   $ + 7\n"); // jump 2 statements later (2+5=7)
					fprintf(asmCode, "    mov  eax, 1\n");
					
				break;
			}
		break;
		
		case REAL:
			switch (rhs->type){
				case INT:					// ---- REAL AND INT ---- //
					switch (lhs->sclass){
						
						case MEMORY:
						
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							fprintf(asmCode, "    fldz\n");
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    je   $ + 15\n"); // jump 4 statements later (2+3+3+2+5=15)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    je   $ + 17\n"); // jump 4 statements later (2+5+3+2+5=17)
									fprintf(asmCode, "    mov  ecx, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    je   $ + 18\n"); // jump 4 statements later (2+6+3+2+5=18)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");	
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");		
								break;
							}
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case  MEMORY:				
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    fldz\n");
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");
									fprintf(asmCode, "    je   $ + 15\n"); // jump 4 statements later (2+3+3+2+5=15)	
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:				
									new->value = (lhs->dvalue && rhs->value);				
									new->sclass=CONSTANT;
								break;
								case REGISTER:
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    fldz\n");
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");
									fprintf(asmCode, "    je   $ + 18\n"); // jump 4 statements later (2+6+3+2+5=18)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");	
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");		
								break;
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
					
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    fld  qword [esp]\n");
							fprintf(asmCode, "    add  esp, 8\n");
							fprintf(asmCode, "    fldz\n");
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    je   $ + 15\n"); // jump 4 statements later (2+3+3+2+5=15)
									fprintf(asmCode, "    mov  ecx, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:				
									fprintf(asmCode, "    je   $ + 17\n"); // jump 4 statements later (2+5+3+2+5=17)
									fprintf(asmCode, "    mov  ecx, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    je   $ + 18\n"); // jump 4 statements later (2+6+3+2+5=18)
									fprintf(asmCode, "    mov  ecx, [REG_INT]\n");	
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");			
								break;			
							}
							
						break;
					}
					
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   $ + 7\n"); // jump 2 statements later (2+5=7)
					fprintf(asmCode, "    mov  eax, 1\n");
					
				break;
				
				case REAL:					// ---- REAL AND REAL ---- //
					switch (lhs->sclass){
						
						case MEMORY:
						
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							fprintf(asmCode, "    fldz\n");
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
							switch (rhs->sclass){
								case  MEMORY:
									fprintf(asmCode, "    je   $ + 18\n"); // jump 7 statements later (2+3+2+2+2+2+5=18)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    je   $ + 21\n"); // jump 7 statements later (2+6+2+2+2+2+5=21)
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    je   $ + 21\n"); // jump 7 statements later (2+6+2+2+2+2+5=21)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");		
								break;
							}
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case  MEMORY:				
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    je   $ + 18\n"); // jump 7 statements later (2+3+2+2+2+2+5=18)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:				
									new->value = (lhs->dvalue && rhs->dvalue);				
									new->sclass=CONSTANT;
								break;
								case REGISTER:
									fprintf(asmCode, "    mov  eax, 0\n");
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    je   $ + 21\n"); // jump 7 statements later (2+6+2+2+2+2+5=21)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");		
								break;
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
					
							fprintf(asmCode, "    mov  eax, 0\n");
							fprintf(asmCode, "    fld  qword [esp]\n");
							fprintf(asmCode, "    add  esp, 8\n");
							fprintf(asmCode, "    fldz\n");
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
							switch (rhs->sclass){
								case  MEMORY:	
									fprintf(asmCode, "    je   $ + 18\n"); // jump 7 statements later (2+3+2+2+2+2+5=18)
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:				
									fprintf(asmCode, "    je   $ + 21\n"); // jump 7 statements later (2+6+2+2+2+2+5=21)
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    je   $ + 21\n"); // jump 7 statements later (2+6+2+2+2+2+5=21)
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");			
								break;			
							}
							
						break;
					}
					
					
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   $ + 7\n"); // jump 2 statements later (2+5=7)
					fprintf(asmCode, "    mov  eax, 1\n");
					
				break;
			}
		break;
	}
	
	if (new->sclass == REGISTER){
		
		if (leftChild == 1){				
			new->sclass = STACK;
			fprintf(asmCode, "    push eax\n");		
		} else {			
			fprintf(asmCode, "    mov  dword [REG_INT], eax\n");			
		}		
		
	}	
	
	push_vs(new);
}

void ProcessRelationExpression(AstNode*p, int lev, int lvalue, int leftChild){
	
	Symbol *lhs, *rhs, *new;
	
	CodeGeneration(p->pAstNode[0],lev+1,lvalue,1); // Expression   
	lhs=pop_vs();
	CodeGeneration(p->pAstNode[2],lev+1,lvalue,0); // AndExpression
	rhs=pop_vs();
	
	
	new = new_symbol("");
	new->lvalue = 0;
	new->type = INT;
	new->sclass = REGISTER;
	
	
	
	switch (lhs->type){
		case INT:
			switch (rhs->type){
				case INT:					// ---- INT compare INT ---- //
					switch (lhs->sclass){
						
						case MEMORY:
						
							fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    cmp  eax, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    cmp  eax, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    cmp  eax, [REG_INT]\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
									fprintf(asmCode, "    cmp  eax, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									switch (p->pAstNode[1]->NodeType){
										case astLessOrEqualOperator:
											new->value = (lhs->value <= rhs->value);
										break;
										case astLessOperator:
											new->value = (lhs->value < rhs->value);				
										break;
										case astGreaterOperator:
											new->value = (lhs->value > rhs->value);			
										break;
										case astGreaterOrEqualOperator:
											new->value = (lhs->value >= rhs->value);					
										break;
										case astEqualOperator:
											new->value = (lhs->value == rhs->value);					
										break;
										case astNotEqualOperator:
											new->value = (lhs->value != rhs->value);				
										break;
										
									}
									new->sclass=CONSTANT;				
								break;
								case REGISTER:
									fprintf(asmCode, "    mov  eax, %d\n", lhs->value);
									fprintf(asmCode, "    cmp  eax, [REG_INT]\n");			
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");	
								break;
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
						
							fprintf(asmCode, "    pop  eax\n");
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    cmp  eax, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    cmp  eax, %d\n", rhs->value);			
								break;
								case REGISTER:
									fprintf(asmCode, "    cmp  eax, [REG_INT]\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");
								break;				
							}
							
						break;
					}
				break;
			
				case REAL:					// ---- INT compare REAL ---- //
					switch (lhs->sclass){
						
						case MEMORY:
						
							fprintf(asmCode, "    fild dword [%s]\n", lhs->MIXname);
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, lhs->value);
									fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");
								break;
								case CONSTANT:
									switch (p->pAstNode[1]->NodeType){
										case astLessOrEqualOperator:
											new->value = (lhs->value <= rhs->dvalue);
										break;
										case astLessOperator:
											new->value = (lhs->value < rhs->dvalue);				
										break;
										case astGreaterOperator:
											new->value = (lhs->value > rhs->dvalue);			
										break;
										case astGreaterOrEqualOperator:
											new->value = (lhs->value >= rhs->dvalue);					
										break;
										case astEqualOperator:
											new->value = (lhs->value == rhs->dvalue);					
										break;
										case astNotEqualOperator:
											new->value = (lhs->value != rhs->dvalue);				
										break;
										
									}
									new->sclass=CONSTANT;				
								break;
								case REGISTER:
									fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, lhs->value);
									fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");	
								break;
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
						
							fprintf(asmCode, "    fild dword [esp]\n");
							fprintf(asmCode, "    add  esp, 4\n");
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");
								break;				
							}
							
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");		
							
						break;
					}
				break;
			}
		break;
		
		case REAL:
			switch (rhs->type){
				case INT:					// ---- REAL compare INT ---- //
					switch (lhs->sclass){
						
						case MEMORY:
						
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
						
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fild  dword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
									fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);
								break;
								case REGISTER:
									fprintf(asmCode, "    fild dword [REG_INT]\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}							
							
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");	
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    fild dword [%s]\n", rhs->MIXname);
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");
								break;
								case CONSTANT:
									switch (p->pAstNode[1]->NodeType){
										case astLessOrEqualOperator:
											new->value = (lhs->dvalue <= rhs->value);
										break;
										case astLessOperator:
											new->value = (lhs->dvalue < rhs->value);				
										break;
										case astGreaterOperator:
											new->value = (lhs->dvalue > rhs->value);			
										break;
										case astGreaterOrEqualOperator:
											new->value = (lhs->dvalue >= rhs->value);					
										break;
										case astEqualOperator:
											new->value = (lhs->dvalue == rhs->value);					
										break;
										case astNotEqualOperator:
											new->value = (lhs->dvalue != rhs->value);				
										break;
										
									}
									new->sclass=CONSTANT;				
								break;
								case REGISTER:								
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    fild dword [REG_INT]\n");
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");	
								break;
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
						
							fprintf(asmCode, "    fld  qword [esp]\n");
							fprintf(asmCode, "    add  esp, 8\n");
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fild dword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
									fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);	
								break;
								case REGISTER:
									fprintf(asmCode, "    fild dword [REG_INT]\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");
								break;				
							}
							
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
						break;
					}
				break;
			
				case REAL:					// ---- REAL compare REAL ---- //
					switch (lhs->sclass){
						
						case MEMORY:
						
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");
							
						break;
						case CONSTANT:
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");
								break;
								case CONSTANT:
									switch (p->pAstNode[1]->NodeType){
										case astLessOrEqualOperator:
											new->value = (lhs->dvalue <= rhs->dvalue);
										break;
										case astLessOperator:
											new->value = (lhs->dvalue < rhs->dvalue);				
										break;
										case astGreaterOperator:
											new->value = (lhs->dvalue > rhs->dvalue);			
										break;
										case astGreaterOrEqualOperator:
											new->value = (lhs->dvalue >= rhs->dvalue);					
										break;
										case astEqualOperator:
											new->value = (lhs->dvalue == rhs->dvalue);					
										break;
										case astNotEqualOperator:
											new->value = (lhs->dvalue != rhs->dvalue);				
										break;
										
									}
									new->sclass=CONSTANT;				
								break;
								case REGISTER:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");
									fprintf(asmCode, "    fcomip\n");
									fprintf(asmCode, "    ffreep\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (CONSTANT-STACK)\n");	
								break;
							}
						break;
						case REGISTER:
								printf("IMPOSSIBLE (REGISTER-*)\n");
						break;
						case STACK:
						
							fprintf(asmCode, "    fld  qword [esp]\n");
							fprintf(asmCode, "    add  esp, 8\n");
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fld  qword [REG_REAL]\n");		
								break;
								case STACK:
									printf("IMPOSSIBLE (STACK-STACK)\n");
								break;				
							}
							
							fprintf(asmCode, "    fcomip\n");
							fprintf(asmCode, "    ffreep\n");		
							
						break;
					}
				break;
			}
		break;
	}
	
	if (new->sclass == REGISTER){
	
		fprintf(asmCode, "    mov  eax, 1\n");
		
		if (lhs->type == INT && rhs->type == INT){
			switch (p->pAstNode[1]->NodeType){
				case astLessOrEqualOperator:
					fprintf(asmCode, "    jle  $+7\n");		
				break;
				case astLessOperator:
					fprintf(asmCode, "    jl   $+7\n");		
				break;
				case astGreaterOperator:
					fprintf(asmCode, "    jg   $+7\n");		
				break;
				case astGreaterOrEqualOperator:	
					fprintf(asmCode, "    jge  $+7\n");				
				break;
				case astEqualOperator:
					fprintf(asmCode, "    je   $+7\n");			
				break;
				case astNotEqualOperator:
					fprintf(asmCode, "    jne  $+7\n");			
				break;
			} // $ + 7 -> 2 (j__ $+7) + 5 (mov  ecx, 0)
		} else {			
			switch (p->pAstNode[1]->NodeType){
				case astLessOrEqualOperator:
					fprintf(asmCode, "    jae  $+7\n");	// values are stored in fstack reversed (st0 = 2nd, st1 = 1st)	
				break;
				case astLessOperator:
					fprintf(asmCode, "    ja   $+7\n");	// values are stored in fstack reversed (st0 = 2nd, st1 = 1st)	
				break;
				case astGreaterOperator:
					fprintf(asmCode, "    jb   $+7\n"); // values are stored in fstack reversed (st0 = 2nd, st1 = 1st)	
				break;
				case astGreaterOrEqualOperator:	
					fprintf(asmCode, "    jbe  $+7\n");	// values are stored in fstack reversed (st0 = 2nd, st1 = 1st)			
				break;
				case astEqualOperator:
					fprintf(asmCode, "    je   $+7\n");			
				break;
				case astNotEqualOperator:
					fprintf(asmCode, "    jne  $+7\n");			
				break;
			} // $ + 7 -> 2 (j__ $+7) + 5 (mov  ecx, 0)
		}
		
		fprintf(asmCode, "    mov  eax, 0\n");
			
		if (leftChild == 1){				
			new->sclass = STACK;
			fprintf(asmCode, "    push eax\n");		
		} else {			
			fprintf(asmCode, "    mov  dword [REG_INT], eax\n");
		}
		
		
	}	
	
	push_vs(new);
	
	
}

void ProcessIfStatement(AstNode*p, int lev){
	
	Symbol *lhs, *new;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Expression
	lhs = pop_vs();
	
	int tempNumIfs;
	
	switch (lhs->type){
		case INT:
			switch (lhs->sclass){	
				case  MEMORY:
				
					numIfs++;
					tempNumIfs = numIfs;
					fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   EndIf%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case CONSTANT:
					if (lhs->value != 0){
						CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)
					}
				break;
				case REGISTER:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					fprintf(asmCode, "    mov  ecx, [REG_INT]\n");
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   EndIf%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in if)\n");
				break;
			}
	
		break;
		
		case REAL:
			switch (lhs->sclass){	
				case  MEMORY:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					
					fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   EndIf%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case CONSTANT:
					if (lhs->dvalue != 0){
						CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)
					}
				break;
				case REGISTER:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   EndIf%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in if)\n");
				break;
			}
		break;
	}
	
}

void ProcessIfElseStatement(AstNode*p, int lev){
	
	Symbol *lhs, *new;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Expression
	lhs = pop_vs();
	
	int tempNumIfs;
	
	switch (lhs->type){
		case INT:
			switch (lhs->sclass){	
				case  MEMORY:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   Else%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)					
					
					fprintf(asmCode, "    jmp  EndIf%d\n", tempNumIfs);
					fprintf(asmCode, "    Else%d:\n", tempNumIfs);
					CodeGeneration(p->pAstNode[2],lev+1,0,0); // Statement (else)
					
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case CONSTANT:
					if (lhs->value != 0){
						CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)
					} else {
						CodeGeneration(p->pAstNode[2],lev+1,0,0); // Statement (else)
					}
				break;
				case REGISTER:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					fprintf(asmCode, "    mov  ecx, [REG_INT]\n");
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   Else%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)					
					
					fprintf(asmCode, "    jmp  EndIf%d\n", tempNumIfs);
					fprintf(asmCode, "    Else%d:\n", tempNumIfs);
					CodeGeneration(p->pAstNode[2],lev+1,0,0); // Statement (else)
					
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in if)\n");
				break;
			}
		break;
		
		case REAL:
			switch (lhs->sclass){	
				case  MEMORY:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   Else%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)					
					
					fprintf(asmCode, "    jmp  EndIf%d\n", tempNumIfs);
					fprintf(asmCode, "    Else%d:\n", tempNumIfs);
					CodeGeneration(p->pAstNode[2],lev+1,0,0); // Statement (else)
					
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case CONSTANT:
					if (lhs->dvalue != 0){
						CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)
					} else {
						CodeGeneration(p->pAstNode[2],lev+1,0,0); // Statement (else)
					}
				break;
				case REGISTER:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   Else%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Statement (if)					
					
					fprintf(asmCode, "    jmp  EndIf%d\n", tempNumIfs);
					fprintf(asmCode, "    Else%d:\n", tempNumIfs);
					CodeGeneration(p->pAstNode[2],lev+1,0,0); // Statement (else)
					
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in if)\n");
				break;
			}
		break;
	}
	
}


void ProcessUnlessStatement(AstNode*p, int lev){
	
	Symbol *rhs, *new;
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Expression
	rhs = pop_vs();
	
	int tempNumIfs;
	
	switch (rhs->type){
		case INT:
			switch (rhs->sclass){	
				case  MEMORY:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					fprintf(asmCode, "    mov  eax, [%s]\n", rhs->MIXname);
					fprintf(asmCode, "    cmp  eax, 0\n");
					fprintf(asmCode, "    jne  EndIf%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[0],lev+1,0,0); // Statement
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case CONSTANT:
					if (rhs->value == 0){
						CodeGeneration(p->pAstNode[0],lev+1,0,0); // Statement
					}
				break;
				case REGISTER:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					fprintf(asmCode, "    mov  eax, [REG_INT]\n");
					fprintf(asmCode, "    cmp  eax, 0\n");
					fprintf(asmCode, "    jne  EndIf%d\n", tempNumIfs);
					CodeGeneration(p->pAstNode[0],lev+1,0,0); // Statement
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in if)\n");
				break;
			}
			
		break;
		
		case REAL:
			switch (rhs->sclass){	
				case  MEMORY:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jnz  EndIf%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[0],lev+1,0,0); // Statement
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case CONSTANT:
					if (rhs->value == 0){
						CodeGeneration(p->pAstNode[0],lev+1,0,0); // Statement
					}
				break;
				case REGISTER:
				
					numIfs++;
					tempNumIfs = numIfs;
					
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jnz  EndIf%d\n", tempNumIfs);
					
					CodeGeneration(p->pAstNode[0],lev+1,0,0); // Statement
					fprintf(asmCode, "    EndIf%d:\n", tempNumIfs);
					
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in if)\n");
				break;
			}
		break;
	}
	
}


void ProcessWhileStatement(AstNode*p, int lev){
	
	Symbol *lhs, *new, *whileSym;
	int tempNumWhiles;
	
	numWhiles++;
	tempNumWhiles = numWhiles;
			
	
	fprintf(asmCode, "    While%d:\n", tempNumWhiles);
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Expression
	lhs = pop_vs();
	
	
	switch (lhs->type){
		case INT:
			switch (lhs->sclass){	
				case MEMORY:	

					whileSym = new_symbol("");
					whileSym->value = tempNumWhiles;
					push_while(whileSym);	
					
					fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);	
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   EndWhile%d\n", tempNumWhiles);
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Loop body	
					
					fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
					fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
					
					pop_while();
					
				break;
				case CONSTANT:
					if (lhs->value != 0){
						
						whileSym = new_symbol("");
						whileSym->value = tempNumWhiles;
						push_while(whileSym);	
					
						CodeGeneration(p->pAstNode[1],lev+1,0,0); // Loop body				
						
						fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
						fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
						
						pop_while();
					}		
				break;
				case REGISTER:	
				
					whileSym = new_symbol("");
					whileSym->value = tempNumWhiles;
					push_while(whileSym);	
							
					fprintf(asmCode, "    mov  ecx, [REG_INT]\n");
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   EndWhile%d\n", tempNumWhiles);
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Loop body			
					
					fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
					fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
					
					pop_while();
					
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in while)\n");
				break;
			}
		break;
		
		case REAL:
			switch (lhs->sclass){	
				case MEMORY:	

					whileSym = new_symbol("");
					whileSym->value = tempNumWhiles;
					push_while(whileSym);	
					
					fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   EndWhile%d\n", tempNumWhiles);
					
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Loop body	
					
					fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
					fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
					
					pop_while();
					
				break;
				case CONSTANT:
					if (lhs->value != 0){
						
						whileSym = new_symbol("");
						whileSym->value = tempNumWhiles;
						push_while(whileSym);	
					
						CodeGeneration(p->pAstNode[1],lev+1,0,0); // Loop body				
						
						fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
						fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
						
						pop_while();
					}		
				break;
				case REGISTER:	
				
					whileSym = new_symbol("");
					whileSym->value = tempNumWhiles;
					push_while(whileSym);	
					
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   EndWhile%d\n", tempNumWhiles);
					
					CodeGeneration(p->pAstNode[1],lev+1,0,0); // Loop body			
					
					fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
					fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
					
					pop_while();
					
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in while)\n");
				break;
			}
		break;
	}
	
}


void ProcessRepeatStatement(AstNode*p, int lev){
	
	Symbol *lhs, *new, *whileSym;
	int tempNumWhiles;
	
	numWhiles++;
	tempNumWhiles = numWhiles;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Expression
	lhs = pop_vs();
	

	switch (lhs->sclass){	
		case MEMORY:	

			whileSym = new_symbol("");
			whileSym->value = tempNumWhiles;
			push_while(whileSym);		
			
			
			
			fprintf(asmCode, "    push dword [%s]\n", lhs->MIXname);	
			fprintf(asmCode, "    While%d:\n", tempNumWhiles);
			fprintf(asmCode, "    pop  eax\n");	
			fprintf(asmCode, "    cmp  eax, 0\n");
			fprintf(asmCode, "    jle  EndWhile%d\n", tempNumWhiles);
			fprintf(asmCode, "    dec  eax\n");
			fprintf(asmCode, "    push eax\n");
			CodeGeneration(p->pAstNode[1],lev+1,0,0); // Loop body			
			
			
			fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
			fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
			
			pop_while();
			
		break;
		case CONSTANT:
			if (lhs->value > 0){
				
				whileSym = new_symbol("");
				whileSym->value = tempNumWhiles;
				push_while(whileSym);	
			
				fprintf(asmCode, "    push %d\n", lhs->value);	
				fprintf(asmCode, "    While%d:\n", tempNumWhiles);
				fprintf(asmCode, "    pop  eax\n");	
				fprintf(asmCode, "    cmp  eax, 0\n");
				fprintf(asmCode, "    jle  EndWhile%d\n", tempNumWhiles);
				fprintf(asmCode, "    dec  eax\n");
				fprintf(asmCode, "    push eax\n");
				CodeGeneration(p->pAstNode[1],lev+1,0,0); // Loop body		
				
				
				fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
				fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
				
				pop_while();
			}		
		break;
		case REGISTER:	
		
			whileSym = new_symbol("");
			whileSym->value = tempNumWhiles;
			push_while(whileSym);	
		
			
			
			fprintf(asmCode, "    push dword [REG_INT]\n");	
			fprintf(asmCode, "    While%d:\n", tempNumWhiles);
			fprintf(asmCode, "    pop  eax\n");	
			fprintf(asmCode, "    cmp  eax, 0\n");
			fprintf(asmCode, "    jle  EndWhile%d\n", tempNumWhiles);
			fprintf(asmCode, "    dec  eax\n");
			fprintf(asmCode, "    push eax\n");
			CodeGeneration(p->pAstNode[1],lev+1,0,0); // Loop body			
			
			
			fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
			fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
			
			pop_while();
			
		break;
		case STACK:
			printf("IMPOSSIBLE (STACK in while)\n");
		break;
	}
	
	
}

void ProcessForStatement(AstNode*p, int lev){
	
	Symbol *lhs, *new, *whileSym;
	int tempNumWhiles;
	
	numWhiles++;
	tempNumWhiles = numWhiles;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // SimpleStatement (i=0)
	
	
	fprintf(asmCode, "    While%d:\n", tempNumWhiles);
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Expression
	lhs = pop_vs();
	

	switch (lhs->type){
		case INT:
			switch (lhs->sclass){	
				case MEMORY:	

					whileSym = new_symbol("");
					whileSym->value = tempNumWhiles;
					push_while(whileSym);	
					
					fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   EndWhile%d\n", tempNumWhiles);
					
					CodeGeneration(p->pAstNode[3],lev+1,0,0); // Loop body
					CodeGeneration(p->pAstNode[2],lev+1,0,0); // SimpleStatement (i++)
					
					fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
					fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
					
					pop_while();
					
				break;
				case CONSTANT:
					if (lhs->value != 0){
						
						whileSym = new_symbol("");
						whileSym->value = tempNumWhiles;
						push_while(whileSym);	
					
						CodeGeneration(p->pAstNode[3],lev+1,0,0); // Loop body
						CodeGeneration(p->pAstNode[2],lev+1,0,0); // SimpleStatement (i++)			
						
						fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
						fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
						
						pop_while();
					}		
				break;
				case REGISTER:	
				
					whileSym = new_symbol("");
					whileSym->value = tempNumWhiles;
					push_while(whileSym);	
				
					fprintf(asmCode, "    mov  ecx, [REG_INT]\n");
					fprintf(asmCode, "    cmp  ecx, 0\n");
					fprintf(asmCode, "    je   EndWhile%d\n", tempNumWhiles);
					
					CodeGeneration(p->pAstNode[3],lev+1,0,0); // Loop body
					CodeGeneration(p->pAstNode[2],lev+1,0,0); // SimpleStatement (i++)				
					
					fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
					fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
					
					pop_while();
					
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in while)\n");
				break;
			}
		break;
		
		case REAL:
			switch (lhs->sclass){	
				case MEMORY:	

					whileSym = new_symbol("");
					whileSym->value = tempNumWhiles;
					push_while(whileSym);	
					
					fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   EndWhile%d\n", tempNumWhiles);					
					
					CodeGeneration(p->pAstNode[3],lev+1,0,0); // Loop body
					CodeGeneration(p->pAstNode[2],lev+1,0,0); // SimpleStatement (i++)		
					
					fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
					fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
					
					pop_while();
					
				break;
				case CONSTANT:
					if (lhs->value != 0){
						
						whileSym = new_symbol("");
						whileSym->value = tempNumWhiles;
						push_while(whileSym);						
						
						CodeGeneration(p->pAstNode[3],lev+1,0,0); // Loop body
						CodeGeneration(p->pAstNode[2],lev+1,0,0); // SimpleStatement (i++)					
						
						fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
						fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
						
						pop_while();
					}		
				break;
				case REGISTER:	
				
					whileSym = new_symbol("");
					whileSym->value = tempNumWhiles;
					push_while(whileSym);	
					
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   EndWhile%d\n", tempNumWhiles);					
					
					CodeGeneration(p->pAstNode[3],lev+1,0,0); // Loop body
					CodeGeneration(p->pAstNode[2],lev+1,0,0); // SimpleStatement (i++)				
					
					fprintf(asmCode, "    jmp  While%d\n", tempNumWhiles);
					fprintf(asmCode, "    EndWhile%d:\n", tempNumWhiles);
					
					pop_while();
					
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in while)\n");
				break;
			}
		break;
	}
	
	
}


void ProcessBreakStatement(){
	
	fprintf(asmCode, "    jmp  EndWhile%d\n", peek_while()->value);
}



void ProcessDeclarations(AstNode* p, int lev){
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0);
	CodeGeneration(p->pAstNode[1],lev+1,0,0);
	
}

void ProcessMoreDeclarations(AstNode* p, int lev){
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0);
	CodeGeneration(p->pAstNode[1],lev+1,0,0);
	
}



void ProcessArrayDeclaration(AstNode* p, int lev, int lvalue, int leftChild){

	switch (p->SymbolNode->type){
		case INT:
			fprintf(asmData, "%s TIMES %d dd 0\n", p->SymbolNode->ArrayName, p->SymbolNode->numOfElements);
		break;
		case REAL:
			fprintf(asmData, "%s TIMES %d dq 0.0\n", p->SymbolNode->ArrayName, p->SymbolNode->numOfElements);
		break;
	}
	
	fprintf(asmCode, "    push %s\n", p->SymbolNode->ArrayName);
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Variables	
	
}

void ProcessArrayVariable(AstNode* p, int lev, int lvalue, int leftChild){
	
	switch (p->SymbolNode->type){
		case INT:
			fprintf(asmData, "%s TIMES %d dd 0\n", p->SymbolNode->ArrayName, p->SymbolNode->numOfElements);
		break;
		case REAL:
			fprintf(asmData, "%s TIMES %d dq 0.0\n", p->SymbolNode->ArrayName, p->SymbolNode->numOfElements);
		break;
	}
	
	fprintf(asmCode, "    push %s\n", p->SymbolNode->ArrayName);
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Variables	
	
}



void ProcessDeclaration(AstNode* p, int lev, int lvalue, int leftChild){
	
	switch (p->SymbolNode->type){
		case INT:
			fprintf(asmCode, "    push 0\n");
		break;
		case REAL:
			fprintf(asmCode, "    sub  esp, 8\n");
			fprintf(asmCode, "    fldz\n");	
			fprintf(asmCode, "    fstp qword [esp]\n");	
		break;
	}
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Variables	
	
}



void ProcessDeclarationExtended(AstNode* p, int lev, int lvalue, int leftChild){
	
	Symbol *rhs;
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Expression
	rhs = pop_vs();
	
	switch (p->SymbolNode->type){
		case INT:		
			switch (rhs->type){
				case INT:			// ---- int INT = INT ---- //
					switch (rhs->sclass){
						case MEMORY:
							fprintf(asmCode, "    push dword [%s]\n", rhs->MIXname);
						break;		
						case CONSTANT:
							fprintf(asmCode, "    push %d\n", rhs->value);		
						break;		
						case REGISTER:
							fprintf(asmCode, "    push dword [REG_INT]\n"); 
						break;	
						case STACK:
							printf("IMPOSSIBLE (STACK in Declaration)\n");
						break;	
					}
				break;				
				case REAL:			// ---- int INT = REAL ---- //
				
					switch (rhs->sclass){
						case MEMORY:
							fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
						break;		
						case CONSTANT:
							fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
							fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
						break;		
						case REGISTER:
							fprintf(asmCode, "    fld  qword [REG_REAL]\n");
						break;	
						case STACK:
							printf("IMPOSSIBLE (STACK in Declaration)\n");
						break;
						
					}
					
					fprintf(asmCode, "    sub  esp, 4\n");
					fprintf(asmCode, "    fistp dword [esp]\n");
					
				break;
			}
		break;
		case REAL:			// ---- int REAL = INT ---- //
			switch (rhs->type){
				case INT:
					switch (rhs->sclass){
						case MEMORY:
							fprintf(asmCode, "    fild dword [%s]\n", rhs->MIXname);			
						break;
						case CONSTANT:	
							fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
							fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);			
						break;
						case REGISTER:
							fprintf(asmCode, "    fild dword [REG_REAL]\n");			
						break;	
						case STACK:
							printf("IMPOSSIBLE (STACK in Declaration)\n");
						break;	
					}					
					
					fprintf(asmCode, "    sub  esp, 8\n");	
					fprintf(asmCode, "    fstp qword [esp]\n");
					
				break;
				case REAL:			// ---- int REAL = REAL ---- //
					switch (rhs->sclass){
						case MEMORY:		
							fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
						break;
						case CONSTANT:								
							fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
							fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
						break;
						case REGISTER:	
							fprintf(asmCode, "    fld  qword [REG_REAL]\n");
						break;	
						case STACK:
							printf("IMPOSSIBLE (STACK in Declaration)\n");
						break;	
					}					
					
					fprintf(asmCode, "    sub  esp, 8\n");	
					fprintf(asmCode, "    fstp qword [esp]\n");
					
				break;				
			}
		break;
		
	}
	
	
	CodeGeneration(p->pAstNode[2],lev+1,0,0); // Variables	
	
}

void ProcessVariable(AstNode* p, int lev, int lvalue, int leftChild){
	
	switch (p->SymbolNode->type){
		case INT:
			fprintf(asmCode, "    push 0\n");
		break;
		case REAL:
			fprintf(asmCode, "    sub  esp, 8\n");
			fprintf(asmCode, "    fldz\n");	
			fprintf(asmCode, "    fstp qword [esp]\n");	
		break;
	}
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Variables
	
}

void ProcessVariableExtended(AstNode* p, int lev, int lvalue, int leftChild){
	
	Symbol *rhs, *curSymbol;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Expression
	rhs = pop_vs();
	
	switch (p->SymbolNode->type){
		case INT:		
			switch (rhs->type){
				case INT:			// ---- int INT = INT ---- //
					switch (rhs->sclass){
						case MEMORY:
							fprintf(asmCode, "    push dword [%s]\n", rhs->MIXname);
						break;		
						case CONSTANT:
							fprintf(asmCode, "    push %d\n", rhs->value);		
						break;		
						case REGISTER:
							fprintf(asmCode, "    push dword [REG_INT]\n"); 
						break;	
						case STACK:
							printf("IMPOSSIBLE (STACK in Declaration)\n");
						break;	
					}
				break;				
				case REAL:			// ---- int INT = REAL ---- //
				
					switch (rhs->sclass){
						case MEMORY:
							fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
						break;		
						case CONSTANT:
							fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
							fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
						break;		
						case REGISTER:
							fprintf(asmCode, "    fld  qword [REG_REAL]\n");
						break;	
						case STACK:
							printf("IMPOSSIBLE (STACK in Declaration)\n");
						break;
						
					}
					
					fprintf(asmCode, "    sub  esp, 4\n");
					fprintf(asmCode, "    fistp dword [esp]\n");
					
				break;
			}
		break;
		case REAL:			// ---- int REAL = INT ---- //
			switch (rhs->type){
				case INT:
					switch (rhs->sclass){
						case MEMORY:
							fprintf(asmCode, "    fild dword [%s]\n", rhs->MIXname);			
						break;
						case CONSTANT:	
							fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
							fprintf(asmCode, "    fild dword [int_for_conversion_%d]\n", countIntForConversions);			
						break;
						case REGISTER:
							fprintf(asmCode, "    fild dword [REG_REAL]\n");			
						break;	
						case STACK:
							printf("IMPOSSIBLE (STACK in Declaration)\n");
						break;	
					}					
					
					fprintf(asmCode, "    sub  esp, 8\n");	
					fprintf(asmCode, "    fstp qword [esp]\n");
					
				break;
				case REAL:			// ---- int REAL = REAL ---- //
					switch (rhs->sclass){
						case MEMORY:		
							fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
						break;
						case CONSTANT:								
							fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
							fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
						break;
						case REGISTER:	
							fprintf(asmCode, "    fld  qword [REG_REAL]\n");
						break;	
						case STACK:
							printf("IMPOSSIBLE (STACK in Declaration)\n");
						break;	
					}					
					
					fprintf(asmCode, "    sub  esp, 8\n");	
					fprintf(asmCode, "    fstp qword [esp]\n");
					
				break;				
			}
		break;
		
	}
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0);
	
}

void ProcessFormalParameters(AstNode* p, int lev, int lvalue, int leftChild){
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Other Formals
	switch (p->SymbolNode->type){
		case INT:
			bytesForParams+=4;
		break;
		case REAL:
			bytesForParams+=8;
		break;		
	}
	//push_vs(p->SymbolNode);
	
	
}

void ProcessFormalArrayParameters(AstNode* p, int lev, int lvalue, int leftChild){
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Other Formals
	bytesForParams+=4;
	//push_vs(p->SymbolNode);
	
	
}

void ProcessMoreFormalParameters(AstNode* p, int lev, int lvalue, int leftChild){
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Other Formals
	switch (p->SymbolNode->type){
		case INT:
			bytesForParams+=4;
		break;
		case REAL:
			bytesForParams+=8;
		break;		
	}	
	//push_vs(p->SymbolNode);
	
	
}

void ProcessMethodCall(AstNode* p, int lev, int lvalue, int leftChild){
	
	Symbol *new, *method;
	
	method = p->SymbolNode;
	
	new = new_symbol("");
	new->sclass= REGISTER;
	new->type = method->type;	
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Actuals

	fprintf(asmCode, "    call %s\n", p->SymbolNode->MIXname);
	
	switch (new->type){
		case INT:
			if(leftChild == 1) {		
				new->sclass=STACK;	
				fprintf(asmCode, "    push eax\n");
			} else {
				fprintf(asmCode, "    mov  dword [REG_INT], eax\n");		
			}
		break;
		
		case REAL:
			if(leftChild == 1) {
				new->sclass=STACK;	
				fprintf(asmCode, "    sub  esp, 8\n");		
				fprintf(asmCode, "    fstp qword [esp]\n");
			} else {
				fprintf(asmCode, "    fstp qword [REG_REAL]\n");		
			}
		break;
	}

	
	push_vs(new);
	
}	



void ProcessActualParameters(AstNode* p, int lev, int lvalue, int leftChild){
	
	Symbol *lhs;
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Expression	
	lhs = pop_vs();

	switch (lhs->type){
		case INT:
			switch(lhs->sclass){
				case MEMORY:					
					fprintf(asmCode, "    push dword [%s]\n", lhs->MIXname);
				break;
				case CONSTANT:					
					fprintf(asmCode, "    push %d\n", lhs->value);
				break;
				case REGISTER:					
					fprintf(asmCode, "    push dword [REG_INT]\n");
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in Actual)\n");
				break;
				
			}
		break;
		
		case REAL:
			switch(lhs->sclass){
				case MEMORY:					
					fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    sub  esp, 8\n");
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case CONSTANT:	
					fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
					fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
					fprintf(asmCode, "    sub  esp, 8\n");
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case REGISTER:
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    sub  esp, 8\n");		
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in Actual)\n");
				break;
				
			}
		break;
	}
	
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Other Arguments
	
}

void ProcessMoreActualParameters(AstNode* p, int lev, int lvalue, int leftChild){
	
	Symbol *lhs;
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // Expression
	
	lhs = pop_vs();
		
	
		switch (lhs->type){
		case INT:
			switch(lhs->sclass){
				case MEMORY:					
					fprintf(asmCode, "    push dword [%s]\n", lhs->MIXname);
				break;
				case CONSTANT:					
					fprintf(asmCode, "    push %d\n", lhs->value);
				break;
				case REGISTER:					
					fprintf(asmCode, "    push dword [REG_INT]\n");
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in Actual)\n");
				break;
				
			}
		break;
		
		case REAL:
			switch(lhs->sclass){
				case MEMORY:					
					fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    sub  esp, 8\n");
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case CONSTANT:	
					fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, lhs->dvalue);
					fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
					fprintf(asmCode, "    sub  esp, 8\n");
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case REGISTER:
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    sub  esp, 8\n");		
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in Actual)\n");
				break;
				
			}
		break;
	}
	
	
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Other Arguments
	
}



void ProcessLocation(AstNode*p){	

	
	Symbol *new;

	new = new_symbol(p->SymbolNode->name);
	strcpy(new->MIXname, p->SymbolNode->MIXname);
	new->lvalue = 0;	
	new->is_char = p->SymbolNode->is_char;	
	new->sclass = MEMORY;	
	new->genre = VARIABLE;
	if (p->SymbolNode->genre == ARRAY){
		new->type = INT; // the address of array
	} else {
		new->type = p->SymbolNode->type;
	}
	push_vs(new);
	
	

}

void ProcessArrayCall(AstNode*p, int lev, int lvalue, int leftChild){
	
	Symbol *new;
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // ArrayName
	new = pop_vs();
	new->sclass = REGISTER;
	
	// now eax has the address of the corresponding index of array
	
	fprintf(asmCode, "    mov  eax, [%s]\n", new->MIXname);
	
	switch (new->type){
		case INT:
			if(leftChild == 1) {
				new->sclass=STACK;
				fprintf(asmCode, "    push dword [eax]\n");		
			} else {
				fprintf(asmCode, "    mov  eax, [eax]\n");
				fprintf(asmCode, "    mov  dword [REG_INT], eax\n");		
			}
		break;
		
		case REAL:
			if(leftChild == 1) {
				fprintf(asmCode, "    sub  esp, 8\n");		
				fprintf(asmCode, "    fstp qword [eax]\n");
				new->sclass=STACK;	
			} else {		
				fprintf(asmCode, "    fld  qword [eax]\n");	
				fprintf(asmCode, "    fstp qword [REG_REAL]\n");		
			}
		break;
	}
	
	push_vs(new);

}

void ProcessArrayName(AstNode*p, int lev, int lvalue, int leftChild){	

	
	Symbol *new, *rhs;

	new = new_symbol(p->SymbolNode->name);
	strcpy(new->MIXname, p->SymbolNode->MIXname);
	strcpy(new->ArrayName, p->SymbolNode->ArrayName);
	new->lvalue = 0;
	new->sclass = MEMORY;
	new->genre = ARRAY;
	new->is_char = p->SymbolNode->is_char;
	new->type = p->SymbolNode->type;
	
	
	CodeGeneration(p->pAstNode[0],lev+1,0,1); // Expression
	rhs = pop_vs();
	
	switch (rhs->sclass){
		case MEMORY:
			fprintf(asmCode, "    mov  eax, [%s]\n", rhs->MIXname);
		break;
		case CONSTANT:
			fprintf(asmCode, "    mov  eax, %d\n", rhs->value);			
		break;
		case REGISTER:
			printf("IMPOSSIBLE (REGISTER in ArrayName)");
		break;
		case STACK:
			fprintf(asmCode, "    pop  eax\n");			
		break;
	}
	
	switch (new->type){
		case INT:
			fprintf(asmCode, "    imul eax, 4\n");	
		break;
		case REAL:
			fprintf(asmCode, "    imul eax, 8\n");
		break;
	}	
	
    fprintf(asmCode, "    add  eax, [%s]\n", new->MIXname);
	
    fprintf(asmData, "address_var_%d dd 0\n", ++countAddressVars);
    fprintf(asmCode, "    mov  dword [address_var_%d], eax\n", countAddressVars);
	
	char newName[30];
	sprintf(newName, "address_var_%d", countAddressVars);
	strcpy(new->MIXname, newName);
	
	
	/*
	if (leftChild == 1){
		new->sclass = STACK;
		fprintf(asmCode, "    push eax\n", new->MIXname);
	} else {
		fprintf(asmCode, "    mov  dword [REG_INT], eax\n", new->MIXname);		
	}
	*/
	
	
	push_vs(new);
	
	

}


void ProcessIntConstant(AstNode* p){   
    push_vs(p->SymbolNode);	
}

void ProcessRealConstant(AstNode* p){   
    push_vs(p->SymbolNode);	
}

void ProcessTrue(AstNode* p){   
    push_vs(p->SymbolNode);	
}

void ProcessFalse(AstNode* p){   
    push_vs(p->SymbolNode);	
}

int numMessages = 0;
int countBytesForPrintf = 0;

void ProcessPrintStatement(AstNode* p, int lev){
	
	Symbol *rhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Message
	rhs = pop_vs();
	
	//printf("%s", pop_vs()->name);
	
	numMessages++;
	
	fprintf(asmData, "msg_%d db \"%s\", 0\n", numMessages, rhs->name);
	
	fprintf(asmCode, "    push msg_%d\n", numMessages);
	fprintf(asmCode, "    call _printf\n");
	fprintf(asmCode, "    add  esp, %d\n", countBytesForPrintf + 4); // pop all parameters of printf
	countBytesForPrintf = 0;
	
}

void ProcessPrintlnStatement(AstNode* p, int lev){
	
	Symbol *rhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Message
	rhs = pop_vs();
	
	//printf("%s", pop_vs()->name);
	
	numMessages++;
	
	fprintf(asmData, "msg_%d db \"%s\", 10, 0\n", numMessages, rhs->name);
	
	fprintf(asmCode, "    push msg_%d\n", numMessages);
	fprintf(asmCode, "    call _printf\n");
	fprintf(asmCode, "    add  esp, %d\n", countBytesForPrintf + 4); // pop all parameters of printf
	countBytesForPrintf = 0;
	
}


void ProcessMessage(AstNode* p, int lev){
	
	Symbol *rhs, *lhs;
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // MoreMessage
	lhs = pop_vs();	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Printable	
	rhs = pop_vs();
	
	strcat(rhs->name, lhs->name);
	push_vs(rhs);
	
	
}

void ProcessMoreMessage(AstNode* p, int lev){
	
	Symbol *rhs, *lhs;
	
	CodeGeneration(p->pAstNode[1],lev+1,0,0); // MoreMessage
	lhs = pop_vs();
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Printable	
	rhs = pop_vs();

	strcat(rhs->name, lhs->name);
	push_vs(rhs);
	
}

void ProcessNoMoreMessage(AstNode* p, int lev){	
	push_vs(new_symbol(""));	
}


void ProcessTextToPrint(AstNode* p, int lev){	
	push_vs(p->SymbolNode);	
} 

void ProcessExpressionToPrint(AstNode* p, int lev){
	
	Symbol *rhs, *new;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Expression	
	rhs = pop_vs();
	
	char format[10];
	switch (rhs->type){
		case INT:
			if (rhs->is_char == 0){
				strcpy(format, "%d");
			} else {
				strcpy(format, "%c");				
			}
		break;
		case REAL:
			strcpy(format, "%lf");
		break;							
	}
	
	new = new_symbol(format);
	push_vs(new);
	
	switch (rhs->type){
		case INT:
			countBytesForPrintf += 4;
			switch(rhs->sclass){
				case MEMORY:
					fprintf(asmCode, "    push dword [%s]\n", rhs->MIXname);
				break;
				case CONSTANT:
					fprintf(asmCode, "    push %d\n", rhs->value);
				break;
				case REGISTER:
					fprintf(asmCode, "    push dword [REG_INT]\n");
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in Actual)\n");
				break;				
			}
		break;
		case REAL:			
			countBytesForPrintf += 8;
			switch(rhs->sclass){
				case MEMORY:	
					fprintf(asmCode, "    fld  qword [%s]\n", rhs->MIXname);
					fprintf(asmCode, "    sub  esp, 8\n");	
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case CONSTANT:						
					fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
					fprintf(asmCode, "    fld  qword [real_constant_%d]\n", countRealConsts);
					fprintf(asmCode, "    sub  esp, 8\n");
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case REGISTER:
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    sub  esp, 8\n");		
					fprintf(asmCode, "    fstp qword [esp]\n");
				break;
				case STACK:
					printf("IMPOSSIBLE (STACK in Actual)\n");
				break;				
			}
		break;
	}
	
}	


void ProcessReadStatement(AstNode* p, int lev){
	
	Symbol *rhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location
	
	rhs = pop_vs();
	
	switch (rhs->type){
		case INT:
			if (rhs->is_char == 0){
				fprintf(asmCode, "    lea  eax, [%s]\n", rhs->MIXname);
				fprintf(asmCode, "    push eax\n");
				fprintf(asmCode, "    push format_read_int\n");
				fprintf(asmCode, "    call _scanf\n");
				fprintf(asmCode, "    add  esp, 8\n");
			} else {
				fprintf(asmCode, "    lea  eax, [%s]\n", rhs->MIXname);
				fprintf(asmCode, "    push eax\n");
				fprintf(asmCode, "    push format_read_char\n");
				fprintf(asmCode, "    call _scanf\n");
				fprintf(asmCode, "    add  esp, 8\n");
				
			}
		break;
		case REAL:		
			fprintf(asmCode, "    lea  eax, [%s]\n", rhs->MIXname);
			fprintf(asmCode, "    push eax\n");
			fprintf(asmCode, "    push format_read_real\n");
			fprintf(asmCode, "    call _scanf\n");
			fprintf(asmCode, "    add  esp, 8\n");
		break;
	}
	
}

void ProcessReadWithPrintStatement(AstNode* p, int lev){
	
	Symbol *rhs;
	
	numMessages++;
	
	fprintf(asmData, "msg_%d db \"%s\", 0\n", numMessages, p->SymbolNode->name);
	
	fprintf(asmCode, "    push msg_%d\n", numMessages);
	fprintf(asmCode, "    call _printf\n");
	fprintf(asmCode, "    add  esp, 4\n");
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location	
	rhs = pop_vs();
	
	switch (rhs->type){
		case INT:
			if (rhs->is_char == 0){
				fprintf(asmCode, "    lea  eax, [%s]\n", rhs->MIXname);
				fprintf(asmCode, "    push eax\n");
				fprintf(asmCode, "    push format_read_int\n");
				fprintf(asmCode, "    call _scanf\n");
				fprintf(asmCode, "    add  esp, 8\n");
			} else {
				fprintf(asmCode, "    lea  eax, [%s]\n", rhs->MIXname);
				fprintf(asmCode, "    push eax\n");
				fprintf(asmCode, "    push format_read_char\n");
				fprintf(asmCode, "    call _scanf\n");
				fprintf(asmCode, "    add  esp, 8\n");
				
			}
		break;
		case REAL:		
			fprintf(asmCode, "    lea  eax, [%s]\n", rhs->MIXname);
			fprintf(asmCode, "    push eax\n");
			fprintf(asmCode, "    push format_read_real\n");
			fprintf(asmCode, "    call _scanf\n");
			fprintf(asmCode, "    add  esp, 8\n");
		break;
	}
	
}


void ProcessIncDecStatement(AstNode* p, int lev){	
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // IncDec
	pop_vs(); // Pops the Location
	
}


void ProcessIncreaseAfter(AstNode* p, int lev, int leftChild){
	
	Symbol *lhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location or ArrayName
	lhs = pop_vs();
	
	if (lhs->genre == ARRAY){		
		fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
		strcpy(lhs->MIXname, "ecx");
	}
	
	
	if (leftChild == 1){
		
		lhs->sclass = STACK;
		
		switch (lhs->type){
			case INT:
				fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    push eax\n");
				fprintf(asmCode, "    inc  eax\n");
				fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
			break;
			case REAL:
				fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    sub  esp, 8\n");
				fprintf(asmCode, "    fst  qword [esp]\n");
				fprintf(asmCode, "    fiadd dword [integer_1]\n");
				fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
			
			break;
		}
	} else {
	
		lhs->sclass = REGISTER;
		
	
		switch (lhs->type){
			case INT:
				fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    mov  dword [REG_INT], eax\n");
				fprintf(asmCode, "    inc  eax\n");
				fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
			break;
			case REAL:
				fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    fst  qword [REG_REAL]\n");
				fprintf(asmCode, "    fiadd dword [integer_1]\n");
				fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
			
			break;
		}
	}
	
	push_vs(lhs);
	
}


void ProcessIncreaseBefore(AstNode* p, int lev, int leftChild){	
	
	Symbol *lhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location or ArrayName
	lhs = pop_vs();
	
	if (lhs->genre == ARRAY){		
		fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
		strcpy(lhs->MIXname, "ecx");
	}
	
	if (leftChild == 1){
		
		lhs->sclass = STACK;
		
		switch (lhs->type){
			case INT:
				fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    inc  eax\n");
				fprintf(asmCode, "    push eax\n");
				fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
			break;
			case REAL:	
				fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    fiadd dword [integer_1]\n");
				fprintf(asmCode, "    sub  esp, 8\n");
				fprintf(asmCode, "    fst  qword [esp]\n");
				fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
			break;
		}
		
	} else {
	
		lhs->sclass = REGISTER;
		
		switch (lhs->type){
			case INT:
				fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    inc  eax\n");
				fprintf(asmCode, "    mov  dword [REG_INT], eax\n");
				fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
			break;
			case REAL:	
				fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    fiadd dword [integer_1]\n");
				fprintf(asmCode, "    fst  qword [REG_REAL]\n");
				fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
			break;
		}
	}
	
	push_vs(lhs);
	
}


void ProcessDecreaseAfter(AstNode* p, int lev, int leftChild){	
	
	Symbol *lhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location or ArrayName
	lhs = pop_vs();
	
	if (lhs->genre == ARRAY){		
		fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
		strcpy(lhs->MIXname, "ecx");
	}
	
	if (leftChild == 1){
		
		lhs->sclass = STACK;
		
		switch (lhs->type){
			case INT:
				fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    push eax\n");
				fprintf(asmCode, "    dec  eax\n");
				fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
			break;
			case REAL:	
				fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    sub  esp, 8\n");
				fprintf(asmCode, "    fst  qword [esp]\n");
				fprintf(asmCode, "    fisub dword [integer_1]\n");
				fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
			break;
		}
		
	} else {
	
		lhs->sclass = REGISTER;
		
		switch (lhs->type){
			case INT:
				fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    mov  dword [REG_INT], eax\n");
				fprintf(asmCode, "    dec  eax\n");
				fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
			break;
			case REAL:	
				fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    fst  qword [REG_REAL]\n");
				fprintf(asmCode, "    fisub dword [integer_1]\n");
				fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
			break;
		}
	
	}
	
	push_vs(lhs);
	
}


void ProcessDecreaseBefore(AstNode* p, int lev, int leftChild){	

	Symbol *lhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location or ArrayName
	lhs = pop_vs();
	
	if (lhs->genre == ARRAY){		
		fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
		strcpy(lhs->MIXname, "ecx");
	}
	
	if (leftChild == 1){
		
		lhs->sclass = STACK;
		
		switch (lhs->type){
			case INT:
				fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    dec  eax\n");
				fprintf(asmCode, "    push eax\n");
				fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
			break;
			case REAL:	
				fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    fisub dword [integer_1]\n");
				fprintf(asmCode, "    sub  esp, 8\n");
				fprintf(asmCode, "    fst  qword [esp]\n");
				fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
			break;
		}
		
	} else {
	
		lhs->sclass = REGISTER;
		
		switch (lhs->type){
			case INT:
				fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    dec  eax\n");
				fprintf(asmCode, "    mov  dword [REG_INT], eax\n");
				fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);	
			break;
			case REAL:	
				fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
				fprintf(asmCode, "    fisub dword [integer_1]\n");
				fprintf(asmCode, "    fst  qword [REG_REAL]\n");
				fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
			break;
		}
	}
	
	push_vs(lhs);
	
}


void ProcessChangeAssignStatement(AstNode* p, int lev){
	
	Symbol *lhs, *rhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,0); // Location or ArrayName
	lhs = pop_vs();
	CodeGeneration(p->pAstNode[2],lev+1,0,0); // Expression
	rhs = pop_vs();
	
	if (lhs->genre == ARRAY){		
		fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
		strcpy(lhs->MIXname, "ecx");
	}	
	
	switch (p->pAstNode[1]->NodeType){
		case astPlusEquals:

			switch (lhs->type){
				case INT:
					switch (rhs->type){
						case INT:		// ---- INT += INT ---- //
						
							fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
						
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    add  eax, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    add  eax, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    add  eax, [REG_INT]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
								
							}
							
							fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
						
						break;
						
						case REAL:		// ---- INT += REAL ---- //
						
							fprintf(asmCode, "    fild dword [%s]\n", lhs->MIXname);
						
							switch (rhs->sclass){								
								case MEMORY:
									fprintf(asmCode, "    fadd qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fadd  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fadd  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}							
							
							fprintf(asmCode, "    fistp dword [%s]\n", lhs->MIXname);
							
						break;
					}
				break;
				
				case REAL:
					switch (rhs->type){
						case INT:		// ---- REAL += INT ---- //
						
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
						
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fiadd dword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
									fprintf(asmCode, "    fiadd dword [int_for_conversion_%d]\n", countIntForConversions);
								break;
								case REGISTER:
									fprintf(asmCode, "    fiadd dword [REG_INT]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
							
						break;
						case REAL:		// ---- REAL += REAL ---- //
							
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fadd qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fadd  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fadd  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
							
						break;	
					}			
				break;
				
			}			
			
		break;
		
		case astMinusEquals:
		
			switch (lhs->type){
				case INT:
					switch (rhs->type){
						case INT:		// ---- INT -= INT ---- //
						
							fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
						
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    sub  eax, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    sub  eax, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    sub  eax, [REG_INT]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
								
							}
							
							fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
							
						break;
						
						case REAL:		// ---- INT -= REAL ---- //
						
							fprintf(asmCode, "    fild dword [%s]\n", lhs->MIXname);
						
							switch (rhs->sclass){								
								case MEMORY:
									fprintf(asmCode, "    fsub qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fsub  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fsub  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fistp dword [%s]\n", lhs->MIXname);
							
						break;
					}
				break;
				
				case REAL:
					switch (rhs->type){
						case INT:		// ---- REAL -= INT ---- //
						
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
						
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fisub dword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
									fprintf(asmCode, "    fisub dword [int_for_conversion_%d]\n", countIntForConversions);
								break;
								case REGISTER:
									fprintf(asmCode, "    fisub dword [REG_INT]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
							
						break;
						case REAL:		// ---- REAL -= REAL ---- //
							
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fsub qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fsub  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fsub  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
							
						break;	
					}			
				break;
				
			}		
			
		break;
		
		case astTimesEquals:
		
			switch (lhs->type){
				case INT:
					switch (rhs->type){
						case INT:		// ---- INT *= INT ---- //
						
							fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
								
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    imul eax, [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmCode, "    imul eax, %d\n", rhs->value);
								break;
								case REGISTER:
									fprintf(asmCode, "    imul eax, [REG_INT]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}							
							
							fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
							
						break;
						
						case REAL:		// ---- INT *= REAL ---- //
						
							fprintf(asmCode, "    fild dword [%s]\n", lhs->MIXname);
							
							switch (rhs->sclass){								
								case MEMORY:
									fprintf(asmCode, "    fmul qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fmul  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fmul  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fistp dword [%s]\n", lhs->MIXname);
							
						break;
					}
				break;
				
				case REAL:
					switch (rhs->type){
						case INT:		// ---- REAL *= INT ---- //
						
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fimul dword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "int_for_conversion_%d dd %d\n", ++countIntForConversions, rhs->value);
									fprintf(asmCode, "    fimul dword [int_for_conversion_%d]\n", countIntForConversions);
								break;
								case REGISTER:
									fprintf(asmCode, "    fimul dword [REG_INT]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
							
						break;
						case REAL:		// ---- REAL *= REAL ---- //
							
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
								
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fmul qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fmul  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fmul  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
							
						break;	
					}			
				break;
				
			}	
		
		break;
		
		case astDivideEquals:
		
			switch (lhs->type){
				case INT:
					switch (rhs->type){
						case INT:		// ---- INT /= INT ---- //
						
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
									fprintf(asmCode, "    cdq\n");
									fprintf(asmCode, "    mov  ebx, [%s]\n", rhs->MIXname);
									fprintf(asmCode, "    idiv ebx\n");
								break;
								case CONSTANT:
									fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
									fprintf(asmCode, "    cdq\n");
									fprintf(asmCode, "    mov  ebx, %d\n", rhs->value);
									fprintf(asmCode, "    idiv ebx\n");
								break;
								case REGISTER:				
									fprintf(asmCode, "    mov  eax, [%s]\n", lhs->MIXname);
									fprintf(asmCode, "    cdq\n");
									fprintf(asmCode, "    mov  ebx, [REG_INT]\n");
									fprintf(asmCode, "    idiv ebx\n");	
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}							
							
							fprintf(asmCode, "    mov  dword [%s], eax\n", lhs->MIXname);
							
						break;
						
						case REAL:		// ---- INT /= REAL ---- //
						
							fprintf(asmCode, "    fild dword [%s]\n", lhs->MIXname);
							
							switch (rhs->sclass){								
								case MEMORY:
									fprintf(asmCode, "    fdiv qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fdiv  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fdiv  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fistp dword [%s]\n", lhs->MIXname);
						
						break;
					}
				break;
				
				case REAL:
					switch (rhs->type){
						case INT:		// ---- REAL /= INT ---- //
						
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
							
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fidiv dword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "int_for_conversion_%d dd %dd\n", ++countIntForConversions, rhs->value);
									fprintf(asmCode, "    fidiv dword [int_for_conversion_%d]\n", countIntForConversions);
								break;
								case REGISTER:
									fprintf(asmCode, "    fidiv dword [REG_INT]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}	
							
							fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);
							
						break;
						case REAL:		// ---- REAL /= REAL ---- //
							
							fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
								
							switch (rhs->sclass){
								case MEMORY:
									fprintf(asmCode, "    fdiv qword [%s]\n", rhs->MIXname);
								break;
								case CONSTANT:
									fprintf(asmData, "real_constant_%d dq %lf\n", ++countRealConsts, rhs->dvalue);
									fprintf(asmCode, "    fdiv  qword [real_constant_%d]\n", countRealConsts);
								break;
								case REGISTER:
									fprintf(asmCode, "    fdiv  qword [REG_REAL]\n");
								break;
								case STACK:
									printf("IMPOSSIBLE (MEMORY-STACK)\n");
								break;
							}
							
							fprintf(asmCode, "    fstp qword [%s]\n", lhs->MIXname);	
							
						break;	
					}			
				break;
				
			}	
		
		break;
	}
	
	
}


void ProcessNotOperator(AstNode* p, int lev, int leftChild){
	
	Symbol *lhs;
	
	CodeGeneration(p->pAstNode[0],lev+1,0,leftChild); // Factor
	lhs = pop_vs();
	
	switch (lhs->type){
		case INT:
			switch (lhs->sclass){
				case MEMORY:
					fprintf(asmCode, "    mov  eax, 1\n");
					fprintf(asmCode, "    mov  ecx, [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    jcxz $ + 8\n"); // jump 2 statements later (3+5=8)
					fprintf(asmCode, "    mov  eax, 0\n");
					if (leftChild == 1){
						fprintf(asmCode, "    push eax\n");
						lhs->sclass = STACK;				
					} else {
						fprintf(asmCode, "    mov  dword [REG_INT], eax\n");
						lhs->sclass = REGISTER;
					}
				break;
				case CONSTANT:
					lhs->value = !lhs->value;
				break;
				case REGISTER:
					fprintf(asmCode, "    mov  eax, 1\n");
					fprintf(asmCode, "    mov  ecx, [REG_INT]\n");
					fprintf(asmCode, "    jcxz $ + 8\n"); // jump 2 statements later (3+5=8)
					fprintf(asmCode, "    mov  eax, 0\n");
					fprintf(asmCode, "    mov  dword [REG_INT], eax\n");	
				break;
				case STACK:
					fprintf(asmCode, "    mov  eax, 1\n");
					fprintf(asmCode, "    pop  ecx\n");
					fprintf(asmCode, "    jcxz $ + 8\n"); // jump 2 statements later (3+5=8)
					fprintf(asmCode, "    mov  eax, 0\n");
					fprintf(asmCode, "    push eax\n");	
				break;
				
			}
		break;
		
		case REAL:
			switch (lhs->sclass){
				case MEMORY:
					fprintf(asmCode, "    mov  eax, 1\n");
					fprintf(asmCode, "    fld  qword [%s]\n", lhs->MIXname);
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz $ + 7\n"); // jump 2 statements later (2+5=7)
					fprintf(asmCode, "    mov  eax, 0\n");
					if (leftChild == 1){
						fprintf(asmCode, "    push eax\n");
						lhs->sclass = STACK;				
					} else {
						fprintf(asmCode, "    mov  dword [REG_INT], eax\n");
						lhs->sclass = REGISTER;
					}
				break;
				case CONSTANT:
					lhs->value = !lhs->dvalue;
				break;
				case REGISTER:
					fprintf(asmCode, "    mov  eax, 1\n");
					fprintf(asmCode, "    fld  qword [REG_REAL]\n");
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   $ + 7\n"); // jump 2 statements later (2+5=7)
					fprintf(asmCode, "    mov  eax, 0\n");
					fprintf(asmCode, "    mov  dword [REG_INT], eax\n");	
				break;
				case STACK:
					fprintf(asmCode, "    mov  eax, 1\n");
					fprintf(asmCode, "    fld  qword [esp]\n");
					fprintf(asmCode, "    add  esp, 8\n");
					fprintf(asmCode, "    fldz\n");
					fprintf(asmCode, "    fcomip\n");
					fprintf(asmCode, "    ffreep\n");
					fprintf(asmCode, "    jz   $ + 7\n"); // jump 2 statements later (2+5=7)
					fprintf(asmCode, "    mov  eax, 0\n");
					fprintf(asmCode, "    push eax\n");	
				break;
				
			}
			lhs->type = INT;
		break;
		
	}
	
	push_vs(lhs);
	
	
}


void CodeGeneration(AstNode *p, int lev, int lvalue, int leftChild)
{  

	//printf("%d\n", p->NodeType);

	switch (p->NodeType)
	{
		case astEmptyProgram:
			break;
        case astProgram: 
			ProcessProgram(p, lev);
			break;
        case astMethods: 
            ProcessMethods(p, lev);
			break;
        case astMethod: 
            ProcessMethod(p, lev);
			break;
        case astFormalParameters: 
            ProcessFormalParameters(p, lev, lvalue, leftChild);
			break;
        case astFormalArrayParameters: 
            ProcessFormalArrayParameters(p, lev, lvalue, leftChild);
			break;
        case astNoFormalParameters: 
            //ProcessNoFormalParameters();
			break;
        case astMoreFormalParameters: 
            ProcessMoreFormalParameters(p, lev, lvalue, leftChild);
			break;
        case astNoMoreFormalParameters: 
			//ProcessNoMoreFormalParameters();
			break;
        case astTypeInt: 
			//ProcessTypeInt();
			break; 
        case astTypeReal: 
			//ProcessTypeReal();
			break;   
        case astBody: 
			ProcessBody(p, lev);
			break;
        case astDeclarations: 
			ProcessDeclarations(p, lev);
			break;
        case astNoDeclarations: 
			//ProcessNoDeclarations();
			break;
        case astMoreDeclarations: 
			ProcessMoreDeclarations(p, lev);
			break;
        case astNoMoreDeclarations:
			//ProcessNoMoreDeclarations();
			break;
        case astDeclaration: 
			ProcessDeclaration(p, lev, lvalue, leftChild);
			break;
		case astArrayDeclaration: 
			ProcessArrayDeclaration(p, lev, lvalue, leftChild); 
			break;
		case astArrayVariable: 
			ProcessArrayVariable(p, lev, lvalue, leftChild); 
			break;
        case astDeclarationExtended: 
			ProcessDeclarationExtended(p, lev, lvalue, leftChild);
			break;
        case astVariable: 
			ProcessVariable(p, lev, lvalue, leftChild);
			break;
        case astVariableExtended: 
			ProcessVariableExtended(p, lev, lvalue, leftChild);
			break;
        case astNoVariable:
			//ProcessNoVariable();
			break;			
		case astIncreaseAfter: 
			ProcessIncreaseAfter(p, lev, leftChild); 
			break;
		case astIncreaseBefore: 
			ProcessIncreaseBefore(p, lev, leftChild);
			break;
		case astDecreaseAfter: 
			ProcessDecreaseAfter(p, lev, leftChild);
			break;
		case astDecreaseBefore: 
			ProcessDecreaseBefore(p, lev, leftChild); 
			break;
		case astPlusEquals: 
			//ProcessPlusEquals(); 
			break;
		case astMinusEquals: 
			//ProcessMinusEquals(); 
			break;
		case astTimesEquals: 
			//ProcessTimesEquals(); 
			break;
		case astDivideEquals: 
			//ProcessDivideEquals(); 
			break;
		case astChangeAssignStatement: 
			ProcessChangeAssignStatement(p, lev); 
			break;
        case astStatements: 
			ProcessStatements(p, lev);
			break;
        case astNoStatements: 
			//ProcessNoStatements();
			break;			
		case astIncDecStatement: 
			ProcessIncDecStatement(p, lev);
			break;
        case astReturn: 
			ProcessReturn(p, lev, lvalue, leftChild);
			break;
        case astUnlessStatement: 
			ProcessUnlessStatement(p, lev);
			break;
        case astIfStatement: 
			ProcessIfStatement(p, lev);
			break;
        case astIfElseStatement: 
			ProcessIfElseStatement(p, lev);
			break;
        case astWhileStatement:
			ProcessWhileStatement(p, lev);
			break;
        case astRepeatStatement:
			ProcessRepeatStatement(p, lev);
			break;
        case astForStatement:
			ProcessForStatement(p, lev);
			break;
        case astBreakStatement: 
			ProcessBreakStatement();
			break;
		case astPrintStatement: 
			ProcessPrintStatement(p, lev); 
			break;	
		case astPrintlnStatement: 
			ProcessPrintlnStatement(p, lev); 
			break;			
		case astMessage: 
			ProcessMessage(p, lev); 
			break;
		case astMoreMessage: 
			ProcessMoreMessage(p, lev); 
			break;
		case astNoMoreMessage: 
			ProcessNoMoreMessage(p, lev); 
			break;
		case astTextToPrint: 
			ProcessTextToPrint(p, lev); 
			break;
		case astExpressionToPrint: 
			ProcessExpressionToPrint(p, lev); 
			break;
		case astReadStatement: 
			ProcessReadStatement(p, lev); 
			break;
		case astReadWithPrintStatement: 
			ProcessReadWithPrintStatement(p, lev);
			break;
        case astEmptyStatement: 
			//ProcessEmptyStatement();
			break;
        case astStartAssignStatement: 
			ProcessStartAssignStatement(p, lev);
			break;
        case astAssignStatement: 
			ProcessAssignStatement(p, lev);
			break;
        case astMoreAssignStatement: 
			ProcessMoreAssignStatement(p, lev);
			break;
		case astAssignMultipleStatement: 
			ProcessAssignMultipleStatement(p, lev);
			break;
		case astNestedAssignStatement: 
			ProcessNestedAssignStatement(p, lev);
			break;
		case astLastNestedAssignStatement: 
			ProcessLastNestedAssignStatement(p, lev);
			break;
        case astLocation: 
			ProcessLocation(p);
			break;
        case astMethodName: 
			//ProcessMethodName();
			break;
		case astArrayName: 
			ProcessArrayName(p, lev, lvalue, leftChild); 
			break;
		case astArrayCall: 
			ProcessArrayCall(p, lev, lvalue, leftChild); 
			break;
		case astOrExpression: 
			ProcessOrExpression(p, lev, lvalue, leftChild); 
			break;
		case astAndExpression: 
			ProcessAndExpression(p, lev, lvalue, leftChild);
			break;
        case astRelationExpression: 
			ProcessRelationExpression(p, lev, lvalue, leftChild);
            break;
        case astLessOrEqualOperator: 
			//ProcessLessOrEqualOperator();
            break;
        case astLessOperator: 
			//ProcessLessOperator();
            break;
        case astGreaterOperator: 
			//ProcessGreaterOperator();
            break;
        case astGreaterOrEqualOperator: 
			//ProcessGreaterOrEqualOperator();
            break;
        case astEqualOperator: 
			//ProcessEqualOperator();
            break;
        case astNotEqualOperator: 
			//ProcessNotEqualOperator();
            break;
        case astAddExpression: 
			ProcessAddExpression(p, lev, lvalue, leftChild);
            break;
		case astAddOperator: 
			//ProcessAddOperator();
            break;
        case astSubtractOperator: 
			//ProcessSubtractOperator();
            break;
        case astTerm: 
			ProcessTerm(p, lev, lvalue, leftChild);
            break;
		case astNotOperator: 
			ProcessNotOperator(p, lev, leftChild);
			break;
        case astMultiplyOperator: 
			//ProcessMultiplyOperator();
            break;
        case astDivideOperator: 
			//ProcessDivideOperator();
            break;
		case astModuloOperator: 
			//ProcessModuloOperator(); 
			break;	
        case astIntConstant: 
			ProcessIntConstant(p);
            break;	
        case astRealConstant: 
			ProcessRealConstant(p);
            break;
        case astTrue: 
			ProcessTrue(p);
            break;
        case astFalse: 
			ProcessFalse(p);
            break;
        case astMethodCall: 
			ProcessMethodCall(p, lev, lvalue, leftChild);
            break;
        case astActualParameters: 
			ProcessActualParameters(p, lev, lvalue, leftChild);
            break;
        case astNoActualParameters: 
			//ProcessNoActualParameters();
            break;
        case astMoreActualParameters: 
			ProcessMoreActualParameters(p, lev, lvalue, leftChild);
            break;
        case astNoMoreActualParameters: 
			//ProcessNoMoreActualParameters();
            break;
        default: 
            printf("AGNOSTO=%d\n",p->NodeType);
		break;
	}
}

void GenerateInitCode(){
	
	
	
	fprintf(asmData, "section .data\n\n");
	fprintf(asmData, "cw dw 057fH\n");
	fprintf(asmData, "integer_1 dd 1\n");
	fprintf(asmData, "REG_INT  dd 0\n");
	fprintf(asmData, "REG_REAL dq 0.0\n");
	//fprintf(asmData, "format_print_int db \"%%d\", 10, 0\n");
	fprintf(asmData, "format_read_int db \"%%d\", 0\n");
	fprintf(asmData, "format_read_char db \"%%c\", 0\n");
	fprintf(asmData, "format_read_real db \"%%lf\", 0\n");
	
	fprintf(asmCode, "\nsection .text\n\n");
	fprintf(asmCode, "extern _printf\n");
	fprintf(asmCode, "extern _scanf\n");
	fprintf(asmCode, "global _main\n");
	fprintf(asmCode, "_main:\n");
	fprintf(asmCode, "    fldcw [cw]\n");
	fprintf(asmCode, "    call _source_main\n");
	fprintf(asmCode, "    ret\n");
	
	fprintf(asmCode, "\n; ----------------------- ;\n\n");
	
	//fprintf(asmCode, "set_true:\n");
	//fprintf(asmCode, "    mov  ecx, 1\n");
	//fprintf(asmCode, "    jmp  ebx\n");
	
	
}

void GenerateEmptyProgrammCode(){

	fprintf(asmCode, "\nsection .text\n");
	fprintf(asmCode, "global _main\n");
	fprintf(asmCode, "_main:\n");
	fprintf(asmCode, "    ret\n");
	
}

void main(void)
{  
	int lathos,i;
  
	lathos=yyparse();
	
	if(!lathos) 
	{
		
		Init_Hash_Table();
		Init_While_Stack();
		
		//printf("\n------------- Syntax Tree -------------\n\n");
		//traverse(TreeRoot,-3);		
		//printf("\n");

		asmData = fopen("C:\\cmpl\\AssemblyData.asm", "w+");
		asmCode = fopen("C:\\cmpl\\AssemblyCode.asm", "w+");
		if (TreeRoot->NodeType != astEmptyProgram){
			GenerateInitCode();
			CodeGeneration(TreeRoot,0,0,0);
		} else {
			GenerateEmptyProgrammCode();
		}
		fclose(asmData);  
		fclose(asmCode); 

	  
	}
}

