#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter a string: ");
    fgets(s,100,stdin);
    s[strcspn(s,"\n")] = '\0';
    int i=0,w=0;

    while(s[i]==' ') i++; //skipping initial spaces if any
    if(s[i] != '\0') w=1; //if only spaces then w=0 else w=1

    for(i;s[i]!='\0';i++){
        if(s[i] == ' ' && s[i+1] != ' ')
            w++;
    }
    printf("Words: %d",w);
    return 0;
}
