#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int w[110]={};
struct node
{
	int weight;
	vector<int> child;
}v[110];
bool cmp(int a,int b){
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
		if (v[root].child.size()!=0)
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
	for (int i = 0; i < v[root].child.size(); ++i)
	{
		int temp=v[root].child[i];
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
	int id,k,kid;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&id,&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&kid);
			v[id].child.push_back(kid);
		}
		sort(v[id].child.begin(),v[id].child.end(),cmp);	
	}
	path[0]=0;
	dfs(0,v[0].weight,1);
	return 0;
}