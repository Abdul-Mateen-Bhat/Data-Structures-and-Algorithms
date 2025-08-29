#include<stdio.h>

typedef struct{
    int A[10];
    int n;  //order of the square matrix

}matrix;

void set(matrix* m,int i,int j,int x)
{
    if(i==j)
        m->A[i-1]=x; //in matrix(1,1)->first diagonal element
                  //in array 0 first index
}

int get(matrix* m,int i,int j)
{
    if(i==j) return m->A[i-1];
    else return 0; //all other elements 0
}

int display(matrix* m)
{
    int i,j;
    for(i=1;i<=m->n;i++){
        for(j=1;j<=m->n;j++){
            if(i==j) printf("%2d ",m->A[i-1]);
            else printf(" 0 ");
        }
        printf("\n");
    }
}

int main()
{
    matrix m;
    m.n=5;
    set(&m,1,1,5);set(&m,2,2,10);set(&m,3,3,15);
    set(&m,4,4,20);set(&m,5,5,25);
    display(&m);
    return 0;
}
