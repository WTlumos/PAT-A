#include<cstdio>
double num[1001];
double ans[2002];
int main()
{
	int k;
	scanf("%d",&k);
	int a;
	double b;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%lf",&a,&b);
		num[a]+=b;
	}
	scanf("%d",&k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%lf",&a,&b);
		for (int j = 0; j < 1001; ++j)
		{
			ans[j+a]+=num[j]*b;
		}
	}
	int cnt=0;
	for (int i = 2000; i >=0 ; i--)
	{
		if (ans[i]!=0)
		{
			cnt++;
		}
	}
	printf("%d",cnt);
	for (int i = 2000; i >=0 ; i--)
	{
		if (ans[i]!=0)
		{
			printf(" %d %.1f",i,ans[i]);
		}
	}
	return 0;
}