#include<cstdio>
int num[10010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	int left,right,sum,dp,temp;
	dp=0; sum=-1; left=right=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		num[i]=a;
		dp+=a;
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