#include<stdio.h>
#include<stdlib.h>
int main()
{
    int A[] = {4,5,7,1,21,3,9,10,11};
    int high=21,low=1,size=9,k=10,i;

    int* H = (int*)calloc(high+1,sizeof(int));

    for(i=0;i<size;i++){
        if(H[k-A[i]] != 0 && A[i]<=k ){ //avoiding negative indexes k-A[i]>=0
            printf("(%d,%d)",A[i],k-A[i]);
        }
        H[A[i]]++;
    }

    return 0;
}

