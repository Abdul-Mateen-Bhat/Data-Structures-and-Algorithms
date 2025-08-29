#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* lchild;
    int data;
    struct Node* rchild;
}Node;

Node* root = NULL;

void Iinsert(int key)//inserts key at right position
{
    Node *t = root;
    Node *p; //temporary node pointer
    Node *r; //tailing pointer

    if(root == NULL){//inserting first element
        p = (Node*)malloc(sizeof(Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p; //assigning first element to root
        return; //insertion done so return
    }

    while(t != NULL){ //searching through whole tree
        r=t;//tailing
        if(key < t->data)
            t = t->lchild;
        else if(key > t->data)
            t = t->rchild;
        else{//if key already in the tree return
            printf("%d already in BST.",key);
            return;
        }
    }
    //Making the new Node
    p = (Node*)malloc(sizeof(Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    //checking if key should be on R or L of the tailing Node
    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

Node* Rinsert(Node* p,int key)
{
    Node* t;
    if(p == NULL){
        t = (Node*)malloc(sizeof(Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = Rinsert(p->lchild,key);
    else if(key > p->data)
        p->rchild = Rinsert(p->rchild,key);

    return p;
}

Node* Isearch(int key)//returns node address of key
{
    Node* t = root;

    while(t != NULL){
        if(key == t->data)
            return t;
        else if(key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL; //either root is NULL or key not found
}

Node* Rsearch(Node* p,int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    else if(key < p->data)
        return Rsearch(p->lchild,key);
    else
        return Rsearch(p->rchild,key);
}

void inorder(Node* p)
{
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

int height(Node* p)
{
    if(p==NULL)
        return 0;

    int x,y;
    x = height(p->lchild);
    y = height(p->rchild);
    return (x>y)?x+1:y+1;
}

Node* InorderPredecessor(Node* p)
{
    while(p && p->rchild)
        p=p->rchild;
    return p;
}

Node* InorderSuccessor(Node* p)
{
    while(p && p->lchild)
        p = p->lchild;
    return p;
}

Node* Delete(Node* p,int key)
{
    Node* q = NULL;

    if(p==NULL)
        return NULL;

    if(p->lchild==NULL && p->rchild==NULL){//leaf node
        if(p==root){
            root=NULL;
        }
        free(p);
        return NULL;
    }

    if(key < p->data)
        p->lchild = Delete(p->lchild,key);

    else if(key > p->data)
        p->rchild = Delete(p->rchild,key);

    else{//if Key == p->data ->delete it
        if(height(p->lchild) > height(p->rchild)){//deleting node from greater height
            q = InorderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data);
        }

        else{
            q = InorderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }
    }
    return p;

}

int main()
{
    Iinsert(10);
    Iinsert(5);
    Iinsert(3);
    Iinsert(7);
    Iinsert(12);
    Iinsert(8);

    Delete(root,7);
    Delete(root,10);
    Delete(root,12);
    inorder(root);

    Node* temp = Isearch(12);
    if(temp != NULL)
        printf("\n%d found",temp->data);
    else
        printf("\nKey not found");




    return 0;
}









