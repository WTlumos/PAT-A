#include<cstdio>
#include<vector>
using namespace std;
vector<int> v[110];
vector<int> level[110];
int maxdeep=-1;
void dfs(int root,int deep)
{
	level[deep].push_back(root);
	if (deep>maxdeep)
	{
		maxdeep=deep;
	}
	if (v[root].size()==0)
	{
		return;
	}
	for (int i = 0; i < v[root].size(); ++i)
	{
		dfs(v[root][i],deep+1);
	}

}
int main()
{
	//01 to N
	int n,m;
    scanf("%d%d",&n,&m);
    int id,k,children;
    for (int i = 0; i < m; ++i)
    {
    	scanf("%d%d",&id,&k);
    	for (int j = 0; j < k; ++j)
    	{
    		scanf("%d",&children);
    		v[id].push_back(children);
    	}
    }
    dfs(1,1);
    int maxnum=-1; int index=0;
    for (int i = 1; i <= maxdeep; ++i)
    {
    	int size=level[i].size();
    	if (size>maxnum)
    	{
    		maxnum=size;
    		//printf("%d\n", maxnum);
    		index=i;
    	}
    }
    printf("%d %d\n",maxnum,index);
	return 0;
}