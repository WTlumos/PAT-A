#include<cstdio>
int k[200010]={};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&k[i]);
	}
	k[n+1]=0x7ffffff;
	int m;
	scanf("%d",&m);
	int pos=(n+m+1)/2;
	int temp;
	int cnt=0;
	int i=1;
	for (int j = 1; j <= m; ++j)
	{
		scanf("%d",&temp);
		while(k[i]<temp){
			cnt++;
			if (cnt==pos)
			{
				printf("%d\n",k[i]);
			}
			i++;
		}
		cnt++;
		if (cnt==pos)
		{
			printf("%d\n",temp);
		}
	}
	while(i<=n){
		cnt++;
		if (cnt==pos)
		{
			printf("%d\n",k[i]);
		}
		i++;
	}
	return 0;
}