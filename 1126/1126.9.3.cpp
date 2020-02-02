#include<cstdio>
#include<vector>
using namespace std;
vector<int> v[510];
bool visit[510]={false};
int cnt=1;
void dfs(int root)
{
	visit[root]=true;
	for (int i = 0; i < v[root].size(); ++i)
	{
		if (visit[v[root][i]]==false)
		{
			cnt++;
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
	int even=0; int odd=0;
	for (int i = 1; i <= n; ++i)
	{
		int size=v[i].size();
		if (visit[i]==false)
		{
			dfs(i);
		}
		if (size%2==0)
		{
			even++;
		}else{
			odd++;
		}
		if (i!=1)
		{
			printf(" ");
		}
		printf("%d",size);
	}
	printf("\n");
	if (even==n&&cnt==n)
	{
		printf("Eulerian\n");
	}else if (odd==2&&cnt==n)
	{
		printf("Semi-Eulerian\n");
	}else{
		printf("Non-Eulerian\n");
	}

	return 0;
}