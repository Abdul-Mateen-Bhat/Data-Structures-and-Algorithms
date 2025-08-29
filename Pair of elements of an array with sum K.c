#include<stdio.h>
int main()
{
    int A[] = {4,5,7,1,13,3,9,10,21};
    int size = 9,k=10,i,j;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if( (A[i] + A[j])== k )
                printf("(%d,%d)",A[i],A[j]);
        }
    }
    return 0;
}
