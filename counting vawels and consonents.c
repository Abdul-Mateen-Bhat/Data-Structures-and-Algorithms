#include<stdio.h>
#include<string.h>
int main()
{
    char A[100];
    printf("Enter String: ");
    fgets(A,100,stdin);
    A[strcspn(A,"\n")] = '\0';
    int i,v=0,c=0;

    for(i=0;A[i]!='\0';i++){
        if((A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122)){
            if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
                v++;
            else
                c++;
        }
    }
    printf("v: %d c: %d",v,c);
    return 0;
}
