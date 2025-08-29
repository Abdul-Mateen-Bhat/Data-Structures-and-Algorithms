#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int* A; //pointer to an array
    int size; //total size of the array
    int length; //no of elements in the array(occupied spaces)

}array;

void Display(array arr);

int main()
{
    array arr;
    printf("Enter size: ");
    scanf("%d",&arr.size);

    arr.A = (int*)malloc(arr.size * sizeof(int));

    int n,i;
    printf("Enter length: ");
    scanf("%d",&n);

    arr.length = n;

    for(i=0;i<n;i++){
        printf("arr[i] = ",i);
        scanf("%d",&arr.A[i]);
    }

    Display(arr);

    return 0;

}

void Display(array arr)
{
    int i;
    printf("Array Elements: ");
    for(i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}
