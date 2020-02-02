#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<int> v[100010];
int maxdeep=-1;
int num=0;
void dfs(int root,int deep)
{
	if (v[root].size()==0)
	{
		if(deep>maxdeep){
			maxdeep=deep;
			num=1;
		}else if(deep==maxdeep){
			num++;
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
	int a;
	int root=-1;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		if (a==-1)
		{
			root=i;
		}else{
			v[a].push_back(i);
		}
	}
	dfs(root,0);
	double ans=p*pow(1+r/100,maxdeep);
	printf("%.2f %d\n",ans,num);

	return 0;
}