#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int w[10010]={};
int dp[10010]={};
bool choose[10010][110];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&w[i]);
	}
	sort(w+1,w+n+1,cmp);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >=w[i] ; j--)
		{
			if (dp[j]<=dp[j-w[i]]+w[i])
			{
				dp[j]=dp[j-w[i]]+w[i];
				choose[i][j]=true;
			}
		}
	}
	if (dp[m]!=m)
	{
		printf("No Solution\n");
		return 0;
	}
	int v=m;
	int cnt=n;
	vector<int> ans;
	while(v>0){
		if (choose[cnt][v])
		{
			ans.push_back(w[cnt]);
			v-=w[cnt];
		}
		cnt--;
	}
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d",ans[i]);
	}
	printf("\n");

	return 0;
}