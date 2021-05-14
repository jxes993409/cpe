#include <stdio.h>
#include <string.h>
#define MAX 1000000

int main()
{
    int i,j,k,m,max=0,count;
    char c[MAX];
    while(gets(c)!=NULL)
    {
        max=0;
        for(i=1;i<=strlen(c);i++)
        {
            if(strlen(c)%i==0) //切割字串，若無法成功切割則不進入迴圈
            {
                m=strlen(c)/i; //計算共切成幾塊
                count=0;
                for(j=0;j<i;j++)
                {
                    for(k=1;k<m;k++) //檢查第k+1塊的第j字元是否與第1塊的第j字元相同，否則跳出迴圈
                    {
                        if(c[j]==c[j+i*k]) //若相同則count+1
                            count++;
                        else
                            break;
                    }
                }
                if(count>max)
                    max=count;
            }
        }
        if(max)
            printf("%d\n",strlen(c)/(strlen(c)-max));
        else
            printf("1\n");
    }
    return 0;
}