#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

//insert
//traversals
struct node* tree=NULL;

void insert(int key){

    struct node* nn,*ptr, *temp;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=key;
    nn->left=NULL;
    nn->right=NULL;
    ptr=tree;
    //1. if nothing is there
    if(tree==NULL){
        tree=nn;
    }

    //2. finding the parent
        while(ptr!=NULL){
            temp=ptr;
            if(key==ptr->data){
                return;
            }
            else if(key<ptr->data){
                ptr=ptr->left;
            }
            else if(key>ptr->data){
                ptr=ptr->right;
            }
        }

    //3.finally isnerting
    if(key > temp->data){
        temp->right=nn;
    }
    else if(key < temp->data){
        temp->left=nn;
    }

}
void inorder(struct node* r){

    if(r){
        inorder(r->left);
        printf("%d",r->data);
        inorder(r->right);
    }
}
/*void preorder(struct node* r);
void postorder(struct node* r);
*/

int main(){

    int key, opt;

    do{
    printf("\nMain Menu");
    printf("\n1.Insert");
    printf("\n2.Inorder Traversal");
    printf("\n3.Preorder Traversal");
    printf("\n4.Postorder Traversal");

    printf("\nEnter your option");
    scanf("%d",&opt);

    switch(opt){
        case 1:
            printf("\nEnter an element");
            scanf("%d",&key);
            insert(key);
            break;
        case 2:
            inorder(tree);
            break;
        case 3:
            //preorder(tree);
            break;
        case 4:
            //postorder(tree);
            break;
        default:
            printf("\nWrong Input");
            break;
    }

    }while(opt!=5);

}
