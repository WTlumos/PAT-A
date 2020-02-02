#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[1010];
int l;
int bfs(int root){
	bool visit[1010]={false};
	queue<int> q;
	q.push(root);
	visit[root]=true;
	int lastnode=root;
	int nownode=0;
	int level=1;
	int num=0;
	while(!q.empty())
	{
		int temp=q.front();
		//printf("%d\n",temp);
		q.pop();
		for (int i = 0; i < v[temp].size(); ++i)
		{
			if (visit[v[temp][i]]==false&&level<=l)
			{
				q.push(v[temp][i]);
				visit[v[temp][i]]=true;
				nownode=v[temp][i];
				num++;
			}
		}
		if (lastnode==temp)
		{
			level++;
			lastnode=nownode;
		}
	}
	return num;
}
int main()
{
	int n;
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