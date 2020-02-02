#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,int> exist;
int fav[210]={};
vector<int> ans;
int dp[100010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d",&fav[i]);
		exist[fav[i]]=i;
	}
	int l;
	scanf("%d",&l);
	int a;
	for (int i = 0; i < l; ++i)
	{
		scanf("%d",&a);
		if (exist[a]>0)
		{
			ans.push_back(exist[a]);
		}
	}
	int max=-1;
	for (int i = 0; i < ans.size(); ++i)
	{
		dp[i]=1;
		for (int j = 0; j < i; ++j)
		{
			if (ans[i]>=ans[j]&&dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
			}
		}
		max=max>dp[i]?max:dp[i];
	}
	printf("%d\n", max);
	return 0;
}