%{

%};

%%
[a-zA-Z_][_a-zA-Z0-9]* {printf("valid\n");}
.* {printf("invalid\n");}
%%


main(int argc, char **argv){
	yylex();
}

