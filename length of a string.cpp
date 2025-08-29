#include<iostream>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int i;
    for(i=0;str[i] != '\0';i++){}
    cout << "Length: " << i;
    return 0;
}
