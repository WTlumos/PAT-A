#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=101;
int w[maxn]={0};
struct node
{
	int w;
	vector<int> children;
};
node v[maxn];
bool cmp(int a,int b)
{
	return v[a].w>v[b].w;
}
int s;
int path[maxn];
void dfs(int root,int sum,int num)
{
	if (sum>s)
	{
		return;
	}
	if(sum==s){
		if(v[root].children.size()!=0)
		{
			return;
		}
		for (int i = 0; i < num; ++i)
		{
			printf("%d",v[path[i]].w);
			if (i<num-1)
			{
				printf(" ");
			}else{
				printf("\n");
			}
		}
		return;
	}
	for (int i = 0; i < v[root].children.size(); ++i)
	{
		int node=v[root].children[i];
		path[num]=node;
		dfs(node,sum+v[node].w,num+1);
	}
}
int main()
{
	int n,m;
	scanf("%d%d%d",&n,&m,&s);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&v[i].w);
	}
	int root,k,kid;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&root,&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&kid);
			v[root].children.push_back(kid);
		}
		sort(v[root].children.begin(), v[root].children.end(),cmp);
	}
	path[0]=0;
	dfs(0,v[0].w,1);

	return 0;
}