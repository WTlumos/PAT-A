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
		graph[a][b]=graph[b][a]=1;
	}
	int k;
	scanf("%d",&k);
	while(k--)
	{
		fill(visit,visit+maxn,false);
		bool simple=true; bool cycle=true; bool connected=true;
		int start,s,t; int a;
		scanf("%d%d",&a,&s);
		start=s;
		for (int i = 1; i < a; ++i)
		{
			scanf("%d",&t);
			if (visit[t]==true)
			{
				simple=false;
			}
			visit[t]=true;
			if (graph[s][t]==Inf)
			{
				connected=false;
			}
			s=t;
		}
		for (int i = 1; i <= n; ++i)
		{
			if (visit[i]==false)
			{
				cycle=false;
			}
		}
		//printf("%d %d %d %d\n", start!=t,!simple,!cycle,!connected);
		if (start!=t||!simple||!cycle||!connected)
		{
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}

	return 0;
}