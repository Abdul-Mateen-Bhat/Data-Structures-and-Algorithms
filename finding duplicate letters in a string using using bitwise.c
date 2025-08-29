
#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    printf("Enter 1st String: ");
    fgets(s,100,stdin);
    s[strcspn(s,"\n")] = '\0';

    int i;

    for(i=0;i<strlen(s);i++){ //lowercasing full string s
        if(s[i]>=65 && s[i]<=90)
            s[i]+=32;
    }

    int H=0;//4 bytes means 32 bits but we only need 26 bits
            // initializing all bits to 0
    int x;

    for(i=0;i<strlen(s);i++){
        x=1;
        x = x << (s[i]-97);
        if((H&x) > 0)
            printf("%c has duplicates",s[i]);
        else
            H = (H | x);
    }

    return 0;
}
