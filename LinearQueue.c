#include<stdio.h>
#define MAX 10

int q[MAX];
int front=-1;
int rear=-1;

void enqueue(int);
int dequeue();
int peek();
void display();

int main(){
    int val, opt;
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

void enqueue(int val){
    if(rear==MAX-1){
        printf("\nOverflow");
        return;
    }
    else if (front==-1 && rear==-1){
        rear=front=0;
    }
    else{
        rear++;
    }
    q[rear]=val;
}

int dequeue(){
    int val=-1;
    if(front==-1 || front>rear){
        printf("\nUnderflow");
    }
    else{
        val=q[front];
        if(front>rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
    }
    return val;
}

int peek(){
    if(front==-1 && rear==-1 || front>rear){
        printf("\nEmpty Queue");
        return -1;
    }
    else{
        return q[front];
    }
}

void display(){

    if(front==-1 & rear==-1 || front>rear){
        printf("\nEmpty Queue");
        return ;
    }
    else{
        for(int i=front; i<=rear; i++){
            printf("%d",q[i]);
        }
    }
}


