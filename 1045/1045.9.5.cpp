#include<cstdio>
#include<map>
using namespace std;
map<int,int> pos;
int num[210]={};
int dp[210]={};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d",&a);
		pos[a]=i;
	}
	scanf("%d",&m);
	int cnt=0;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&a);
		if (pos[a]>0)
		{
			num[cnt++]=pos[a];
		}
	}
    int max=-1;
	for (int i = 0; i < cnt; ++i)
	{
		dp[i]=1;
		for (int j = 0; j < i ; ++j)
		{
			if (num[j]<=num[i]&&dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
			}
		}
        max=dp[i]>max?dp[i]:max;
    }
	printf("%d\n", max);
	return 0;
}