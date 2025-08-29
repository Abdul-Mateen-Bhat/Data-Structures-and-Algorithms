#include<stdio.h>
#include<stdlib.h>
int main()
{
    int A[]={3,6,6,7,9,9,9,20,20,20,20};
    int size = 11,high=20,low=3,i;

    int* H =(int*)calloc(high+1,sizeof(int));

    for(i=0;i<size;i++){
        H[A[i]]++;
    }
    for(i=low;i<=high;i++){
        if(H[i] > 1)
        {
            printf("%d is Repeating %d times.\n",i,H[i]);
        }
    }
    return 0;
}
