#include<stdio.h>
int main()
{
    int A[] = {100,99,54,23,5,63,4,23,2};
    int n = sizeof(A)/sizeof(int);

    int i,max = A[0],max2=A[0];

    for(i=0;i<n;i++){
        if(A[i] > max)
            max = A[i];
    }

    if(max2 == max)
        max2 = A[1];

    for(i=0;i<n;i++){
        if(A[i] == max)
            continue;
        if(A[i] > max2)
            max2 = A[i];
    }
    printf("Max: %d Max2: %d",max,max2);
    return 0;

}
