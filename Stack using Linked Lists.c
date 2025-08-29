#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* Top = NULL;

void display();
void push(int x);
int pop();
int peek(int pos);
int stackTop();
int is_full();
int is_empty();

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    display();
    printf("\nTop element: %d",stackTop());

    int pos;
    printf("\nEnter a position to peek at: ");
    scanf("%d",&pos);
    printf("Peeking at position %d: %d",pos,peek(pos));
    return 0;
}

void display()
{
    Node* p = Top;
    while(p){
        printf("\n%d",p->data);
        p=p->next;
    }
}


void push(int x)
{
    if(is_full()){
        printf("\nStack Overflow!!");
        return;
    }
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->next = Top;
    Top = t;
}

int pop()
{
    int x = -1;
    if(is_empty()){
        printf("\nStack Underflow!!");
        return x;
    }
    Node* p = Top;
    Top = Top->next;
    x = p->data;
    free(p);
    return x;
}

int peek(int pos)
{
    if(pos < 1){
        printf("\nInvalid Index\n");
        return -1;
    }
    int i;
    Node* p = Top;
    for(i=1;(p!=NULL) && (i<pos);i++){
        p=p->next;
    }
    if(p==NULL){
        printf("\nInvalid Index\n");
        return -1;
    }

    return p->data;
}

int stackTop()
{
    if(is_empty()){
        printf("\nStack Empty!");
        return -1;
    }
    return Top->data;
}

int is_full()
{
    Node* t = (Node*)malloc(sizeof(Node));
    int r = t?0:1;
    free(t);
    return r;
}

int is_empty()
{
    return (Top==NULL)?1:0;
}
