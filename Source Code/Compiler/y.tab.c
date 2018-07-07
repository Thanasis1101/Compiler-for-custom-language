#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "SyntaxAnalysis.yacc"
 
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

#line 52 "SyntaxAnalysis.yacc"
typedef union
{
    int   					yint;
    char  					ystr[100];
    struct AstNode_tag   	*stNode;
} YYSTYPE;
#line 68 "y.tab.c"
#define IF 257
#define ELSE 258
#define WHILE 259
#define BREAK 260
#define RETURN 261
#define INT 262
#define REAL 263
#define CHAR 264
#define TRUE 265
#define FALSE 266
#define PRINT 267
#define PRINTLN 268
#define READ 269
#define REPEAT 270
#define TIMES 271
#define UNLESS 272
#define AND 273
#define OR 274
#define FOR 275
#define INT_CONST 276
#define REAL_CONST 277
#define TEXT 278
#define CHAR_CONST 279
#define INCREASE_SIGN 280
#define DECREASE_SIGN 281
#define NOT_SIGN 282
#define PLUS_EQUALS_SIGN 283
#define MINUS_EQUALS_SIGN 284
#define TIMES_EQUALS_SIGN 285
#define DIVIDE_EQUALS_SIGN 286
#define IS_EQUAL 287
#define IS_NOT_EQUAL 288
#define IS_LESS_OR_EQUAL 289
#define IS_GREATER_OR_EQUAL 290
#define ID 291
#define LOWER_THAN_ELSE 292
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    1,   38,    2,   39,    2,    3,    3,
    3,    4,    4,    4,    5,    5,    5,    6,    7,    7,
    8,    8,   40,    9,   41,    9,   42,    9,   43,   10,
   44,   10,   45,   10,   10,   11,   11,   33,   33,   33,
   33,   33,   33,   33,   33,   36,   36,   36,   36,   32,
   32,   32,   32,   32,   32,   32,   32,   32,   32,   12,
   12,   12,   46,   12,   47,   12,   48,   12,   49,   12,
   12,   12,   12,   26,   27,   27,   28,   28,   13,   14,
   14,   14,   14,   29,   29,   30,   30,   30,   30,   15,
   16,   37,   17,   17,   35,   35,   34,   34,   18,   18,
   18,   18,   18,   18,   19,   19,   20,   20,   21,   21,
   21,   22,   22,   22,   23,   23,   23,   23,   23,   23,
   23,   23,   23,   23,   23,   23,   50,   24,   24,   25,
   25,   31,
};
short yylen[] = {                                         2,
    1,    0,    2,    1,    0,    7,    0,    9,    3,    5,
    0,    4,    6,    0,    1,    1,    1,    4,    2,    0,
    2,    0,    0,    5,    0,    8,    0,    7,    0,    4,
    0,    7,    0,    6,    0,    2,    0,    2,    2,    2,
    2,    2,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    3,    3,    1,    2,    4,    2,    2,    2,
    3,    6,    0,    9,    0,    6,    0,    5,    0,   10,
    4,    1,    1,    2,    3,    0,    1,    1,    3,    3,
    3,    3,    3,    5,    5,    5,    5,    3,    3,    1,
    1,    4,    3,    1,    3,    1,    3,    1,    1,    1,
    1,    1,    1,    1,    3,    1,    1,    1,    3,    1,
    2,    1,    1,    1,    3,    1,    1,    1,    2,    1,
    2,    1,    1,    1,    4,    1,    0,    3,    0,    3,
    0,    0,
};
short yydefred[] = {                                      0,
   15,   16,   17,    0,    1,    0,    0,    3,    0,    0,
    0,    0,    0,    0,    0,    5,    0,    0,    0,    0,
    0,    0,    6,   12,    0,    7,   37,    0,    0,    0,
    0,    0,    0,   13,    8,  132,   65,   55,    0,    0,
    0,    0,   67,   69,    0,    0,   37,   18,   73,    0,
   36,   72,   50,    0,   51,    0,   52,    0,    0,    0,
    0,  122,  123,  118,  120,  124,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  110,  126,   96,    0,    0,
   77,    0,   58,    0,   59,    0,   91,   56,    0,    0,
   40,   41,   44,   45,    0,    0,   38,   42,   46,   47,
   48,   49,    0,    0,    0,    0,   60,   39,   43,    0,
    0,    0,    0,    0,    0,    0,    0,  119,  121,  111,
    0,    0,    0,   61,  107,  108,  103,  104,   99,  102,
  100,  101,    0,    0,  112,  113,  114,    0,    0,    0,
   74,    0,    0,    0,   79,    0,   81,    0,    0,    0,
    0,    0,    0,    0,    0,   83,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  115,    0,  131,    0,    0,
    0,  109,   95,    0,   57,    0,    0,   92,    0,    0,
    0,    0,    0,   71,    0,    0,   25,    0,   24,    0,
    0,  125,    0,   75,   68,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   66,    0,
    0,    0,    0,   28,    0,    0,    0,   30,   63,  130,
    0,    0,    0,   26,    0,   31,    0,    0,   34,    0,
   64,    0,   32,   70,
};
short yydgoto[] = {                                       4,
    5,    6,   13,   14,    7,   23,   27,   28,   33,  163,
   31,   51,   52,   53,   71,   72,   82,  133,   74,  134,
   75,  138,   76,  167,  193,   83,  141,   84,   55,  152,
   60,   56,   77,   78,   79,  105,   80,   19,   30,  115,
  204,  186,  207,  230,  225,  227,   61,   89,   90,  168,
};
short yysindex[] = {                                    -82,
    0,    0,    0,    0,    0,  -82,  -75,    0,    4,  -19,
    0, -212,   59,  -82,  108,    0, -130,    0,   40,   37,
  128,    0,    0,    0,   98,    0,    0,  -82,  148,   40,
  302,  -96,    0,    0,    0,    0,    0,    0,  113,   86,
   86, -237,    0,    0,  -94,  -94,    0,    0,    0,  110,
    0,    0,    0,  156,    0,  -41,    0,  164,  -26,  159,
  162,    0,    0,    0,    0,    0, -120,  120,  113,  110,
  163, -109,  -46,  125,    5,    0,    0,    0,  -67,  -97,
    0,  -65,    0,  167,    0,  168,    0,    0,  113,  173,
    0,    0,    0,    0,  344,  113,    0,    0,    0,    0,
    0,    0,  113,  -94,  113,  113,    0,    0,    0,  113,
  -94,  113,  113,  -62,  174,  113,  113,    0,    0,    0,
  -32,    0,  113,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  113,  113,    0,    0,    0,  120,  113,   86,
    0,  -72, -128,  231,    0,  -76,    0,  -58,  -65,    3,
   29,  176,   88,  -65,  -45,    0,  -65,  182,  -65,  -65,
  147,  -35,  198,  -29,  -20,    0,  226,    0,  -67,  102,
    5,    0,    0,  167,    0,  213,  212,    0,  113,  -94,
  113,  113,  -94,    0,  113,  174,    0,   75,    0,  213,
  213,    0,  113,    0,    0,  113,  -65,  230,  -65,  -65,
  236,  -65,  216,  174,  113,    6,  174,   23,    0,  -33,
  -44,  113,  113,    0,  227,  -65,  192,    0,    0,    0,
  231,  -65,  -65,    0,  174,    0,  213,  250,    0,  174,
    0,  213,    0,    0,
};
short yyrindex[] = {                                    292,
    0,    0,    0,    0,    0,  293,    0,    0,    0,    0,
    2,    0,    0,    0,    0,    0,    0,    2,    0,  253,
    0,  196,    0,    0,    0,    0,    0,    0,  254,    0,
    0,    0,  257,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -37,
    0,    0,    0,    0,    0,    0,    0,    0,   47,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -11,
    0,   16,    0,   36,  134,    0,    0,    0,   83,   25,
    0,   -4,    0,  -40,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  241,    0,    0,    0,    0,    0,
    0,   93,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   51,  -39,   60,
    0,    0,    0,  -14,    0,    0,  -13,    0,   30,   81,
    0,    0,    0,    0,    0,    0,    0,    0,  180,   71,
  145,    0,    0,  -40,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  241,    0,   91,    0,    0,
    0,    0,    0,    0,    0,    0,  267,    0,   45,  274,
    0,   58,    0,  241,    0,    0,  241,  361,    0,  260,
    0,    0,    0,    0,    0,   95,    0,    0,    0,    0,
    0,  276,  278,    0,  241,    0,    0,    0,    0,  241,
    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  320,    0,  309,    0,  123,  298,    0,    0,    0,  -63,
  282,  -17,    0,   11,    0,  505,  611,    0,  202,    0,
  197,    0,  -30,    0,    0,  296,  172,  220,    0,  -28,
    0, -105,  447,  214,  233,  313,  553,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 824
short yytable[] = {                                      91,
   76,   80,  103,   91,   91,   91,   91,   91,  166,   91,
  220,  190,  124,  184,  221,   10,  178,  107,   76,   80,
  191,   91,   91,   91,   91,   91,   53,   82,   90,   91,
   91,   91,   91,   91,  113,   91,   78,  120,  177,   78,
   86,  137,   11,   11,   53,   82,  135,   91,   91,   91,
   91,  136,  116,   87,   78,   91,  116,  116,  116,  116,
  116,  117,  116,  110,  114,  117,  117,  117,  117,  117,
   54,  117,  180,   12,  116,  116,   98,  116,   15,   98,
   24,   91,  158,  117,  117,   84,  117,  116,   54,  179,
   23,  116,  116,  116,   98,  116,  117,  116,   85,   16,
  117,  117,  117,   84,  117,   23,  117,  172,  116,  116,
  116,   97,  116,  147,   97,  228,   85,  117,  117,  117,
  156,  117,  203,   94,   27,   69,   94,   25,   98,   97,
   67,  183,  127,  129,   29,  205,   17,  127,   33,   27,
  215,   94,  176,  218,  125,  123,  126,   18,  182,   29,
   32,  198,   69,   33,  201,  118,  119,   67,  195,   69,
   20,  229,   22,   97,   67,  206,  233,  125,   26,  126,
   97,   98,  208,  209,  106,   94,  106,  106,  106,    1,
    2,    3,  108,  109,  131,  105,  132,  105,  105,  105,
   29,   34,  106,  106,   59,  106,   50,  123,  116,  104,
   96,  117,  122,  105,  105,  139,  105,  111,  123,  231,
  140,  142,  144,  161,  234,    9,  103,  162,   87,  181,
   93,   97,   98,   93,  110,  185,  106,  123,  123,  123,
  106,   76,   80,   91,   91,   91,   91,  105,   93,  187,
  123,  123,   91,   91,  123,   91,   91,   91,   91,   91,
   91,   91,   91,  123,   20,  188,  189,   53,   82,   91,
   91,   91,   91,   14,   14,   14,  192,   78,   91,   91,
  196,   49,   93,  212,  214,   91,   91,   91,   91,  213,
  219,  217,  108,  109,  226,  224,  116,  116,  116,  116,
  232,    2,    4,    9,   10,  117,  117,  117,  117,   35,
  128,   54,  116,  116,  116,  116,   98,   98,   98,   98,
   88,  117,  117,  117,  117,   19,   84,   89,   20,   86,
   20,   87,  116,  116,  116,    8,   21,   35,   95,   85,
  171,  117,  117,  117,  170,   47,   85,  116,  116,  116,
  116,   97,   97,   97,   97,  194,  117,  117,  117,  117,
   62,   63,  173,   94,   94,  169,   94,  127,  127,  174,
   49,   64,   65,   81,   66,   45,   46,   68,  127,  127,
  112,  127,  127,  127,  127,    0,   70,   62,   63,   19,
    0,   19,    0,  127,   62,   63,    0,    0,   64,   65,
    0,   66,   45,   46,   68,   64,   65,    0,   66,   45,
   46,    0,   49,   70,  106,  106,  106,  106,    0,    0,
   70,  127,  128,  129,  130,  105,  105,  105,  105,   62,
  106,  106,  106,  106,   47,    0,   48,    0,    0,    0,
    0,  105,  105,  105,  105,   97,   98,    0,   99,  100,
  101,  102,    0,  108,  109,    0,   99,  100,  101,  102,
   93,   93,   20,   93,   20,   20,   20,   22,   22,   22,
    0,    0,   20,   20,   20,   20,   47,    0,  145,   36,
   20,   37,   38,   39,    0,   20,   20,   57,    0,   40,
   41,   42,   43,   62,    0,   62,   20,   44,    0,    0,
   38,    0,   45,   46,    0,    0,    0,   40,   41,   42,
    0,    0,    0,   50,    0,    0,    0,    0,    0,    0,
   45,   46,    0,   19,    0,   19,   19,   19,   21,   21,
   21,   50,    0,   19,   19,   19,   19,    0,    0,    0,
    0,   19,    0,    0,    0,   54,   19,   19,    0,    0,
    0,   57,    0,    0,    0,    0,   88,   19,    0,   91,
   93,    0,    0,    0,    0,    0,    0,    0,   36,    0,
   37,   38,   39,    0,    0,    0,    0,    0,   40,   41,
   42,   43,    0,    0,    0,    0,   44,    0,    0,    0,
    0,   45,   46,   58,    0,    0,    0,    0,    0,    0,
   57,    0,   50,    0,    0,    0,    0,   92,   94,   54,
   36,    0,   37,   38,   39,    0,    0,  148,  151,    0,
   40,   41,   42,   43,  148,  151,    0,   62,   44,   62,
   62,   62,   57,   45,   46,    0,    0,   62,   62,   62,
   62,    0,    0,    0,   50,   62,   57,   57,    0,    0,
   62,   62,    0,    0,    0,    0,  175,   58,   54,   73,
    0,   62,    0,    0,    0,  150,  153,    0,    0,    0,
    0,    0,  150,  153,    0,    0,    0,   57,    0,    0,
    0,    0,    0,   57,    0,    0,    0,    0,   57,  121,
   54,    0,    0,    0,  151,    0,    0,  151,    0,    0,
    0,    0,    0,    0,   54,   54,   58,    0,    0,  143,
    0,    0,    0,    0,    0,    0,  146,    0,    0,    0,
    0,    0,    0,  149,    0,  154,  155,    0,    0,    0,
  157,    0,  159,  160,    0,   54,  164,  165,   58,    0,
    0,   54,  153,    0,    0,  153,   54,    0,    0,    0,
    0,    0,   58,   58,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   58,    0,    0,    0,    0,    0,   58,
    0,    0,    0,    0,   58,    0,    0,    0,    0,  197,
    0,  199,  200,    0,    0,  202,    0,    0,    0,    0,
    0,    0,    0,  210,    0,    0,  211,    0,    0,    0,
    0,    0,    0,    0,    0,  216,    0,    0,    0,    0,
    0,    0,  222,  223,
};
short yycheck[] = {                                      37,
   41,   41,   61,   41,   42,   43,   44,   45,   41,   47,
   44,   41,   59,   59,   59,   91,   93,   59,   59,   59,
   41,   59,   60,   61,   62,   37,   41,   41,   40,   41,
   42,   43,   44,   45,   61,   47,   41,   68,  144,   44,
  278,   37,   41,   40,   59,   59,   42,   59,   60,   61,
   62,   47,   37,  291,   59,   93,   41,   42,   43,   44,
   45,   37,   47,   61,   91,   41,   42,   43,   44,   45,
   41,   47,   44,   93,   59,   60,   41,   62,  291,   44,
   44,   93,  111,   59,   60,   41,   62,   37,   59,   61,
   44,   41,   42,   43,   59,   45,   37,   47,   41,   41,
   41,   42,   43,   59,   45,   59,   47,  138,   93,   59,
   60,   41,   62,  103,   44,  221,   59,   93,   59,   60,
  110,   62,  186,   41,   44,   40,   44,   91,   93,   59,
   45,   44,   40,   41,   44,   61,   14,   45,   44,   59,
  204,   59,  271,  207,   43,  274,   45,   40,   61,   59,
   28,  180,   40,   59,  183,  276,  277,   45,  176,   40,
  291,  225,  123,   93,   45,   91,  230,   43,   41,   45,
  280,  281,  190,  191,   41,   93,   43,   44,   45,  262,
  263,  264,  280,  281,   60,   41,   62,   43,   44,   45,
   93,   44,   59,   60,  291,   62,  291,  274,   40,   44,
   91,   40,   40,   59,   60,  273,   62,   44,  274,  227,
   44,   44,   40,  276,  232,  291,   61,   44,  291,   44,
   41,  280,  281,   44,   61,   44,   93,  274,  274,  274,
  272,  272,  272,  271,  272,  273,  274,   93,   59,   93,
  274,  274,  280,  281,  274,  283,  284,  285,  286,  287,
  288,  289,  290,  274,   59,  291,   59,  272,  272,  271,
  272,  273,  274,  262,  263,  264,   41,  272,  280,  281,
   59,   59,   93,   44,   59,  287,  288,  289,  290,   44,
  258,  276,  280,  281,   93,   59,  271,  272,  273,  274,
   41,    0,    0,   41,   41,  271,  272,  273,  274,   59,
   41,  272,  287,  288,  289,  290,  271,  272,  273,  274,
   44,  287,  288,  289,  290,   59,  272,   44,  123,   44,
  125,   44,  272,  273,  274,    6,   18,   30,   47,  272,
  134,  272,  273,  274,  133,  123,   41,  287,  288,  289,
  290,  271,  272,  273,  274,  174,  287,  288,  289,  290,
  265,  266,  139,  271,  272,  123,  274,  265,  266,  140,
   59,  276,  277,  278,  279,  280,  281,  282,  276,  277,
   58,  279,  280,  281,  282,   -1,  291,  265,  266,  123,
   -1,  125,   -1,  291,  265,  266,   -1,   -1,  276,  277,
   -1,  279,  280,  281,  282,  276,  277,   -1,  279,  280,
  281,   -1,   59,  291,  271,  272,  273,  274,   -1,   -1,
  291,  287,  288,  289,  290,  271,  272,  273,  274,   59,
  287,  288,  289,  290,  123,   -1,  125,   -1,   -1,   -1,
   -1,  287,  288,  289,  290,  280,  281,   -1,  283,  284,
  285,  286,   -1,  280,  281,   -1,  283,  284,  285,  286,
  271,  272,  257,  274,  259,  260,  261,  262,  263,  264,
   -1,   -1,  267,  268,  269,  270,  123,   -1,  125,  257,
  275,  259,  260,  261,   -1,  280,  281,   31,   -1,  267,
  268,  269,  270,  123,   -1,  125,  291,  275,   -1,   -1,
  260,   -1,  280,  281,   -1,   -1,   -1,  267,  268,  269,
   -1,   -1,   -1,  291,   -1,   -1,   -1,   -1,   -1,   -1,
  280,  281,   -1,  257,   -1,  259,  260,  261,  262,  263,
  264,  291,   -1,  267,  268,  269,  270,   -1,   -1,   -1,
   -1,  275,   -1,   -1,   -1,   31,  280,  281,   -1,   -1,
   -1,   95,   -1,   -1,   -1,   -1,   42,  291,   -1,   45,
   46,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,
  259,  260,  261,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,  270,   -1,   -1,   -1,   -1,  275,   -1,   -1,   -1,
   -1,  280,  281,   31,   -1,   -1,   -1,   -1,   -1,   -1,
  144,   -1,  291,   -1,   -1,   -1,   -1,   45,   46,   95,
  257,   -1,  259,  260,  261,   -1,   -1,  103,  104,   -1,
  267,  268,  269,  270,  110,  111,   -1,  257,  275,  259,
  260,  261,  176,  280,  281,   -1,   -1,  267,  268,  269,
  270,   -1,   -1,   -1,  291,  275,  190,  191,   -1,   -1,
  280,  281,   -1,   -1,   -1,   -1,  142,   95,  144,   39,
   -1,  291,   -1,   -1,   -1,  103,  104,   -1,   -1,   -1,
   -1,   -1,  110,  111,   -1,   -1,   -1,  221,   -1,   -1,
   -1,   -1,   -1,  227,   -1,   -1,   -1,   -1,  232,   69,
  176,   -1,   -1,   -1,  180,   -1,   -1,  183,   -1,   -1,
   -1,   -1,   -1,   -1,  190,  191,  144,   -1,   -1,   89,
   -1,   -1,   -1,   -1,   -1,   -1,   96,   -1,   -1,   -1,
   -1,   -1,   -1,  103,   -1,  105,  106,   -1,   -1,   -1,
  110,   -1,  112,  113,   -1,  221,  116,  117,  176,   -1,
   -1,  227,  180,   -1,   -1,  183,  232,   -1,   -1,   -1,
   -1,   -1,  190,  191,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  221,   -1,   -1,   -1,   -1,   -1,  227,
   -1,   -1,   -1,   -1,  232,   -1,   -1,   -1,   -1,  179,
   -1,  181,  182,   -1,   -1,  185,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  193,   -1,   -1,  196,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  205,   -1,   -1,   -1,   -1,
   -1,   -1,  212,  213,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",
0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IF","ELSE","WHILE","BREAK","RETURN","INT","REAL",
"CHAR","TRUE","FALSE","PRINT","PRINTLN","READ","REPEAT","TIMES","UNLESS","AND",
"OR","FOR","INT_CONST","REAL_CONST","TEXT","CHAR_CONST","INCREASE_SIGN",
"DECREASE_SIGN","NOT_SIGN","PLUS_EQUALS_SIGN","MINUS_EQUALS_SIGN",
"TIMES_EQUALS_SIGN","DIVIDE_EQUALS_SIGN","IS_EQUAL","IS_NOT_EQUAL",
"IS_LESS_OR_EQUAL","IS_GREATER_OR_EQUAL","ID","LOWER_THAN_ELSE",
};
char *yyrule[] = {
"$accept : Program",
"Program : MethodsList",
"Program :",
"MethodsList : Method MethodsList",
"MethodsList : Method",
"$$1 :",
"Method : Type ID '(' Parameters ')' $$1 Body",
"$$2 :",
"Method : Type '[' ']' ID '(' Parameters ')' $$2 Body",
"Parameters : Formals Type ID",
"Parameters : Formals Type ID '[' ']'",
"Parameters :",
"Formals : Formals Type ID ','",
"Formals : Formals Type ID '[' ']' ','",
"Formals :",
"Type : INT",
"Type : REAL",
"Type : CHAR",
"Body : '{' Declarations Statements '}'",
"Declarations : DeclarationsList Declaration",
"Declarations :",
"DeclarationsList : DeclarationsList Declaration",
"DeclarationsList :",
"$$3 :",
"Declaration : Type ID $$3 Variables ';'",
"$$4 :",
"Declaration : Type ID '[' INT_CONST ']' $$4 Variables ';'",
"$$5 :",
"Declaration : Type ID '=' Expression $$5 Variables ';'",
"$$6 :",
"Variables : ',' ID $$6 Variables",
"$$7 :",
"Variables : ',' ID '[' INT_CONST ']' $$7 Variables",
"$$8 :",
"Variables : ',' ID '=' Expression $$8 Variables",
"Variables :",
"Statements : Statements Statement",
"Statements :",
"IncDec : Location INCREASE_SIGN",
"IncDec : ArrayName INCREASE_SIGN",
"IncDec : INCREASE_SIGN Location",
"IncDec : INCREASE_SIGN ArrayName",
"IncDec : Location DECREASE_SIGN",
"IncDec : ArrayName DECREASE_SIGN",
"IncDec : DECREASE_SIGN Location",
"IncDec : DECREASE_SIGN ArrayName",
"ChangeAssignSymbol : PLUS_EQUALS_SIGN",
"ChangeAssignSymbol : MINUS_EQUALS_SIGN",
"ChangeAssignSymbol : TIMES_EQUALS_SIGN",
"ChangeAssignSymbol : DIVIDE_EQUALS_SIGN",
"SimpleStatement : Assign",
"SimpleStatement : AssignMultiple",
"SimpleStatement : IncDec",
"SimpleStatement : Location ChangeAssignSymbol Expression",
"SimpleStatement : ArrayName ChangeAssignSymbol Expression",
"SimpleStatement : BREAK",
"SimpleStatement : READ Location",
"SimpleStatement : READ TEXT ',' Location",
"SimpleStatement : PRINT Message",
"SimpleStatement : PRINTLN Message",
"Statement : SimpleStatement ';'",
"Statement : RETURN Expression ';'",
"Statement : IF Code1 '(' Expression ')' Statement",
"$$9 :",
"Statement : IF Code1 '(' Expression ')' Statement ELSE $$9 Statement",
"$$10 :",
"Statement : WHILE $$10 '(' Expression ')' Statement",
"$$11 :",
"Statement : REPEAT $$11 Expression TIMES Statement",
"$$12 :",
"Statement : FOR $$12 '(' SimpleStatement ';' Expression ';' SimpleStatement ')' Statement",
"Statement : SimpleStatement UNLESS Expression ';'",
"Statement : Block",
"Statement : ';'",
"Message : Printable MoreMessage",
"MoreMessage : ',' Printable MoreMessage",
"MoreMessage :",
"Printable : TEXT",
"Printable : Expression",
"Block : '{' Statements '}'",
"Assign : Location '=' Expression",
"Assign : Location '=' Assign",
"Assign : ArrayName '=' Expression",
"Assign : ArrayName '=' Assign",
"AssignMultiple : Location ',' NestedAssign ',' Expression",
"AssignMultiple : ArrayName ',' NestedAssign ',' Expression",
"NestedAssign : Location ',' NestedAssign ',' Expression",
"NestedAssign : ArrayName ',' NestedAssign ',' Expression",
"NestedAssign : Location '=' Expression",
"NestedAssign : ArrayName '=' Expression",
"MethodName : ID",
"Location : ID",
"ArrayName : ID '[' Expression ']'",
"Expression : Expression OR AndExpression",
"Expression : AndExpression",
"AndExpression : AndExpression AND RelationExpression",
"AndExpression : RelationExpression",
"RelationExpression : AddExpression RelationOperator AddExpression",
"RelationExpression : AddExpression",
"RelationOperator : IS_LESS_OR_EQUAL",
"RelationOperator : '<'",
"RelationOperator : '>'",
"RelationOperator : IS_GREATER_OR_EQUAL",
"RelationOperator : IS_EQUAL",
"RelationOperator : IS_NOT_EQUAL",
"AddExpression : AddExpression AddOperator Term",
"AddExpression : Term",
"AddOperator : '+'",
"AddOperator : '-'",
"Term : Term MultiplyOperator Factor",
"Term : Factor",
"Term : NOT_SIGN Factor",
"MultiplyOperator : '*'",
"MultiplyOperator : '/'",
"MultiplyOperator : '%'",
"Factor : '(' Expression ')'",
"Factor : Location",
"Factor : ArrayName",
"Factor : INT_CONST",
"Factor : '-' INT_CONST",
"Factor : REAL_CONST",
"Factor : '-' REAL_CONST",
"Factor : TRUE",
"Factor : FALSE",
"Factor : CHAR_CONST",
"Factor : MethodName '(' Actuals ')'",
"Factor : IncDec",
"$$13 :",
"Actuals : $$13 Arguments Expression",
"Actuals :",
"Arguments : Arguments Expression ','",
"Arguments :",
"Code1 :",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 1627 "SyntaxAnalysis.yacc"





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
#line 960 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 98 "SyntaxAnalysis.yacc"
{
					
						s = find_method("main");
						
						if (!s){
							printf("ERROR: Main function not found\n");
							exit(1);
						}
						
                        TreeRoot=MkNode(astProgram,NULL,yyvsp[0].stNode,NULL,NULL,NULL);
						
					}
break;
case 2:
#line 111 "SyntaxAnalysis.yacc"
{
						
                        TreeRoot=MkNode(astEmptyProgram,NULL,NULL,NULL,NULL,NULL);
					
					}
break;
case 3:
#line 119 "SyntaxAnalysis.yacc"
{
                        yyval.stNode=MkNode(astMethods,NULL,yyvsp[-1].stNode,yyvsp[0].stNode,NULL,NULL);
					
					}
break;
case 4:
#line 124 "SyntaxAnalysis.yacc"
{
						
						yyval.stNode=yyvsp[0].stNode;
					
					}
break;
case 5:
#line 132 "SyntaxAnalysis.yacc"
{
							push_ret(new_symbol("start"));
							
							char temp[200];
							
							int i;
							new = new_symbol("");
							new->genre = VARIABLE;
							/*strcpy(new->origName, $2);*/
							if (strcmp(yyvsp[-3].ystr, "main") == 0){
								
								strcpy(new->name, "main");
								strcpy(new->MIXname, "_source_main");
								for (i = 0; i < numOfFormals; i++){
									pop_vs(); /* Parameter*/
								}
								
							} else {
								
								for (i = 0; i < numOfFormals; i++){
									s4 = pop_vs(); /* Parameter*/
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
								strcpy(temp, yyvsp[-3].ystr);
								strcat(temp, new->name);
								strcpy(new->name, temp);
								strcpy(new->MIXname, "_");
								strcat(new->MIXname, new->name);
								/*createMIXMethod(new->MIXname);*/
							}
							
							s1 = pop_vs(); /* Type*/
							
							new->type = s1->type;
							new->lvalue = 0;
							new->numOfParams = numOfFormals;
							
							numOfFormals = 0;
							add_method_to_table(new);
							push_vs(new);
							
							
							bytesCountParameters = 0;
							bytesCountVariables = 0;
							
						}
break;
case 6:
#line 202 "SyntaxAnalysis.yacc"
{						
						
						if (check_has_return() == 1){		
							enableRetStuck = 1;
						} else {
							printf("ERROR: No return statement in method '%s'\n", yyvsp[-5].ystr);
							exit(1);
						}
						
						curMethodID++;
						new = pop_vs();
						
						yyval.stNode=MkNode(astMethod, new, yyvsp[-6].stNode, yyvsp[-3].stNode, yyvsp[0].stNode, NULL);
					}
break;
case 7:
#line 217 "SyntaxAnalysis.yacc"
{
							push_ret(new_symbol("start"));
							
							char temp[200];
							
							int i;
							new = new_symbol("");
							new->genre = ARRAY;
							/*strcpy(new->origName, $4);*/
							if (strcmp(yyvsp[-3].ystr, "main") == 0){
								
								strcpy(new->name, "main");
								strcpy(new->MIXname, "_source_main");
								for (i = 0; i < numOfFormals; i++){
									pop_vs(); /* Parameter*/
								}
								
							} else {
								
								for (i = 0; i < numOfFormals; i++){
									s6 = pop_vs(); /* Parameter*/
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
								strcpy(temp, yyvsp[-3].ystr);
								strcat(temp, new->name);
								strcpy(new->name, temp);
								strcpy(new->MIXname, "_");
								strcat(new->MIXname, new->name);
								/*createMIXMethod(new->MIXname);*/
							}
							
							s1 = pop_vs(); /* Type*/
							
							new->type = s1->type;
							new->lvalue = 0;
							new->numOfParams = numOfFormals;
							
							numOfFormals = 0;
							add_method_to_table(new);
							push_vs(new);
							
							
							bytesCountParameters = 0;
							bytesCountVariables = 0;
							
						}
break;
case 8:
#line 287 "SyntaxAnalysis.yacc"
{						
						
						if (check_has_return() == 1){		
							enableRetStuck = 1;
						} else {
							printf("ERROR: No return statement in method '%s'\n", yyvsp[-5].ystr);
							exit(1);
						}
						
						curMethodID++;
						new = pop_vs();
						
						yyval.stNode=MkNode(astMethod, new, yyvsp[-8].stNode, yyvsp[-3].stNode, yyvsp[0].stNode, NULL);
					}
break;
case 9:
#line 304 "SyntaxAnalysis.yacc"
{
						
						s2 = pop_vs(); /* Type*/
						
						new = new_symbol(yyvsp[0].ystr);
						new->type = s2->type;
						new->is_char = s2->is_char;
						new->is_param = 1;
						
						createMIXParameter(new->MIXname, new->type);						
						
						add_variable_to_table(new);
						push_vs(new);
						
						numOfFormals++;						
						
						yyval.stNode=MkNode(astFormalParameters, new, yyvsp[-2].stNode, yyvsp[-1].stNode, NULL, NULL);
					}
break;
case 10:
#line 323 "SyntaxAnalysis.yacc"
{
						
						s2 = pop_vs(); /* Type*/
						
						new = new_symbol(yyvsp[-2].ystr);
						new->type = s2->type;
						new->is_char = s2->is_char;
						new->genre = ARRAY;
						new->is_param = 1;
						
						/*new->numOfElements = atoi($4);*/
						
						createMIXParameter(new->MIXname, INT);						
						
						add_variable_to_table(new);
						push_vs(new);
						
						numOfFormals++;						
						
						yyval.stNode=MkNode(astFormalArrayParameters, new, yyvsp[-4].stNode, yyvsp[-3].stNode, NULL, NULL);
					}
break;
case 11:
#line 345 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astNoFormalParameters, NULL, NULL, NULL, NULL, NULL);
					}
break;
case 12:
#line 351 "SyntaxAnalysis.yacc"
{
						s2 = pop_vs(); /* Type*/
						
						new = new_symbol(yyvsp[-1].ystr);
						new->type = s2->type;
						new->is_char = s2->is_char;
						new->is_param = 1;
						
						createMIXParameter(new->MIXname, new->type);
						
						add_variable_to_table(new);
						push_vs(new);
						
						numOfFormals++;						
						
						yyval.stNode=MkNode(astMoreFormalParameters, new, yyvsp[-3].stNode, yyvsp[-2].stNode, NULL, NULL);
					}
break;
case 13:
#line 369 "SyntaxAnalysis.yacc"
{
						
						s2 = pop_vs(); /* Type*/
						
						new = new_symbol(yyvsp[-3].ystr);
						new->type = s2->type;
						new->is_char = s2->is_char;
						new->genre = ARRAY;
						new->is_param = 1;
						
						/*new->numOfElements = atoi($4);*/
						
						createMIXParameter(new->MIXname, INT);						
						
						add_variable_to_table(new);
						push_vs(new);
						
						numOfFormals++;						
						
						yyval.stNode=MkNode(astFormalArrayParameters, new, yyvsp[-5].stNode, yyvsp[-4].stNode, NULL, NULL);
					}
break;
case 14:
#line 391 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astNoMoreFormalParameters, NULL, NULL, NULL, NULL, NULL);
					}
break;
case 15:
#line 397 "SyntaxAnalysis.yacc"
{
						
						new = new_symbol("");
						new->type = INT;
						new->lvalue = 0;
						
						push_vs(new);
						
						yyval.stNode=MkNode(astTypeInt, new, NULL, NULL, NULL, NULL);
						
					}
break;
case 16:
#line 409 "SyntaxAnalysis.yacc"
{
						
						new = new_symbol("");
						new->type = REAL;
						new->lvalue = 0;
						
						push_vs(new);
						
						yyval.stNode=MkNode(astTypeReal, new, NULL, NULL, NULL, NULL);
						
					}
break;
case 17:
#line 421 "SyntaxAnalysis.yacc"
{
						
						new = new_symbol("");
						new->type = INT;
						new->lvalue = 0;
						new->is_char = 1;
						
						push_vs(new);
						
						yyval.stNode=MkNode(astTypeReal, new, NULL, NULL, NULL, NULL);
						
					}
break;
case 18:
#line 436 "SyntaxAnalysis.yacc"
{

						yyval.stNode=MkNode(astBody, NULL, yyvsp[-2].stNode, yyvsp[-1].stNode, NULL, NULL);
					}
break;
case 19:
#line 443 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astDeclarations, NULL, yyvsp[-1].stNode, yyvsp[0].stNode, NULL, NULL);
					}
break;
case 20:
#line 447 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astNoDeclarations, NULL, NULL, NULL, NULL, NULL);					
					}
