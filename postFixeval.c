#include<stdio.h>
#include<ctype.h>
#define MAX 10

float st[MAX];
int top=-1;

void push(float val);
float pop();
float evaluratePS(char ans[]);

int main(){
    float fin;
    char postfix[100];
    printf("\n Enter a postfix expression");
    gets(postfix);
    fin=evaluratePS(postfix);
    printf("\nThe value is %f",fin);
}

float evaluratePS(char ans[]){
    int i=0;
    float val, op1, op2;
    while(ans[i]!='\0'){
        if(isdigit(ans[i])){
            push((float)(ans[i]-'0'));
        }
        else{
            op2=pop();
            op1=pop();
            switch(ans[i]){
                case '+':
                    val=op1+op2;
                    break;
                case '-':
                    val=op1-op2;
                    break;
                case '*':
                    val=op1*op2;
                    break;
                case '/':
                    val=op1/op2;
                    break;
                case '%':
                    val=(int)op1%(int)op2;
                    break;
            }
            push(val);

        }
        i++;

    }
    return st[top];
}

void push(float val){
    top++;
    st[top]=val;
}

float pop(){
    float val;
    val=st[top];
    top--;

    return val;
}
