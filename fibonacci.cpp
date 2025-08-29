#include<cstdio>

int F[100]; // initialized to 0 itself

int fib(int n)
{
    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int fib2(int n)
{
    if(n <= 1)
    {
        F[n] = n;
        return F[n];
    }
    else
    {
        if(F[n-1] == 0)
        {
            F[n-1] = fib2(n-1);
        }
        if(F[n-2] == 0)
        {
            F[n-2] = fib2(n-2);
        }
    }
    F[n] = F[n-1] + F[n-2];

    return F[n];
}

int fib3(int n)
{
    if(n <= 1)
        return n;

    if(F[n] != 0)
        return F[n];

    F[n] = fib3(n-1) + fib3(n-2);

    return F[n];
}

int main()
{
    printf("\n%d",fib(10));
    printf("\n%d",fib2(9));
    printf("\n%d",fib3(8));
    return 0;
}
