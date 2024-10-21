#include<stdio.h>

struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;

void push(int val);
int pop();
int peek();
void display();

int main(){
    int val, opt;
    do{
        printf("\n--Main Menu---");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display");

        printf("\nEnter your choice- ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("\nEnter the value to be pushed on to the stack");
                scanf("%d",&val);
                push(val);
                break;

            case 2:
                val=pop();
                printf("\nThe value popped from the stack is %d",val);
                break;

            case 3:
                val=peek();
                printf("\nThe value present at the top of the stack is %d",val);
                break;

            case 4:
                display();
        }
    }while(opt!=5);
}

void push(int val){
    struct node* nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->next=NULL;
    if(top==NULL){
        top=nn;
    }
    else{
        nn->next=top;
        top=nn;
    }
}

int pop(){
    struct node* ptr;
    if(top==NULL){
        printf("\nUnderflow");
        return 0;
    }
    else{
        ptr=top;
        top=top->next;
        free(ptr);
        return top->data;
    }
}

int peek(){
    if(top==NULL){
        printf("\nStack is empty");
        return 0;
    }
    else{
        return top->data;
    }
}

 void display(){
    struct node* ptr;
    ptr=top;
    if(top==NULL){
        printf("\nStack is empty");
        return 0;
    }
    else{
        while(ptr!=NULL){
            printf("%d",ptr->data);
            ptr=ptr->next;
        }
    }
 }
