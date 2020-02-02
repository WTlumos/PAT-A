#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10010;
int face[maxn]={0};
int dp[maxn]={0};
int choice[maxn][maxn]={false};
int n,m;
vector<int> ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&face[i]);
	}
	sort(face+1, face+n+1,cmp);
	for (int i = 1; i <= n; ++i)
	{
		for (int v = m; v >=face[i] ; v--)
		{
			if(dp[v]<=dp[v-face[i]]+face[i]){
				choice[i][v]=true;
				dp[v]=dp[v-face[i]]+face[i];
			}
		}
	}
	if (dp[m]!=m)
	{
		printf("No Solution\n");
	}else{
		int v=m;
		int index=n;
		while(v>0){
			if (choice[index][v]==true)
			{
				ans.push_back(face[index]);
				v-=face[index];
			}
			index--;
		}
		for (int i = 0; i < ans.size(); ++i)
		{
			
			printf("%d",ans[i]);
			if (i<ans.size()-1)
			{
				printf(" ");
			}else{
				printf("\n");
			}
		}
	}

	
	return 0;
}