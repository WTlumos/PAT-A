#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int weight[10010]={};
int dp[10010]={};
bool choose[10010][110];
vector<int> ans;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&weight[i]);
	}
	sort(weight+1,weight+n+1,cmp);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= weight[i]; j--)
		{
			if (dp[j]<=dp[j-weight[i]]+weight[i])
			{
				dp[j]=dp[j-weight[i]]+weight[i];
				choose[i][j]=true;
			}
		}
	}
	if (dp[m]!=m)
	{
		printf("No Solution\n");
	}else{
		int v=m;
		int idx=n;
		while(v>0){
			if (choose[idx][v])
			{
				ans.push_back(weight[idx]);
				v-=weight[idx];
			}
			idx--;
		}
	}
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d", ans[i]);
	}
	return 0;
}