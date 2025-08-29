#include<stdio.h>

void swap(int* x,int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void insert(int A[],int n)//n->last index of array upto which heap is to be created
{
    int temp = A[n]; //A[n] -> newly inserted element
    int i=n;

    while(i>1 && temp > A[i/2]){ //i>1 -> 1 based indexing ... i/2 -> parent element
        A[i] = A[i/2];
        i= i/2;
    }

    A[i] = temp;

}

int delete(int A[],int n)
{
    int temp,i,j;
    temp = A[1]; //root to be deleted stored in temporary variable

    swap(&A[1],&A[n]);//Swapping root with last element of heap
    i=1;
    j=2*i;//left child of root

    while(j<n-1){

        if(A[j+1] > A[j]){
            j++;//right child
        }
        if(A[i] < A[j]){
            swap(&A[i],&A[j]);

            i=j;
            j=2*i;
        }
        else
            break;
    }

    return temp;
}

void HeapSort(int A[],int n)
{
    for(int i=n;i>=2;i--){
        delete(A,i);
    }
}

void Heapify(int A[],int n)
{
    int i,j;
    for(i=n/2;i>=1;i--){

        j=2*i;

        while(j<n){
            if(A[j+1] > A[j])
                j++;
            if(A[i] < A[j]){
                swap(&A[i],&A[j]);
                i=j;
                j=2*i;
            }
            else{
                break;
            }
        }
    }
}

int main()
{
    int H[] = {0,10,20,30,25,5,40,35};
    int size = sizeof(H)/sizeof(H[0]) - 1; //-1 due to 1-based indexing

    Heapify(H,size);

    for(int i=1;i<=size;i++){
        printf("%d ",H[i]);
    }




    return 0;
}
