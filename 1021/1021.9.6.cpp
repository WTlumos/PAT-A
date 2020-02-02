#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> v[10010];
bool visit[10010]={false};
set<int> s;
int maxdeep=-1;
vector<int> path;
void dfs(int root,int deep){

	visit[root]=true;
	if (deep>maxdeep)
	{
		maxdeep=deep;
		path.clear();
		path.push_back(root);
		//printf("%d %lu\n", root,path.size());
	}else if (maxdeep==deep){
		path.push_back(root);
	}
	if (v[root].size()==0)
	{
		return;
	}
	for (int i = 0; i < v[root].size(); ++i)
	{
		if (visit[v[root][i]]==false)
		{
			dfs(v[root][i],deep+1);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a,b;
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cnt=0; int root=0;
	for (int i = 1; i <= n; ++i)
	{
		if (visit[i]==false)
		{
			dfs(i,0);
			cnt++;
			if ((int)path.size()!=0)
			{
				root=path[0];
				//printf("%d\n", root);
			}
			
			for (int j = 0; j < path.size(); ++j)
			{
				s.insert(path[j]);
			}
		}
	}
	if (cnt>1)
	{
		printf("Error: %d components\n",cnt);
	}else{
		maxdeep=-1;
		fill(visit,visit+10010,false);
		path.clear();
		dfs(root,0);
		for (int j = 0; j < path.size(); ++j)
		{
			s.insert(path[j]);
		}
		for (set<int>::iterator i = s.begin(); i != s.end() ; ++i)
		{
			printf("%d\n",*i);
		}
	}
	return 0;
}