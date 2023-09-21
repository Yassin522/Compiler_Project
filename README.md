# Compiler_Project

## Test
### you can test the project by run ./a.exe test1.c in terminal


---

## Compilation Steps 
* flex lex.l
* bison -d parser.y
* gcc parser.tab.c lex.yy.c -w
* ./a.exe test.c