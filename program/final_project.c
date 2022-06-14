#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 4 // 實例的個數

void Print(int **, int **, int **, int **, int *, int, int);
void Scan(int **, int);
void Calc_Need(int **, int **, int **, int);
int Calc_New_Available(int **, int **, int *, int);
int Detect(int **, int **, int **, int *, int);

int main()
{
  srand(time(NULL)); // 保證每次產生不同亂數
  int N, i, j, input, p, p_count, mode, count;
  printf("Please enter the number of the processes : "); // 輸入行程數
  scanf("%d", &N);
  printf("Please choose the mode, 0 forrandom, 1 formanual input : "); // 選擇亂數產生或手動輸入行程的資源
  scanf("%d", &mode);
  // 分配記憶體空間給陣列
  int **max = (int **)malloc(N * sizeof(int *));
  int **need = (int **)malloc(N * sizeof(int *));
  int **allocation = (int **)malloc(N * sizeof(int *));
  int **available = (int **)malloc((N + 1) * sizeof(int *));
  int *stack = (int *)malloc(N * sizeof(int));
  int *request = (int *)malloc(M * sizeof(int));
  available[N] = (int *)malloc(M * sizeof(int));
  for(i = 0; i < N; i++)
  {
    max[i] = (int *)malloc(M * sizeof(int));
    need[i] = (int *)malloc(M * sizeof(int));
    allocation[i] = (int *)malloc(M * sizeof(int));
    available[i] = (int *)malloc(M * sizeof(int));
  }
  // 手動輸入
  if(mode)
  {
    printf("Please enter sthe instances of available: ");
    Scan(available, 0);
    for(i = 0; i < N; i++)
    {
      printf("Please enter the max of P%d : ", i);
      Scan(max, i);
      printf("Please enter the allocation of P%d : ", i);
      Scan(allocation, i);
      Calc_Need(max, allocation, need, i);
    }
  }
  // 亂數產生
  else
  {
    for(i = 0; i < M; i++)
    {
      available[0][i] = rand() % 5;
    }
    for(i = 0; i < N; i++)
    {
      for(j = 0; j < M; j++)
      {
        max[i][j] = rand() % 10 + 1;
        while((allocation[i][j] = rand() % 10) > max[i][j])
          ; // 確保產生的 allocation 比 max 還小
      }
      Calc_Need(max, allocation, need, i);
    }
  }
  printf("\n");
  count = Detect(allocation, need, available, stack, N);    // 利用回傳值確認是否在安全狀態
  Print(max, allocation, need, available, stack, N, count); // 輸出計算結果
  printf("\n");
  if(count == N) // 如果在安全狀態，選擇哪個行程要求實例
  {
    printf("Please choose which instances of process to alter : ");
    scanf("%d", &p);
    printf("Please enter the request instances of P%d : ", p);
    for(i = 0; i < M; i++)
    {
      scanf("%d", &request[i]);
    }
    while(!(input = Calc_New_Available(allocation, available, request, p))) // 如果要求超過可用的實例，重新輸入或直接離開
    {
      printf("Please enter the request instances of P%d : ", p);
      for(i = 0; i < M; i++)
      {
        scanf("%d", &request[i]);
      }
    }
    if(input == 2) // 輸出更改後的結果
    {
      Calc_Need(max, allocation, need, p);
      count = Detect(allocation, need, available, stack, N);
      Print(max, allocation, need, available, stack, N, count);
    }
  }
  // 釋放記憶體空間
  free(max);
  free(need);
  free(allocation);
  free(available);
  free(stack);
  free(request);
  return 0;
}

void Scan(int **array, int row)
{
  int i;
  for(i = 0; i < M; i++)
  {
    scanf("%d", (array[row] + i));
  }
}

void Print(int **max, int **allocation, int **need, int **available, int *stack, int N, int count)
{
  int i, j;
  printf("    Allocation       Max           Need        Available\n");
  for(i = 0; i < N; i++)
  {
    printf("P%d ", i);
    for(j = 0; j < M; j++)
    {
      printf("%2d ", *(allocation[i] + j));
    }
    printf("||");
    for(j = 0; j < M; j++)
    {
      printf("%2d ", *(max[i] + j));
    }
    printf("||");
    for(j = 0; j < M; j++)
    {
      printf("%2d ", *(need[i] + j));
    }
    printf("||");
    if(i <= count)
    {
      for(j = 0; j < M; j++)
      {
        printf("%2d ", *(available[i] + j));
      }
    }
    printf("\n");
  }
  if(N == count)
  {
    printf("               ||            ||            ||");
    for(i = 0; i < M; i++)
    {
      printf("%2d ", *(available[N] + i));
    }
    printf("\n\n");
    printf("It's safe! The order the process is : ");
    for(i = 0; i < N; i++)
    {
      printf("P%d ", stack[i]);
    }
    printf("\n");
  }
  else
  {
    printf("\n");
    printf("It's unsafe!\n");
  }
}

void Calc_Need(int **max, int **allocation, int **need, int row)
{
  int i;
  for(i = 0; i < M; i++)
  {
    *(need[row] + i) = *(max[row] + i) - *(allocation[row] + i);
  }
}

int Calc_New_Available(int **allocation, int **available, int *request, int row)
{
  int i, input, flag = 0;
  for(i = 0; i < M; i++)
  {
    if((*(available[0] + i) - request[i]) < 0)
    {
      flag = 1;
      printf("Exceeded the instances of the available!\n");
      printf("Press 0 to continue or Press 1 to exit : ");
      scanf("%d", &input);
      break;
    }
  }
  for(i = 0; i < M && flag == 0; i++)
  {
    *(available[0] + i) -= request[i];
    *(allocation[row] + i) += request[i];
  }
  if(flag)
  {
    return input;
  }
  else
  {
    return 2;
  }
}

int Detect(int **allocation, int **need, int **available, int *stack, int N)
{
  int *state = (int *)malloc(N * sizeof(int));
  int *check = (int *)malloc(N * sizeof(int));
  int i, j, sum_state, sum_check, break_count = 0, count = 0;
  for(i = 0; i < N; i++)
  {
    check[i] = 0;
    state[i] = 0;
  }
  for(i = 0; i < N; i++)
  {
    for(j = 0; j < M; j++)
    {
      if(*(available[0] + j) >= *(need[i] + j))
      {
        check[i]++;
      }
    }
  }
  do
  {
    sum_state = 0;
    sum_check = 0;
    for(i = 0; i < N; i++)
    {
      if(check[i] == M && !state[i])
      {
        state[i] = 1;
        stack[count] = i;
        for(j = 0; j < M; j++)
        {
          *(available[count + 1] + j) = *(available[count] + j) + *(allocation[i] + j);
        }
        count++;
      }
      else if(check[i] != M && !state[i])
      {
        check[i] = 0;
        for(j = 0; j < M; j++)
        {
          if(*(available[count] + j) >= *(need[i] + j))
          {
            check[i]++;
          }
        }
      }
    }
    for(i = 0; i < N; i++)
    {
      sum_state += state[i];
      if(check[i] == M)
      {
        sum_check++;
      }
    }
    if(sum_check == sum_state)
    {
      break_count++;
    }
  } while(sum_check != sum_state || break_count != 2);
  free(state);
  free(check);
  return count;
}