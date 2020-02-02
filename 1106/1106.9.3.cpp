#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<int> v[100010];
int mindeep=312312;
int cnt=1;
void dfs(int root,int deep)
{
	if (v[root].size()==0)
	{
		if (deep<mindeep)
		{
			mindeep=deep;
			cnt=1;
		}else if (deep==mindeep){
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
	int n;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	for (int i = 0; i < n; ++i)
	{
		int k;
		scanf("%d",&k);
		int a;
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&a);
			v[i].push_back(a);
		}
	}
	dfs(0,0);
	printf("%.4f %d\n", p*pow((1+r/100),mindeep),cnt);

	return 0;
}