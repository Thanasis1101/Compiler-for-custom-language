yacc -dv SyntaxAnalysis.yacc
flex LexicalAnalysis.flex
gcc lex.yy.c y.tab.c zyywrap.c Semantics.c -o Compiler.exe

pause