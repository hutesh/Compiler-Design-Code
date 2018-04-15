%{

%};

%%
(0|1(00|11)*(01|10))(00|11|(01|10)(00|11)*(01|10))* {printf("valid\n");}
.* {printf("invalid\n");}
%%


main(int argc, char **argv){
	yylex();
}

