#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
   int weight;
   vector<int> children;
}v[110];
bool cmp(int a,int b)
{
	return v[a].weight>v[b].weight;
}
int path[110]={};
int s;
void dfs(int root,int sum,int cnt)
{
	if (sum>s)
	{
		return;
	}
	if (sum==s)
	{
		if (v[root].children.size()!=0)
		{
			return;
		}
		for (int i = 0; i < cnt; ++i)
		{
			if (i!=0)
			{
				printf(" ");
			}
			printf("%d",v[path[i]].weight);
		}
		printf("\n");
		return;	
	}
	for (int i = 0; i < v[root].children.size(); ++i)
	{
		int temp=v[root].children[i];
		path[cnt]=temp;
		dfs(temp,sum+v[temp].weight,cnt+1);
	}
}
int main()
{
	int n,m;
	scanf("%d%d%d",&n,&m,&s);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&v[i].weight);
	}
	int id,k,children;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&id,&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&children);
			v[id].children.push_back(children);
		}
		sort(v[id].children.begin(),v[id].children.end(),cmp);
	}
	path[0]=0;
	dfs(0,v[0].weight,1);
	return 0;
}