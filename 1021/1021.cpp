#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=10010;
vector<int> v[maxn];
bool visit[maxn]={false};
int maxDeep=-1;
vector<int> temp;
void dfs(int root,int deep)
{
	visit[root]=true;
	if (deep>maxDeep)
	{
		maxDeep=deep;
		temp.clear();
		temp.push_back(root);
	}else if(deep==maxDeep){
		temp.push_back(root);
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
	int cnt=0;
	int start=0;
	set<int> s;
	for (int i = 1; i <= n; ++i)
	{
		if (visit[i]==false)
		{
			dfs(i,1);
			if(i==1){
				if(temp.size()!=0){
					start=temp[0];
				}
				for (int j = 0; j < temp.size(); ++j)
				{
					//printf("%d\n",temp[j]);
					s.insert(temp[j]);
				}
			}
			cnt++;
		}
	}
	if (cnt>1)
	{
		printf("Error: %d components\n", cnt);
	}
	else{
		maxDeep=-1;
		fill(visit,visit+maxn,false);
		dfs(start,1);
		for (int i = 0; i < temp.size(); ++i)
		{
			s.insert(temp[i]);
		}
		for (set<int>::iterator i=s.begin();i!= s.end(); ++i)
		{
			printf("%d\n", *i);
		}
	}
	return 0;
}