#include<cstdio>
using namespace std;
int a[10010];
int main()
{
	int k;
	scanf("%d",&k);
	int temp,j,dp;
	dp=0;
	int sum=-1;
	int left,right;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d",&a[i]);
		dp+=a[i];
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
	printf("%d %d %d\n",sum,a[left],a[right]);

	return 0;
}