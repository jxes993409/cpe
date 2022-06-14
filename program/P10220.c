#include <stdio.h>
#define max 1000
#define len 2600

int s[max][len];

void Calc() //先計算階層的值
{
  int i, j, carry = 0;
  s[0][0] = 0;
  s[1][0] = 1;
  for(i = 0; i < max; i++)
  {
    for(j = 0; j < len; j++)
    {
      s[i][j] += i * s[i - 1][j] + carry; // ex. 6!=120*6 (120=s[i-1]、i=6)
      if (s[i][j] >= 10)
      {
        carry = s[i][j] / 10;
        s[i][j] %= 10;
      }
      else
      {
        carry = 0;
      }
    }
  }
}

int main()
{
  int i, n, sum;
  Calc();
  while(scanf("%d", &n) != EOF)
  {
    sum = 0; //歸零sum的值
    for(i = 0; i < len; i++)
    {
      sum += s[n][i]; //加總sum的值後輸出
    }
    printf("%d\n", sum);
  }
  return 0;
}