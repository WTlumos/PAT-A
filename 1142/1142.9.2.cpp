#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=210;
const int Inf=312312312;
int graph[maxn][maxn];
bool visit[maxn]={false};
set<int> s;
int main()
{
	for (int i = 1; i < maxn; ++i)
	{
		for (int j = 1; j < maxn; ++j)
		{
			graph[i][j]=Inf;
		}
		graph[i][i]=1;
	}
	int nv,ne;
	scanf("%d%d",&nv,&ne);
	int a,b;
	for (int i = 0; i < ne; ++i)
	{
		scanf("%d%d",&a,&b);
		graph[a][b]=graph[b][a]=1;
	}
	int m;
	scanf("%d",&m);
	int k;
	while(m--)
	{
		bool clique=true; bool maxiaml=true;
		fill(visit,visit+maxn,false);
		s.clear();
		scanf("%d%d",&k,&a);
		visit[a]=true;
		s.insert(a);
		for (int i = 1; i < k; ++i)
		{
			scanf("%d",&b);
			s.insert(b);
			if (graph[a][b]==Inf)
			{
				clique=false;
			}
			visit[b]=true;
			a=b;
		}
		if (!clique)
		{
			printf("Not a Clique\n");
			continue;
		}
		int cnt=0;
		for (int i = 1; i <= nv; ++i)
		{
			if (visit[i]==false)
			{
				int flag=0;
				for (set<int>::iterator j = s.begin(); j != s.end(); ++j)
				{
					if (graph[i][*j]==Inf)
					{
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					cnt++;
				}
			}
		}
		if (cnt==0)
		{
			printf("Yes\n");
		}else{
			printf("Not Maximal\n");
		}
		
	}
	return 0;
}