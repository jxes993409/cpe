#include <stdio.h>
#include <string.h>
#define max 1000

int main()
{
    int i,j;
    int letter[6][26]={0};
    char s[6][max];
    for(i=0;i<6;i++)
    {
        gets(s[i]);
        for(j=0;j<strlen(s[i]);j++)
            letter[i][s[i][j]-'a']++;
    }
    for(i=0;i<6;i=i+2)
    {   
        for(j=0;j<26;j++)
            if(letter[i][j]>0&&letter[i+1][j]>0)
                printf("%c",j+'a');
        printf("\n");
    }
    return 0;
}