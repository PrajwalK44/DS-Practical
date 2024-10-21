#include<stdio.h>
#define MAX 10
int q[MAX];
int front=-1;
int rear=-1;

void enqueue(int);
int dequeue();
void display();

int main(){
    int opt, val;
    do{
        printf("\n--MAIN MENU---");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");

        printf("\n3.Display");

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
                display();
                break;
            default:
                break;
        }
    }while(opt!=5);
}

void enqueue(int val){
    if((rear==MAX-1 && front==0 ) || rear==front-1 ){
        printf("\nOverflow");
        return;
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
    }
    else if(rear==MAX-1 && front!=0){
        rear=0;
    }
    else{
        rear++;
    }
    q[rear]=val;
}

int dequeue(){
    int val=-1;
    if(front==-1 && rear==-1){
        printf("\nUnderflow");
        return -1;
    }
    val=q[front];
    if (front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==MAX-1){
        front=0;
    }
    else{
        front++;
    }
    return val;
}

void display(){
    if(front==-1 && rear==-1){
        printf("\nEmpty Queue");
        return;
    }
    else{
        if(front<=rear){
            for(int i=front; i<=rear; i++){
                printf("%d",q[i]);
            }
        }
        else{
            for(int i=front; i<=MAX; i++){
                printf("%d",q[i]);
            }
            for(int i=0; i<=rear; i++){
                printf("%d",q[i]);
            }
        }
    }
}
