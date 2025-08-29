#include<iostream>
#include<cstdio>

using namespace std;

void funA(int n);
void funB(int n);

void funA(int n)
{
    printf("\nInside A");
    if(n > 0)
    {
        printf("\n%d",n);
        funB(n - 1);
    }
    printf("\nOutside A");
}

void funB(int n)
{
    printf("\nInside B");
    if(n > 0)
    {
        printf("\n%d",n);
        funA(n/2);
    }
    printf("\nOutside B");
}

int main()
{
    printf("\nInside main");
    funA(20);
    printf("\nOutside main");
    return 0;
}
