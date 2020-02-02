#include<cstdio>
#include<cstring>
const int maxn=1001;
const int INF=312312;
int graph[maxn][maxn];
int visit[maxn]={0};
int n;
void dfs(int root)
{
	visit[root]=1;
	for (int i = 1; i <= n; ++i)
	{
		if (visit[i]==0&&graph[root][i]==1)
		{
			dfs(i);
		}
	}

}
int main()
{
	int m,k;
	scanf("%d%d%d",&n,&m,&k);
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		graph[a][b]=graph[b][a]=1;		
	}
	for (int i = 0; i < k; ++i)
	{
		scanf("%d",&a);
		int cnt=0;
		memset(visit,0,sizeof(visit));
		visit[a]=1;
		for (int j = 1; j <= n; ++j)
		{
			if (visit[j]==0)
			{
				dfs(j);
				cnt++;

			}
		}
		printf("%d\n", cnt-1);
	}


	return 0;
}