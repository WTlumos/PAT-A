#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=510;
const int Inf=312312312;
int graph[maxn][maxn];
int timecost[maxn][maxn];
int dis[maxn];
bool visit[maxn]={false};
int co[maxn];
int pre[maxn]={};
int num[maxn]={};
int s,t;
void dfs(vector<int> &v,int a)
{
	if (a==s)
	{
		return;
	}else{
		dfs(v,pre[a]);
	}
	v.push_back(a);
}
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	fill(timecost[0],timecost[0]+maxn*maxn,Inf);
	int n,m;
	scanf("%d%d",&n,&m);
	int v1,v2,oneway;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d",&v1,&v2,&oneway);
		scanf("%d%d",&graph[v1][v2],&timecost[v1][v2]);
		if (oneway==0)
		{
			graph[v2][v1]=graph[v1][v2];
			timecost[v2][v1]=timecost[v1][v2];
		}
	}
	scanf("%d%d",&s,&t);
	fill(dis,dis+maxn,Inf);
	fill(co,co+maxn,Inf);
	dis[s]=0;
	co[s]=0;
	for (int i = 0; i < n; ++i)
	{
		int u=-1;int min=Inf;
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
				if (dis[u]+graph[u][v]<dis[v])
				{
					dis[v]=dis[u]+graph[u][v];
					co[v]=timecost[u][v]+co[u];
					pre[v]=u;
				}else if(dis[u]+graph[u][v]==dis[v]){
					if (co[u]+timecost[u][v]<co[v])
					{
						co[v]=co[u]+timecost[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
	vector<int> ansD;
	dfs(ansD,t);
	fill(visit,visit+maxn,false);
	fill(pre,pre+maxn,0);
	fill(co,co+maxn,Inf);
	fill(num,num+maxn,Inf);
	co[s]=0;
	num[s]=1;
	for (int i = 0; i < n; ++i)
	{
		int u=-1;
		int min=Inf;
		for (int j = 0; j < n; ++j)
		{
			if (visit[j]==false&&co[j]<min)
			{
				u=j;
				min=co[j];
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
				if (co[u]+timecost[u][v]<co[v])
				{
					co[v]=co[u]+timecost[u][v];
					num[v]=num[u]+1;
					pre[v]=u;
				}else if(co[u]+timecost[u][v]==co[v]){
					if (num[u]+1<num[v])
					{
						num[v]=num[u]+1;
						pre[v]=u;
					}

				}
			}
		}
	}
	vector<int> ansT;
	dfs(ansT,t);

	if (ansD==ansT)
	{
		printf("Distance = %d; Time = %d: %d", dis[t],co[t],s);
		for (int i = 0; i < ansD.size(); ++i)
		{
			printf(" -> %d",ansD[i]);
		}
		printf("\n");
	}else{
		printf("Distance = %d: %d", dis[t],s);
		for (int i = 0; i < ansD.size(); ++i)
		{
			printf(" -> %d",ansD[i]);
		}
		printf("\n");

		printf("Time = %d: %d", co[t],s);
		for (int i = 0; i < ansT.size(); ++i)
		{
			printf(" -> %d",ansT[i]);
		}
		printf("\n");
	}
	return 0;
}