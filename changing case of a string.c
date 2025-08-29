#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter String: ");
    fgets(s,100,stdin);
    s[strcspn(s,"\n")] = '\0';
    int i;
    for(i=0;s[i]!='\0';i++){
        if(s[i]>=65 && s[i]<= 90)
            s[i] += 32;
        else if(s[i]>=97 && s[i]<=122)
            s[i] -= 32;
    }
    printf("%s",s);

    return 0;
}
