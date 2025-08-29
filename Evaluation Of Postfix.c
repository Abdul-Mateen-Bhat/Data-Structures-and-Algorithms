
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* Top = NULL;

int isOperand(char x);
void push(int x);
int pop();
int is_full();
int is_empty();
int evaluate(char* postfix);

int main()
{
    char* postfix = "234*+82/-";
    printf("%d",evaluate(postfix));
    return 0;
}

int evaluate(char* postfix)
{
    int i=0,x1,x2,r;
    while(postfix[i] != '\0'){
        if(isOperand(postfix[i])){
            push(postfix[i++] - '0');
        }
        else{
            x2=pop();
            x1=pop();
            switch(postfix[i++]){
                case '+': r=x1+x2; break;
                case '-': r=x1-x2; break;
                case '*': r=x1*x2; break;
                case '/': r=x1/x2; break;
            }
            push(r);
        }
    }
    return Top->data;
}


int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x== '/')
        return 0;
    return 1;
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

