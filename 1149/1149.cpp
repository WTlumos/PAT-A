#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100000;
vector<int> goods[maxn];
int match[maxn]={};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&a,&b);
		goods[a].push_back(b);
		goods[b].push_back(a);
	}
	int k;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&k);
		int flag=0;
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&a);
			if (match[a]>0)
			{
				flag=1;
				continue;
			}
			for (int t = 0; t < goods[a].size(); ++t)
			{
				match[goods[a][t]]++;
			}
		}
		if (flag==0)
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		fill(match,match+maxn,0);
	}
	return 0;
}