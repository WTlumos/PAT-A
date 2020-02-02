#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=10000;
const int Inf=312312312;
bool visit[maxn]={false};
vector<int> v[maxn];
map<int,int> line;
vector<int> path,tempath;
int mincnt,minTrans;
int transfercnt(vector<int> path)
{
	int cnt=0;
	int preline=1;
	for (int i = 1; i < path.size(); ++i)
	{
		if (line[path[i]+path[i-1]*maxn]!=preline)
		{
			cnt++;
		}
		preline=line[path[i-1]*maxn+path[i]];
	}
	return cnt;

}
int t;
void dfs(int root,int cnt){
	visit[root]=true;
	if (root==t)
	{
		if (cnt<mincnt||(cnt==mincnt&&transfercnt(tempath)<minTrans))
		{
			path=tempath;
			mincnt=cnt;
			minTrans=transfercnt(tempath);
		}
		return;
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
		int m,a,b;
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
	int k,s;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&s,&t);
		fill(visit,visit+maxn,false);
		path.clear();
		tempath.clear();
		mincnt=Inf;
		minTrans=Inf;
		tempath.push_back(s);
		dfs(s,0);
		printf("%d\n",mincnt);
		int preline=0;
    	int preTransfer=s;
    	for (int j = 1; j < path.size(); ++j)
    	{
    		if (line[path[j-1]*maxn+path[j]]!=preline)
    		{
    			if(preline!=0){
					printf("Take Line#%d from %04d to %04d.\n", preline,preTransfer,path[j-1]);
	    		}
	    		preline=line[path[j-1]*maxn+path[j]];
	    		preTransfer=path[j-1];
    		}
    	}
		printf("Take Line#%d from %04d to %04d.\n",preline,preTransfer,t);
	}
	return 0;
}