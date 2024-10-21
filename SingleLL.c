#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* next;
};
struct node* start=NULL;

void create_LL();

void insert_beg_LL();
void insert_end_LL();
void insert_bef_LL();
void insert_after_LL();

struct node* delete_beg_LL();
struct node* delete_end_LL();
struct node* delete_bef_LL();
struct node* delete_after_LL();
struct node* delete_specnode_LL();

void search();

void display();

int main(){
    int val, opt;

    do{
        printf("\nMain Menu");
        printf("\n1. Create");
        printf("\n2. Insert at beginning");
        printf("\n3. Insert at end");
        printf("\n4. Insert at before a node");
        printf("\n5. Insert at after a node");
        printf("\n6. Delete at beginning");
        printf("\n7. Delete at end");
        printf("\n8. Delete at before");
        printf("\n9. Delete at after");
        printf("\n10. Delete at specific");

        printf("\n11. Display");

        printf("\nEnter your option");
        scanf("%d",&opt);

        switch(opt){
            case 1:
                create_LL();
                break;
            case 2:
                insert_beg_LL();
                break;
            case 3:
                insert_end_LL();
                break;
            case 4:
                insert_bef_LL();
                break;
            case 5:
                insert_after_LL();
                break;
            case 6:
                start=delete_beg_LL();
                break;
            case 7:
                start=delete_end_LL();
                break;
            case 8:
                start=delete_bef_LL();
                break;
            case 9:
                start=delete_after_LL();
                break;
            case 10:
                start=delete_specnode_LL();
                break;

            case 11:
                display();
                break;
        }
    }while(opt!=12);
}

void create_LL(){
    struct node* nn, *ptr;

    int val;
    printf("\nEnter the value (-1 to end)");
    scanf("%d",&val);
    while(val!=-1){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=val;
        nn->next=NULL;
        ptr=start;
        if(start==NULL){
            start=nn;
        }
        else{
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=nn;
        }
        printf("\nEnter the value (-1 to end)");
        scanf("%d",&val);
    }
}

void insert_beg_LL(){
    int data;
    printf("\n Enter data");
    scanf("%d",&data);
    struct node* nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=start;
    start=nn;
}

void insert_end_LL(){
    int data;
    printf("\n Enter data");
    scanf("%d",&data);
    struct node* nn, *ptr;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    ptr=start;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=nn;
}

void insert_bef_LL(){
    int data, val;
    printf("\n Enter data");
    scanf("%d",&data);
    printf("\nEnter the value before which you want to insert the data: ");
    scanf("%d", &val);
    struct node* nn, *ptr, *temp;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    ptr=start;
    temp=start;

    while(ptr->data!=val){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=nn;
    nn->next=ptr;
}

void insert_after_LL(){
    int data, val;
    printf("\n Enter data");
    scanf("%d",&data);
    struct node* nn, *ptr, *temp;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    ptr=start;
    temp=start;

    printf("\nEnter the value before which a node is to be inserted");
    scanf("%d",&val);
    while(temp->data!=val){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=nn;
    nn->next=ptr;
}

//delete
struct node* delete_beg_LL(){
    struct node* ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}

struct node* delete_end_LL(){
    struct node* ptr, *temp;
    ptr=start;
    while(ptr->next!=NULL){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    free(ptr);
    return start;
}

struct node* delete_specnode_LL(){
    struct node* ptr, *temp;
    int data;
    printf("\n Enter the value");
    scanf("%d",&data);
    ptr=start;
    while(ptr->data!=data){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    free(ptr);
    return start;
}

struct node* delete_bef_LL(){
    struct node* ptr, *temp, *pretemp;
    int data;
    printf("\n Enter the value");
    scanf("%d",&data);
    ptr=start;
    temp=start;
    pretemp=start;
    while(ptr->data!=data){
        pretemp=temp;
        temp=ptr;
        ptr=ptr->next;
    }
    pretemp->next=ptr;
    free(temp);
    return start;
}

struct node* delete_after_LL(){
    struct node* ptr, *temp;
    int data;
    printf("\n Enter the value");
    scanf("%d",&data);
    ptr=start;
    temp=start;
    while(temp->data!=data){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    free(ptr);
    return start;
}

void display(){
    struct node* ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
