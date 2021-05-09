#include <stdio.h>
int px, py;
void f1()
{
	px--;
	py++;
}
void f2()
{
	px--;
}
void f3()
{
	py--;
} 
void f4()
{
	px++;
	py--;
}
void f5()
{
	px++;
}
void f6()
{
	py++;
}
int main()
{
	int n, sum, pw, t;
	while(scanf("%d", &n)!=EOF)
	{
		sum=0;pw=0;
		while(sum<n)
		{
			pw++;
			sum+=pw*6;		
		}
		
		sum-=pw*6;	
		n=n-sum;
		if(n==1)
			printf("%d 0\n", pw-1);
		else{
			px=pw;
			py=0;
			n--;
			t=pw;
			while(n && t)
			{
				n--;t--;
				f1();
			}
				
			t=pw;
			while(n && t)
			{
				n--;t--;
				f2();
			}
				
			t=pw;
			while(n && t)
			{
				n--;t--;
				f3();
			}
				
			t=pw;
			while(n && t)
			{
				n--;t--;
				f4();
			}
				
			t=pw;
			while(n && t)
			{
				n--;t--;
				f5();
			}
				
			t=pw;
			while(n && t)
			{
				n--;t--;
				f6();
			}
				
			printf("%d %d\n", px, py);
		}
	}
	return 0;
}