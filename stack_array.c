#include<stdio.h>
#define MAX 10
int st[MAX];
int top=-1;


void push(int val);
int pop();
int peek();
void display();

int main(){

    int val,opt;
    do{
        printf("\n----MAIN MENU---");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.PEEK");
        printf("\n4.DISPLAY");
        printf("\n5.Exit");

        printf("\nEnter your option -");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("\nEnter the value to push on the stack");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
                val=pop();
                printf("The value popped from the stack is %d",val);
                break;
            case 3:
                val=peek();
                printf("The value present at the top of the stack is %d",val);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nThank You");
                break;

            default:
                printf("\nWrong Input");

        }
    }while(opt!=5);

}

void push(int val){
    if(top==MAX-1){
        printf("\nOverflow");
        return;
    }
    else{
        top++;
        st[top]=val;
    }
}

int pop(){
    int x=-1;
    if(top==-1){
        printf("\nUnderflow");
        return 0;
    }
    else{
        x=st[top];
        top--;
    }
    return x;
}

int peek(){

    if(top==-1){
        printf("\nEmpty stack");
        return -1;
    }
    else{
        return (st[top]);
    }
}

void display(){
    if(top==-1){
        printf("\nStack is empty");
        return;
    }
    else{
        for(int i=top; i>=0; i--){
            printf("\n%d",st[i]);
        }
    }
}
