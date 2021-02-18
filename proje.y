%{
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
%}

%union
{
int number;
char *str;
}

%token ASSIGNOP IFRSW COLON EXCLAMATION LESS GREATER ELSE ELIF MINUSOP PLUSOP MULTOP DIVIDEOP
%token<str> INTEGER FLOAT TAB
%token<str> VARIABLE STRING
%type<number> expression var_type if_expression

%%
program:
    statement
	|
	statement program
    ;
statement:
	VARIABLE ASSIGNOP expression
	{
		if($3 == 1)
		{
			values[string($1)+"_int"] = $3;
			finalOutput+= "\n\t" + string($1) + "_int" + " = ";
		}
		else if($3 == 2)
		{
			values[string($1)+"_flt"] = $3;
			finalOutput+= "\n\t" + string($1) + "_flt" + " = ";
		}
		else if($3 == 0)
		{
			values[string($1)+"_str"] = $3;
			finalOutput+= "\n\t" + string($1) + "_str" + " = ";
		}
		finalOutput+= var + ";";
		var="";
				
	}
	|
	IFRSW if_case COLON if_body
	{
		finalOutput+= ifVar + "\t}";
		ifVar="";
	}
	|
	IFRSW if_case COLON
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block "<<endl;
		exit (EXIT_FAILURE);
	}
	|
	ELIF elif_case COLON elif_body
	{
		finalOutput+= elifVar + "\t}";
		elifVar="";
	}
	|
	ELIF elif_case COLON
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block "<<endl;
		exit (EXIT_FAILURE);
	}
	|
	ELSE COLON else_body
	{
		finalOutput+= "\n\telse\n\t{\n" + elseVar + "\t}";
		elseVar="";
	}
	|
	ELSE COLON
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block "<<endl;
		exit (EXIT_FAILURE);
	}
	|
	TAB
	{
		cout<<"tab inconsistency in line "<<linenum<<endl;
		exit (EXIT_FAILURE);
	}
    ;
	
if_body:
	if_statement
	|
	if_statement if_body
	;
	
elif_body:
	elif_statement
	|
	elif_statement elif_body
	;

else_body:
	else_statement
	|
	else_statement else_body
	;

if_statement:
	TAB VARIABLE ASSIGNOP if_expression
	{
		ifVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($2)+"_int" || itr->first == string($2)+"_flt" || itr->first == string($2)+"_str")
			{
				ifVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if($4 == 1)
			{
				values[string($2)+"_int"] = $4;
				ifVar+= "\t" + string($2) + "_int";
			}
			else if($4 == 2)
			{
				values[string($2)+"_flt"] = $4;
				ifVar+= "\t" + string($2) + "_flt";
			}
			else if($4 == 0)
			{
				values[string($2)+"_str"] = $4;
				ifVar+= "\t" + string($2) + "_str";
			}
		}
		ifVar+= " = " + var + ";\n";
		var="";
	}
	|
	TAB IFRSW if_case COLON if_body
	{
		finalOutput+= ifVar + "\t}\n";
		ifVar="";
	}
	|
	TAB ELSE COLON else_body
	{
		finalOutput+= "\telse\n\t{\n" + elseVar + "\t}\n";
		elseVar="";
	}
	;
	
elif_statement:
	TAB VARIABLE ASSIGNOP if_expression
	{
		elifVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($2)+"_int" || itr->first == string($2)+"_flt" || itr->first == string($2)+"_str")
			{
				elifVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if($4 == 1)
			{
				values[string($2)+"_int"] = $4;
				elifVar+= "\t" + string($2) + "_int";
			}
			else if($4 == 2)
			{
				values[string($2)+"_flt"] = $4;
				elifVar+= "\t" + string($2) + "_flt";
			}
			else if($4 == 0)
			{
				values[string($2)+"_str"] = $4;
				elifVar+= "\t" + string($2) + "_str";
			}
		}
		elifVar+= " = " + var + ";\n";
		var="";
	}
	;

