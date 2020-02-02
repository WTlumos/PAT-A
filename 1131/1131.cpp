#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int Inf=312312312;
const int maxn=10000;
vector<int> v[maxn];
map<int,int> line;
int s,t;
int minCnt=Inf;
int tranferMin=Inf;
bool visit[maxn]={false};
vector<int> tempPath,path;
int transfer(vector<int> v)
{
	int cnt=0;
	int preline=1;
	for (int i = 1; i < v.size(); ++i)
	{
		if (line[v[i-1]*maxn+v[i]]!=preline)
		{
			cnt++;
		}
		preline=line[v[i-1]*maxn+v[i]];
	}
	return cnt;
}
void dfs(int root,int cnt)
{
	visit[root]=true;
	if (root==t)
	{
		if (cnt<minCnt||(cnt==minCnt&&transfer(tempPath)<tranferMin))
		{
			minCnt=cnt;
			tranferMin=transfer(tempPath);
			path=tempPath;
		}
		return;
	}
	for (int i = 0; i < v[root].size(); ++i)
	{
		if (visit[v[root][i]]==false)
		{
			tempPath.push_back(v[root][i]);
			dfs(v[root][i],cnt+1);
			tempPath.pop_back();
			visit[v[root][i]]=false;
		}
	}

}
int main()
{
	int n,m,a,b;
	scanf("%d",&n);
    for (int i = 1; i <= n; ++i)
    {
    	scanf("%d",&m);
    	scanf("%d",&a);
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
    for (int i = 0; i < k; ++i)
    {
    	scanf("%d%d",&s,&t);
        minCnt=Inf;
	    tranferMin=Inf;
	    fill(visit,visit+maxn,false);
	    tempPath.clear();
	    tempPath.push_back(s);
    	dfs(s,0);
    	printf("%d\n",minCnt);
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