#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define len 120

int main()
{
  int n, m, i, j, sum_flag, flag, count = 0;
  int run[100] = {0};            //讓輸出結果一起輸出
  while(scanf("%d", &n) != EOF) //讀取標準解答共有幾列
  {
    if(!n)
    {
      break;
    }
    flag = 0;
    sum_flag = 0;
    char **ans = (char **)malloc(n * sizeof(char *));
    char **team = (char **)malloc(n * sizeof(char *));
    int **ans_sum = (int **)malloc(n * sizeof(int *));
    int **team_sum = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
    {
      ans[i] = (char *)malloc(len * sizeof(char));
      team[i] = (char *)malloc(len * sizeof(char));
      ans_sum[i] = (int *)malloc(len * sizeof(int));
      team_sum[i] = (int *)malloc(len * sizeof(int));
    }
    getchar(); //讀取換行字元
    for(i = 0; i < n; i++)
    {
      gets(ans[i]); //讀取每列的標準解答
    }
    scanf("%d", &m);
    getchar(); //讀取換行字元
    for(i = 0; i < n; i++)
    {
      gets(team[i]); //讀取每列的輸入答案
    }
    for(i = 0; i < n; i++)
    {
      if(!strcmp(ans[i], team[i]))
      {
        flag++; //比較每列的解答與輸入答案，若相同則flag+1
      }
    }
      
    if(flag == n) run[count] = 0;//若每列皆相同，則為AC
    else
    {
      for(j = 0; j < n; j++)
      {
        for(i = 0; i < strlen(ans[j]); i++)
        {
          if(isdigit(ans[j][i]))
          {
            ans_sum[j][ans[j][i] - '0']++; //讀取每列解答的數字，並記錄每個數字有幾個
          }
        }
          
        for(i = 0; i < strlen(team[j]); i++)
        {
          if(isdigit(team[j][i]))
          {
            team_sum[j][team[j][i] - '0']++; //讀取每列輸入答案的數字，並記錄每個數字有幾個
          }
        }
        for(i = 0; i < 10; i++)
        {
          if(ans_sum[j][i] == team_sum[j][i])
          {
            sum_flag++; //若該列數字的數目皆相同，則sum_flag+1
          }
        }
      }
      if(sum_flag == 10 * n)
      {
        run[count] = 1; //若每列的數字數目皆相同，則為PE
      }
      else
      {
        run[count] = 2; //否則為WA
      } 
    }
    count++;
    free(ans);
    free(ans_sum);
    free(team);
    free(team_sum);
  }
  for(i = 0; i < count; i++)
  {
    if(run[i] == 0)
    {
      printf("Run #%d: Accepted\n", i + 1); // AC
    }
    else if(run[i] == 1)
    {
      printf("Run #%d: Presentation Error\n", i + 1); // PE
    }
    else
    {
      printf("Run #%d: Wrong Answer\n", i + 1); // WA
    }
  }
}