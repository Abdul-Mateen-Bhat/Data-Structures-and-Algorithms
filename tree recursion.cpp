#include<iostream>
#include<cstdio>

using namespace std;

static int count = 0;
void fun(int n)
{
    count++;
    printf("\nInside fun(%d)",n);
    if(n > 0)
    {
        fun(n - 1);
        fun(n - 1);
    }
    //printf("\nOutside fun(%d)",n);

}

int main()
{
    fun(3);
    printf("\nNumber of calls: %d",count);
    return 0;
}