break;
case 21:
#line 453 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astMoreDeclarations, NULL, yyvsp[-1].stNode, yyvsp[0].stNode, NULL, NULL);
					}
break;
case 22:
#line 457 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astNoMoreDeclarations, NULL, NULL, NULL, NULL, NULL);
					
					}
break;
case 23:
#line 464 "SyntaxAnalysis.yacc"
{
							s1 = pop_vs(); /* Type*/
							new = new_symbol(yyvsp[0].ystr);							
							new->type = s1->type;
							new->is_char = s1->is_char;
							new->genre = VARIABLE;
							
							createMIXVariable(new->MIXname, new->type);
							
							add_variable_to_table(new);							
							push_vs(new);							
							push_vs(s1);
						}
break;
case 24:
#line 478 "SyntaxAnalysis.yacc"
{
						new = pop_vs();
						yyval.stNode=MkNode(astDeclaration, new, yyvsp[-4].stNode, yyvsp[-1].stNode, NULL, NULL);
					}
break;
case 25:
#line 483 "SyntaxAnalysis.yacc"
{
							s1 = pop_vs(); /* Type*/
							new = new_symbol(yyvsp[-3].ystr);							
							new->type = s1->type;
							new->is_char = s1->is_char;
							new->genre = ARRAY;
							new->numOfElements = atoi(yyvsp[-1].ystr);
							
							createMIXVariable(new->MIXname, INT);
							createMIXArray(new->ArrayName, new->type);
							
							add_variable_to_table(new);							
							push_vs(new);							
							push_vs(s1);
						}
