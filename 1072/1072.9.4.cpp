#include<cstdio>
#include<algorithm>
using namespace std;
const int Inf=312312312;
const int maxn=1100;
int graph[maxn][maxn];
int dis[maxn];
bool visit[maxn]={false};
int n;
int convert(char c[])
{
	int idx=0;
	if (c[0]=='G')
	{
		for (int i = 1; c[i] != '\0'; ++i)
		{
			idx=idx*10+c[i]-'0';
		}
		idx+=n;
	}
	else{
		for (int i = 0; c[i] != '\0'; ++i)
		{
			idx=idx*10+c[i]-'0';
		}
	}
	return idx;
}
char c1[10],c2[10];
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	int m,k,ds;
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	for (int i = 0; i < k; ++i)
	{
		scanf("%s%s",c1,c2);
		int a=convert(c1);
		int b=convert(c2);
		scanf("%d",&graph[a][b]);
		graph[b][a]=graph[a][b];	
	}
	int minsum=Inf;
	int idx=0;
	int mindis=-1;
	for (int s = n+1; s <= n+m; ++s)
	{
		fill(dis,dis+maxn,Inf);
		fill(visit,visit+maxn,false);
		dis[s]=0;
		for (int i = 1; i <= n+m; ++i)
		{
			int u=-1; int min=Inf;
			for (int j = 1; j <= n+m; ++j)
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
			for (int v = 1; v <= n+m; ++v)
			{
				if (visit[v]==false&&graph[u][v]!=Inf)
				{
					if (dis[u]+graph[u][v]<dis[v])
					{
						dis[v]=dis[u]+graph[u][v];
					}
				}
			}
		}
		int flag=0; int sum=0; int min=Inf;
		for (int i = 1; i <= n; ++i)
		{
			if (dis[i]>ds)
			{
				flag=1;
				break;
			}
			if (dis[i]<min)
			{
				min=dis[i];
			}
			sum+=dis[i];
		}
		if (flag==0)
		{
			if (min>mindis)
			{
				minsum=sum;
				idx=s;
				mindis=min;
			}else if (min==mindis&&sum<minsum){
				minsum=sum;
				idx=s;
			}
		}
	}
	if (idx==0)
	{
		printf("No Solution\n");
		return 0;
	}
	printf("G%d\n",idx-n);
	printf("%.1f %.1f\n", 1.0*mindis,1.0*minsum/n);
	return 0;
}