/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "proje.y"

	#include <stdio.h>
	#include <iostream>
	#include <string>
	#include <map>
	using namespace std;
	
	#include "y.tab.h"
	extern FILE *yyin;
	extern int yylex();
	extern int linenum;
	extern int tabNum;
	extern int ifNum;
	extern int elseNum;
	extern int elifNum;
	void yyerror(string s);
	
	string finalOutput="";
	string var="";
	string ifVar="";
	string ifVarInside="";
	string elseVar="";
	string elifVar="";
	int tabIf=0;
	map<string,int> values;
	map<string,int>::iterator itr;
#line 29 "proje.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
int number;
char *str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 61 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ASSIGNOP 257
#define IFRSW 258
#define COLON 259
#define EXCLAMATION 260
#define LESS 261
#define GREATER 262
#define ELSE 263
#define ELIF 264
#define MINUSOP 265
#define PLUSOP 266
#define MULTOP 267
#define DIVIDEOP 268
#define INTEGER 269
#define FLOAT 270
#define TAB 271
#define VARIABLE 272
#define STRING 273
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    4,    4,    4,    4,    4,    4,    4,    4,
    6,    6,    8,    8,    9,    9,   10,   10,   10,   11,
   12,   12,    5,    7,    2,    2,    2,    2,   13,   13,
   13,   13,   13,   13,    1,    1,    1,    1,    1,    3,
    3,    3,    3,    3,   14,   14,   14,   14,
};
static const YYINT yylen[] = {                            2,
    1,    2,    3,    4,    3,    4,    3,    3,    2,    1,
    1,    2,    1,    2,    1,    2,    4,    5,    4,    4,
    4,    5,    3,    3,    1,    1,    1,    1,    2,    2,
    1,    2,    1,    2,    1,    1,    1,    1,    3,    1,
    1,    1,    1,    3,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   10,    0,    0,    0,   26,   27,   25,
   28,    0,    0,    0,    0,    0,    0,    2,    0,    0,
    0,    0,    0,    0,    0,    8,    0,    0,    0,   35,
   36,   38,   37,    0,   29,   30,   32,   34,   23,    0,
    4,    0,    0,    0,   16,   24,    0,    6,    0,   45,
   46,   47,   48,    0,    0,    0,    0,   12,    0,    0,
    0,   14,    0,    0,    0,    0,    0,   40,   41,   43,
   42,    0,    0,    0,   19,    0,   22,    0,    0,   18,
    0,
};
static const YYINT yydgoto[] = {                          6,
   34,   12,   72,    7,   13,   41,   16,   48,   26,   42,
   49,   27,   23,   78,
};
static const YYINT yysindex[] = {                      -246,
 -210, -253, -210,    0, -244,    0, -246,    0,    0,    0,
    0, -215, -248, -263, -215, -243, -205,    0, -242, -229,
 -228, -225, -210, -235, -251,    0, -263, -210, -231,    0,
    0,    0,    0, -181,    0,    0,    0,    0,    0, -249,
    0, -235, -210, -209,    0,    0, -222,    0, -231,    0,
    0,    0,    0, -205, -210, -208, -204,    0, -207, -200,
 -202,    0, -181, -198, -263, -200, -235,    0,    0,    0,
    0, -181, -200, -235,    0, -181,    0, -200, -181,    0,
 -181,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,   57,    0,    0,    0,
    0,    0,    0,   39,    0,    0,    0,    0,    0,    0,
 -195, -190,    0,   41,    0,    0,   43,    0,   54,    0,
    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,
    0,   56,    0,    0,    0,    0,    0,    0,   58,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    3,    0,    0,    0,    0,    0,    0,    0,
    0,    5,    0,    0,    0,   20,    0,    0,   22,    0,
   24,
};
static const YYINT yygindex[] = {                        59,
   17,    7,  -29,    0,  -24,  -40,    0,   27,  -27,    0,
    0,    0,   66,  -30,
};
#define YYTABLESIZE 330
static const YYINT yytable[] = {                         45,
    3,   58,   39,   54,   21,   14,   43,   25,   55,   15,
   24,    1,   17,   56,   35,   29,    2,    3,   59,   17,
   44,   20,   57,   44,    4,    5,   77,   36,   37,   39,
   64,   38,   54,   80,   46,   40,   76,   75,    9,   47,
    5,   19,   15,   79,   20,   21,   22,   60,   81,   61,
   65,   67,   66,    7,   73,   11,    1,   13,    8,    9,
   74,   10,   11,   30,   31,   18,   32,   33,   68,   69,
   63,   70,   71,   31,   31,   62,   31,   31,   33,   33,
   28,   33,   33,   50,   51,   52,   53,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    3,    0,
   39,    0,   21,    3,    3,   39,   39,   21,   21,    0,
    0,    3,    3,   39,   39,   21,   21,   17,    0,   20,
    0,   44,   17,   17,   20,   20,   44,   44,    0,    0,
   17,   17,   20,   20,   44,   44,    9,    0,    5,    0,
   15,    9,    9,    5,    5,   15,   15,    0,    0,    0,
    9,    7,    5,   11,   15,   13,    7,    7,   11,   11,
   13,   13,    0,    0,    0,    7,    0,   11,    0,   13,
};
static const YYINT yycheck[] = {                         27,
    0,   42,    0,   34,    0,  259,  258,  271,  258,    3,
  259,  258,  257,  263,  257,  259,  263,  264,   43,    0,
  272,    0,  272,    0,  271,  272,   67,  257,  257,   23,
   55,  257,   63,   74,   28,  271,   66,   65,    0,  271,
    0,  257,    0,   73,  260,  261,  262,  257,   78,  272,
  259,  259,  257,    0,  257,    0,    0,    0,  269,  270,
  259,  272,  273,  269,  270,    7,  272,  273,  269,  270,
   54,  272,  273,  269,  270,   49,  272,  273,  269,  270,
   15,  272,  273,  265,  266,  267,  268,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,   -1,
  258,   -1,  258,  263,  264,  263,  264,  263,  264,   -1,
   -1,  271,  272,  271,  272,  271,  272,  258,   -1,  258,
   -1,  258,  263,  264,  263,  264,  263,  264,   -1,   -1,
  271,  272,  271,  272,  271,  272,  258,   -1,  258,   -1,
  258,  263,  264,  263,  264,  263,  264,   -1,   -1,   -1,
  272,  258,  272,  258,  272,  258,  263,  264,  263,  264,
  263,  264,   -1,   -1,   -1,  272,   -1,  272,   -1,  272,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 273
#define YYUNDFTOKEN 290
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ASSIGNOP","IFRSW","COLON",
"EXCLAMATION","LESS","GREATER","ELSE","ELIF","MINUSOP","PLUSOP","MULTOP",
"DIVIDEOP","INTEGER","FLOAT","TAB","VARIABLE","STRING",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : statement",
"program : statement program",
"statement : VARIABLE ASSIGNOP expression",
"statement : IFRSW if_case COLON if_body",
"statement : IFRSW if_case COLON",
"statement : ELIF elif_case COLON elif_body",
"statement : ELIF elif_case COLON",
"statement : ELSE COLON else_body",
"statement : ELSE COLON",
"statement : TAB",
"if_body : if_statement",
"if_body : if_statement if_body",
"elif_body : elif_statement",
"elif_body : elif_statement elif_body",
"else_body : else_statement",
"else_body : else_statement else_body",
"if_statement : TAB VARIABLE ASSIGNOP if_expression",
"if_statement : TAB IFRSW if_case COLON if_body",
"if_statement : TAB ELSE COLON else_body",
"elif_statement : TAB VARIABLE ASSIGNOP if_expression",
"else_statement : TAB VARIABLE ASSIGNOP if_expression",
"else_statement : TAB IFRSW if_case COLON if_body",
"if_case : var_type case_type var_type",
"elif_case : var_type case_type var_type",
"var_type : VARIABLE",
"var_type : INTEGER",
"var_type : FLOAT",
"var_type : STRING",
"case_type : ASSIGNOP ASSIGNOP",
"case_type : EXCLAMATION ASSIGNOP",
"case_type : LESS",
"case_type : LESS ASSIGNOP",
"case_type : GREATER",
"case_type : GREATER ASSIGNOP",
"expression : INTEGER",
"expression : FLOAT",
"expression : STRING",
"expression : VARIABLE",
"expression : expression operator expression",
"if_expression : INTEGER",
"if_expression : FLOAT",
"if_expression : STRING",
"if_expression : VARIABLE",
"if_expression : if_expression operator if_expression",
"operator : MINUSOP",
"operator : PLUSOP",
"operator : MULTOP",
"operator : DIVIDEOP",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 517 "proje.y"


void yyerror(string s){
	cout<<"error: "<<s<<endl;
}
int yywrap(){
	return 1;
}
int main(int argc, char *argv[])
{
    
    yyin=fopen(argv[1],"r");
    yyparse();
    fclose(yyin);
	
	cout<<"void main()\n{";
	int varNum=0;
	for (itr = values.begin(); itr != values.end(); ++itr)
	{
		if(itr->second == 1)
		{
			varNum++;
		}
	}
	if(varNum != 0)
	{
		cout<<"\n\tint ";
		for (itr = values.begin(); itr != values.end(); ++itr)
		{
			if(itr->second == 1 && varNum != 1)
			{
				cout<<itr->first<<",";
				varNum--;
			}
			else if(itr->second == 1 && varNum == 1)
			{
				cout<<itr->first<<";"<< endl;
				varNum--;
			}
		}
	}
	
	varNum=0;
	for (itr = values.begin(); itr != values.end(); ++itr)
	{
		if(itr->second == 2)
		{
			varNum++;
		}
	}
	if(varNum != 0)
	{
		cout<<"\tfloat ";
		for (itr = values.begin(); itr != values.end(); ++itr)
		{
			if(itr->second == 2 && varNum != 1)
			{
				cout<<itr->first<<",";
				varNum--;
			}
			else if(itr->second == 2 && varNum == 1)
			{
				cout<<itr->first<<";"<< endl;
				varNum--;
			}
		}
	}
	
	varNum=0;
	for (itr = values.begin(); itr != values.end(); ++itr)
	{
		if(itr->second == 0)
		{
			varNum++;
		}
	}
	if(varNum != 0)
	{
		cout<<"\tstring ";
		for (itr = values.begin(); itr != values.end(); ++itr)
		{
			if(itr->second == 0 && varNum != 1)
			{
				cout<<itr->first<<",";
				varNum--;
			}
			else if(itr->second == 0 && varNum == 1)
			{
				cout<<itr->first<<";"<< endl;
				varNum--;
			}
		}
	}
	
	cout<<finalOutput<<endl;
	
	cout<<"}"<<endl;
    return 0;
}
#line 447 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
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
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
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

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 48 "proje.y"
	{
		if(yystack.l_mark[0].number == 1)
		{
			values[string(yystack.l_mark[-2].str)+"_int"] = yystack.l_mark[0].number;
			finalOutput+= "\n\t" + string(yystack.l_mark[-2].str) + "_int" + " = ";
		}
		else if(yystack.l_mark[0].number == 2)
		{
			values[string(yystack.l_mark[-2].str)+"_flt"] = yystack.l_mark[0].number;
			finalOutput+= "\n\t" + string(yystack.l_mark[-2].str) + "_flt" + " = ";
		}
		else if(yystack.l_mark[0].number == 0)
		{
			values[string(yystack.l_mark[-2].str)+"_str"] = yystack.l_mark[0].number;
			finalOutput+= "\n\t" + string(yystack.l_mark[-2].str) + "_str" + " = ";
		}
		finalOutput+= var + ";";
		var="";
				
	}
break;
case 4:
#line 70 "proje.y"
	{
		finalOutput+= ifVar + "\t}";
		ifVar="";
	}
break;
case 5:
#line 76 "proje.y"
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block "<<endl;
		exit (EXIT_FAILURE);
	}
