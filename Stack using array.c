#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int size;
    int top;
    int* s;
}stack;

void create(stack *st);
void display(stack st);
void push(stack* st,int data);
int pop(stack* st);
int is_full(stack st);
int is_empty(stack st);
int peek(stack st,int pos);
int stackTop(stack st);


int main()
{
    stack s1;
    create(&s1);
    push(&s1,23);
    push(&s1,34);
    push(&s1,4);
    push(&s1,56);
    pop(&s1);
    display(s1);
    printf("\nPeeking at 2: %d",peek(s1,2));
    printf("\nTop element: %d",stackTop(s1));
    return 0;
}

void create(stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d",&st->size);
    st->s = (int*)malloc(sizeof(int)*st->size);
    st->top = -1;
}

void display(stack st)
{
    int i;
    for(i=st.top;i>=0;i--){
        printf("\n%d",st.s[i]);
    }
}

void push(stack* st,int data)
{
    if(is_full(*st))
    {
        printf("\nStack Overflow!!");
        return ;
    }

    st->top++;
    st->s[st->top] = data;

}

int pop(stack* st)
{
    int x = -1;
    if(is_empty(*st))
        printf("\nStack Underflow!!\n");

    x = st->s[st->top];
    st->top--;

    return x;

}

int peek(stack st,int pos)
{
    if(pos<1 || pos>st.top+1){
        printf("\nInvalid Index!\n");
        return -1;
    }
    return st.s[st.top-pos+1];

}


int is_full(stack st)
{
    if(st.top == st.size-1)
        return 1;
    else
        return 0;
}

int is_empty(stack st)
{
    if(st.top == -1)
        return 1;
    else
        return 0;
}

int stackTop(stack st)
{
    if(!is_empty(st))
        return st.s[st.top];
    return -1;
}


