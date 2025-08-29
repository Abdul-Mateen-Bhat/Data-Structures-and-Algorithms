#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int size;
    int rear;
    int front;
    int* Q;
}queue;

void create(queue* q);
void display(queue q);
int is_empty(queue q);
int is_full(queue q);
void enqueue(queue* q,int x);
int dequeue(queue* q);


int main()
{
    queue q;
    create(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    dequeue(&q);
    display(q);
    return 0;
}

void create(queue* q)
{
    printf("\nEnter size of the queue: ");
    scanf("%d",&q->size);
    q->Q = (int*)malloc(sizeof(int)*q->size);
    q->rear = q->front = -1;
}

void display(queue q)
{
    if(is_empty(q)){
        printf("\nQueue Empty!!");
        return;
    }
    printf("\nDisplaying Queue: ");
    q.front++;
    while(q.front <= q.rear){
        printf("%d ",q.Q[q.front++]);
    }
}

int is_empty(queue q)
{
    return (q.rear==q.front)?1:0;
}

int is_full(queue q)
{
    return (q.rear==q.size-1)?1:0;
}

void enqueue(queue* q,int x)
{
    if(is_full(*q)){
        printf("\nQueue is Full!!");
        return;
    }
     q->rear++;
     q->Q[q->rear] = x;
}

int dequeue(queue* q)
{
    int x = -1;
    if(is_empty(*q)){
        printf("\nQueue empty!!");
        return x;
    }
    q->front++;
    x = q->Q[q->front];
    return x;
}














































