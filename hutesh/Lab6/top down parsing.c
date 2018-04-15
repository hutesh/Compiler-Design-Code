#include<stdio.h>
#include<string.h>

void check(void);
void set_value(void);
void get_value(void);
void display_output_string(void);

int iptr=0,optr=0,current_optr=0;
char output_string[20],current_output_string[20],input_string[20],temp_string[20];

int main(){
printf("\nEnter the string to check From the grammer: ");
scanf("%s",input_string);
check();
return 0;}
void check(void){
   int flag=1,rule2_index=1;
    strcpy(output_string,"S");
    printf("\nThe output string in different stages are:\n");
    while(iptr<=strlen(input_string)){

        if(strcmp(output_string,temp_string)!=0)
            {
            display_output_string();
            }

        if((iptr!=strlen(input_string)) || (optr!=strlen(output_string))){
            if(input_string[iptr]==output_string[optr]){
                iptr=iptr+1;
                optr=optr+1;}
            else{
                if(output_string[optr]=='S'){
                    memset(output_string,0,strlen(output_string));
                    strcpy(output_string,"aBd");}
                else if(output_string[optr]=='B'){
                    set_value();
                    if(rule2_index==1&&input_string[iptr]=='p'){
                    memset(output_string,0,strlen(output_string));
                    strcpy(output_string,"apbd");}
                    else{
                    memset(output_string,0,strlen(output_string));
                    strcpy(output_string,"add");}}

                else if(output_string[optr]=='b' && input_string[iptr]=='d'){
                    rule2_index=2;
                    get_value();
                    iptr=iptr-1;}

                else{
                    printf("\nThe given string, '%s' is NOT a VALID string.\n\n",input_string);
                    break;}}}

        else{
            printf("\nThe given string, '%s' is VALID string.\n\n",input_string);
            break;}}}

void set_value(void){ //setting values
    current_optr=optr;
    strcpy(current_output_string,output_string);
    return;}
void get_value(void){ //  obtaining previous values
    optr=current_optr;
    memset(output_string,0,strlen(output_string));
    strcpy(output_string,current_output_string);
    return;}
void display_output_string(void){
    printf("%s\n",output_string);
    memset(temp_string,0,strlen(temp_string));
    strcpy(temp_string,output_string);
    return;
    }

