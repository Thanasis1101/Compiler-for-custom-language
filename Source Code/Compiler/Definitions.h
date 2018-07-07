#define SYM_TABLE_SIZE 41
#define NAME_MAX  300

#define astEmptyProgram	499
#define astProgram	500
#define astMethods	501
#define astMethod	502
#define astFormalParameters	503
#define astNoFormalParameters	504
#define astMoreFormalParameters	505
#define astNoMoreFormalParameters	506
#define astTypeInt	507
#define astBody	508
#define astDeclarations	509
#define astNoDeclarations	510
#define astMoreDeclarations	511
#define astNoMoreDeclarations	512
#define astDeclaration	513
#define astDeclarationExtended	514
#define astVariable	515
#define astVariableExtended	516
#define astNoVariable	517
#define astStatements	518
#define astNoStatements	519
#define astReturn	520
#define astIfStatement	521
#define astWhileStatement	522
#define astBreakStatement	523
#define astEmptyStatement	524
#define astAssignStatement	525
#define astLocation	526
#define astMethodName	527
#define astRelationExpression	528
#define astLessOrEqualOperator	529
#define astLessOperator	530
#define astGreaterOperator	531
#define astGreaterOrEqualOperator	532
#define astEqualOperator	533
#define astNotEqualOperator	534
#define astAddExpression	535
#define astAddOperator	536
#define astSubtractOperator	537
#define astTerm	538
#define astMultiplyOperator	539
#define astDivideOperator	540
#define astIntConstant	541
#define astTrue	542
#define astFalse	543
#define astMethodCall	544
#define astActualParameters	545
#define astNoActualParameters	546
#define astMoreActualParameters	547
#define astNoMoreActualParameters	548
#define astPrintStatement 549
#define astReadStatement 550
#define astMessage 551
#define astMoreMessage 552
#define astNoMoreMessage 553
#define astTextToPrint 554
#define astExpressionToPrint 555
#define astReadWithPrintStatement 556
#define astAssignMultipleStatement 557
#define astNestedAssignStatement 558
#define astLastNestedAssignStatement 559
#define astMoreAssignStatement 560
#define astRepeatStatement 561
#define astIfElseStatement 562
#define astUnlessStatement 563
#define astIncreaseAfter 564
#define astIncreaseBefore 565
#define astDecreaseAfter 566
#define astDecreaseBefore 567
#define astIncDecStatement 568
#define astOrExpression 569
#define astAndExpression 570
#define astNotOperator 571
#define astModuloOperator 572
#define astRealConstant 573
#define astTypeReal 574
#define astStartAssignStatement 575
#define astForStatement 576
#define astChangeAssignStatement 577
#define astPlusEquals 578
#define astMinusEquals 579
#define astTimesEquals 580
#define astDivideEquals 581
#define astArrayDeclaration 582
#define astArrayCall 583
#define astArrayName 584
#define astArrayVariable 585
#define astAssignArrayStatement 586
#define astMoreAssignArrayStatement 587
#define astAssignArrayMultipleStatement 588
#define astNestedAssignArrayStatement 589
#define astLastNestedAssignArrayStatement 590
#define astFormalArrayParameters 591
#define astPrintlnStatement 592


#define METHOD 			800
#define CONST_VAL       801
#define CONSTANT      	802
#define MEMORY          803
#define REGISTER        804
#define STACK           805
#define VARIABLE        806
#define ARRAY           807



// ---------------------------------- Structures ---------------------------------- //


// ---- Symbol  ---- //

typedef struct Symbol_tag {

   //unsigned char origName[NAME_MAX]; /* -- For methods -------- */
   unsigned char name[NAME_MAX];     /* -- Variable name ------ */
   unsigned char ArrayName[NAME_MAX];/* -- For arrays --------- */
   unsigned char MIXname[NAME_MAX];  /* -- Var name in MIX ---- */
   int sclass;                       /* -- MEMORY, CONSTANT, -- */
                                     /* -- REGISTER, STACK ---- */
   int genre;						 /* -- VARIABLE, METHOD, -- */
									 /* -- ARRAY -------------- */
   int type;                       	 /* -- INT, REAL ---------- */
   int value;                        /* -- Value for ints ----- */
   double dvalue;                    /* -- Value for reals ---- */
   int has_value;                    /* -- 0 OR CONST_VAL ----- */   
   int lvalue;						 /* -- 0 or 1 ------------- */ 
   int is_param;					 /* -- 0 or 1 ------------- */   
   int numOfParams;					 /* -- For methods -------- */
   int numOfElements;				 /* -- For arrays --------- */
   int is_char;						 /* -- For arrays --------- */
   
   struct HashTable_tag *symbols_table_of_method; // Pointer to the symbol table if it is a method
   
   struct Symbol_tag *NextSymbol;
   struct Symbol_tag *PrevSymbol;
   
   
   
} Symbol;

// ---- Symbol Table ---- //

typedef struct HashTable_tag {
   int numbSymbols;
   Symbol *table[SYM_TABLE_SIZE];
} HashTable;



// ---- Syntax Tree ---- //

typedef struct AstNode_tag {
    int NodeType;
    struct Symbol_tag *SymbolNode;
    struct AstNode_tag *pAstNode[4];
} AstNode;





// ---------------------------------- Prototypes ---------------------------------- //

void Show_VStack();
void push_vs(Symbol *p);
Symbol *pop_vs();
void Show_Ret_Stack();
void push_ret(Symbol *p);
Symbol *pop_ret();
int check_has_return();
Symbol* peek_while();
void push_while(Symbol* whileSym);
Symbol *pop_while();
void Init_While_Stack();
void Show_While_Stack();
AstNode *MkNode(int tipos,Symbol *sn,AstNode *z0,AstNode *z1,AstNode *z2,AstNode *z3);
void createMIXVariable(char* MIXname, int type);
void createMIXParameter(char* MIXname, int type);
void Init_Hash_Table();
void Show_Hash_Table();
void add_variable_to_table(Symbol *symbp);
void add_method_to_table(Symbol *symbp);
int mkkey(char *s);
void add_variable(Symbol *symbp);
Symbol *find_variable(char *onoma);
void add_method(Symbol *symbp);
Symbol *find_method(char *onoma);
Symbol *new_symbol(char *name);
void yyerror(char *s);

int yylex();
int yyparse();

void CodeGeneration(AstNode *p, int lev, int lvalue, int leftChild);

