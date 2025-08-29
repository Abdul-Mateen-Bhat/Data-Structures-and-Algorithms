#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int* A; //pointer to an array
    int size; //total size of the array
    int length; //no of elements in the array(occupied spaces)
}array;

void swap(int* x,int* y);
void Display(array* arr);
void append(array* arr);
void insert(array* arr);
void delete(array* arr);
void linear_search(array* arr);
void binary_search(array* arr);
int Recursive_binary_search(array* arr,int low,int high,int key);
int get(array* arr,int index);
void set(array* arr,int index,int x);
int max(array* arr);
int min(array* arr);
int sum(array* arr);
void reverse1(array* arr);
void reverse2(array* arr);
void insert_in_sorted(array* arr,int x);
int check_sorted(array* arr);
void rearrange(array* arr);
array merge(array* arr1,array* arr2);
array Union(array* arr1,array* arr2);
array Intersection(array* arr1,array* arr2);
array Difference(array* arr1,array* arr2);


int main()
{
//    int temp[] = {2,6,10,15,25};
//    array ARR1 = {temp,10,5};
//
//    int t[] = {3,6,7,15,20};
//    array ARR2 = {t,10,5};

    array arr;
    printf("Enter size: ");
    scanf("%d",&arr.size);

    arr.A = (int*)malloc(arr.size * sizeof(int));

    int n,i;
    printf("Enter length: ");
    scanf("%d",&n);

    arr.length = n;

    for(i=0;i<n;i++){
        printf("arr[%d] = ",i);
        scanf("%d",&arr.A[i]);
    }

//    Display(&ARR1);
//    Display(&ARR2);
//    array result = Difference(&ARR1,&ARR2);
//    Display(&result);



    return 0;

}

array Union(array* arr1,array* arr2)
{
    array result;
    result.A = (int*)malloc(sizeof(int)*(arr1->length + arr2->length));

    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length) //when any of the 2 arrays get fully used we get out of this loop and directly copy the remaining elements of the other array in result
    {
        if(arr1->A[i] < arr2->A[j])
            result.A[k++] = arr1->A[i++];

        else if(arr1->A[i] > arr2->A[j])
            result.A[k++] = arr2->A[j++];

        else if(arr1->A[i] == arr2->A[j]) //single copy of common elements
            {
                result.A[k++] = arr1->A[i++]; //copy from either of the two arrays
                j++; //incrementing both indicies but copying only 1 element
            }
    }

    //copying remaining elements
    for(i;i<arr1->length;i++)
        result.A[k++] = arr1->A[i];
    for(j;j<arr2->length;j++)
        result.A[k++] = arr2->A[j];

    result.length = k; //length will be smaller or equal to the sum of lengths
                        // length = k because length = final index +1

    return result;
}

array Intersection(array* arr1,array* arr2)
{
    array result;
    result.A = (int*)malloc(sizeof(int)*(arr1->length + arr2->length));

    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length) //when any of the 2 arrays get fully used we get out of this loop and directly copy the remaining elements of the other array in result
    {
        if(arr1->A[i] < arr2->A[j]) i++;

        else if(arr1->A[i] > arr2->A[j]) j++;

        else if(arr1->A[i] == arr2->A[j])
            {
                result.A[k++] = arr1->A[i++];
                j++;
            }
    }

    result.length = k;

    return result;
}

array Difference(array* arr1,array* arr2)
{
    array result;
    result.A = (int*)malloc(sizeof(int)*(arr1->length + arr2->length));

    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length) //when any of the 2 arrays get fully used we get out of this loop and directly copy the remaining elements of the other array in result
    {
        if(arr1->A[i] < arr2->A[j])
            result.A[k++] = arr1->A[i++];

        else if(arr1->A[i] > arr2->A[j]) j++;

        else{j++;i++;}
    }

    //copying remaining elements only from arr1
    for(i;i<arr1->length;i++)
        result.A[k++] = arr1->A[i];


    result.length = k;

    return result;
}

array merge(array* arr1,array* arr2)
{
    array result;
    result.A = (int*)malloc(sizeof(int)*(arr1->length + arr2->length));
    result.length = arr1->length + arr2->length;

    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length) //when any of the 2 arrays get fully used we get out of this loop and directly copy the remaining elements of the other array in result
    {
        if(arr1->A[i] < arr2->A[j])
            result.A[k++] = arr1->A[i++];
        else
            result.A[k++] = arr2->A[j++];
    }
    for(i;i<arr1->length;i++)
        result.A[k++] = arr1->A[i];
    for(j;j<arr2->length;j++)
        result.A[k++] = arr2->A[j];

    return result;
}


