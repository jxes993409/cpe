#include <stdio.h>

int main()
{
  int i, j, N, l = 0;
  while(scanf("%d", &N) != EOF)
  {
    int m = 0, k = N * (N + 1) / 2, flag = 1;
    int *s = (int *)malloc(N * sizeof(int));
    int *sum = (int *)malloc(k * sizeof(int));
    for(i = 0; i < N; i++) //讀取數字
    {
      scanf("%d", &s[i]);
    }
    printf("\n");
    for(i = 0; i < N; i++)
    {
      for(j = i; j < N; j++, m++) //讓兩數字相加並記錄至sum陣列
      {
        sum[m] = s[i] + s[j];
      }
    }
    for(i = 0; i < k; i++)
    {
      if(!flag) //減少迴圈讀取時間
      {
        break;
      }
      for(j = i + 1; j < k; j++)
      {
        if(sum[i] == sum[j]) //若有相同的則令flag=0，並跳出迴圈
        {
          flag = 0;
          break;
        }
      }
    }
    l++;
    if(!flag)
    {
      printf("Case #%d: It is not a B2-Sequence.\n", l);
    }
    else
    {
      printf("Case #%d: It is a B2-Sequence.\n", l);
    }
    printf("\n");
    free(s);
    free(sum);
  }
}