#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* start=NULL;

struct node* create_LL();
struct node* display_LL();

struct node* insert_beg_LL();
struct node* insert_end_LL();
struct node* insert_bef_LL();
struct node* insert_after_LL();

struct node* delete_beg_LL();
struct node* delete_end_LL();
struct node* delete_before_LL();
struct node* delete_after_LL();

int main(){
    int option;
    do{
        printf("\n---Main Menu-----");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Insert");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nEnter your option- ");
        scanf("%d",&option);

        switch(option){
            case 1:
                start=create_LL();
                printf("Linked List created");
                break;

            case 2:
                start=display_LL();
                break;

            case 3:
                {
                    int opt1;
                    do{
                        printf("\n1. Insert at the beginning");
                        printf("\n2. Insert at the end");
                        printf("\n3. Insert before a specified node");
                        printf("\n4. Insert after a specified node");
                        printf("\n5. Exit ");
                        printf("\nEnter your option- ");
                        scanf("%d",&opt1);
                        switch (opt1)
                        {
                        case 1:
                            start=insert_beg_LL();
                            break;
                        case 2:
                            start=insert_end_LL();
                            break;

                        case 3:
                            start=insert_bef_LL();
                            break;
                        case 4:
                            start=insert_after_LL();
                            break;
                        case 5:
                            printf("..........");
                            break;
                        default:
                            break;
                        }
                    }while(opt1!=5);

                }
                break;
                case 4:
                {
                    int opt2;
                    do{
                        printf("\n1. Delete at the beginning");
                        printf("\n2. Delete at the end");
                        printf("\n3. Delete a node before specified node");
                        printf("\n4. Delete a node after a specified node");
                        printf("\n5. Exit ");
                        printf("\nEnter your option- ");
                        scanf("%d",&opt2);
                        switch (opt2)
                        {
                        case 1:
                            start=delete_beg_LL();
                            break;
                        case 2:
                            start=delete_end_LL();
                            break;

                        case 3:
                            start=delete_before_LL();
                            break;
                        case 4:
                            start=delete_after_LL();
                            break;
                        case 5:
                            printf("..........");
                            break;
                        default:
                            break;
                        }
                    }while(opt2!=5);
                }
                break;

        }
    }while(option!=5);
}

struct node* create_LL(){
    struct node* nn, *ptr;
    int val;
    printf("Enter -1 to end ");
    printf("\nEnter data ");
    scanf("%d",&val);

    while(val!=-1)
    {
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=val;

        if(start==NULL){
        nn->next=NULL;
        nn->prev=NULL;
        start=nn;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=nn;
            nn->next=NULL;
            nn->prev=ptr;
        }

        printf("\nEnter data ");
        scanf("%d",&val);
    }
    return start;
}

void insert_beg_LL(){
    struct node* nn, *ptr;
    int data;
    printf("\nEnter data");
    scanf("%d",&data);
    ptr=start;

}



