#include<stdio.h>
#define SIZE 10

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");
}

int hash(int key)
{
    return key%SIZE;
}

int probe(int H[],int key)
{
    int index = hash(key);
    int i=0;

    while(H[(index+i)%SIZE] != 0)
        i++;

    return (index+i)%SIZE;
}

void insert(int H[],int key)
{
    int index = probe(H,key);
    H[index] = key;
}

int search(int H[],int key)
{
    int index = hash(key);

    int i=0;
    while(H[(index+i)%SIZE] != key)
        i++;

    return (index+i)%SIZE;

}

int main()
{
    int HT[SIZE] = {0};

    insert(HT,24);
    insert(HT,34);
    insert(HT,45);
    insert(HT,74);

    print(HT,SIZE);

    printf("%d ",search(HT,45));

    return 0;
}
