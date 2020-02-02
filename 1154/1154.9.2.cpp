#include<vector>
#include<cstdio>
#include<set>
using namespace std;
vector<int> v[10010];
int color[10010]={};
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
	while(k--){
		int flag=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&color[i]);
			s.insert(color[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < v[i].size(); ++j)
			{
				if (color[i]==color[v[i][j]])
				{
					flag=1;
					break;
				}
			}
			if (flag==1)
			{
				break;
			}
		}
		if (flag==1)
		{
			printf("No\n");
		}else{
			printf("%lu-coloring\n",s.size());
		}
		s.clear();
	}
	return 0;
}