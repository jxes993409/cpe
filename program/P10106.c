#include <stdio.h>
#include <string.h>
#define max 250

int main()
{
    int i,j,carry;
    char x1[max],y1[max];
    int x2[max],y2[max],sum[max*2];
    while(gets(x1)!=NULL&&gets(y1)!=NULL) //讀取x1與y1
    {
        carry=0;
        for(i=0;i<max;i++) //清空陣列
        {
            x2[i]=0;
            y2[i]=0;
        }
        for(i=0;i<max*2;i++) //清空陣列
            sum[i]=0;
        for(i=strlen(x1)-1;i>=0;i--)
            x2[strlen(x1)-i-1]=x1[i]-'0'; //將x1頭尾互換記錄到x2，ex.123->321
        for(i=strlen(y1)-1;i>=0;i--)
            y2[strlen(y1)-i-1]=y1[i]-'0'; //將y1頭尾互換記錄到y2，ex.123->321
        for(i=0;i<max;i++)
        {
            for(j=0;j<max;j++)
            {
                sum[i+j]+=x2[i]*y2[j]+carry; //每位元=進位以及相乘的值+之前的值
                if(sum[i+j]>=10) //若超過10，則需進位以及該位元需取10的餘數
                {
                    carry=sum[i+j]/10;
                    sum[i+j]%=10;
                }
                else
                    carry=0;
            }
        }
        for(i=max-1;i>=0;i--) //前面的數字皆為0，直到找到沒有0的數字為止開始輸出
        {
            if(sum[i]!=0)
                break;
        }
        for(;i>=0;i--)
            printf("%d",sum[i]);
        printf("\n");
    }
}

