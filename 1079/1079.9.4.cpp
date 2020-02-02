#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<int> v[100010];
int weight[100010]={};
double p,r; double ans=0;
void dfs(int root,int deep){
	if (v[root].size()==0)
	{
		ans+=p*pow((1+r/100),deep)*weight[root];
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
	scanf("%d%lf%lf",&n,&p,&r);
	for (int i = 0; i < n; ++i)
	{
		int k;
		scanf("%d",&k);
		if (k==0)
		{
			scanf("%d",&weight[i]);
		}else{
			int a;
			for (int j = 0; j < k; ++j)
			{
				scanf("%d",&a);
				v[i].push_back(a);
			}
		}
	}
	dfs(0,0);
	printf("%.1f\n",ans);
	return 0;
}