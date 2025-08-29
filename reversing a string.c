#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    printf("Enter String: ");
    fgets(s,100,stdin);
    s[strcspn(s,"\n")] = '\0';
    int i,j;
    for(i=0,j=strlen(s)-1;i<j;i++,j--){
        char temp = s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    printf("Reversed: %s",s);
    return 0;
}
