#include<cstdio>
#include<vector>
#include<set>
using namespace std;
const int maxn=10010;
vector<int> v[maxn];
int color[maxn]={};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int k;
	scanf("%d",&k);
	while(k--)
	{
		set<int> s;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&color[i]);
			s.insert(color[i]);
		}
		int flag=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < v[i].size(); ++j)
			{
				if (color[v[i][j]]==color[i])
				{
					flag=1;
					break;
				}
			}
			if (flag!=0)
			{
				break;
			}
		}
		if (flag!=0)
		{
			printf("No\n");
		}else{
			printf("%d-coloring\n",(int)s.size());
		}
	}
	return 0;
}