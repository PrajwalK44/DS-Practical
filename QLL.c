//Queue using Linked List
#include<stdio.h>
#include<malloc.h>
//enqueue
//dequeue
//peek
//display

struct node{
    int data;
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;

void enqueue(int);
int dequeue();
int peek();
void display();

int main(){
    int opt, val;
    do{
        printf("\n--MAIN MENU---");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Peek");
        printf("\n4.Display");

        printf("\nEnter your option");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("\nEnter the value to enter in Queue");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                val=dequeue();
                printf("\nThe dequeued value is %d",val);
                break;
            case 3:
                val=peek();
                printf("\nElement at the front of the queue is %d-",val);
                break;
            case 4:
                display();
                break;
            default:
                break;
        }
    }while(opt!=5);
}

//enqueue
void enqueue(int val){
    struct node* nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->next=NULL;
    if(front==NULL){
        front=nn;
        rear=nn;
    }
    else{
        rear->next=nn;
        rear=nn;
    }
}

//dequeue
int dequeue(){
    struct node* ptr;
    int x=-1;
    if(front==NULL){
        printf("\nUnderflow");
    }
    else{
        ptr=front;
        x=front->data;
        front=front->next;
        free(ptr);
    }
    return x;
}

//peek
int peek(){
    if(front==NULL){
        printf("\nStack is empty");
        return 0;
    }
    else{
        return front->data;
    }
}

void display(){
    struct node* ptr;
    ptr=front;
    if(front==NULL){
        printf("\nStack is empty");
        return;
    }
    else{
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
