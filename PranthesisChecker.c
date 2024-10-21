#include<stdio.h>
#define MAX 100

char st[MAX];
int top=-1;

void push(char ch);
char pop();

int main(){
    int i=0;
    int flag=1;
    char exp[100];
    char temp;
    printf("\nEnter the expression- ");
    gets(exp);
    while(exp[i]!='\0'){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
           }
        if (exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top==-1){
                flag=0;
                break;
            }
            else{
                temp=pop();
                if ((exp[i] == ')' && temp != '(') ||
                    (exp[i] == ']' && temp != '[') ||
                    (exp[i] == '}' && temp != '{')) {
                    flag = 0;
                    break;
                }
            }
        }
        i++;
    }
    if(top>=0){
        flag=0;
    }
    if(flag==1){
        printf("\nValid");
    }
    else printf("\nInvalid");

}

void push(char ch){
    top++;
    st[top]=ch;
}

char pop(){
    char val;
    val=st[top];
    top--;
    return val;
}
