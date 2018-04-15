%{

%};

%%
[B][0-1]* {printf("UNSIGNED BINARY CONSTANT\n");}
[B][-][0-1]* {printf("NEGETIVE BINARY CONSTANT\n");}
[B][+][0-1]* {printf("POSITIVE BINARY CONSTANT\n");}

[O][0-7]* {printf("UNSIGNED OCTAL CONSTANT\n");}
[O][-][0-7]* {printf("NEGETIVE OCTAL CONSTANT\n");}
[O][+][0-7]* {printf("POSITIVE OCTAL CONSTANT\n");}

[D][0-9]* {printf("UNSIGNED DECIMAL CONSTANT\n");}
[D][-][0-9]* {printf("NEGETIVE DECIMAL CONSTANT\n");}
[D][+][0-9]* {printf("POSITIVE DECIMAL CONSTANT\n");}

[H][0-9]*[A-F]* {printf("UNSIGNED HEXADECIMAL CONSTANT\n");}
[H][-][0-9]*[A-F]* {printf("NEGETIVE HEXADECIMAL CONSTANT\n");}
[H][+][0-9]*[A-F]* {printf("POSITIVE HEXADECIMAL CONSTANT\n");}

.* {printf("invalid\n");}
%%


main(int argc, char **argv){
	yylex();
}

