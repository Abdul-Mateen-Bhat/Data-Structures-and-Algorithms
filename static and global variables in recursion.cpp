#include<iostream>
#include<cstdio>

using namespace std;

int fun(int n)
{
    static int x = 0;
    if(n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{
    printf("%d\n",fun(5)); //x = 5 so , 5*5
    printf("%d\n",fun(5)); //10*5
    printf("%d\n",fun(5)); //15*5
    printf("%d\n",fun(5)); //20*5
    printf("%d\n",fun(5)); //25*5

    return 0;

}
