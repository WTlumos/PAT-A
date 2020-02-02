#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=210;
const int Inf=312312312;
int graph[maxn][maxn];
int path[maxn];
int n,m;
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		scanf("%d",&graph[a][b]);
		graph[b][a]=graph[a][b];
	}
	int k;
	scanf("%d",&k); int index=0; int minDis=Inf;
	for (int i = 1; i <= k; ++i)
	{
		scanf("%d",&a);
		int sum=0; int s,t;
		int visit[maxn]={false};
		scanf("%d",&s); int temp=s;
		bool na=false;
		bool cycle=true;
		bool simple=true;
		for (int j = 1; j < a; ++j)
		{
			scanf("%d",&t);
			if (graph[temp][t]!=Inf)
			{
				sum+=graph[temp][t];
			}else{
				na=true;
				cycle=false;
			}
			if (visit[t])
			{
				simple=false;
			}
			visit[t]=true;
			temp=t;
		}
		for (int j = 1; j <= n; ++j)
		{
			if (visit[j]==false)
			{
				cycle=false;
			}
		}
		printf("Path %d: ",i);
		if (s!=t||cycle==false)
		{
			if (na)
			{
				printf("NA (Not a TS cycle)\n");	
			}else{
				printf("%d (Not a TS cycle)\n",sum);
			}
			continue;	
		}
		if (simple)
		{
			printf("%d (TS simple cycle)\n",sum);
		}else{
			printf("%d (TS cycle)\n",sum);
		}
		if (sum<minDis)
		{
			minDis=sum;
			index=i;
		}
	}
	printf("Shortest Dist(%d) = %d\n",index,minDis);
	return 0;
}