break;
case 6:
#line 82 "proje.y"
	{
		finalOutput+= elifVar + "\t}";
		elifVar="";
	}
break;
case 7:
#line 88 "proje.y"
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block "<<endl;
		exit (EXIT_FAILURE);
	}
break;
case 8:
#line 94 "proje.y"
	{
		finalOutput+= "\n\telse\n\t{\n" + elseVar + "\t}";
		elseVar="";
	}
break;
case 9:
#line 100 "proje.y"
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block "<<endl;
		exit (EXIT_FAILURE);
	}
break;
case 10:
#line 106 "proje.y"
	{
		cout<<"tab inconsistency in line "<<linenum<<endl;
		exit (EXIT_FAILURE);
	}
break;
case 17:
#line 132 "proje.y"
	{
		ifVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[-2].str)+"_int" || itr->first == string(yystack.l_mark[-2].str)+"_flt" || itr->first == string(yystack.l_mark[-2].str)+"_str")
			{
				ifVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if(yystack.l_mark[0].number == 1)
			{
				values[string(yystack.l_mark[-2].str)+"_int"] = yystack.l_mark[0].number;
				ifVar+= "\t" + string(yystack.l_mark[-2].str) + "_int";
			}
			else if(yystack.l_mark[0].number == 2)
			{
				values[string(yystack.l_mark[-2].str)+"_flt"] = yystack.l_mark[0].number;
				ifVar+= "\t" + string(yystack.l_mark[-2].str) + "_flt";
			}
			else if(yystack.l_mark[0].number == 0)
			{
				values[string(yystack.l_mark[-2].str)+"_str"] = yystack.l_mark[0].number;
				ifVar+= "\t" + string(yystack.l_mark[-2].str) + "_str";
			}
		}
		ifVar+= " = " + var + ";\n";
		var="";
	}
