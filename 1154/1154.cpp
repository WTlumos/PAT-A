#include<cstdio>
#include<vector>
#include<set>
using namespace std;
const int maxn=10010;
vector<int> v[maxn];
int color[maxn]={};
set<int> s;
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
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&color[j]);
			s.insert(color[j]);
		}
		int flag=true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < v[i].size(); ++j)
			{
				//printf("%d %d\n", i,v[i][j]);
				if(color[i]==color[v[i][j]])
				{
					flag=false;
					break;
				}
			}
			if (!flag)
			{
				break;
			}
		}
		if (!flag)
		{
			printf("No\n");
		}else{
			printf("%lu-coloring\n", s.size());
		}
		s.clear();
	}
	return 0;
}