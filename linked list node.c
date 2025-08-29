#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};

int main()
{
    struct Node p;
    printf("%d ",sizeof(p.data));
    printf("\n%d ",sizeof(p.next));
    printf("\n%d ",sizeof(p));
    return 0;
}
