#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector<int> v[10010];
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
	while(k--)
	{
		int nv;
		scanf("%d",&nv);
		map<int,int> hashtable;
		for (int i = 0; i < nv; ++i)
		{
			scanf("%d",&a);
			for (int j = 0; j < v[a].size(); ++j)
			{
				hashtable[v[a][j]]++;
			}
		}
		int flag=0;
		for (int i = 0; i < m; ++i)
		{
			if (hashtable[i]==0)
			{
				flag=1;
				break;
			}
		}
		if (flag==1)
		{
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
	return 0;
}