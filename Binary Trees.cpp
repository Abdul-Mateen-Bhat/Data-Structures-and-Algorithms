#include <iostream>
#include <stdio.h>
#include "QueueCpp.h"

using namespace std;

class Tree{
private:
    Node* root;
public:
    Tree(){root = NULL;}
    void TreeCreate();
    void preorder(){preorder(root);}
    void preorder(Node* p);
    void inorder(){inorder(root);}
    void inorder(Node* p);
    void postorder(){postorder(root);}
    void postorder(Node* p);
};

void Tree::TreeCreate()
{
    Node* p = NULL;
    Node* t = NULL;
    queue q(10);
    int x;

    printf("Enter Root Value: ");
    scanf("%d",&x);

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(!q.is_empty()){

        p = q.dequeue();

        printf("Enter left child of %d : ",p->data);
        scanf("%d",&x);

        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        printf("Enter right child of %d : ",p->data);
        scanf("%d",&x);

        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node* p)
{
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(Node* p)
{
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void Tree::postorder(Node* p)
{
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int main()
{
    Tree t;
    t.TreeCreate();
    printf("\nPreorder: ");
    t.preorder();
    printf("\nInorder: ");
    t.inorder();
    printf("\nPostorder: ");
    t.postorder();
    return 0;
}

//QueueCpp.h
/*
#include<stdio.h>

#ifndef QueueCpp_h
#define QueueCpp_h

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class queue{
private:
    int size;
    int rear;
    int front;
    Node** Q;
public:
    queue();
    queue(int size);
    int is_empty();
    int is_full();
    void enqueue(Node* x);
    Node* dequeue();
};


queue::queue()
{
    printf("\nEnter size of the queue: ");
    scanf("%d",&this->size);
    Q = new Node*[this->size];
    rear = front = 0;
}

queue::queue(int size)
{
    rear = front = 0;
    this->size = size;
    Q = new Node*[this->size];
}

int queue::is_empty()
{
    return (rear==front)?1:0;
}

int queue::is_full()
{
    return ((rear+1)%size)==front ? 1 : 0;
}

void queue::enqueue(Node* x)
{
    if(is_full()){
        printf("\nQueue is Full!!");
        return;
    }
     rear = (rear+1)%size;
     Q[rear] = x;
}

Node* queue::dequeue()
{
    Node* x = NULL;
    if(is_empty()){
        printf("\nQueue empty!!");
        return x;
    }
    front= (front+1)%size ;
    x = Q[front];
    return x;
}

#endif // Queue



*/
