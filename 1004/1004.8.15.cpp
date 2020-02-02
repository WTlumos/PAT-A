#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> v[101];
int depth[101]={0};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int id,k,a;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&id,&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&a);
			v[id].push_back(a);
		}
	}
	queue<int> q;
	q.push(1);
	int level=0;
	int lastNode=1;
	int nowNode=0;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		if (v[node].size()==0)
		{
			depth[level]++;
		}
		for (int i = 0; i < v[node].size(); ++i)
		{
			q.push(v[node][i]);
			nowNode=v[node][i];
		}
		if(lastNode==node){
			level++;
			lastNode=nowNode;
		}
	}
	printf("%d",depth[0]);
	for (int i = 1; i < level; ++i)
	{
		printf(" %d",depth[i]);
	}
	
	printf("\n");

	return 0;
}