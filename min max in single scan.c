#include<stdio.h>
int main()
{
    int A[] = {1,2,-3,3,23,-12,32,5,5,3,-12};
    int n = sizeof(A)/sizeof(int),max,min,i;

    max=min=A[0];

    for(i=0;i<n;i++){ //either the element can be min or max
                      //so we only check one of the cases thats why if and else if
        if(A[i] < min)
            min = A[i];
        else if(A[i] > max)
            max = A[i];
    }
    printf("Min: %d \nMax: %d",min,max);

    return 0;
}
