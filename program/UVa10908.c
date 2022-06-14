#include <stdio.h>
#define max 100

int main()
{
  int T, Q, M, N, r, c, i, j, k;
  char s[max][max], letter;
  scanf("%d", &T);
  for(i = 0; i < T; i++)
  {
    scanf("%d %d %d", &M, &N, &Q);
    getchar();
    for(j = 0; j < M; j++)
    {
      gets(s[j]); //讀取字串
    }
    printf("%d %d %d\n", M, N, Q);
    for(k = 0; k < Q; k++)
    {
      int ans = 1;
      j = 1;
      scanf("%d %d", &r, &c); //讀取中心座標
      letter = s[r][c];
      while(1)
      {
        if(c + j < N && c - j >= 0 && r + j < M && r - j >= 0 && letter == s[r - j][c] && letter == s[r + j][c] && letter == s[r][c - j] && letter == s[r][c + j] && letter == s[r - j][c - j] && letter == s[r + j][c - j] && letter == s[r - j][c + j] && letter == s[r + j][c + j])
        {
          //檢查是否超出陣列，依序檢查上，下，左，右，左上，左下，右上，右下是否相等
          ans++;
          j++;
        }
        else
        {
          break;
        }
      }
      printf("%d\n", ans * 2 - 1); //輸出答案
    }
  }
  return 0;
}