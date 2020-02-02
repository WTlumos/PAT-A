#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
vector<int> v[maxn];
int mindeep=312312312;
int cnt=1;
void dfs(int root,int deep)
{
	if (v[root].size()==0)
	{
		if (deep<mindeep)
		{
			mindeep=deep;
			cnt=1;
		}else if(mindeep==deep){
			cnt++;
		}
	}
	for (int i = 0; i < v[root].size(); ++i)
	{
		dfs(v[root][i],deep+1);
	}
}
int main()
{
	int n;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	int k,child;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&child);
			v[i].push_back(child);
		}
	}
	dfs(0,0);
	double ans=p*pow((1+r/100),mindeep);
	printf("%.4f %d\n",ans,cnt);
	return 0;
}