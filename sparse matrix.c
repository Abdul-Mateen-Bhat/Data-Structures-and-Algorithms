#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int i; //row
    int j; //col
    int x; //element's value
}element;

typedef struct{
    int m;   //no. of rows
    int n;   //no. of columns
    int num; //no. of non zero elements
    element *e; //array of non zero elements
}sparse;

void create(sparse *s)
{
    printf("Enter no of rows and columns(m n): ");
    scanf("%d %d",&s->m,&s->n);
    printf("Enter number of non zero elements: ");
    scanf("%d",&s->num);
    s->e = (element*)malloc(s->num * sizeof(element)); //creating an array of elements of the same size as no. of non zero elements

    int i;
    printf("Enter the values (row(0 to m-1),col(0 to n-1),element):\n");
    for(i=0;i<s->num;i++){
        printf("%d: ",i+1);
        scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x);//e[i].x means ith element ka x
                                                        // input should be organized least (row,col) should come first for correct display
    }
}

void display(sparse s)
{
    int i,j,k=0; //i->for rows j->for columns k->current element(0 to s.num-1)
    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==s.e[k].i && j==s.e[k].j)
                printf("%2d ",s.e[k++].x); //if element matched then incrementing it
            else
                printf(" 0 ");
        }
        printf("\n");
    }
}

sparse* add(sparse* s1,sparse* s2)
{
    if((s1->m!=s2->m) || (s1->n!=s2->n))
        printf("Cannot Add Matrices different no of rows or columns!");

    sparse* sum = (sparse*)malloc(sizeof(sparse)); //creating another sparse matrix to hold the sum
    sum->e = (element*)malloc((s1->num + s2->num)*sizeof(element));//taking worst case: all elements at different positions
    sum->m = s1->m;  //no of rows will be same
    sum->n = s1->n;  //no of columns also same

    int i=0,j=0,k=0; //i for s1 elements
                     //j for s2 //k for sum
    while(i<s1->num && j<s2->num)
    {
        if(s1->e[i].i < s2->e[j].i) //if row of s1's ele is less than row of s2's ele
            sum->e[k++] = s1->e[i++];   //copying full element(i,j,x)
                                        //incrementing both as they both got used

        else if(s1->e[i].i > s2->e[j].i)  //if row of s1's ele is greater than row of s2's ele
            sum->e[k++]=s2->e[j++];

        else{ //if rows are equal, check columns

            if(s1->e[i].j < s2->e[j].j) //if col of s1's ele is less than col of s2's ele
                sum->e[k++] = s1->e[i++];

            else if(s1->e[i].j > s2->e[j].j) //if col of s1's ele is greater than col of s2's ele
                sum->e[k++] = s2->e[j++];

            else{ //if same row as well as col then add
                sum->e[k] = s1->e[i++]; //first copying entire element from s1 (i,j,x)
                sum->e[k++].x += s2->e[j++].x; //now only adding s2.x
            }
        }
    }

    //copying remaining elements(if any)
    for(;i<s1->num;i++)
        sum->e[k++]=s1->e[i];
    for(;j<s2->num;j++)
        sum->e[k++]=s2->e[j];


    sum->num = k; //total no. of elements in sum
    return sum;
}

int main()
{
    sparse s1,s2;
    create(&s1);
    create(&s2);
    display(s1);
    printf("\n");
    display(s2);
    printf("\n");
    sparse* sum;
    sum = add(&s1,&s2);
    display(*sum);
    return 0;
}
