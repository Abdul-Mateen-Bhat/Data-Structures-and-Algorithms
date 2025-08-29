#include<iostream>
#include<cstdio>
using namespace std;

class diagonal{
private:
    int n; //order
    int* A; //will be used to dynamically allocate memory
public:
    diagonal(){n=3; A=new int[n];}
    diagonal(int n){this->n = n; A=new int[n];}
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    ~diagonal(){delete []A;}
};

void diagonal::set(int i,int j,int x)
{
    if(i==j)
        A[i-1]=x;
}

int diagonal::get(int i,int j)
{
    if(i==j) return A[i-1];
    else return 0; //all other elements 0
}

void diagonal::display()
{
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j) printf("%2d ",A[i-1]);
            else printf(" 0 ");
        }
        printf("\n");
    }

}

int main()
{
    diagonal m(5);
    m.set(1,1,5);m.set(2,2,10);m.set(3,3,15);
    m.set(4,4,20);m.set(5,5,25);
    m.display();
    return 0;
}
