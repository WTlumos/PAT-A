#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[10010];
bool visit[10010]={false};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(i);
		v[b].push_back(i);
	}
	int k;
	scanf("%d",&k);
	while(k--){
		fill(visit,visit+10010,false);
		int nv;
		scanf("%d",&nv);
		for (int i = 0; i < nv; ++i)
		{
			scanf("%d",&a);
			for (int j = 0; j < v[a].size(); ++j)
			{
				visit[v[a][j]]=true;
			}
		}
		int flag=0;
		for (int i = 0; i < m; ++i)
		{
			if (visit[i]==false)
			{
				flag=1;
				printf("No\n");
				break;
			}
		}
		if (flag==0)
		{
			printf("Yes\n");
		}
	}
	return 0;
}