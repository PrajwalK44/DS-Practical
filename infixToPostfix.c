#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20

char st[MAX];
int top=-1;

void push(char c);
char pop();
void InfixToPostfix(char source[], char target[]);
int getPriority(char op);

int main(){
    char infix[100], postfix[100];
    printf("\nEnter an infix expression- ");
    gets(infix);
    strcpy(postfix, "");
    InfixToPostfix(infix, postfix);
    printf("Postfix expression- ");
    puts(postfix);
    return 0;
}

void InfixToPostfix(char source[], char target[]){
    int i=0;
    int j=0;
    char temp;
    strcpy(target, "");
    while(source[i]!='\0'){
        if(source[i]=='('){
            push(source[i]);
            i++;
           }
        else if(source[i]==')'){
            while(top!=-1 && st[top]!='('){
                    target[j]=pop();
                    j++;
            }
            if(top==-1){
                printf("\nInvalid Expression");
                exit(1);
            }
            temp=pop();
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i])){
            target[j]=source[i];
            j++;
            i++;
        }
        else if(source[i]=='+' || source[i]=='-' || source[i]=='*' || source[i]=='/' || source[i]=='%'){
            while((top!=-1)&&(st[top]!='(')&& getPriority(st[top])>=getPriority(source[i])){
                    target[j]=pop();
                    j++;
                  }
                  push(source[i]);
                  i++;
        }
        else{
            printf("\nIncorrect expression");
            exit(1);
        }

    }

    while((top!=-1)&&st[top]!='('){
            target[j]=pop();
            j++;
          }
    target[j]='\0';

}

int getPriority(char op){
    if(op=='*' || op=='/'|| op=='%'){
        return 1;
    }
    else if(op=='+'|| op=='-'){
        return 0;
    }
}

void push(char r){
    if(top==MAX-1){
        printf("\nOverflow");
        return;
    }
    else{
        top++;
        st[top]=r;
    }
}

char pop(){
    char val;
    if(top==-1){
        printf("\nUnderflow");
        return '\0';
    }else{
    val=st[top];
    top--;
    return val;
    }
}

