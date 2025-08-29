#include<stdio.h>

int main()
{
    int A[] = {1,2,3,5,6,7,8}; //first n natural numbers but 4 is missing
    int size = 7;
    int sum = 8*(8+1)/2; //n*(n+1)/1
    int i,s=0;
    for(i=0;i<size;i++){
        s += A[i];
    }

    printf("Missing element is %d",sum-s);
    return 0;
}
