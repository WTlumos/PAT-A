#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<int> v[100010];
int maxdeep=-1;
int cnt=1;
void dfs(int root,int deep){
	if (v[root].size()==0)
	{
		if (deep>maxdeep)
		{
			maxdeep=deep;
			cnt=1;
		}else if (deep==maxdeep){
			cnt++;
		}
		return;
	}
	for (int i = 0; i < v[root].size(); ++i)
	{
		dfs(v[root][i],deep+1);
	}
}
int main()
{
	int n; int root=0;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		if (a!=-1)
		{
			v[a].push_back(i);
		}else{
			root=i;
		}
	}
	dfs(root,0);
	printf("%.2f %d\n", p*pow((1+r/100),maxdeep),cnt);
	return 0;
}