else_statement:
	TAB VARIABLE ASSIGNOP if_expression
	{
		elseVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($2)+"_int" || itr->first == string($2)+"_flt" || itr->first == string($2)+"_str")
			{
				elseVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if($4 == 1)
			{
				values[string($2)+"_int"] = $4;
				elseVar+= "\t" + string($2) + "_int";
			}
			else if($4 == 2)
			{
				values[string($2)+"_flt"] = $4;
				elseVar+= "\t" + string($2) + "_flt";
			}
			else if($4 == 0)
			{
				values[string($2)+"_str"] = $4;
				elseVar+= "\t" + string($2) + "_str";
			}
		}
		elseVar+= " = " + var + ";\n";
		var="";
	}
	|
	TAB IFRSW if_case COLON if_body
	{
		finalOutput+= ifVar + "\t}\n";
		ifVar="";
	}
	;

if_case:
	var_type case_type var_type
	{
		if($1 == $3)
		{
			ifVar+= "\n\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if($1 == 9 || $3 == 9)
		{
			ifVar+= "\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if($1 != $3 && $1 != 0 && $3 != 0)
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
	;

elif_case:
	var_type case_type var_type
	{
		if(elseNum != 0)
		{
			cout<<"elif after else in line " << linenum << endl;
			exit (EXIT_FAILURE); //HATALI OUTPUT!!!
		}
		
		if($1 == $3)
		{
			elifVar+= "\n\telse if( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if($1 == 9 || $3 == 9)
		{
			elifVar+= "\n\telse if( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if($1 != $3 && $1 != 0 && $3 != 0)
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
	;

var_type:
	VARIABLE
	{
		bool check = 0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($1)+"_int" || itr->first == string($1)+"_flt" || itr->first == string($1)+"_str")
			{
				ifVarInside+=itr->first;
				$$=itr->second;
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			ifVarInside+=string($1);
			$$=9;
			
		}
	}
	|
	INTEGER
	{
		ifVarInside+=string($1);
		$$=1;
	}
	|
	FLOAT
	{
		ifVarInside+=string($1);
		$$=2;
	}
	|
	STRING
	{
		ifVarInside+=string($1);
		$$=0;
	}
	;
	
case_type:
	ASSIGNOP ASSIGNOP
	{
		ifVarInside+= " == ";
	}
	|
	EXCLAMATION ASSIGNOP
	{
		ifVarInside+= " != ";
	}
	|
	LESS
	{
		ifVarInside+= " < ";
	}
	|
	LESS ASSIGNOP
	{
		ifVarInside+= " <= ";
	}
	|
	GREATER
	{
		ifVarInside+= " > ";
	}
	|
	GREATER ASSIGNOP
	{
		ifVarInside+= " >= ";
	}
	;
	
expression:
	INTEGER	
	{
		ifNum=0;
		$$=1;
		var+=string($1);
	}
	|
	FLOAT	
	{
		ifNum=0;
		$$=2;
		var+=string($1);
	}
	|
	STRING	
	{
		ifNum=0;
		$$=0;
		var+=string($1);
	}
	|
	VARIABLE
	{
		ifNum=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($1)+"_int" || itr->first == string($1)+"_flt" || itr->first == string($1)+"_str")
			{
				$$ = itr->second;
				var+=itr->first;
				break;
			}
		}
	}
	|
	expression operator expression  
	{
		if($1 == $3)	//control type mach
		{
			$$=$1;
		}
		else if($1 != $3 && $1 == 0 || $3 == 0)
		{
			cout<<"type mismatch in line "<<linenum<<endl;
			exit (EXIT_FAILURE);
		}
		else
		{
			$$=2;
		}
	}
    ;
	
if_expression:
	INTEGER	
	{
		$$=1;
		var+=string($1);
	}
	|
	FLOAT	
	{
		$$=2;
		var+=string($1);
	}
	|
	STRING	
	{
		$$=0;
		var+=string($1);
	}
	|
	VARIABLE
	{
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($1)+"_int" || itr->first == string($1)+"_flt" || itr->first == string($1)+"_str")
			{
				$$ = itr->second;
				var+=itr->first;
				break;
			}
		}
	}
	|
	if_expression operator if_expression  
	{
		if($1 == $3)	//control type mach
		{
			$$=$1;
		}
		else if($1 != $3 && $1 == 0 || $3 == 0)
		{
			cout<<"type mismatch in line "<<linenum<<endl;
			exit (EXIT_FAILURE);
		}
		else
		{
			$$=2;
		}
	}
    ;
	
operator:
	MINUSOP
	{
		var+=" - ";
	}
	|
	PLUSOP
	{
		var+=" + ";
	}
	|
	MULTOP
	{
		var+=" * ";
	}
	|
	DIVIDEOP
	{
		var+=" / ";
	}
	;

%%

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
