#include<cstdio>
const int maxn=1001;
double num[maxn];
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
		num[a]+=b;
	}
	int cnt=0;
	for (int i = maxn; i >=0 ; i--)
	{
		if (num[i]!=0)
		{
			cnt++;
		}
	}
	printf("%d",cnt);
	for (int i = maxn; i >=0 ; i--)
	{
		if (num[i]!=0)
		{
			printf(" %d %.1f",i,num[i]);
		}
	}
	return 0;
}