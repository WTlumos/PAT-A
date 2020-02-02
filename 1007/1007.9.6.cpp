#include<cstdio>
int num[10010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	int dp=0;
	int left=0;
	int right=n-1;
	int temp=0;
	int sum=-1;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);
		dp+=num[i];
		if (dp<0)
		{
			dp=0;
			temp=i+1;
		}
		else if (dp>sum)
		{
			sum=dp;
			left=temp;
			right=i;
		}
	}
	if (sum<0)
	{
		sum=0;
	}
	printf("%d %d %d\n",sum,num[left],num[right]);
	return 0;
}