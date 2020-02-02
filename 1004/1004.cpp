#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;
vector<int> tree[100];
int main()
{
	int n,m;
	n=0;
	scanf("%d%d",&n,&m);
	if(n==0||m>=n){
		return 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int id,k,children;
		scanf("%d%d",&id,&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&children);
			tree[id].push_back(children);
		}
	}
	int root=1;
	queue<int> q;
	q.push(root);
	int lastnode=root;
	int newnode=0;
	map<int,int> depth;
	int level=0;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		if(tree[node].size()==0){
			depth[level]++;
		}else{
			for (int i = 0; i < tree[node].size(); ++i)
			{
				q.push(tree[node][i]);
				newnode=tree[node][i];
			}
		}
		if(node==lastnode){
			level++;
			lastnode=newnode;
		}
	}
	for (int i = 0; i < level; ++i)
	{
		printf("%d",depth[i]);
		if (i<level-1)
		{
			printf(" ");
		}else{
			printf("\n");
		}
	}

	return 0;
}