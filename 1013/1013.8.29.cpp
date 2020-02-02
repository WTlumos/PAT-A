#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1010;
vector<int> v[maxn];
bool visit[maxn]={false};
void dfs(int root)
{
	visit[root]=true;
	for (int i = 0; i < v[root].size(); ++i)
	{
		if (visit[v[root][i]]==false)
		{
			dfs(v[root][i]);
		}
	}

}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < k; ++i)
	{
		scanf("%d",&a);
		int cnt=0;
		fill(visit,visit+maxn,false);
		visit[a]=true;
		for (int j = 1; j <= n; ++j)
		{
			if (visit[j]==false)
			{
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}