break;
case 26:
#line 499 "SyntaxAnalysis.yacc"
{
						new = pop_vs();
						yyval.stNode=MkNode(astArrayDeclaration, new, yyvsp[-7].stNode, yyvsp[-1].stNode, NULL, NULL);
					}
break;
case 27:
#line 504 "SyntaxAnalysis.yacc"
{
							s4 = pop_vs(); 	/* Expression*/
							s1 = pop_vs(); 	/* Type*/
							new = new_symbol(yyvsp[-2].ystr);
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
break;
case 28:
#line 521 "SyntaxAnalysis.yacc"
{
						new = pop_vs();
						yyval.stNode=MkNode(astDeclarationExtended, new, yyvsp[-6].stNode, yyvsp[-3].stNode, yyvsp[-1].stNode, NULL);
					}
break;
case 29:
#line 528 "SyntaxAnalysis.yacc"
{	
							s = pop_vs(); /* Type*/
							new = new_symbol(yyvsp[0].ystr);
							new->type = s->type;
							new->is_char = s->is_char;
							new->genre = VARIABLE;
							
							createMIXVariable(new->MIXname, new->type);	
							
							add_variable_to_table(new);
							push_vs(new);
							push_vs(s);
						}
break;
case 30:
#line 542 "SyntaxAnalysis.yacc"
{	
						new = pop_vs();				
						yyval.stNode=MkNode(astVariable, new, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 31:
#line 547 "SyntaxAnalysis.yacc"
{
							s = pop_vs(); /* Type*/
							new = new_symbol(yyvsp[-3].ystr);							
							new->type = s->type;
							new->is_char = s->is_char;
							new->genre = ARRAY;
							new->numOfElements = atoi(yyvsp[-1].ystr);
							
							createMIXVariable(new->MIXname, INT);
							createMIXArray(new->ArrayName, new->type);
							
							add_variable_to_table(new);							
							push_vs(new);
							push_vs(s);
						}
break;
case 32:
#line 563 "SyntaxAnalysis.yacc"
{
						new = pop_vs();
						yyval.stNode=MkNode(astArrayVariable, new, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 33:
#line 568 "SyntaxAnalysis.yacc"
{							
							s4 = pop_vs(); 	/* Expression*/
							s = pop_vs(); 	/* Type*/
							new = new_symbol(yyvsp[-2].ystr);
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
break;
case 34:
#line 585 "SyntaxAnalysis.yacc"
{	
						new = pop_vs();					
						yyval.stNode=MkNode(astVariableExtended, new, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
					}
break;
case 35:
#line 590 "SyntaxAnalysis.yacc"
{
						pop_vs(); /* Type*/
						yyval.stNode=MkNode(astNoVariable, NULL, NULL, NULL, NULL, NULL);
					}
break;
case 36:
#line 597 "SyntaxAnalysis.yacc"
{
						/*s2 = pop_vs(); // Statement*/
						yyval.stNode=MkNode(astStatements, NULL, yyvsp[-1].stNode, yyvsp[0].stNode, NULL, NULL);
					}
break;
case 37:
#line 602 "SyntaxAnalysis.yacc"
{
						
						yyval.stNode=MkNode(astNoStatements, NULL, NULL, NULL, NULL, NULL);
					}
break;
case 38:
#line 609 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astIncreaseAfter, NULL, yyvsp[-1].stNode, NULL, NULL, NULL);
					}
break;
case 39:
#line 613 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astIncreaseAfter, NULL, yyvsp[-1].stNode, NULL, NULL, NULL);
					}
break;
case 40:
#line 617 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astIncreaseBefore, NULL, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 41:
#line 621 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astIncreaseBefore, NULL, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 42:
#line 625 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astDecreaseAfter, NULL, yyvsp[-1].stNode, NULL, NULL, NULL);
						
					}
break;
case 43:
#line 630 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astDecreaseAfter, NULL, yyvsp[-1].stNode, NULL, NULL, NULL);
					}
break;
case 44:
#line 634 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astDecreaseBefore, NULL, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 45:
#line 638 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astDecreaseBefore, NULL, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 46:
#line 644 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astPlusEquals, NULL, NULL, NULL, NULL, NULL);
					}
break;
case 47:
#line 648 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astMinusEquals, NULL, NULL, NULL, NULL, NULL);
					}
break;
case 48:
#line 652 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astTimesEquals, NULL, NULL, NULL, NULL, NULL);						
					}
