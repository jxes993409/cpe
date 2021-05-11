#include <stdio.h>
int px, py;
void f1() //左下
{
	px--;
	py++;
}
void f2() //左
{
	px--;
}
void f3() //上
{
	py--;
} 
void f4() //右上
{
	px++;
	py--;
}
void f5() //右
{
	px++;
}
void f6() //下
{
	py++;
}
int main()
{
	int n,sum,pw,t;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;pw=0;
		while(sum<n) //讀取所在層數
		{
			pw++;
			sum+=pw*6;		
		}
		
		sum-=pw*6;	
		n=n-sum; //找出該層數第n+1個
		if(n==1)
			printf("%d 0\n",pw-1);
		else{
			px=pw;
			py=0;
			//從該層數字最大者開始搜尋
			n--;
			t=pw;
			//依序由左下、左、上、右上、右、下來符合順時針搜尋法則，每迴圈執行至超出該層為止
			while(n && t)
			{
				n--;t--;
				f1();
			}
			t=pw; //重置層數
			while(n && t)
			{
				n--;t--;
				f2();
			}
			t=pw; //重置層數
			while(n && t)
			{
				n--;t--;
				f3();
			}
			t=pw; //重置層數
			while(n && t)
			{
				n--;t--;
				f4();
			}
			t=pw; //重置層數
			while(n && t)
			{
				n--;t--;
				f5();
			}
			t=pw; //重置層數
			while(n && t)
			{
				n--;t--;
				f6();
			}
			printf("%d %d\n",px, py);
		}
	}
	return 0;
}