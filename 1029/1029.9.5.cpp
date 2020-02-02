#include<cstdio>
int num[1000010]={};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&num[i]);
	}
	num[n+1]=312312312;
	int m;
	scanf("%d",&m);
	int a;
	int pos=(m+n+1)/2;
	int idx=1; int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		while (num[idx]<a)
		{
			cnt++;
			if (cnt==pos)
			{
				printf("%d\n",num[idx]);
			}
			idx++;
		}
		cnt++;
		if (cnt==pos)
		{
			printf("%d\n", a);
		}

	}
	while(idx<=n){
		cnt++;
		if (cnt==pos)
		{
			printf("%d\n", num[idx]);
		}
		idx++;
	}
	return 0;
}