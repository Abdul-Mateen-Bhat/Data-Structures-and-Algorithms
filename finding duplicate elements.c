#include<stdio.h>
int main()
{
    int A[]={3,6,6,7,9,9,9,10,10};
    int size = 9,i;
    int lastDup = 0;

    printf("Duplicates: ");
    for(i=0;i<size-1;i++){
        if(A[i] == A[i+1] && A[i] != lastDup){ //avoiding repeated printing if same duplicate
            printf("%d ");
            lastDup = A[i];
        }
    }
    return 0;
}
