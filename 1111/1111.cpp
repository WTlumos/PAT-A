#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=510;
const int Inf=312312312;
int graph[maxn][maxn];
int cost[maxn][maxn];
int dis[maxn];
bool visit[maxn]={false};
int co[maxn];
int pre[maxn]={};
int times[maxn]={};
int number[maxn]={};
vector<int> dispath,timepath;
int s,t;
void dfs(int u,vector<int> &v)
{
    if (s==u)
    {
        v.push_back(s);
        return;   
    }
    dfs(pre[u],v);
    v.push_back(u);
}
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	fill(cost[0],cost[0]+maxn*maxn,Inf);
	int n,m;
    scanf("%d%d",&n,&m);
    int v1,v2,oneway,length,timecost;
    for (int i = 0; i < m; ++i)
    {
    	scanf("%d%d%d%d%d",&v1,&v2,&oneway,&length,&timecost);
    	graph[v1][v2]=length;
    	cost[v1][v2]=timecost;
    	if (oneway==0)
    	{
    		graph[v2][v1]=length;
            cost[v2][v1]=timecost;
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
    				if (co[v]>co[u]+cost[u][v])
                    {
                       co[v]=co[u]+cost[u][v];
                       pre[v]=u;
                    }
    			}
    		}
    	}
    }
    dfs(t,dispath);
    fill(times,times+maxn,Inf);
    fill(visit,visit+maxn,false);
    fill(pre,pre+maxn,0);
    fill(number,number+maxn,Inf);
    times[s]=0; number[s]=1;
    for (int i = 0; i < n; ++i)
    {
        int u=-1;int min=Inf;
        for (int j = 0; j < n; ++j)
        {
            if (visit[j]==false&&times[j]<min)
            {
               min=times[j];
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
            if (visit[v]==false&&cost[u][v]!=Inf)
            {
                if (times[u]+cost[u][v]<times[v])
                {
                    times[v]=times[u]+cost[u][v];
                    number[v]=number[u]+1;
                    pre[v]=u;
                }else if(times[u]+cost[u][v]==times[v]){
                    if (number[v]>number[u]+1)
                    {
                        number[v]=number[u]+1;
                        pre[v]=u;
                    }
                }
            }
        }
    }
    dfs(t,timepath);
    if (timepath==dispath)
    {
        printf("Distance = %d; Time = %d: %d",dis[t],times[t],dispath[0]);
        for (int i = 1; i < dispath.size(); ++i)
        {
            printf(" -> %d", dispath[i]);
        }
        printf("\n");
    }else{
        printf("Distance = %d: %d",dis[t],dispath[0]);
        for (int i = 1; i < dispath.size(); ++i)
        {
            printf(" -> %d", dispath[i]);
        }
        printf("\n");
        printf("Time = %d: %d",times[t],timepath[0]);
        for (int i = 1; i < timepath.size(); ++i)
        {
            printf(" -> %d", timepath[i]);
        }
        printf("\n");
    }
	return 0;
}