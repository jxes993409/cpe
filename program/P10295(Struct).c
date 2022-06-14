#include <stdio.h>
#include <string.h>
#define len 16
#define max 100

typedef struct
{
  int money;
  char word[len];
} dictionary;

int main()
{
  int m, n, i, j, sum;
  scanf("%d %d", &m, &n); //讀取共有m個字串以及須執行n次
  char t[max];
  dictionary *Hay_Point = malloc(m * sizeof(*Hay_Point));
  for (i = 0; i < m; i++)
    scanf("%s %d", Hay_Point[i].word, &Hay_Point[i].money); //讀取每個字串以及價格
  for (i = 0; i < n; i++)
  {
    sum = 0; //金額歸零
    while (scanf("%s", t) != EOF)
    {
      if (!strcmp(t, ".")) //讀取到.則跳出迴圈
        break;
      for (j = 0; j < m; j++)
      {
        if (!strcmp(t, Hay_Point[j].word)) //若有相同字串則增加對應金額
          sum += Hay_Point[j].money;
      }
    }
    printf("%d\n", sum); //輸出金額
  }
  free(Hay_Point);
  return 0;
}