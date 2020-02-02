#include<cstdio>
#include<vector>
using namespace std;
vector<int> v[110];
vector<int> level[110];
int maxdeep=-1;
void dfs(int root,int deep)
{
	if (deep>maxdeep)
	{
		maxdeep=deep;
	}
	if (v[root].size()==0)
	{
		level[deep].push_back(root);
		return;
	}
	for (int i = 0; i < v[root].size(); ++i)
	{
		dfs(v[root][i],deep+1);
	}
}
int main()
{
	int n,m,k,id,kid;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&id,&k);
		for (int i = 0; i < k; ++i)
		{
			scanf("%d",&kid);
			v[id].push_back(kid);
		}
	}
	dfs(1,0);
	int key=0;
	for (int i = 0; i <= maxdeep; ++i)
	{
		if (key>0)
		{
			printf(" ");
		}else{
			key++;
		}
		printf("%d",(int)level[i].size());
	}
	printf("\n");
	return 0;
}