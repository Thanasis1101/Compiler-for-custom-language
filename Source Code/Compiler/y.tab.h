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
typedef union
{
    int   					yint;
    char  					ystr[100];
    struct AstNode_tag   	*stNode;
} YYSTYPE;
extern YYSTYPE yylval;
