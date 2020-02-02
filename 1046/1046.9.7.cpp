#include<cstdio>
int num[100010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int a; int sum=0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a);
		num[i]=num[i-1]+a;
		sum+=a;
	}
	int m;
	scanf("%d",&m);
	int b;
	for (int i = 0; i < m; ++i)
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
			printf("%d\n",temp);
		}else{
			printf("%d\n", sum-temp);
		}
	}
	return 0;
}