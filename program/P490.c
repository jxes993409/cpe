#include <stdio.h>
#include <string.h>
#define max 100

int main()
{
    int i=0,j,k,maxlen=0;
    char s[max][max];
    while(gets(s[i])!=NULL) //輸入失敗時跳出迴圈
    {
        if(strlen(s[i])>=maxlen) //找出最長的字串並記錄
            maxlen=strlen(s[i]);
        i++; //紀錄共有幾行
    }
    for(j=0;j<maxlen;j++) //換列
    {
        for(k=i;k>=0;k--)
            printf("%c",s[k][j]); //輸出列，從最下一個元素開始輸出
        printf("\n");
    }
    return 0;
}