void insert_in_sorted(array* arr,int x)
{
    if(arr->length < arr->size)
    {
        int i;
        for(i=arr->length-1;arr->A[i]>x && i>=0 ;i--)
            arr->A[i+1] = arr->A[i];
        arr->A[++i] = x; //i will decrement one extra time we need to increment it
        arr->length++;
        printf("\nLength: %d",arr->length);
    }
    else{
        printf("\nArray already full!");
    }
}

int check_sorted(array* arr)
{
    int i;
    for(i=0;i<arr->length-1;i++){
        if(arr->A[i] > arr->A[i+1])
            return 0; //false
    }
    return 1; //true
}

void rearrange(array* arr)
{
    int i=0,j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>=0){j--;}
        if(i<j)
        {
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}

void reverse1(array* arr)
{
    int* B =(int*)malloc(sizeof(int)*(arr->length));
    int i,j;
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j] = arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i] = B[i];
}

void reverse2(array* arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int get(array* arr,int index)
{
    if(index>=0 && index<arr->length)
        return arr->A[index];
    return -1;
}

void set(array* arr,int index,int x)
{
    if(index>=0 && index<arr->length)
        arr->A[index] = x;
    else
        printf("\nInvalid Index!");

}
int max(array* arr)
{
    int i,max = arr->A[0];
    for(i=1;i<arr->length;i++){
        if(arr->A[i] > max)
            max = arr->A[i];
    }
    return max;
}

int min(array* arr)
{
    int i,min = arr->A[0];
    for(i=1;i<arr->length;i++){
        if(arr->A[i] < min)
            min = arr->A[i];
    }
    return min;
}

int sum(array* arr)
{
    int total = 0;
    int i;
    for(i=0;i<arr->length;i++){
        total += arr->A[i];
    }
    return total;
}

int Recursive_binary_search(array* arr,int low,int high,int key)
{
    if(low<=high)
    {
        int mid = (low+high)/2;
        if(key == arr->A[mid])
            return key;
        else if(key < arr->A[mid])
            return Recursive_binary_search(arr,low,mid-1,key);
        else
            return Recursive_binary_search(arr,mid+1,high,key);
    }
    return -1;
}


void binary_search(array* arr)
{
    int low=0, high=arr->length-1;

    int key;
    printf("\nEnter Key: ");
    scanf("%d",&key);

    while(low <= high)
    {
        int mid = (low+high)/2;
        if(key == arr->A[mid])
        {
            printf("\nElement %d found at %d",key,mid);
            return;
        }
        else if(key < arr->A[mid])
            high = mid - 1;
        else
            low = mid +1;
    }
    printf("\nKey not found!");
}


void linear_search(array* arr)
{
    int i,key;
    printf("\nEnter Key: ");
    scanf("%d",&key);
    for(i=0;i<arr->length;i++){
        if(arr->A[i] == key){
            printf("\nElement %d found at %d",key,i);
            return;
        }
    }
    printf("\nKey not found!");
}


void delete(array* arr)
{
    int index;
    printf("\nEnter Index: ");
    scanf("%d",&index);
    if(index>=0 && index < arr->length)
    {
        int i;
        for(i=0;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
    else{printf("\nIndex exceeds array size");}
}

void insert(array* arr)
{
    if(arr->length < arr->size)
    {
        int index;
        printf("\nEnter index: ");
        scanf("%d",&index);
        if(index>=0 && index < arr->length)
        {
            int i,x;
            printf("\nEnter number to be inserted: ");
            scanf("%d",&x);

            for(i=arr->length;i>index;i--){
                arr->A[i] = arr->A[i-1];
            }
            arr->A[i] = x;
            arr->length++;
            printf("after insertion length: %d",arr->length);
        }
        else{printf("\nIndex exceeds array size!");}

    }
    else{printf("\nArray already full!");}


}

void append(array* arr)
{
    if(arr->length < arr->size)
    {
        int x;
        printf("\nEnter number to be added: ");
        scanf("%d",&x);
        arr->A[arr->length] = x;
        arr->length++;
        printf("after appending length: %d",arr->length);

    }
    else{printf("\nArray already full!");}
}

void Display(array* arr)
{
    int i;
    printf("\nArray Elements: ");
    for(i=0;i<arr->length;i++){
        printf("%d ",arr->A[i]);
    }
}

void swap(int* x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}














