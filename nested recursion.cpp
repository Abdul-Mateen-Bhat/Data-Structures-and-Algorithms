#include<iostream>
#include<cstdio>

using namespace std;
int count = 0;
int fun(int n)
{
    count++;
    printf("\nInside fun");
    if(n > 100){
        printf("\nOutside fun");
        return n - 10;}
    else{
        printf("\nOutside fun");
        return fun(fun(n + 11));}
}

int main()
{
    printf("\n%d",fun(95));
    printf("\nNo. of calls: %d",count);
    return 0;
}
