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

    int H[26]={0};//0-25

    for(i=0;i<strlen(s);i++){
        H[s[i]-97]++; //H[a-97]->H[97-97] means H[0] and H[z-97] means H[25]
    }
    for(i=0;i<26;i++){
        if(H[i] > 1){
            printf("\n%c is repeating %d times",i+97,H[i]);
        }
    }

    return 0;
}
