/*
visits every edge exactly once
*/
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=510;
vector<int> v[maxn];
bool visit[maxn]={false};
int cnt=0;
void dfs(int root)
{
	visit[root]=true;
	cnt++;
	for (int i = 0; i < v[root].size(); ++i)
	{
		if (visit[v[root][i]]==false)
		{
			dfs(v[root][i]);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int even=0;
	for (int i = 1; i <= n; ++i)
	{
		printf("%lu",v[i].size());
		if (v[i].size()%2==0)
		{
			even++;
		}
		if (i<n)
		{
			printf(" ");
		}else{
			printf("\n");
		}
	}
    dfs(1);
    if (even==n&&cnt==n)
    {
    	printf("Eulerian\n");
    }else if(even==n-2&&cnt==n){
    	printf("Semi-Eulerian\n");
    }else{
    	printf("Non-Eulerian\n");
    }
	return 0;
}