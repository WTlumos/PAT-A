#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10000;
const int Inf=312312312;
vector<int> v[10010];
map<int,int> line;
int mincnt;
int mintransfer;
vector<int> path,tempath;
bool visit[10010]={false};
int getTransfer(vector<int> path){
	int cnt=0;
	int preline=1;
	for (int i = 1; i < path.size(); ++i)
	{
		if (line[path[i]*maxn+path[i-1]]!=preline)
		{
			cnt++;
		}
		preline=line[path[i]*maxn+path[i-1]];
	}
	return cnt;
}
int t;
void dfs(int root,int cnt){
	visit[root]=true;
	if (root==t)
	{
		if (cnt<mincnt||(cnt==mincnt&&getTransfer(tempath)<mintransfer))
		{
			mintransfer=getTransfer(tempath);
			path=tempath;
			mincnt=cnt;
		}
	}
	for (int i = 0; i < v[root].size(); ++i)
	{
		if (visit[v[root][i]]==false)
		{
			
			tempath.push_back(v[root][i]);
			dfs(v[root][i],cnt+1);
            visit[v[root][i]]=false;
			tempath.pop_back();
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		int m; int a,b;
		scanf("%d%d",&m,&a);

		for (int j = 1; j < m; ++j)
		{
			scanf("%d",&b);
			v[a].push_back(b);
			v[b].push_back(a);
			line[a*maxn+b]=line[b*maxn+a]=i;
			a=b;
		}
	}
	int k;
	scanf("%d",&k);
	int s;
	while(k--)
	{
		scanf("%d%d",&s,&t);
		mincnt=Inf;
		mintransfer=Inf;
		tempath.clear();
		tempath.push_back(s);
		fill(visit,visit+10010,false);
		dfs(s,0);
		int preline=-1;
		int first=s;
		printf("%d\n", mincnt);
		for (int i = 1; i < path.size(); ++i)
		{
			if (line[path[i]*maxn+path[i-1]]!=preline)
			{
				if (preline!=-1)
				{
					printf("Take Line#%d from %04d to %04d.\n",preline,first,path[i-1]);
				}
				preline=line[path[i]*maxn+path[i-1]];
				first=path[i-1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n",preline,first,t);

	}
	return 0;
}