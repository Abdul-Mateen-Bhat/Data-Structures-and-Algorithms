#include<stdio.h>
int main()
{
    int A[]={3,6,6,7,9,9,9,10,10,10,10};
    int size = 11,i,j;

    for(i=0;i<size-1;i++){
            if(A[i] == A[i+1])
            {
                j = i+1;
                while(A[i] == A[j]){j++;} //j will finally be at the next distinct element
                printf("%d is Repeating %d times.\n",A[i],j-i); //j - i will give total no. of copies
                i = j-1; //because i will increment one more time after exiting this if block
                        //i will be at last duplicate copy
            }
    }
    return 0;
}
