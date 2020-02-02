#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,c1,c2;

const int maxn=501;
const int INF=312312;
int teams[maxn];
int graph[maxn][maxn];

int d[maxn];
bool visit[maxn]={false};
int num[maxn];
int w[maxn];

void Dijskstra(int s)
{
	fill(d,d+maxn,INF);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w));
	d[s]=0;
	num[s]=1;
	w[s]=teams[s];
	for (int i = 0; i < n; ++i)
	{
		int u=-1; 
		int min=INF;
		for (int j = 0; j < n; ++j)
		{
			if(visit[j]==false&&d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if (u==-1)
		{
			return;
		}
		visit[u]=true;
		for (int v = 0; v < n; ++v)
		{
			if (visit[v]==false&&graph[u][v]!=INF)
			{
				//printf("%d %d %d %d\n",u,v,d[u],d[v]);
				if(d[u]+graph[u][v]<d[v]){
					d[v]=d[u]+graph[u][v];
					w[v]=w[u]+teams[v];
					num[v]=num[u];
				}
				else if (d[u]+graph[u][v]==d[v])
				{
					if(w[v]<w[u]+teams[v]){
						w[v]=w[u]+teams[v];
					}
					num[v]+=num[u];
				}
			}
		}
	}

}

int main()
{
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&teams[i]);
	}
	int a,b,l;

	fill(graph[0],graph[0]+maxn*maxn,INF);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d",&a,&b,&l);
		graph[a][b]=l;
		graph[b][a]=l;
	}

	Dijskstra(c1);
	printf("%d %d\n",num[c2],w[c2]);

	return 0;
}