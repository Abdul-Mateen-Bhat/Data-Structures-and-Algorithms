#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    fgets(s,100,stdin);
    s[strcspn(s,"\n")] = '\0';
    int i;
    for(i=0;s[i]!='\0';i++){}
    printf("Length: %d",i);
    return 0;
}

