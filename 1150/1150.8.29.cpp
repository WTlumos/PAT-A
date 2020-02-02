#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=210;
const int Inf=312312312;
int graph[maxn][maxn];
bool visit[maxn]={false};
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		scanf("%d",&graph[a][b]);
		graph[b][a]=graph[a][b];
	}
	int k;
	scanf("%d",&k);
	int s,t; int min=Inf; int idx=0;
	for (int i = 1; i <= k; ++i)
	{
		printf("Path %d:",i);
		fill(visit,visit+210,false);
		scanf("%d%d",&a,&s);
		int start=s;
		//visit[s]=true;
		int sum=0;
		bool connected=true;
		bool simple=true;
		bool cycle=true;
		bool na=false;
		for (int j = 1; j < a; ++j)
		{
			scanf("%d",&t);
			if (graph[s][t]==Inf)
			{
				connected=false;
				na=true;
			}else{
				sum+=graph[s][t];
			}
			if (visit[t]==true)
			{
				simple=false;
			}
			visit[t]=true;
			s=t;
		}
		for (int j = 1; j <= n; ++j)
		{
			if (visit[j]==false)
			{
				cycle=false;
			}
		}
		if (start!=t||!connected||!cycle)
		{
			if (na)
			{
				printf(" NA (Not a TS cycle)\n");
			}else{
				printf(" %d (Not a TS cycle)\n",sum);
			}
			continue;
		}else{
			if (simple)
			{
				printf(" %d (TS simple cycle)\n", sum);
			}else{
				printf(" %d (TS cycle)\n", sum);
			}
			if (sum<min)
			{
				min=sum;
				idx=i;
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n",idx,min);
	return 0;
}