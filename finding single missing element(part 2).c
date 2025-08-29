#include<stdio.h>
int main()
{
    int A[] = {11,12,13,15,16,17,18}; //first n natural numbers but 14 is missing
    //index:    0  1  2  3  4  5  6
    //diff:     11 11 11 12 12 12 12
    int size = 7;

    int i,diff=A[0]-0;//element - index

    for(i=0;i<size;i++){
        if(A[i]-i != diff)
        {
            printf("Missing Element is %d",i+diff);
            break;
        }
    }

    return 0;
}
