#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[1001];
vector<int> ans;
int n,l;

int bfs(int root)
{
	bool visit[1001]={false};
	queue<int> q;
	q.push(root);
	visit[root]=true;
	int lastnode=root;
	int newnode=0;
	int level=1;
	int num=0;
	while(!q.empty())
	{
		int node=q.front();
		//printf("%d ",node);
		q.pop();
		for (int i = 0; i < v[node].size(); ++i)
		{
			if(visit[v[node][i]]==false&&level<=l){
				q.push(v[node][i]);
			    newnode=v[node][i];
			    visit[v[node][i]]=true;
			    num++;
			}
		}
		if (lastnode==node)
		{
			level++;
			lastnode=newnode;
		}
	}
	return num;
	
}
int main()
{
	scanf("%d%d",&n,&l);
	int m,a;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&m);
		for (int j = 0; j < m; ++j)
		{
			scanf("%d",&a);
			v[a].push_back(i);
		}
	}
	int k;
	scanf("%d",&k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d",&a);
		printf("%d\n",bfs(a));
	}
	return 0;
}