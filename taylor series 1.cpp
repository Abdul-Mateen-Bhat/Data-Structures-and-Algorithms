#include<cstdio>

double e(int x, int n)
{
    static double p = 1,f = 1;

    if(n == 0)
        return 1;

    else
    {
        double r;
        r = e(x,n-1);
        p *= x;
        f *= n;
        return ( r + p/f );
    }
}

int main()
{
    int x = 2;
    printf("%lf",e(x,10));
    return 0;
}
