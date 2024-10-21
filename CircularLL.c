#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_ll()
{
    struct node *nn, *ptr;
    int val;
    printf("Enter -1 to end.\n");
    printf("Enter the data : ");
    scanf("%d", &val);

    while (val != -1)
    {
        nn = (struct node *)malloc(sizeof(struct node));
        nn->data = val;
        nn->next = NULL;

        if (start == NULL)
        {

            start = nn;
            nn->next = start;
        }
        else
        {

            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = nn;
            nn->next = start;
        }

        printf("Enter the data : ");
        scanf("%d", &val);
    }

    return start;
}


struct node *insert_beg()
{
    struct node *nn,*ptr;
    int val;
    printf("Enter the data to be inserted in beg : \n");
    scanf("%d",&val);

    nn =(struct node *)malloc(sizeof(struct node));
    nn -> data = val;

    ptr = start;
    while(ptr->next!=start)
    {
        ptr = ptr->next;
    }
    ptr -> next = nn;
    nn -> next = start;
    start = nn;
    return start;
}

struct node *insert_end()
{
    struct node *nn,*ptr;
    int val;
    printf("Enter the data to be inserted in end : \n");
    scanf("%d",&val);

    nn =(struct node *)malloc(sizeof(struct node));
    nn -> data = val;

    ptr = start;
    while(ptr->next!=start)
    {
        ptr = ptr->next;
    }
    ptr -> next = nn;
    nn -> next = start;
    return start;
}

struct node *insert_after()
{
    struct node *nn,*ptr,*temp;
    int val,num;
    printf("Enter the data to be inserted after a given node : \n");
    scanf("%d",&num);
    printf("Enter the data after which you wanna insert the data : ");
    scanf("%d",&val);

    nn =(struct node *)malloc(sizeof(struct node));
    nn -> data = num;

    ptr = start;
    temp = ptr;
    while(temp->data!=val)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    temp -> next = nn;
    nn -> next = ptr;
    return start;
}

struct node *insert_before()
{
    struct node *nn,*ptr,*temp;
    int val,num;
    printf("Enter the data to be inserted before a given node : \n");
    scanf("%d",&num);
    printf("Enter the data brfore which you wanna insert the data : ");
    scanf("%d",&val);

    nn =(struct node *)malloc(sizeof(struct node));
    nn -> data = num;

    ptr = start;
    temp = ptr;

    if(ptr->data == val)
    {
        insert_beg();
    }
    else
    {
        while(ptr->data!=val)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp -> next = nn;
        nn -> next = ptr;
    }
    return start;
}

struct node *del_beg()
{
    struct node *ptr;
    ptr = start;
    while(ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr -> next = start -> next;
    free(start);
    start = ptr->next;
    return start;
}

struct node *del_end()
{
    struct node *ptr,*temp;
    ptr = start;
    temp = ptr;
    while(ptr->next != start)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    temp -> next = ptr -> next;
    free(ptr);
    return start;
}

struct node *del_specific()
{
    struct node *ptr,*temp;
    int val;
    printf("enter the value to get deleted : \n");
    scanf("%d",&val);

    ptr = start;
    temp = ptr;
    if(ptr->data == val)
    {
        del_beg();
    }
    else
    {
        while(ptr->data!=val)
        {
            temp = ptr;
            ptr = ptr -> next;
        }
        temp -> next = ptr -> next;
    }
    free(ptr);
    return start;
}

struct node *del_after()
{
    struct node *ptr,*temp;
    int val;
    printf("enter the value after which you wanna the data to get deleted : \n");
    scanf("%d",&val);

    ptr = start;
    temp = ptr;
    while(temp->data!=val)
    {
        temp = ptr;
        ptr = ptr -> next;
    }
    temp -> next = ptr -> next;
    free(ptr);
    return start;
}

struct node *del_before()
{
    struct node *ptr,*temp;
    int val;
    printf("enter the value before which you wanna the data to get deleted : \n");
    scanf("%d",&val);

    ptr = start;
    temp = ptr;
    while(ptr->next->data!=val)
    {
        temp = ptr;
        ptr = ptr -> next;
    }
    temp -> next = ptr -> next;
    free(ptr);
    return start;
}

struct node *display()
{
    struct node *ptr;
    ptr = start;
    while(ptr->next!=start)
    {
        printf("%d",ptr->data);
        ptr = ptr->next;
    }
    printf("%d",ptr->data);
    return start;
}

void main()
{
    int choice;
    do
    {
        printf("---MAIN MENU---\n");
        printf("1.Create LL\n");
        printf("2.Insert_beg\n");
        printf("3.Insert_end\n");
        printf("4.Insert_after\n");
        printf("5.Insert_before\n");
        printf("6.Delete_beg\n");
        printf("7.Delete_end\n");
        printf("8.Delete_specific\n");
        printf("9.Delete_after\n");
        printf("10.Delete_before\n");
        printf("11.Display\n");
        printf("12.Exit\n");
        printf("What's your choice? ");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                create_ll();
                printf("LL created!");
                break;
            case 2:
                insert_beg();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                insert_after();
                break;
            case 5:
                insert_before();
                break;
            case 6:
                del_beg();
                break;
            case 7:
                del_end();
                break;
            case 8:
                del_specific();
                break;
            case 9:
                del_after();
                break;
            case 10:
                del_before();
                break;
            case 11:
                display();
                break;
            case 12:
                printf("Exit");
                break;
            default:
                printf("Invalid");
                break;
        }
    }while(choice!=12);
}
