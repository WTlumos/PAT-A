#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=510;
const int Inf=312312312;
int graph[maxn][maxn];
int weight[510]={};
int dis[maxn];
bool visit[maxn]={false};
int num[maxn]={};
int w[maxn]={};
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	int n,m,c1,c2;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&weight[i]);
	}
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		scanf("%d",&graph[a][b]);
		graph[b][a]=graph[a][b];
	}
	fill(dis,dis+maxn,Inf);
	dis[c1]=0;
	w[c1]=weight[c1];
	num[c1]=1;
	for (int i = 0; i < n; ++i)
	{
		int u=-1; int min=Inf;
		for (int j = 0; j < n; ++j)
		{
			if (visit[j]==false&&min>dis[j])
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
				if (dis[u]+graph[u][v]<dis[v])
				{
					dis[v]=dis[u]+graph[u][v];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				}else if(dis[v]==dis[u]+graph[u][v]){
					if (w[v]<w[u]+weight[v])
					{
						w[v]=w[u]+weight[v];
					}
					num[v]+=num[u];
				}
			}
		}	
	}
	printf("%d %d\n",num[c2],w[c2]);
	return 0;
}