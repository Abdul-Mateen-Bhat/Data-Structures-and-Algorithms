#include<stdio.h>

void perm(char s[],int k)
{
    static int A[10] = {0};
    static char result[10];
    int i;

    if(s[k]=='\0'){
        result[k] = '\0';
        printf("\n %s",result);

    }
    else{
        for(i=0;s[i]!='\0';i++){
            if(A[i]==0){
                result[k] = s[i];
                A[i]=1;
                perm(s,k+1);
                A[i]=0;
            }
        }
    }
}

int main()
{
    char s[] = "mateen";
    perm(s,0);
    return 0;
}
