#include<cstdio>

double ie(int x, int n)
{
    double r = 1;

    for(;n>0;n--){
        r = 1 + (double)x/n * r;
    }
    return r;
}

double e(int x,int n)
{
    static double r = 1;
    if(n == 0)
        return r;

    r = 1 + (double)x/n * r;
    return e(x,n-1);
}

int main()
{
    int x = 2;
    printf("%lf",ie(1,10));
    printf("\n");
    printf("%lf",e(1,10));
    return 0;
}
