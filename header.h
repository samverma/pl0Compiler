//Sam Verma
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nameMCode "mcode.txt"
#define nameTrace "stacktrace.txt"
#define nameCode "input.txt"
#define nameCleanCode "cleaninput.txt"
#define nameLexTable "lexemetable.txt"
#define nameLexTableList "lexemelist.txt"

#define MAXSTACKHEIGHT 2000
#define MAXSYMTABSIZE 2000
#define MAXCODELENGTH 2000
#define MAXLEXLEVELS 2000
#define identMax 10
#define numMax 10

#ifndef GLB
#define GLB

//files
FILE *fileCode;
FILE *fileCleanCode;
FILE *fileLexTable;
FILE *fileLexTableList;
FILE *fileMCode;
FILE *fileTrace;

char inputFileName[999];
int procedures[999][2], procPos = 0; //0=level 1= line

typedef enum{
	nulsym = 1, identsym, numbersym, plussym, minussym, multsym, slashsym,
	oddsym, eqlsym, neqsym, lessym, leqsym, gtrsym, geqsym, lparentsym,
	rparentsym, commasym, semicolonsym, periodsym, becomessym, beginsym, endsym,
	ifsym, thensym, whilesym, dosym, callsym, constsym, varsym, procsym, writesym,
	readsym, elsesym, errsym, newlinesym
} token;

void printError(int n){
    switch(n){
        case 1:
            printf("Invalid file input\n");
            break;
        case 2:
            printf("Use ""="", not "":=""\n");
            break;
        case 3:
            printf("Use "":="", not ""=""\n");
            break;
        case 4:
            printf("""="" expected after const declaration\n");
            break;
        case 5:
            printf("Number expected after ""="" with const\n");
            break;
        case 6:
            printf("""then"" expected after ""if""\n");
            break;
        case 7:
            printf("""do"" expected after ""while""\n");
            break;
        case 8:
            printf("const, var, and procedure must be followed by an identifier\n");
            break;
        case 9:
            printf(""":="" expected after identifier\n");
            break;
        case 10:
            printf("Ident expected after ""call""\n");
            break;
        case 11:
            printf("Relational operator expected\n");
            break;
        case 12:
            printf("Assignment to constants and procedures not allowed\n");
            break;
        case 13:
            printf("Semicolon needed between statements.\n");
            break;
        case 14:
            printf("Cannot begin new statement with this symbol\n");
            break;
        case 15:
            printf("Undeclared identifier detected\n");
            break;
        case 16:
            printf("Unclosed parenthesis detected\n");
            break;
        case 17:
            printf("Invalid operator\n");
            break;
        case 18:
            printf("Invalid symbol\n");
            break;
        case 19:
            printf(""";"" expected\n");
            break;
        case 20:
            printf("Number too long\n");
            break;
        case 21:
            printf("Identifier too long\n");
            break;
        case 22:
            printf("Generated code too long\n");
            break;
        case 23:
            printf("Compiler has run out of memory\n");
            break;
        case 24:
            printf("Period expected\n");
            break;
        case 25:
            printf("Var or const detected more than once\n");
            break;
        case 26:
            printf("Ident name declared twice\n");
            break;
        case 27:
            printf("Reached end of program, no main detected\n");
            break;
        default:
            printf("An error has occurred.\n");
        }
    exit(n);
}

int hashMe(char *name);

typedef struct sym {
    int kind; //const = 1, var = 2, proc = 3
    char name[12]; //name
    int val; // number
    int level; //L level
    int addr; //M 
} symTable;

typedef struct instr{
	int OP; //constants-store kind, name and value
	int L; //variables-store kind, name, L and M
	int M; //-procedures-store kind, name, L and M
} instruction;

//lex table
typedef struct tokens{
    int type;
    char name[identMax];
} Token;
Token tokenList[MAXCODELENGTH];

#endif 

