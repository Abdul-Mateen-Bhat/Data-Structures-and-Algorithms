#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;

int* create_array(int n)
{
    int *q = new int[n];
    //int *p = (int *)malloc(n * sizeof(n));
    return q;
}
int main()
{
    int *A = create_array(5);
    for(int i = 0 ; i < 5 ; i++){
        A[i] = i;
        printf("%d ",A[i]);
    }

    cout << endl;

    for(int i = 0 ; i < 5 ; i++){
        A[i] = i;
        cout << A[i] << " ";
    }
    return 0;
}
