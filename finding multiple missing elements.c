
#include<stdio.h>
int main()
{
    int A[] = {11,12,13,15,16,17,20,21}; //first n natural numbers but 14 is missing
    //index:    0  1  2  3  4  5  6  7
    //diff:     11 11 11 12 12 12 14 14
    int size = 8;

    int i,diff=A[0];

    printf("Missing Elements: ");
    for(i=0;i<size;i++){
        if(A[i]-i != diff)
        {
            while(diff < A[i]-i)
            {
                printf("%d ",i+diff);
                diff++;
            }
        }
    }

    return 0;
}
