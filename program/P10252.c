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
        gets(s[i]); //讀取字串
        for(j=0;j<strlen(s[i]);j++)
            letter[i][s[i][j]-'a']++; //讀到英文字母後該陣列值+1
    }
    for(i=0;i<6;i=i+2)
    {
        for(j=0;j<26;j++)
            if(letter[i][j]>0&&letter[i+1][j]>0) //檢查是否兩句都有該字母，有則輸出
                printf("%c",j+'a');
        printf("\n");
    }
    return 0;
}