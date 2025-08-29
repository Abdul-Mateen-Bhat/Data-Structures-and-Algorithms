#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void SortedInsert(Node** Head,int x)
{
    Node *t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->next = NULL;

    if(*Head == NULL) //if slot empty make t as head pointer of that slot
        *Head = t;

    else{
        Node *p=*Head;
        Node *q = NULL;

        while(p && p->data < x){
            q=p;
            p = p->next;
        }
        if(p == *Head){
            t->next = *Head;
            *Head = t;
        }

        else{
           t->next = q->next;
           q->next = t;
        }

    }
}

int hash(int key)
{
    return key%10;
}

void insert(Node** HT,int key)
{
    int index = hash(key);
    SortedInsert(&HT[index],key);
}

Node* search(Node* p,int key)
{
    while(p && p->data < key)
        p=p->next;

    if(p && p->data == key)
        return p;

    else
        return NULL;
}

int delete(Node **head,int key)
{
    Node* p = *head;
    Node* q = NULL;
    int x = -1;

    while(p && p->data != key){
        q=p;
        p=p->next;
    }

    if(p){//found
        x = p->data;

        if(q == NULL)//if p is head pointer-> head pointer carries the key
            *head = p->next;

        else
            q->next = p->next;

        free(p);

    }

    return x;
}

void printTable(Node** HT)
{
    for (int i = 0; i < 10; i++) {
        printf("Index %d:", i);
        Node* p = HT[i];
        while (p) {
            printf(" %d", p->data);
            p = p->next;
        }
        printf("\n");
    }
}



int main()
{
    Node** HT;
    HT = (Node**)malloc(sizeof(Node*)*10); //0-9
    for(int i=0;i<10;i++){
        HT[i] = NULL;
    }
    insert(HT,12);
    insert(HT,22);
    insert(HT,57);
    insert(HT,2);
    printTable(HT);

    Node* temp = search(HT[hash(12)],12);
    if(temp != NULL)
        printf("\n%d",temp->data);
    else
        printf("\nKey not found");


    int x = delete(&HT[hash(2)],2);
    if(x != -1)
        printf("\n%d deleted",x);
    else
        printf("\nNot found so cant delete");


    temp = search(HT[hash(2)],2);
    if(temp != NULL)
        printf("\n%d",temp->data);
    else
        printf("\nKey not found");

    printTable(HT);


    return 0;
}
