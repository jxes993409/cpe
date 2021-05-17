#include <stdio.h>
#include <string.h>
#define len 16
#define max 100

int main()
{
    int m,n,i,j,k,sum;
    scanf("%d %d",&m,&n); //讀取共有m個字串以及須執行n次
    char s[m][len],t[max];
    int money[m];
    for(j=0;j<m;j++)
            scanf("%s %d",s[j],&money[j]); //讀取每個字串以及價格
    for(i=0;i<n;i++)
    {
        sum=0; //金額歸零
        while(scanf("%s",t)!=EOF)
        {
            if(!strcmp(t,".")) //讀取到.則跳出迴圈
                break;
            for(k=0;k<m;k++)
            {
                if(!strcmp(t,s[k])) //若有相同字串則增加對應金額
                    sum+=money[k];
            }
        }
        printf("%d\n",sum); //輸出金額
    }
    return 0;
}