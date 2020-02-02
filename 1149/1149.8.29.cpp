#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector<int> v[1000000];
map<int,int> match;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int k;
	while(m--){
		scanf("%d",&k);
        int flag=0;
		for (int i = 0; i < k; ++i)
		{
			scanf("%d",&a);
			if (match[a]>0)
			{
				flag=1;
				continue;
			}
			for (int j = 0; j < v[a].size(); ++j)
			{
				match[v[a][j]]++;
			}
		}
		if (flag==0)
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		match.clear();
	}
	return 0;
}