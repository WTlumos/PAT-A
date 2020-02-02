#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> v[1010];
bool visit[1010]={false};
int l;
int bfs(int root){
	queue<int> q;
	q.push(root);
	int level=0;
	int lastnode=root;
	int nownode=0;
	int cnt=0;
	visit[root]=true;
	while(!q.empty()){
		int temp=q.front();
		//printf("%d %d\n", temp,level);
		q.pop();
		for (int i = 0; i < v[temp].size(); ++i)
		{
			if (!visit[v[temp][i]])
			{
				q.push(v[temp][i]);
				visit[v[temp][i]]=true;
				nownode=v[temp][i];
			}
		}
		if (level<=l)
		{
			cnt++;
		}
		if (lastnode==temp)
		{
			level++;
			lastnode=nownode;
		}
	}
	return cnt;
}
int main()
{
	int n;
	scanf("%d%d",&n,&l);
	for (int i = 1; i <= n; ++i)
	{
		int m;
		scanf("%d",&m);
		for (int j = 0; j < m; ++j)
		{
			int a;
			scanf("%d",&a);
			v[a].push_back(i);
		}	
	}
	int k;
	scanf("%d",&k);
	int a;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d",&a);
		fill(visit,visit+1010,false);
		printf("%d\n",bfs(a)-1);
	}

	return 0;
}