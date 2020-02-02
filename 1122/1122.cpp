#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=210;
const int Inf=312312312;
int graph[maxn][maxn];
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	int N,m;
	scanf("%d%d",&N,&m);
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
		int n;
		scanf("%d",&n);
		bool visit[N+1];
		fill(visit,visit+N+1,false);
		bool simple=true;  //简单
		bool path=true; //路径可达
		int s,t;
		scanf("%d",&s);
		int start=s;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d",&t);
			if(visit[t]==true){
				simple=false;
			}
			visit[t]=true;
			if (graph[s][t]==Inf)
			{
				path=false;
			}
			s=t;		
		}
		bool cycle=true;
		for (int i = 1; i <= N; ++i)
		{
			if (visit[i]==false)
			{
				cycle=false;
			}
		}
		//printf("%d %d %d\n",path,simple,cycle);
		if (start!=t||!path||!simple||!cycle)
		{
			printf("NO\n");
		}else{
			printf("YES\n");
		}

	}
	return 0;
}