%{
#include <stdio.h>
%}


%%
auto|break|case|constant|continue|else|enum|extern|long|double|char|default|do|float|for|goto|if|int|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {printf("reserved Word");}

^[a-zA-Z_][a-zA-z0-9_]* {printf("Valid Identifier");}

^[0-9][a-zA-Z0-9_]* {printf("InValid Identifier");}


%%

int main()
{
	yylex();
}
