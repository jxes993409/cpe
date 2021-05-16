#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define max 100

void check(char,int *);
void index_to_binary(char [],int,int);
void convert_to_ascii(char [],int [],int);
void print(int [],int);

//encode[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

int main()
{
    char s[max],binary[max*6];
    int i,n,j;
    while(gets(s)!=NULL)
    {
        if(!strcmp(s,"#")) //遇到#直接輸出#
            printf("#");
        else if(!strcmp(s,"##")) //遇到##代表輸入結束
            break;
        else
        {
            n=strlen(s);
            j=n*6/8; //一個字元6位元，合併後再拆成8位元一個
            int index[n],decode[j]={0};
            memset(binary,'\0',max*6); //做binary陣列的清空 memset(陣列,想放入的值,長度)
            for(i=0;i<n;i++)
            {
                check(s[i],&index[i]); //查詢讀取到字元的索引值
                index_to_binary(binary,index[i],i); //將該字元的索引值轉換成二進制並記錄到binary
            }
            convert_to_ascii(binary,decode,j); //以8個為一組的二進制值轉成十進制
            print(decode,j); //輸出轉換結果
        }
        printf("\n");
    }
    return 0;
}

void check(char s,int *index)
{
    if(isupper(s))
        *index=s-'A'; //如果為大寫，索引值為字元-'A'的值
    else if(islower(s))
        *index=s-'a'+26; //如果為小寫，索引值為字元-'a'+26
    else if(isdigit(s))
        *index=s-'0'+52; //如果為數字，索引值為字元-'0'+52
    else if(s=='+')
        *index=62; //如果為'+'，索引值為62
    else if(s=='/')
        *index=63; //如果為'/'，索引值為63
    else if(s=='=')
        *index=0; //如果為'='，索引值為0
}

void index_to_binary(char binary[],int index,int i)
{
    int j;
    for(j=0;j<6;j++) //做2進制轉換，i*6為區分每個字元的空間
    {
        binary[5-j+i*6]=(index%2)+'0';
        index=index/2;
    }
}

void convert_to_ascii(char binary[],int decode[],int j)
{
    int i,k,m;
    for(i=0;i<j;i++)
    {
        for(k=0;k<8;k++)
            decode[i]+=(binary[7-k+8*i]-'0')*pow(2,k); //以8個為一組，將二進制轉成十進制
    }
}

void print(int decode[],int j)
{
    int i;
    for(i=0;i<j;i++)
        if(isprint(decode[i])) //如果為有效字元(ascii碼>32)，則輸出
            printf("%c",decode[i]);
}