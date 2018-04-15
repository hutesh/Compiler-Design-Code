%{

%};

%%
["].*["] {printf("String constant\n");}
['].['] {printf("Character constant\n");}
.* {printf("Neither string nor char constant\n");}
%%


main(int argc, char **argv){
	yylex();
}

