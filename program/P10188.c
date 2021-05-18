#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define len 120

int main()
{
    int n,m,i,j,sum_flag,flag,count=0;
    int run[100]={0}; //讓輸出結果一起輸出
    while(scanf("%d",&n)!=EOF) //讀取標準解答共有幾列
    {
        if(!n)
            break;
        flag=0;sum_flag=0;
        char ans[n][len],team[n][len];
        int ans_sum[n][10]={0},team_sum[n][10]={0};
        getchar(); //讀取換行字元
        for(i=0;i<n;i++)
            gets(ans[i]); //讀取每列的標準解答
        scanf("%d",&m);
        getchar(); //讀取換行字元
        for(i=0;i<n;i++)
            gets(team[i]); //讀取每列的輸入答案
        for(i=0;i<n;i++)
            if(!strcmp(ans[i],team[i])) //比較每列的解答與輸入答案，若相同則flag+1
                flag++;
        if(flag==n) //若每列皆相同，則為AC
            run[count]=0;
        else
        {
            for(j=0;j<n;j++)
            {
                for(i=0;i<strlen(ans[j]);i++)
                    if(isdigit(ans[j][i]))
                        ans_sum[j][ans[j][i]-'0']++; //讀取每列解答的數字，並記錄每個數字有幾個
                for(i=0;i<strlen(team[j]);i++)
                    if(isdigit(team[j][i]))
                        team_sum[j][team[j][i]-'0']++; //讀取每列輸入答案的數字，並記錄每個數字有幾個
                for(i=0;i<10;i++)
                {
                    if(ans_sum[j][i]==team_sum[j][i]) //若該列數字的數目皆相同，則sum_flag+1
                        sum_flag++;
                } 
            }
            if(sum_flag==10*n)
                run[count]=1; //若每列的數字數目皆相同，則為PE
            else
                run[count]=2; //否則為WA
        }
        count++;
    }
    for(i=0;i<count;i++)
    {
        if(run[i]==0)
            printf("Run #%d: Accepted\n",i+1); //AC
        else if(run[i]==1)
            printf("Run #%d: Presentation Error\n",i+1); //PE
        else
            printf("Run #%d: Wrong Answer\n",i+1); //WA
    }
}