break;
case 49:
#line 656 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astDivideEquals, NULL, NULL, NULL, NULL, NULL);			
					}
break;
case 50:
#line 662 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astStartAssignStatement, NULL, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 51:
#line 666 "SyntaxAnalysis.yacc"
{
						yyval.stNode=yyvsp[0].stNode;
					}
break;
case 52:
#line 670 "SyntaxAnalysis.yacc"
{
						s1 = pop_vs(); /* IncDec*/
						yyval.stNode=MkNode(astIncDecStatement, NULL, yyvsp[0].stNode, NULL, NULL, NULL);						
					}
break;
case 53:
#line 675 "SyntaxAnalysis.yacc"
{
						s3 = pop_vs(); /* Expression*/
						s1 = pop_vs(); /* Location*/
						
						yyval.stNode=MkNode(astChangeAssignStatement, NULL, yyvsp[-2].stNode, yyvsp[-1].stNode, yyvsp[0].stNode, NULL);
						
					}
break;
case 54:
#line 683 "SyntaxAnalysis.yacc"
{
						s3 = pop_vs(); /* Expression*/
						s1 = pop_vs(); /* Location*/
						
						yyval.stNode=MkNode(astChangeAssignStatement, NULL, yyvsp[-2].stNode, yyvsp[-1].stNode, yyvsp[0].stNode, NULL);
						
					}
