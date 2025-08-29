#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* lchild;
    int data;
    struct Node* rchild;
    int height;
}Node;

Node* root = NULL;

void inorder(Node* p)
{
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
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

int NodeHeight(Node* p)
{
    int hl,hr; //height of left and right subtree

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return (hl>hr) ? hl+1 : hr+1;

}

int BalanceFactor(Node* p)
{
    int hl,hr; //height of left and right subtree

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

Node* LLrotation(Node* p)
{
    Node* pl = p->lchild; //left child pf p
    Node* plr = pl->rchild; //right child of pl

    //rotating results in change of two links -> disconnecting pl right child and connecting to original roots left child
    pl->rchild = p;
    p->lchild = plr;

    //height of p and pl get changed
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    //if rotation about root then assigning new root as pl
    if(root == p)
        root = pl;

    return pl;

}

Node* RRrotation(Node* p)
{
    return NULL;
}

Node* LRrotation(Node* p)
{
    return NULL;
}

Node* RLrotation(Node* p)
{
    return NULL;
}

Node* Rinsert(Node* p,int key)
{
    Node* t=NULL;

    if(p==NULL){
        t = (Node*)malloc(sizeof(Node));
        t->data = key;
        t->height = 1; //considering leaf node's height to be 1
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data)
        p->lchild = Rinsert(p->lchild,key);

    else if(key > p->data)
        p->rchild = Rinsert(p->rchild,key);

    p->height = NodeHeight(p);//after all recursive calls update height of every node

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLrotation(p);

    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRrotation(p);

    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLrotation(p);

    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRrotation(p);

    return p;

}


int main()
{
    root=Rinsert(root,10);
    Rinsert(root,5);
    Rinsert(root,2);

    inorder(root);
    printf("\n");
    preorder(root);
    return 0;
}
