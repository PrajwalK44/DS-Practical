//BFS//enqueue
//while
//dequeue
//printf
//in for for row
//enqueue
//visited as 1

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int n;
void BFS(int adj[][n], int v[], int start){

    int q[n];
    int r=-1, f=-1;
    int i;
    q[++r]=start;
    v[start]=1;
    while(r!=f){
        start=q[++f];
        printf("%c\t",start+65);
        for(i=0; i<n; i++){
            if(adj[start][i]==1 && v[i]==0){
                q[++r]=i;
                v[i]=1;
            }
        }
    }
}

int main(){

    int i,j,v[MAX]={0};

    printf("Enter the size of the matrix-");
    scanf("%d",&n);
    int adj[n][n];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d",&adj[i][j]);
        }
    }
    BFS(adj, v, 0);

}
