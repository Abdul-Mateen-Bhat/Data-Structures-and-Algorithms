#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x)
{
    Node* t = (Node*)malloc(sizeof(Node));
    if(t == NULL){
        printf("\nStack Overflow!!");
        return;
    }

    t->data = x;
    t->next = NULL;

    if(front == NULL){
        front = rear = t;
    }
    else{
        rear->next = t;
        rear = t;
    }
}

int dequeue()
{
    int x = -1;
    if(front == NULL){
        printf("\nQueue is Empty!!");
        return x;
    }
    Node* p;
    p = front;
    front = front->next;
    x=p->data;
    free(p);

    return x;
}

void display()
{
    Node* p = front;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    display();
    return 0;
}
