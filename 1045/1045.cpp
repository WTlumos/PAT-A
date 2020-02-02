#include<cstdio>
int fav[201]={};
int a[10010]={};
//fav[i] 与 str[j] 之前的最长不下降子序列
int dp[10010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	int x;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d",&x);
		fav[x]=i;
	}
	int l;
	scanf("%d",&l);
	int index=0;
	for (int i = 0; i < l; ++i)
	{
		scanf("%d",&x);
	    if (fav[x]>0)
	    {
	    	a[index++]=fav[x];
	    }
	}
	int ans=1;
	for (int i = 0; i < index; ++i)
	{
		dp[i]=1;
		for (int j =0; j<i; ++j)
		{
			if(a[i]>=a[j]&&dp[j]+1>dp[i]){
				dp[i]=dp[j]+1;
			}
		}
		ans=ans>dp[i]?ans:dp[i];
	}
	printf("%d\n",ans);


	return 0;
}