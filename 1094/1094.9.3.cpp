#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[110];
int deep=1;
int level[110]={};
void bfs(int root){
	queue<int> q;
	q.push(root);
	int lastnode=root;
	int nownode=0;
	while(!q.empty()){
		int temp=q.front();
		//printf("%d\n",temp);
		level[deep]++;
		q.pop();
		for (int i = 0; i < v[temp].size(); ++i)
		{
			q.push(v[temp][i]);
			nownode=v[temp][i];
		}
		if (lastnode==temp)
		{
			deep++;
			lastnode=nownode;
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; ++i)
	{
		int id,k,a;
		scanf("%d%d",&id,&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&a);
			v[id].push_back(a);
		}
	}
	bfs(1);
	int maxnum=-1; int maxidx=0;
	for (int i = 1; i <= deep; ++i)
	{
		int size=level[i];
		if (size>maxnum)
		{
			maxnum=size;
			maxidx=i;
		}
		
	}
	printf("%d %d\n",maxnum,maxidx);
	return 0;
}