break;
case 18:
#line 167 "proje.y"
	{
		finalOutput+= ifVar + "\t}\n";
		ifVar="";
	}
break;
case 19:
#line 173 "proje.y"
	{
		finalOutput+= "\telse\n\t{\n" + elseVar + "\t}\n";
		elseVar="";
	}
break;
case 20:
#line 181 "proje.y"
	{
		elifVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[-2].str)+"_int" || itr->first == string(yystack.l_mark[-2].str)+"_flt" || itr->first == string(yystack.l_mark[-2].str)+"_str")
			{
				elifVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if(yystack.l_mark[0].number == 1)
			{
				values[string(yystack.l_mark[-2].str)+"_int"] = yystack.l_mark[0].number;
				elifVar+= "\t" + string(yystack.l_mark[-2].str) + "_int";
			}
			else if(yystack.l_mark[0].number == 2)
			{
				values[string(yystack.l_mark[-2].str)+"_flt"] = yystack.l_mark[0].number;
				elifVar+= "\t" + string(yystack.l_mark[-2].str) + "_flt";
			}
			else if(yystack.l_mark[0].number == 0)
			{
				values[string(yystack.l_mark[-2].str)+"_str"] = yystack.l_mark[0].number;
				elifVar+= "\t" + string(yystack.l_mark[-2].str) + "_str";
			}
		}
		elifVar+= " = " + var + ";\n";
		var="";
	}
