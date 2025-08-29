#include<stdio.h>

void swap(char *x,char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void perm(char s[],int l,int h)
{
    int i;

    if(l==h){
        printf("\n %s",s);
    }
    else{
        for(i=l;i<=h;i++){
            swap(&s[l],&s[i]);
            perm(s,l+1,h);
            swap(&s[l],&s[i]);
        }
    }
}


int main()
{
    char s[] = "abc";
    perm(s,0,2);
    return 0;
}

