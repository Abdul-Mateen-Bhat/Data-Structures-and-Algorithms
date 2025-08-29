#include<stdio.h>
#include<stdlib.h>
int main()
{
    int A[] = {11,20,13,17,21,15,12,16};
    int high = 21,low =11,size = 8;
    int* H = (int*)calloc(high+1,sizeof(int)); //creating an array which has indexes upto high
                                                //calloc initializes to 0

    int i;
    for(i=0;i<size;i++){
        H[A[i]]++; //A's value is H's index.so incrementing at every index
    }

    for(i=low;i<=high;i++){
        if(H[i] == 0) //means A didn't have this index as its element
            printf("%d ",i);
    }

    return 0;
}
