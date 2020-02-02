#include<cstdio>
#include<vector>
using namespace std;
vector<int> v[110];
int maxdeep=-1;
int level[110];
bool visit[110]={false};
void dfs(int root,int deep){
	//printf("%d\n", deep);
	if (deep>maxdeep)
	{
		maxdeep=deep;
	}
	if (v[root].size()==0)
	{
		level[deep]++;
		return;
	}
	for (int i = 0; i < v[root].size(); ++i)
	{
		dfs(v[root][i],deep+1);
	}

}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int id,k,a;
	while(m--)
	{
		scanf("%d%d",&id,&k);
		for (int i = 0; i < k; ++i)
		{
			scanf("%d",&a);
			v[id].push_back(a);
		}
	}
	dfs(1,0);
	for (int i = 0; i <= maxdeep; ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d",level[i]);
	}
	printf("\n");
	return 0;
}