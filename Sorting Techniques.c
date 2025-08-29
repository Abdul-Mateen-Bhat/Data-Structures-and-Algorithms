#include<stdio.h>
#include<stdlib.h>
void swap(int* x,int* y)
{
    int temp = *x;
    *x=*y;
    *y=temp;
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void BubbleSort(int arr[],int n)
{
    int flag;

    // Outer loop - controls number of passes through array (i<n-1 because we need n-1 passes max)
    for(int i=0;i<n-1;i++){
        flag = 0; // Reset flag to check if any swaps occurred

        // Inner loop - compares adjacent elements (j<n-1-i because largest elements bubble to end)
        for(int j=0;j<n-1-i;j++){
            // Swap if current element is greater than next element
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag = 1; // Mark that a swap occurred
            }
        }

        // If no swaps occurred, array is already sorted
        if(flag == 0)
            break;
    }
}

void InsertionSort(int arr[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++){
        x = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>x){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}

void SelectionSort(int arr[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i;j<n;j++){
            if(arr[j] < arr[k])
                k=j;
        }
        swap(&arr[i],&arr[k]);
    }
}

int partition(int arr[],int low,int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(i<j){
        while(i<=high && arr[i] <= pivot)i++;
        while(j>= low && arr[j] > pivot)j--;
        if(i<j)
            swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void QuickSort(int arr[],int low,int high)
{
    if(low < high){
        int pivotIndex = partition(arr,low,high);
        QuickSort(arr,low,pivotIndex-1);
        QuickSort(arr,pivotIndex+1,high);
    }
}

void merge(int A[],int low,int mid,int high)
{
    int i,j,k;
    i=k=low;
    j=mid+1;

    int B[high +1];


    while(i<=mid && j<=high){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];

    }

    while(i<=mid)
        B[k++] = A[i++];
    while(j<=high)
        B[k++] = A[j++];

    for(i=low;i<=high;i++)
        A[i] = B[i];


}

void ItertiveMergeSort(int A[],int n)
{
    int p,i,l,mid,h;
    for(p=2; p<=n; p=p*2){
        for(i=0; i+p-1 < n;i=i+p){
            l = i;
            h = i+p-1;
            mid = (l + h) / 2;
            merge(A,l,mid,h);
        }
    }
    if(p/2 < n)
        merge(A,0,p/2-1,n-1);
}

void RecursiveMergeSort(int A[],int low,int high)
{
    if(low<high){
        int mid = (low+high)/2;
        RecursiveMergeSort(A,low,mid);
        RecursiveMergeSort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}

int findMax(int A[],int n)
{
    int max = A[0];
    for(int i=1;i<n;i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

void CountSort(int A[],int n)
{
    int max = findMax(A,n);
    int i,j;
    int* C = (int*)malloc(sizeof(int)*(max+1)); //max = 15 -> max + 1=16 -> C[16] -> last index 15

    for(i=0;i<max+1;i++)
        C[i] = 0;

    for(i=0;i<n;i++){
        C[A[i]]++;
    }

    i=j=0;
    while(j<n){
        if(C[i] > 0){
            A[j++] = i;
            C[i]--;
        }
        else
            i++;
    }

    free(C);
}

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void insert(Node** bin,int idx)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = idx;
    temp->next = NULL;

    if(bin[idx] == NULL)
        bin[idx] = temp;

    else{
        Node* p = bin[idx];
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

int delete(Node** bin,int idx)
{
    Node* p = bin[idx];
    bin[idx] = bin[idx]->next;
    int x = p->data;
    free(p);
    return x;
}

void BinSort(int A[],int n)
{
    int max = findMax(A,n);
    Node** bin;
    int i,j;

    bin = (Node**)malloc(sizeof(Node*)*(max+1));
    for(i=0;i<max+1;i++)
        bin[i] = NULL;

    for(i=0;i<n;i++){
        insert(bin,A[i]);
    }

    i=j=0;

    while(j<n){
        if(bin[i] != NULL){
            A[j++] = delete(bin,i);
        }else
            i++;
    }


    free(bin);
}


void ShellSort(int A[], int n) {
    int gap, i, j, temp;

    // Start with large gap, then reduce it
    for (gap = n / 2; gap >= 1; gap /= 2) {

        // Perform gapped insertion sort
        for (i = gap; i < n; i++) {
            temp = A[i]; // Store current element
            j = i;

            // Shift earlier gap-sorted elements until correct position found
            while (j >= gap && A[j - gap] > temp) {
                A[j] = A[j - gap];
                j = j - gap;
            }

            // Place temp at its correct location
            A[j] = temp;
        }
    }
}



int main()
{

    int arr[] = {8,7,6,5,4,3,2,1,0};
    int n = sizeof(arr)/sizeof(int);

    ShellSort(arr,n);
    print(arr,n);


    return 0;
}
