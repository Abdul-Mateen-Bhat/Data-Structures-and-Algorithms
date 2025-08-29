#include<cstdio>

int power(int b,int n)
{
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return power(b*b,n/2);
    else
        return b * power(b * b , (n - 1) / 2);
}

int main()
{
    printf("%d",power(2,5));
    return 0;
}
