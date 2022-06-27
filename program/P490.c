#include <stdio.h>
#include <string.h>
#define max 100

int main()
{
  int count = 0, maxlen = 0, i, j;
  char s[max][max];
  while(gets(s[count])) //輸入失敗時跳出迴圈
  {
    if(!(strcmp(s[count], "\t"))) //若讀到tab，則跳出迴圈
    {
      count--;
      break;
    }
    if(strlen(s[count]) > maxlen) //找出最長的字串並記錄
    {
      maxlen = strlen(s[count]);
    }
    count++; //紀錄共有幾行
  }
  for(i = 0; i < maxlen; i++) //換列
  {
    for(j = count; j >= 0; j--)
    {
      if(i >= strlen(s[j]))
      {
        printf(" ");
      }
      else
      {
        printf("%c", s[j][i]);  //輸出列，從最下面的元素開始輸出
      }
    }
    printf("\n");
  }
  return 0;
}