#include<iostream>
using namespace std;

int main()
{
    int sum = 0;
    int A[] = {1,2,3,4,5};
    for(auto x:A){
        sum += x;
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
