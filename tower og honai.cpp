#include<cstdio>

static int count = 0;

void TOH(int n,int A,int B,int C) //moving n disks from A to C using B
{
    if(n>0)
    {
        TOH(n-1,A,C,B); //moving n-1 disks from A to B
        printf("Step %d: Disk %d from %d to %d\n",++count,n,A,C); //moving nth disk from A to C
        TOH(n-1,B,A,C); //moving n-1 disks from B to A
    }
}


int main()
{
    TOH(3,1,2,3);
    return 0;
}
