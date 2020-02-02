#include<cstdio>
int s1[200010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&s1[i]);
	}
	s1[n+1]=312312312;
	int m;
	scanf("%d",&m);
	int pos=(n+m+1)/2;
	int j=1; int cnt=0;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d",&a);
		while (s1[j]<a){
			cnt++;
			if (cnt==pos)
			{
				printf("%d\n",s1[j]);
			}
			j++;
		}
		cnt++;
		if (cnt==pos)
		{
			printf("%d\n", a);
		}	
	}
	while(j<=n){
		cnt++;
		if (cnt==pos)
		{
			printf("%d\n",s1[j]);
		}
		j++;
	}
	return 0;
}