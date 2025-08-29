#include<stdio.h>

int main()
{
    int A[] = {5,4,6,7,4,8,5,8,3,5,6,8,9,3};
    int size = 14,i,j,count;

    for(i=0;i<size-1;i++)
    {
        count = 1; //A[i] present once so far
        if(A[i] != -1)
        {
           for(j=i+1;j<size;j++){
                if(A[i] == A[j])
                {
                    count++;
                    A[j] = -1; // in future we will skip if element is -1 in the array
                            // it will avoid checking duplicates of previously checked elements
                }
            }

        if(count > 1)
            printf("%d is Repeating %d times.\n",A[i],count);
        }

    }
    return 0;
}
