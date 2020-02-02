#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=510;
const int Inf=312312312;
int team[maxn]={};
int graph[maxn][maxn];
int dis[maxn];
bool visit[maxn]={false};
int num[maxn]={};
int w[maxn]={};
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&team[i]);
	}
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		scanf("%d",&graph[a][b]);
		graph[b][a]=graph[a][b];
	}
	fill(dis,dis+maxn,Inf);
	dis[s]=0;
	num[s]=1;
	w[s]=team[s];
	for (int i = 0; i < n; ++i)
	{
		int u=-1; int min=Inf;
		for (int j = 0; j < n; ++j)
		{
			if (visit[j]==false&&dis[j]<min)
			{
				u=j;
				min=dis[j];
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
				if (dis[v]>dis[u]+graph[u][v])
				{
					dis[v]=dis[u]+graph[u][v];
					num[v]=num[u];
					w[v]=w[u]+team[v];
				}else if (dis[v]==dis[u]+graph[u][v]){
					if (w[u]+team[v]>w[v])
					{
						w[v]=w[u]+team[v];
					}
					num[v]+=num[u];
				}
			}
		}
	}
	printf("%d %d\n",num[t],w[t]);

	return 0;
}