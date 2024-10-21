#include<stdio.h>
#define MAX 10

int st[MAX];
int top=-1;
void push(int val);
void display();

int main(){
    int d;
    printf("\nEnter a number");
    scanf("%d",&d);
    if(d==0){
        printf("%d",d);
    }
    while(d!=0){
        push(d%2);
        d/=2;
    }
    display();
}

void push(int val){
    top++;
    st[top]=val;
}
void display(){
    for(int i=top; i>=0; i--){
        printf("%d",st[i]);
    }
}
