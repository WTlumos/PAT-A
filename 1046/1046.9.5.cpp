#include<cstdio>
int num[100010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int sum=0;
	int a;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a);
		num[i]=num[i-1]+a;
		sum+=a;
		//printf("%d %d\n", i,num[i]);
	}
	int k;
	scanf("%d",&k);
	int b;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%d",&a,&b);
		if (a<b)
		{
			int temp=b;
			b=a;
			a=temp;
		}
		int temp=num[a-1]-num[b-1];
		if (sum-temp>temp)
		{
			printf("%d\n", temp);
		}else{
			printf("%d\n",sum-temp);
		}
	}
	return 0;
}