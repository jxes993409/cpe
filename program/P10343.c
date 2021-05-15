#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define max 100

void check(const char [],char,int *);
void index_to_binary(char [],int,int);
void combine(char [],int);
void convert_to_ascii(char [],int [],int);
void print(int [],int);

int main()
{
    const char encode[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char s[max],binary[max*6];
    int i,n,j;
    while(gets(s)!=NULL)
    {
        if(!strcmp(s,"#"))
            printf("#");
        else if(!strcmp(s,"##"))
            break;
        else
        {
            n=strlen(s);
            j=n*6/8;
            int index[n],decode[j]={0};
            memset(binary,'\0',max);
            for(i=0;i<n;i++)
            {
                check(encode,s[i],&index[i]);
                index_to_binary(binary,index[i],i);
            }
            combine(binary,n);
            convert_to_ascii(binary,decode,j);
            print(decode,j);
        }
        printf("\n");
    }
    return 0;
}

void check(const char encode[],char s,int *index)
{
    if(isupper(s))
        *index=encode[s-'A']-'A';
    else if(islower(s))
        *index=encode[s-'a'+26]-'a'+26;
    else if(isdigit(s))
        *index=encode[s-'0'+52]-'0'+52;
    else
    {
        if(s=='+')
            *index=encode[s-'+'+62]-'+'+62;
        else if(s=='/')
            *index=encode[s-'/'+63]-'/'+63;
        else if(s=='=')
            *index=0;
    }
}

void index_to_binary(char binary[],int index,int i)
{
    int j;
    for(j=0;j<6;j++)
    {
        binary[j+i*6]=(index%2)+'0';
        index=index/2;
    }
}

void combine(char binary[],int n)
{
    int i,j;
    char temp[n*6];
    strcpy(temp,binary);
    for(j=0;j<n;j++)
    {    
        for(i=0;i<6;i++)
            binary[i+j*6]=temp[5-i+j*6];
    }
}

void convert_to_ascii(char binary[],int decode[],int j)
{
    int i,k,m;
    for(i=0;i<j;i++)
    {
        for(k=0;k<8;k++)
            decode[i]+=(binary[7-k+8*i]-'0')*pow(2,k);
    }
}

void print(int decode[],int j)
{
    int i;
    for(i=0;i<j;i++)
        if(isprint(decode[i]))
            printf("%c",decode[i]);
}