break;
case 21:
#line 218 "proje.y"
	{
		elseVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[-2].str)+"_int" || itr->first == string(yystack.l_mark[-2].str)+"_flt" || itr->first == string(yystack.l_mark[-2].str)+"_str")
			{
				elseVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if(yystack.l_mark[0].number == 1)
			{
				values[string(yystack.l_mark[-2].str)+"_int"] = yystack.l_mark[0].number;
				elseVar+= "\t" + string(yystack.l_mark[-2].str) + "_int";
			}
			else if(yystack.l_mark[0].number == 2)
			{
				values[string(yystack.l_mark[-2].str)+"_flt"] = yystack.l_mark[0].number;
				elseVar+= "\t" + string(yystack.l_mark[-2].str) + "_flt";
			}
			else if(yystack.l_mark[0].number == 0)
			{
				values[string(yystack.l_mark[-2].str)+"_str"] = yystack.l_mark[0].number;
				elseVar+= "\t" + string(yystack.l_mark[-2].str) + "_str";
			}
		}
		elseVar+= " = " + var + ";\n";
		var="";
	}
break;
case 22:
#line 253 "proje.y"
	{
		finalOutput+= ifVar + "\t}\n";
		ifVar="";
	}
break;
case 23:
#line 261 "proje.y"
	{
		if(yystack.l_mark[-2].number == yystack.l_mark[0].number)
		{
			ifVar+= "\n\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if(yystack.l_mark[-2].number == 9 || yystack.l_mark[0].number == 9)
		{
			ifVar+= "\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if(yystack.l_mark[-2].number != yystack.l_mark[0].number && yystack.l_mark[-2].number != 0 && yystack.l_mark[0].number != 0)
		{
			ifVar+= "\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else
		{
			cout<< "comparison type mismatch in line " << linenum << endl;
			exit (EXIT_FAILURE);
		}
	}
break;
case 24:
#line 287 "proje.y"
	{
		if(elseNum != 0)
		{
			cout<<"elif after else in line " << linenum << endl;
			exit (EXIT_FAILURE); /*HATALI OUTPUT!!!*/
		}
		
		if(yystack.l_mark[-2].number == yystack.l_mark[0].number)
		{
			elifVar+= "\n\telse if( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if(yystack.l_mark[-2].number == 9 || yystack.l_mark[0].number == 9)
		{
			elifVar+= "\n\telse if( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if(yystack.l_mark[-2].number != yystack.l_mark[0].number && yystack.l_mark[-2].number != 0 && yystack.l_mark[0].number != 0)
		{
			ifVar+= "\n\telse if( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else
		{
			cout<< "comparison type mismatch in line " << linenum << endl;
			exit (EXIT_FAILURE);
		}
		
	}
break;
case 25:
#line 320 "proje.y"
	{
		bool check = 0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[0].str)+"_int" || itr->first == string(yystack.l_mark[0].str)+"_flt" || itr->first == string(yystack.l_mark[0].str)+"_str")
			{
				ifVarInside+=itr->first;
				yyval.number=itr->second;
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			ifVarInside+=string(yystack.l_mark[0].str);
			yyval.number=9;
			
		}
	}
break;
case 26:
#line 341 "proje.y"
	{
		ifVarInside+=string(yystack.l_mark[0].str);
		yyval.number=1;
	}
break;
case 27:
#line 347 "proje.y"
	{
		ifVarInside+=string(yystack.l_mark[0].str);
		yyval.number=2;
	}
break;
case 28:
#line 353 "proje.y"
	{
		ifVarInside+=string(yystack.l_mark[0].str);
		yyval.number=0;
	}
break;
case 29:
#line 361 "proje.y"
	{
		ifVarInside+= " == ";
	}
break;
case 30:
#line 366 "proje.y"
	{
		ifVarInside+= " != ";
	}
break;
case 31:
#line 371 "proje.y"
	{
		ifVarInside+= " < ";
	}
break;
case 32:
#line 376 "proje.y"
	{
		ifVarInside+= " <= ";
	}
break;
case 33:
#line 381 "proje.y"
	{
		ifVarInside+= " > ";
	}
break;
case 34:
#line 386 "proje.y"
	{
		ifVarInside+= " >= ";
	}
break;
case 35:
#line 393 "proje.y"
	{
		ifNum=0;
		yyval.number=1;
		var+=string(yystack.l_mark[0].str);
	}
break;
case 36:
#line 400 "proje.y"
	{
		ifNum=0;
		yyval.number=2;
		var+=string(yystack.l_mark[0].str);
	}
break;
case 37:
#line 407 "proje.y"
	{
		ifNum=0;
		yyval.number=0;
		var+=string(yystack.l_mark[0].str);
	}
break;
case 38:
#line 414 "proje.y"
	{
		ifNum=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[0].str)+"_int" || itr->first == string(yystack.l_mark[0].str)+"_flt" || itr->first == string(yystack.l_mark[0].str)+"_str")
			{
				yyval.number = itr->second;
				var+=itr->first;
				break;
			}
		}
	}
break;
case 39:
#line 428 "proje.y"
	{
		if(yystack.l_mark[-2].number == yystack.l_mark[0].number)	/*control type mach*/
		{
			yyval.number=yystack.l_mark[-2].number;
		}
		else if(yystack.l_mark[-2].number != yystack.l_mark[0].number && yystack.l_mark[-2].number == 0 || yystack.l_mark[0].number == 0)
		{
			cout<<"type mismatch in line "<<linenum<<endl;
			exit (EXIT_FAILURE);
		}
		else
		{
			yyval.number=2;
		}
	}
break;
case 40:
#line 447 "proje.y"
	{
		yyval.number=1;
		var+=string(yystack.l_mark[0].str);
	}
break;
case 41:
#line 453 "proje.y"
	{
		yyval.number=2;
		var+=string(yystack.l_mark[0].str);
	}
break;
case 42:
#line 459 "proje.y"
	{
		yyval.number=0;
		var+=string(yystack.l_mark[0].str);
	}
break;
case 43:
#line 465 "proje.y"
	{
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[0].str)+"_int" || itr->first == string(yystack.l_mark[0].str)+"_flt" || itr->first == string(yystack.l_mark[0].str)+"_str")
			{
				yyval.number = itr->second;
				var+=itr->first;
				break;
			}
		}
	}
break;
case 44:
#line 478 "proje.y"
	{
		if(yystack.l_mark[-2].number == yystack.l_mark[0].number)	/*control type mach*/
		{
			yyval.number=yystack.l_mark[-2].number;
		}
		else if(yystack.l_mark[-2].number != yystack.l_mark[0].number && yystack.l_mark[-2].number == 0 || yystack.l_mark[0].number == 0)
		{
			cout<<"type mismatch in line "<<linenum<<endl;
			exit (EXIT_FAILURE);
		}
		else
		{
			yyval.number=2;
		}
	}
break;
case 45:
#line 497 "proje.y"
	{
		var+=" - ";
	}
break;
case 46:
#line 502 "proje.y"
	{
		var+=" + ";
	}
break;
case 47:
#line 507 "proje.y"
	{
		var+=" * ";
	}
break;
case 48:
#line 512 "proje.y"
	{
		var+=" / ";
	}
break;
#line 1120 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
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
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
