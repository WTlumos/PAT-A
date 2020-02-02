#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=510;
const int Inf=312312312;
int graph[maxn][maxn];
int cost[maxn][maxn];
int dis[maxn];
int visit[maxn]={false};
int c[maxn];
int pre[maxn]={};
int s;
void dfs(int v)
{
	if(v==s){
		printf("%d ",v);
		return;
	}
	dfs(pre[v]);
	printf("%d ", v);
}
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	fill(cost[0],cost[0]+maxn*maxn,Inf);
	int n,m,d;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	int c1,c2,ds,co;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d%d",&c1,&c2,&ds,&co);
		graph[c1][c2]=graph[c2][c1]=ds;
		cost[c1][c2]=cost[c2][c1]=co;
	}
	fill(dis,dis+maxn,Inf);
	fill(c,c+maxn,Inf);
	dis[s]=0;
	c[s]=0;
	for (int i = 0; i < n; ++i)
	{
		int u=-1; int min=Inf;
		for (int j = 0; j < n; ++j)
		{
			if (visit[j]==false&&dis[j]<min)
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
			if(visit[v]==false&&graph[u][v]!=Inf){
				if (dis[u]+graph[u][v]<dis[v])
				{
					dis[v]=dis[u]+graph[u][v];
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
				}else if(dis[u]+graph[u][v]==dis[v]){
					if (c[u]+cost[u][v]<c[v])
					{
						c[v]=c[u]+cost[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
	dfs(d);
	printf("%d %d\n",dis[d],c[d]);

	return 0;
}