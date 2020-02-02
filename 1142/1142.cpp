#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=210;
int graph[maxn][maxn];
int main()
{
	int nv,ne;
	scanf("%d%d",&nv,&ne);
	//初始化
	for (int i = 1; i <= nv; ++i)
	{
		for (int j = 1; j <= nv; ++j)
		{
			graph[i][j]=0;
		}
		graph[i][i]=1;
	}
	int a,b;
	for (int i = 0; i < ne; ++i)
	{
		scanf("%d%d",&a,&b);
		graph[a][b]=graph[b][a]=1;
	}
	int m,k;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&k);
		vector<int> v; //记录结点数
		bool visit[nv+1]; //当前结点
		fill(visit,visit+nv+1,false);
		bool clique=true; //连通图
		scanf("%d",&a);
		v.push_back(a);
		visit[a]=true;
		for (int i = 1; i < k; ++i)
		{
			scanf("%d",&b);
			v.push_back(b);	
			visit[b]=true;
			if (graph[a][b]==0)
			{
				clique=false;
			}
			a=b;	
		}
		int cnt=0;
		for (int i = 1; i <= nv; ++i)
		{
			if (visit[i]==false)
			{
				//printf("%d\n",i);
				int flag=0;
				for (int j = 0; j < v.size(); ++j)
				{
					if (graph[i][v[j]]==0)
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
		if (clique==false)
		{
			printf("Not a Clique\n");
		}else{
			if (cnt>0)
			{
				printf("Not Maximal\n");
			}else{
				printf("Yes\n");
			}
		}		
	}
	return 0;
}