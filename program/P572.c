#include <stdio.h>
#include <stdlib.h>
#define max 100

void find(int, int);
int m, n, id[max][max];
char map[max][max];

int main()
{
  int i, j;
  while(scanf("%d %d", &m, &n) != EOF)
  {
    if(m == 0 && n == 0)
    {
      break;
    }
    int table = 0;
    getchar();
    for(i = 0; i < m; i++)
    {
      for(j = 0; j < n; j++)
      {
        scanf("%c", &map[i][j]); //讀取字串
      }
      getchar();
    }
    for(i = 0; i < m; i++)
    {
      for(j = 0; j < n; j++)
      {
        id[i][j] = 0; //標籤歸零
      }
    }
    for(i = 0; i < m; i++)
    {
      for(j = 0; j < n; j++)
      {
        if(map[i][j] == '@' && id[i][j] == 0)
        {
          find(i, j); //開始尋找
          table++;
        }
      }
    }
    printf("%d\n", table); //輸出共有幾個油田
  }
}

void find(int row, int column) //不斷搜尋直到沒有相鄰的油田
{
  if(row < 0 || row >= m)
  {
    return; //若超出陣列則回到前個find
  }
  if(column < 0 || column >= n)
  {
    return; //若超出陣列則回到前個find
  }
  if(map[row][column] == '*' || id[row][column] == 1)
  {
    return; //若已經檢查過或不是油田則回到前個find
  }
  id[row][column] = 1;
  find(row - 1, column - 1); //左上
  find(row - 1, column);     //上
  find(row - 1, column + 1); //右上
  find(row, column - 1);     //左
  find(row, column + 1);     //右
  find(row + 1, column - 1); //左下
  find(row + 1, column);     //下
  find(row + 1, column + 1); //右下
}