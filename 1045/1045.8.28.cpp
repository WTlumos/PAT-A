#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,int> color;
vector<int> v;
int dp[10010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	int fav;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d",&fav);
		color[fav]=i;
	}
	int l;
	scanf("%d",&l);
	int a;
	for (int i = 0; i < l; ++i)
	{
		scanf("%d",&a);
		if (color[a]>0)
		{
			v.push_back(color[a]);
		}
	}
	int ans=-1;
	for (int i = 0; i < v.size(); ++i)
	{
		dp[i]=1;
		for (int j = 0; j < i; ++j)
		{
			if (v[i]>=v[j]&&dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
			}
		}
		ans=ans>dp[i]?ans:dp[i];
	}
	printf("%d\n",ans);
	return 0;
}