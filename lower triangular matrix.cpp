
#include<iostream>
#include<cstdio>
using namespace std;

class lower_tri{
private:
    int n; //order
    int* A; //will be used to dynamically allocate memory
public:
    lower_tri(){n=3; A=new int[n*(n+1)/2];}
    lower_tri(int n){this->n = n; A=new int[n*(n+1)/2];}
    void set(int i,int j,int x);
    int get(int i,int j);
    int get_size(){return n;}
    void display();
    ~lower_tri(){delete []A;}
};

void lower_tri::set(int i,int j,int x)
{
    if(i>=j)
        A[i*(i-1)/2+j-1]=x;
}

int lower_tri::get(int i,int j)
{
    if(i>=j) return A[i*(i-1)/2+j-1];
    else return 0; //all other elements 0
}

void lower_tri::display()
{
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i>=j) printf("%2d ",A[i*(i-1)/2+j-1]);
            else printf(" 0 ");
        }
        printf("\n");
    }

}

int main()
{
    lower_tri m(4);
    int x;
    printf("Enter elements: ");
    for(int i=1;i<=m.get_size();i++){
        for(int j=1;j<=m.get_size();j++){
            scanf("%d",&x);
            m.set(i,j,x);
        }
    }
    printf("\n\n");
    m.display();

    return 0;
}

