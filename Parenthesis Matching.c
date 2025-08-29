#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char data;
    struct Node* next;
}Node;

Node* Top = NULL;

void display();
void push(char x);
char pop();
int is_full();
int is_empty();
int is_balanced(char* exp);
int isMatchingPair(char open, char close);
int isOperand(char x);
int precedence(char x);
char* Infix_to_postfix(char* infix);

int main()
{
    char* s = "a+b*c-d/e";
    push('#');
    printf("%s",Infix_to_postfix(s));

    return 0;
}

char* Infix_to_postfix(char* infix)
{
    int i=0,j=0;
    char* postfix = (char*)malloc(sizeof(char)*(strlen(infix)+2));

    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(precedence(infix[i]) > precedence(Top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++] = pop();
            }
        }
    }
    while(!is_empty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;

}

int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x== '/')
        return 0;
    return 1;
}

int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;

    else if(x == '*' || x == '/')
        return 2;

    return 0;
}

int is_balanced(char* exp)
{
    int i;
    char ch;
    for(i=0;exp[i]!='\0';i++){
        ch=exp[i];

        if(ch == '(' || ch == '[' || ch == '{')
            push(ch);

        else if(ch== ')' || ch == ']' || ch == '}'){
            if(is_empty())
                return 0;

            if(!isMatchingPair(pop(),ch))
                return 0;
            }
    }
    if(is_empty())
        return 1;
    return 0;
}

int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

void display()
{
    Node* p = Top;
    while(p){
        printf("\n%d",p->data);
        p=p->next;
    }
}


void push(char x)
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

char pop()
{
    char x = -1;
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