break;
case 55:
#line 691 "SyntaxAnalysis.yacc"
{
						s = pop_while();
						
						if (s){
							push_while(new_symbol(""));
						} else {
							printf("ERROR: Break must be in a while loop\n");
							exit(1);
						}
						
						yyval.stNode=MkNode(astBreakStatement, NULL, NULL, NULL, NULL, NULL);
					}
break;
case 56:
#line 705 "SyntaxAnalysis.yacc"
{
						s2 = pop_vs();	/* Location*/
						
						if (s2->genre == ARRAY){
							printf("ERROR Can't read arrays ('%s').\n", s2->name);
							exit(1);
						}
						
						yyval.stNode=MkNode(astReadStatement, NULL, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 57:
#line 716 "SyntaxAnalysis.yacc"
{
						s2 = pop_vs();	/* Location*/
						
						if (s2->genre == ARRAY){
							printf("ERROR Can't read arrays ('%s').\n", s2->name);
							exit(1);
						}
						
						new = new_symbol(yyvsp[-2].ystr);
						
						yyval.stNode=MkNode(astReadWithPrintStatement, new, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 58:
#line 729 "SyntaxAnalysis.yacc"
{						
						yyval.stNode=MkNode(astPrintStatement, NULL, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 59:
#line 733 "SyntaxAnalysis.yacc"
{						
						yyval.stNode=MkNode(astPrintlnStatement, NULL, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 60:
#line 739 "SyntaxAnalysis.yacc"
{
						yyval.stNode = yyvsp[-1].stNode;
					}
break;
case 61:
#line 743 "SyntaxAnalysis.yacc"
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
						
						s2 = pop_vs(); /* Expression*/
						
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
						
						yyval.stNode=MkNode(astReturn, curMethod, yyvsp[-1].stNode, NULL, NULL, NULL);
					}
break;
case 62:
#line 788 "SyntaxAnalysis.yacc"
{
						if (enableRetStuck == 1){
							if (strcmp(ret_stack[TopOfRetStack]->name, "if") != 0){
								pop_ret(); /* return or no-ret*/
							}
							pop_ret(); /* if*/
						}
						
						/*s6 = pop_vs(); // Statement (if)*/
						s4 = pop_vs(); /* Expression						*/
						
						yyval.stNode=MkNode(astIfStatement, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
						
						/*//push_vs(NULL);*/
					}
break;
case 63:
#line 804 "SyntaxAnalysis.yacc"
{
							if (enableRetStuck == 1){
								
								if (strcmp(ret_stack[TopOfRetStack]->name, "return") !=0 && strcmp(ret_stack[TopOfRetStack]->name, "no_ret") !=0){
									push_ret(new_symbol("no_ret"));
								}
								
								push_ret(new_symbol("else"));
							}
						}
break;
case 64:
#line 815 "SyntaxAnalysis.yacc"
{
						
						if (enableRetStuck == 1){							
							
							if (strcmp(ret_stack[TopOfRetStack]->name, "return") !=0 && strcmp(ret_stack[TopOfRetStack]->name, "no_ret") !=0){
								push_ret(new_symbol("no_ret"));
							}
							
							r4 = pop_ret(); /* return or no_ret*/
							r3 = pop_ret(); /* else*/
							r2 = pop_ret(); /* return or no_ret*/
							r1 = pop_ret(); /* if*/
							
							if (strcmp(r4->name, "return") == 0 && strcmp(r2->name, "return") ==0){
								push_ret(new_symbol("return"));
							} else if (strcmp(ret_stack[TopOfRetStack]->name, "no_ret") !=0){
								push_ret(new_symbol("no_ret"));
							}
							
						}
						
						/*s9 = pop_vs(); // Statement (else)*/
						/*s6 = pop_vs(); // Statement (if)*/
						s4 = pop_vs(); /* Expression						*/
						
						yyval.stNode=MkNode(astIfElseStatement, NULL, yyvsp[-5].stNode, yyvsp[-3].stNode, yyvsp[0].stNode, NULL);
						
						/*//push_vs(NULL);*/
					}
break;
case 65:
#line 845 "SyntaxAnalysis.yacc"
{	
							enableRetStuck = 0;
							push_while(new_symbol(""));
						}
break;
case 66:
#line 850 "SyntaxAnalysis.yacc"
{
						
						pop_while();
						if (TopOfWhileStack <0){
							enableRetStuck = 1;
						}
						
						
						/*s6 = pop_vs(); // Statement*/
						s4 = pop_vs(); /* Expression*/
						
						/*push_vs(NULL);*/
						
						yyval.stNode=MkNode(astWhileStatement, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
						
					
					}
break;
case 67:
#line 868 "SyntaxAnalysis.yacc"
{	
							enableRetStuck = 0;
							push_while(new_symbol(""));
						}
break;
case 68:
#line 873 "SyntaxAnalysis.yacc"
{
						
						pop_while();
						if (TopOfWhileStack <0){
							enableRetStuck = 1;
						}
						
						
						/*s6 = pop_vs(); // Statement*/
						s4 = pop_vs(); /* Expression*/
						
						if (s4->type == REAL){
							printf("ERROR: Repeat times must be with an integer.\n");
							exit(1);
						}
						
						/*push_vs(NULL);*/
						
						yyval.stNode=MkNode(astRepeatStatement, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
						
					
					}
break;
case 69:
#line 896 "SyntaxAnalysis.yacc"
{	
							enableRetStuck = 0;
							push_while(new_symbol(""));
						}
break;
case 70:
#line 901 "SyntaxAnalysis.yacc"
{
						
						pop_while();
						if (TopOfWhileStack <0){
							enableRetStuck = 1;
						}
						
						
						/*s6 = pop_vs(); // Statement*/
						s4 = pop_vs(); /* Expression*/
						
						/*push_vs(NULL);*/
						
						yyval.stNode=MkNode(astForStatement, NULL, yyvsp[-6].stNode, yyvsp[-4].stNode, yyvsp[-2].stNode, yyvsp[0].stNode);
						
					
					}
break;
case 71:
#line 919 "SyntaxAnalysis.yacc"
{
						s3 = pop_vs(); /* Expression*/
						/*push_vs(NULL);*/
						yyval.stNode=MkNode(astUnlessStatement, NULL, yyvsp[-3].stNode, yyvsp[-1].stNode, NULL, NULL);
					}
break;
case 72:
#line 925 "SyntaxAnalysis.yacc"
{						
						/*push_vs(NULL);*/
						yyval.stNode=yyvsp[0].stNode;
					}
break;
case 73:
#line 930 "SyntaxAnalysis.yacc"
{
						/*push_vs(NULL);*/
						yyval.stNode=MkNode(astEmptyStatement, NULL, NULL, NULL, NULL, NULL);					
					}
break;
case 74:
#line 937 "SyntaxAnalysis.yacc"
{						
					
						yyval.stNode=MkNode(astMessage, NULL, yyvsp[-1].stNode, yyvsp[0].stNode, NULL, NULL);
						
					}
break;
case 75:
#line 945 "SyntaxAnalysis.yacc"
{
						
						yyval.stNode=MkNode(astMoreMessage, NULL, yyvsp[-1].stNode, yyvsp[0].stNode, NULL, NULL);	
						
					}
break;
case 76:
#line 951 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astNoMoreMessage, NULL, NULL, NULL, NULL, NULL);	
						
					}
break;
case 77:
#line 958 "SyntaxAnalysis.yacc"
{
						new = new_symbol(yyvsp[0].ystr);
						
						yyval.stNode=MkNode(astTextToPrint, new, NULL, NULL, NULL, NULL);	
						
					}
break;
case 78:
#line 965 "SyntaxAnalysis.yacc"
{
						s1 = pop_vs(); /* Expression*/
						
						yyval.stNode=MkNode(astExpressionToPrint, NULL, yyvsp[0].stNode, NULL, NULL, NULL);	
					}
break;
case 79:
#line 973 "SyntaxAnalysis.yacc"
{		
						yyval.stNode=yyvsp[-1].stNode;
					}
break;
case 80:
#line 979 "SyntaxAnalysis.yacc"
{
						s3 = pop_vs();	/* Expression*/
						s1 = pop_vs();	/* Location*/
						
						yyval.stNode=MkNode(astAssignStatement, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
					}
break;
case 81:
#line 986 "SyntaxAnalysis.yacc"
{
						s1 = pop_vs();	/* Location*/
						
						yyval.stNode=MkNode(astMoreAssignStatement, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
						
					}
break;
case 82:
#line 993 "SyntaxAnalysis.yacc"
{
						s3 = pop_vs();	/* Expression*/
						s1 = pop_vs();	/* ArrayName*/
						
						yyval.stNode=MkNode(astAssignStatement, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
					}
break;
case 83:
#line 1000 "SyntaxAnalysis.yacc"
{
						s1 = pop_vs();	/* ArrayName*/
						
						yyval.stNode=MkNode(astMoreAssignStatement, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
						
					}
break;
case 84:
#line 1009 "SyntaxAnalysis.yacc"
{
						s5 = pop_vs();	/* Expression*/
						s1 = pop_vs();	/* Location*/
						
						yyval.stNode=MkNode(astAssignMultipleStatement, NULL, yyvsp[-4].stNode, yyvsp[-2].stNode, yyvsp[0].stNode, NULL);
						
					}
break;
case 85:
#line 1017 "SyntaxAnalysis.yacc"
{
						s5 = pop_vs();	/* Expression*/
						s1 = pop_vs();	/* ArrayName*/
						
						yyval.stNode=MkNode(astAssignMultipleStatement, NULL, yyvsp[-4].stNode, yyvsp[-2].stNode, yyvsp[0].stNode, NULL);
						
					}
break;
case 86:
#line 1027 "SyntaxAnalysis.yacc"
{
						s5 = pop_vs();	/* Expression*/
						s1 = pop_vs();	/* Location*/
						
						yyval.stNode=MkNode(astNestedAssignStatement, NULL, yyvsp[-4].stNode, yyvsp[-2].stNode, yyvsp[0].stNode, NULL);
						
					}
break;
case 87:
#line 1035 "SyntaxAnalysis.yacc"
{
						s5 = pop_vs();	/* Expression*/
						s1 = pop_vs();	/* ArrayName*/
						
						yyval.stNode=MkNode(astNestedAssignStatement, NULL, yyvsp[-4].stNode, yyvsp[-2].stNode, yyvsp[0].stNode, NULL);
						
					}
break;
case 88:
#line 1043 "SyntaxAnalysis.yacc"
{
						s3 = pop_vs();	/* Expression*/
						s1 = pop_vs();	/* Location*/
						
						yyval.stNode=MkNode(astLastNestedAssignStatement, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
						
					}
break;
case 89:
#line 1051 "SyntaxAnalysis.yacc"
{
						s3 = pop_vs();	/* Expression*/
						s1 = pop_vs();	/* ArrayName*/
						
						yyval.stNode=MkNode(astLastNestedAssignStatement, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
						
					}
break;
case 90:
#line 1062 "SyntaxAnalysis.yacc"
{
						new = new_symbol(yyvsp[0].ystr);				
						
						push_vs(new);
						
						yyval.stNode=MkNode(astMethodName, new, NULL, NULL, NULL, NULL);
					}
break;
case 91:
#line 1072 "SyntaxAnalysis.yacc"
{
						new = find_variable(yyvsp[0].ystr);
						/*printf("Found variable %s\n", new);*/
						if (!new){							
							printf("ERROR: Undeclared variable '%s'\n", yyvsp[0].ystr);
							exit(1);
						}
						
						
						push_vs(new);
						
						yyval.stNode=MkNode(astLocation, new, NULL, NULL, NULL, NULL);
					}
break;
case 92:
#line 1088 "SyntaxAnalysis.yacc"
{
						
						s3 = pop_vs(); /* Expression*/
						
						if (s3->type != INT){
							printf("ERROR: Array ('%s') index is not an integer.\n", yyvsp[-3].ystr);
							exit(1);
						}
						
						new = find_variable(yyvsp[-3].ystr);
						/*printf("Found variable %s\n", new);*/
						if (!new){							
							printf("ERROR: Undeclared array '%s'\n", yyvsp[-3].ystr);
							exit(1);
						}
						
						if (new->genre != ARRAY){
							printf("ERROR: Expected array but found variable '%s'.\n",  yyvsp[-3].ystr);
							exit(1);
						}
						
						push_vs(new);
						
						yyval.stNode=MkNode(astArrayName, new, yyvsp[-1].stNode, NULL, NULL, NULL);
					}
break;
case 93:
#line 1117 "SyntaxAnalysis.yacc"
{
						
						s3 = pop_vs(); /* AndExpression*/
						s1 = pop_vs(); /* Expression*/
						
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
						
						yyval.stNode=MkNode(astOrExpression, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
					}
break;
case 94:
#line 1142 "SyntaxAnalysis.yacc"
{
						
						yyval.stNode=yyvsp[0].stNode;
						
					}
break;
case 95:
#line 1150 "SyntaxAnalysis.yacc"
{						
						s3 = pop_vs(); /* RelOperation*/
						s1 = pop_vs(); /* AndExpression*/
						
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
							
						
						yyval.stNode=MkNode(astAndExpression, NULL, yyvsp[-2].stNode, yyvsp[0].stNode, NULL, NULL);
					}
break;
case 96:
#line 1175 "SyntaxAnalysis.yacc"
{
						
						yyval.stNode=yyvsp[0].stNode;
						
					}
break;
case 97:
#line 1183 "SyntaxAnalysis.yacc"
{
						s3 = pop_vs(); /* AddExpression*/
						s1 = pop_vs(); /* AddExpression*/
						
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
						
						
						yyval.stNode=MkNode(astRelationExpression, NULL, yyvsp[-2].stNode, yyvsp[-1].stNode, yyvsp[0].stNode, NULL);
					}
break;
case 98:
#line 1209 "SyntaxAnalysis.yacc"
{
						
						yyval.stNode=yyvsp[0].stNode;					
					}
break;
case 99:
#line 1216 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astLessOrEqualOperator, NULL, NULL, NULL, NULL, NULL);	
					}
break;
case 100:
#line 1220 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astLessOperator, NULL, NULL, NULL, NULL, NULL);	
					}
break;
case 101:
#line 1224 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astGreaterOperator, NULL, NULL, NULL, NULL, NULL);	
					}
break;
case 102:
#line 1228 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astGreaterOrEqualOperator, NULL, NULL, NULL, NULL, NULL);	
					}
break;
case 103:
#line 1232 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astEqualOperator, NULL, NULL, NULL, NULL, NULL);	
					}
break;
case 104:
#line 1236 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astNotEqualOperator, NULL, NULL, NULL, NULL, NULL);	
					}
break;
case 105:
#line 1242 "SyntaxAnalysis.yacc"
{
						s3 = pop_vs(); /* Term*/
						s1 = pop_vs(); /* AddExpression*/
						
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
						
						yyval.stNode=MkNode(astAddExpression, NULL, yyvsp[-2].stNode, yyvsp[-1].stNode, yyvsp[0].stNode, NULL);	
					}
break;
case 106:
#line 1278 "SyntaxAnalysis.yacc"
{
						yyval.stNode=yyvsp[0].stNode;	
					}
break;
case 107:
#line 1284 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astAddOperator, NULL, NULL, NULL, NULL, NULL);	
					}
break;
case 108:
#line 1288 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astSubtractOperator, NULL, NULL, NULL, NULL, NULL);	
					}
break;
case 109:
#line 1294 "SyntaxAnalysis.yacc"
{
						s3 = pop_vs(); /* Factor*/
						s2 = pop_vs(); /* MultiplyOperator*/
						s1 = pop_vs(); /* Term*/
						
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
						
						
						yyval.stNode=MkNode(astTerm, NULL, yyvsp[-2].stNode, yyvsp[-1].stNode, yyvsp[0].stNode, NULL);	
					}
break;
case 110:
#line 1337 "SyntaxAnalysis.yacc"
{
						yyval.stNode=yyvsp[0].stNode;
					}
break;
case 111:
#line 1341 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astNotOperator, NULL, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 112:
#line 1347 "SyntaxAnalysis.yacc"
{
						push_vs(new_symbol("*"));
						yyval.stNode=MkNode(astMultiplyOperator, NULL, NULL, NULL, NULL, NULL);	
					}
break;
case 113:
#line 1352 "SyntaxAnalysis.yacc"
{
						push_vs(new_symbol("/"));
						yyval.stNode=MkNode(astDivideOperator, NULL, NULL, NULL, NULL, NULL);
					}
break;
case 114:
#line 1357 "SyntaxAnalysis.yacc"
{
						push_vs(new_symbol("%"));
						yyval.stNode=MkNode(astModuloOperator, NULL, NULL, NULL, NULL, NULL);
					}
break;
case 115:
#line 1364 "SyntaxAnalysis.yacc"
{
						yyval.stNode=yyvsp[-1].stNode;
					}
break;
case 116:
#line 1368 "SyntaxAnalysis.yacc"
{
						yyval.stNode=yyvsp[0].stNode;
					}
break;
case 117:
#line 1372 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astArrayCall, NULL, yyvsp[0].stNode, NULL, NULL, NULL);
					}
break;
case 118:
#line 1376 "SyntaxAnalysis.yacc"
{
						new = new_symbol("");
						new->type = INT;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->value = atoi(yyvsp[0].ystr);
						new->dvalue = new->value;
						push_vs(new);
						
						yyval.stNode=MkNode(astIntConstant, new, NULL, NULL, NULL, NULL);	
					}
break;
case 119:
#line 1389 "SyntaxAnalysis.yacc"
{
						new = new_symbol("");
						new->type = INT;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->value = -atoi(yyvsp[0].ystr);
						new->dvalue = new->value;
						push_vs(new);
						
						yyval.stNode=MkNode(astIntConstant, new, NULL, NULL, NULL, NULL);	
					}
break;
case 120:
#line 1402 "SyntaxAnalysis.yacc"
{
						new = new_symbol("");
						new->type = REAL;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->dvalue = atof(yyvsp[0].ystr);
						new->value = new->dvalue;/* -------- REMOVE ME ------------- //*/
						push_vs(new);
						
						yyval.stNode=MkNode(astRealConstant, new, NULL, NULL, NULL, NULL);	
					}
break;
case 121:
#line 1415 "SyntaxAnalysis.yacc"
{
						new = new_symbol("");
						new->type = REAL;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->dvalue = -atof(yyvsp[0].ystr);
						new->value = new->dvalue;/* -------- REMOVE ME ------------- //*/
						push_vs(new);
						
						yyval.stNode=MkNode(astRealConstant, new, NULL, NULL, NULL, NULL);	
					}
break;
case 122:
#line 1428 "SyntaxAnalysis.yacc"
{
						new = new_symbol("");						
						new->type = INT;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->value = 1;
						new->dvalue = 1;
						push_vs(new);
						
						yyval.stNode=MkNode(astTrue, new, NULL, NULL, NULL, NULL);	
					}
break;
case 123:
#line 1441 "SyntaxAnalysis.yacc"
{
						new = new_symbol("");
						new->type = INT;
						new->sclass = CONSTANT;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						new->value = 0;
						new->dvalue = 0;
						push_vs(new);
						
						yyval.stNode=MkNode(astFalse, new, NULL, NULL, NULL, NULL);	
					}
break;
case 124:
#line 1454 "SyntaxAnalysis.yacc"
{
						new = new_symbol("");
						new->type = INT;
						new->sclass = CONSTANT;
						new->is_char = 1;
						new->has_value = CONST_VAL;
						new->lvalue = 0;
						if (yyvsp[0].ystr[0] != '\\'){
							new->value = yyvsp[0].ystr[0];
						} else {
							switch (yyvsp[0].ystr[1]){
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
						
						yyval.stNode=MkNode(astFalse, new, NULL, NULL, NULL, NULL);	
					}
break;
case 125:
#line 1485 "SyntaxAnalysis.yacc"
{				
					
						char temp[200];
						
						new = new_symbol("");
						strcpy(paramTypes, "");
						int i;
						for (i = 0; i < numOfActuals; i++){
							s4 = pop_vs(); /* Actual*/
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
						
						s1 = pop_vs();	/* 	MethodName	*/
						
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
						
						
						
						yyval.stNode=MkNode(astMethodCall, new, yyvsp[-3].stNode, yyvsp[-1].stNode, NULL, NULL);
						push_vs(new);
					
					}
break;
case 126:
#line 1582 "SyntaxAnalysis.yacc"
{
						yyval.stNode=yyvsp[0].stNode;
					}
break;
case 127:
#line 1587 "SyntaxAnalysis.yacc"
{tempNumOfActuals = numOfActuals; numOfActuals = 0;}
break;
case 128:
#line 1588 "SyntaxAnalysis.yacc"
{
						numOfActuals++;
						yyval.stNode=MkNode(astActualParameters, NULL, yyvsp[-1].stNode, yyvsp[0].stNode, NULL, NULL);	
					}
break;
case 129:
#line 1593 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astNoActualParameters, NULL, NULL, NULL, NULL, NULL);						
					}
break;
case 130:
#line 1599 "SyntaxAnalysis.yacc"
{						
						numOfActuals++;
						yyval.stNode=MkNode(astMoreActualParameters, NULL, yyvsp[-2].stNode, yyvsp[-1].stNode, NULL, NULL);
					}
break;
case 131:
#line 1604 "SyntaxAnalysis.yacc"
{
						yyval.stNode=MkNode(astNoMoreActualParameters, NULL, NULL, NULL, NULL, NULL);	
					
					}
break;
case 132:
#line 1613 "SyntaxAnalysis.yacc"
{
						if (enableRetStuck == 1){
							push_ret(new_symbol("if"));
						}
					}
break;
#line 2809 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
