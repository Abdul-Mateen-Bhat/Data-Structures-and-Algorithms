
#include<stdio.h>
#include<string.h>

int main()
{
    int i,j;

    char s[100];
    printf("Enter 1st String: ");
    fgets(s,100,stdin);
    s[strcspn(s,"\n")] = '\0';

    for(i=0;i<strlen(s);i++){ //lowercasing full string s
        if(s[i]>=65 && s[i]<=90)
            s[i]+=32;
    }

    printf("After Lowercasing: %s\n",s);

    for(i=0,j=strlen(s)-1;i<j;i++,j--){
        if(s[i]!=s[j]){
            printf("Not Palindrome");
            return 0;
        }
    }
    printf("Palindrome");
    return 0;
}

