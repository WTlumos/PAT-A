#include<cstdio>
int dis[100010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int sum=0; int d;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&d);
        dis[i]=dis[i-1]+d;
		sum+=d;
	}
	int m;
	scanf("%d",&m);
	int s,t;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&s,&t);
		if (s>t)
		{
			int temp=s;
			s=t;
			t=temp;
		}
		int temp=dis[t-1]-dis[s-1];
		if (sum-temp>temp)
		{
			printf("%d\n",temp);
		}else{
			printf("%d\n",sum-temp);
		}

	}
	return 0;
}