#include <stdio.h>
#include <string.h>
#define max 10000

int main()
{
  int i, flag, j;
  char s[max], t[max];
  while(scanf("%s %s", s, t) != EOF)
  {
    flag = 0, j = 0;
    for(i = 0; i < strlen(s); i++)
    {
      for(j = j; j < strlen(t); j++) //只能往後檢查，若找到符合字元便跳出迴圈
      {
        if(s[i] == t[j])
        {
          flag++;
          break;
        }
      }
    }
    if(flag == strlen(s))
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }
  }
  return 0;
}