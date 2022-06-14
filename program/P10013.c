#include <stdio.h>
#include <stdlib.h>
#define max 1000000

int main()
{
  int N, M, i, j;
  scanf("%d", &N); //讀取共有N個區塊
  for(i = 0; i < N; i++)
  {
    scanf("%d", &M);
    int *sum = (int *)malloc(M * sizeof(int));
    int *s = (int *)malloc(M * sizeof(int));
    int *t = (int *)malloc(M * sizeof(int));
    int carry = 0;
    for(j = M - 1; j >= 0; j--)
    {
      scanf("%d %d", &s[j], &t[j]); //讀取輸入的值
    }
    for(j = 0; j < M; j++)
    {
      if (carry) sum[j]++; //如果有進位，則該位元+1
      sum[j] += (s[j] + t[j]) % 10;
      carry = (s[j] + t[j]) / 10; //若相加超過10，則下個位元進位
    }
    for(j = M - 1; j >= 0; j--)
    {
      printf("%d", sum[j]); //輸出結果
    }
    printf("\n");
    free(sum);
    free(s);
    free(t);
  }
  return 0;
}