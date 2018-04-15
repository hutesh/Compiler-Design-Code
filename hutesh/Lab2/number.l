%{
	int a = 0;
%}

%%
"zero" {a += 0;}
"one" {a += 1;}
"two" {a += 2;}
"three" {a += 3;}
"four" {a += 4;}
"five" {a += 5;}
"six" {a += 6;}
"seven" {a += 7;}
"eight" {a += 8;}
"nine" {a += 9;}
"ten" {a += 10;}
"eleven" {a += 11;}
"twelve" {a += 12;}
"thirteen" {a += 13;}
"fourteen" {a += 14;}
"fifteen" {a += 15;}
"sixteen" {a += 16;}
"seventeen" {a += 17;}
"eighteen" {a += 18;}
"ninteen" {a += 19;}
"twenty" {a += 20;}
"thirty" {a += 30;}
"forty" {a += 40;}
"fifty" {a += 50;}
"sixty" {a += 60;}
"seventy" {a += 70;}
"eighty" {a += 80;}
"ninty" {a += 90;}
"hundred" {a *= 100;}
%%

main(int argc, char **argv)
{
	yylex();
	if(a > 999){
		printf("Invalid input, terminating...\n");
	}
	else
		printf("The number is %d\n", a);
}
