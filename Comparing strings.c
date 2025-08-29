
#include<stdio.h>
#include<string.h>

int main()
{
    int i,j;

    char s[100];
    printf("Enter 1st String: ");
    fgets(s,100,stdin);
    s[strcspn(s,"\n")] = '\0';

    char s2[100];
    printf("Enter 2nd String: ");
    fgets(s2,100,stdin);
    s2[strcspn(s2,"\n")] = '\0';

    for(i=0;i<strlen(s);i++){ //lowercasing full string s
        if(s[i]>=65 && s[i]<=90)
            s[i]+=32;
    }

    for(i=0;i<strlen(s2);i++){ //lowercasing full string s2
        if(s2[i]>=65 && s2[i]<=90)
            s2[i]+=32;
    }

    printf("After Lowercasing:- String 1: %s String 2: %s\n",s,s2);

    for(i=0,j=0;(s[i]!='\0' && s2[j]!='\0');i++,j++){
        if(s[i]!=s2[j])
            break;
    }
    if(s[i] == s2[j]) printf("Equal");
    else if(s[i] < s2[j]) printf("1st is smaller");
    else printf("1st is greater");



    return 0;
}
