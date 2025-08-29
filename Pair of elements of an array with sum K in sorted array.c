#include<stdio.h>

int main()
{
    int A[] = {1,3,4,5,6,8,9,10};
    int size = 8,k=10;
    int i=0,j=size-1;

    //Method-1
    while(i<j)
    {
        if(A[i] + A[j] == k){
            printf("(%d,%d)",A[i],A[j]);
            i++;j--;
        }
        else if(A[i] + A[j] < 10)
            i++;
        else
            j--;
    }

    //Method-2
    for(i=0,j=size-1;i<j;){
        if(A[i] + A[j] == k){
            printf("(%d,%d)",A[i],A[j]);
            i++;j--;
        }
        else if(A[i] + A[j] < 10)
            i++;
        else
            j--;
    }

    return 0;
}
