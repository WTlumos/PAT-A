#include<cstdio>
const int maxn=2020;
double num[1010]={};
double ans[maxn]={};
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
		for (int j = 0; j < 1010; ++j)
		{
			ans[j+a]+=b*num[j];
		}
	}
	int cnt=0;
	for (int i = 0; i < maxn; ++i)
	{
		if (ans[i]!=0)
		{
			cnt++;
		}
	}
	printf("%d ",cnt);
	for (int i = maxn-1; i >= 0 ; i--)
	{
		if (ans[i]!=0)
		{
			printf(" %d %.1f",i,ans[i]);
		}
	}
	printf("\n");
	return 0;
}