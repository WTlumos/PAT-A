#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[101];
int depth[101]={};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int root,k,kid;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&root,&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&kid);
			v[root].push_back(kid);
		}
	}
	int level=0;
	int lastnode=1;
	int newnode;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int node=q.front();
        depth[level]++;
		q.pop();
		for (int i = 0; i < v[node].size(); ++i)
		{
			q.push(v[node][i]);
			newnode=v[node][i];
		}
		if(lastnode==node){
			level++;
			lastnode=newnode;
		}
	}
	int max=-1; int index=0;
	for (int i = 0; i < level; ++i)
	{
		if (depth[i]>max)
		{
			max=depth[i];
			index=i;
		}
	}
	printf("%d %d\n",max,index+1);

	return 0;
}