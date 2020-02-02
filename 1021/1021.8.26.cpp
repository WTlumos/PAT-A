#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> v[10010];
bool visit[10010]={false};
set<int> s;
vector<int> ans;
int maxdeep=-1;
void dfs(int root,int deep)
{
	//printf("%d\n", root);
	visit[root]=true;
	if (deep>maxdeep)
	{
		maxdeep=deep;
		ans.clear();
		ans.push_back(root);
	}else if (deep==maxdeep){
		ans.push_back(root);
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
	int cnt=0; int start=0;
	for (int i = 1; i <= n; ++i)
	{
		if (visit[i]==false)
		{
			dfs(i,1);
			cnt++;
			if (ans.size()!=0)
			{
				start=ans[0];
			}
			for (int j = 0; j < ans.size(); ++j)
			{
				s.insert(ans[j]);
			}      
		}
	}
	if (cnt<2)
	{
		maxdeep=-1;
		fill(visit,visit+10010,false);
		dfs(start,1);
		for (int i = 0; i < ans.size(); ++i)
		{
			s.insert(ans[i]);
		}
		for (set<int>::iterator i = s.begin(); i != s.end() ; ++i)
		{
			printf("%d\n",*i);
		}
	}else{
		printf("Error: %d components\n",cnt);
	}
	return 0;
}