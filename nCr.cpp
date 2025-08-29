#include<cstdio>

int fact(int n)
{
    if(n<=1)
        return 1;

    return n*fact(n-1);
}

int ncr(int n,int r)
{
    return fact(n)/(fact(r)*fact(n-r));
}

int c(int n,int r)
{
    if(r == 0 || r == n)
        return 1;

    return c(n-1,r-1) + c(n-1,r);
}

int main()
{
    printf("%d",ncr(5,4));
    printf("\n%d",c(7,4));
    return 0;
}
