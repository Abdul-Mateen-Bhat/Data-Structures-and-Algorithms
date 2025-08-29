#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

Node* root = NULL;

void create_Tree()
{
    Node* p = NULL;
    Node* t = NULL;
    queue q;
    int x;

    create(&q);
    printf("Enter Root Value: ");
    scanf("%d",&x);

    root = (Node*)malloc(sizeof(Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);

    while(!is_empty(q)){

        p = dequeue(&q);

        printf("Enter left child of %d : ",p->data);
        scanf("%d",&x);

        if(x != -1){
            t = (Node*)malloc(sizeof(Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }

        printf("Enter right child of %d : ",p->data);
        scanf("%d",&x);

        if(x != -1){
            t = (Node*)malloc(sizeof(Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void preorder(Node* p)
{
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(Node* p)
{
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(Node* p)
{
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void Iterative_preorder(Node* p)
{
    stack st;
    stackcreate(&st);

    while(p != NULL || !stack_is_empty(st)){
        if(p != NULL){
            printf("%d ",p->data);
            push(&st,p);
            p = p->lchild;
        }
        else{
            p = pop(&st);
            p=p->rchild;
        }
    }
}

void Iterative_inorder(Node* p)
{
    stack st;
    stackcreate(&st);

    while(p != NULL || !stack_is_empty(st)){
        if(p != NULL){
            push(&st,p);
            p = p->lchild;
        }
        else{
            p = pop(&st);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}

void level_order_traversal(Node* p)
{
    queue q;
    create(&q);

    printf("%d ",p->data);
    enqueue(&q,p);
    while(!is_empty(q)){
        p = dequeue(&q);
        if(p->lchild != NULL){
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild != NULL){
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}

int count(Node* p)
{
    int x,y;
    if(p != NULL){
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int height(Node* p)
{
    int x,y;
    if(p!=NULL){
        x = height(p->lchild);
        y = height(p->rchild);
        return (x>y)?x+1:y+1; //returning max(x,y) + 1
    }
    return 0;
}

int main()
{
    create_Tree();
    printf("Level Order Traversal: ");
    printf("Count: %d\nHeight: %d",count(root),height(root));
    return 0;
}


//Stack.h
/*#ifndef Stack_h
#define Stack_h

#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

typedef struct{
    int size;
    int top;
    Node** s;
}stack;

void stackcreate(stack *st)
{
    printf("\nEnter size of stack: ");
    scanf("%d",&st->size);
    st->s = (Node**)malloc(sizeof(Node*)*st->size);
    st->top = -1;
}


int stack_is_full(stack st)
{
    if(st.top == st.size-1)
        return 1;
    else
        return 0;
}

int stack_is_empty(stack st)
{
    if(st.top == -1)
        return 1;
    else
        return 0;
}


void stack_display(stack st)
{
    int i;
    for(i=st.top;i>=0;i--){
        printf("\n%p",st.s[i]);
    }
}

void push(stack* st,Node* x)
{
    if(stack_is_full(*st))
    {
        printf("\nStack Overflow!!");
        return ;
    }

    st->top++;
    st->s[st->top] = x;

}

Node* pop(stack* st)
{
    Node* x = NULL;
    if(stack_is_empty(*st))
        printf("\nStack Underflow!!\n");

    x = st->s[st->top];
    st->top--;

    return x;

}
#endif // Stack_h
*/


//Queue.h
/*
#ifndef Queue_h
#define Queue_h


#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* lchild;
    int data;
    struct Node* rchild;
}Node;

typedef struct{
    int size;
    int rear;
    int front;
    Node** Q;
}queue;


void create(queue* q)
{
    printf("\nEnter size of the queue: ");
    scanf("%d",&q->size);
    q->Q = (Node**)malloc(q->size*(sizeof(Node*)));
    q->rear = q->front = 0;
}


int is_empty(queue q)
{
    return (q.rear==q.front)?1:0;
}

int is_full(queue q)
{
    return ((q.rear+1)%q.size)==q.front ? 1 : 0;
}

void enqueue(queue* q,Node* x)
{
    if(is_full(*q)){
        printf("\nQueue is Full!!");
        return;
    }
     q->rear = (q->rear+1)%q->size;
     q->Q[q->rear] = x;
}

Node* dequeue(queue* q)
{
    Node* x = NULL;
    if(is_empty(*q)){
        printf("\nQueue empty!!");
        return x;
    }
    q->front= (q->front+1)%q->size ;
    x = q->Q[q->front];
    return x;
}

#endif // Queue
*/








