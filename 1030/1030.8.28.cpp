#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=510;
const int Inf=312312312;
int graph[maxn][maxn];
int cost[maxn][maxn];
bool visit[maxn]={false};
int dis[maxn];
int co[maxn];
int pre[maxn]={};
int s;
vector<int> path;
void dfs(int t){
	if (s==t)
	{
		printf("%d ",s);
		return;
	}else{
		dfs(pre[t]);
	}
	printf("%d ",t);
}
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	int n,m,d;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		scanf("%d%d",&graph[a][b],&cost[a][b]);
		graph[b][a]=graph[a][b];
		cost[b][a]=cost[a][b];
	}
	fill(dis,dis+maxn,Inf);
	fill(co,co+maxn,Inf);
	dis[s]=0;
	co[s]=0;
	for (int i = 0; i < n; ++i)
	{
		int u=-1; int min=Inf;
		for (int j = 0; j < n; ++j)
		{
			if (visit[j]==false&&min>dis[j])
			{
				min=dis[j];
				u=j;
			}
		}
		if (u==-1)
		{
			break;
		}
		visit[u]=true;
		for (int v = 0; v < n; ++v)
		{
			if (visit[v]==false&&graph[u][v]!=Inf)
			{
				if (dis[u]+graph[u][v]<dis[v])
				{
					dis[v]=dis[u]+graph[u][v];
					co[v]=co[u]+cost[u][v];
					pre[v]=u;
				}else if(dis[u]+graph[u][v]==dis[v]){
					if (co[u]+cost[u][v]<co[v])
					{
						co[v]=co[u]+cost[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
	dfs(d);
	printf("%d %d\n",dis[d],co[d]);
	return 0;
}