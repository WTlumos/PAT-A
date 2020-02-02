#include<cstdio>
double num[100010]={};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",&num[i]);
	}
	double ans=0;
	for (int i = 0; i < n; ++i)
	{
		ans+=num[i]*(n-i)*(i+1);
	}
	printf("%.2f\n",ans);
	return 0;
}