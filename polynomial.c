#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
    int coeff; //coefficient of the term
    int exp;   //exponent of x in that term
}term;

typedef struct{
    int n; //no of terms in the polynomial
    term* t; //array of terms
}poly;

void create(poly* p)
{
    int i;
    printf("Enter number of terms: ");
    scanf("%d",&p->n);
    p->t = (term*)malloc(p->n * sizeof(term)); //allocating memory for n terms

    printf("Enter terms(coeff,exp): \n");
    for(i=0;i<p->n;i++){
        printf("Term %d: ",i+1);
        scanf("%d%d",&p->t[i].coeff,&p->t[i].exp);
    }
}

void display(poly p)
{
    int i;
    printf("p(x) = ");
    for(i=0;i<p.n;i++){
        if(i != p.n-1) //to avoid printing + after last term
            printf("%dx^%d+ ",p.t[i].coeff,p.t[i].exp);
        else
            printf("%dx^%d",p.t[i].coeff,p.t[i].exp);
    }
    printf("\n");
}

int evaluate(poly* p,int x) //x -> value of x for evaluation
{
    int i,sum=0;
    for(i=0;i<p->n;i++){
        sum += p->t[i].coeff * pow(x,p->t[i].exp);
    }
    return sum;
}

poly* add(poly* p1,poly* p2)
{
    int i=0,j=0,k=0,sum=0; //i for p1.. j for p2.. k for current term

    poly* res =(poly*)malloc(sizeof(poly));//creating a resultant polynomial
    res->t = (term*)malloc((p1->n +p2->n) * sizeof(term)); //worst case: creating n1+n2 terms

    while(i<p1->n && j<p2->n)
    {
        if(p1->t[i].exp > p2->t[j].exp) //if exponent of p1's term is greater
            res->t[k++]=p1->t[i++]; //copying that to result

        else if(p1->t[i].exp < p2->t[j].exp) //if exponent of p2's term is greater
            res->t[k++]=p2->t[j++]; //copying that to result

        else{ //if exponent equal adding coefficients but exp remains same
            res->t[k]=p1->t[i++]; //copying exp and coeff of p1
            res->t[k++].coeff += p2->t[j++].coeff; //adding coeff of p2
        }
    }
    //copying remaining terms
    for(;i<p1->n;i++)
        res->t[k++]=p1->t[i];
    for(;j<p2->n;j++)
        res->t[k++]=p2->t[j];

    res->n = k; //no of terms in result
    return res;
}

int main()
{
    poly p1,p2;
    create(&p1); create(&p2);
    display(p1); display(p2);

    poly* result = add(&p1,&p2);
    printf("Resultant Polynomial:\n");
    display(*result);

    printf("%d + %d = %d",evaluate(&p1,2),evaluate(&p2,2),evaluate(result,2));
    return 0;
}
