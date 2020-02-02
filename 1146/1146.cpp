#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1010;
int indegree[maxn]={};
int temp[maxn]={};
vector<int> v[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		indegree[b]++;
		temp[b]++;
		v[a].push_back(b);
	}
	int k; int index=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int flag=0;
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&a);
			if (indegree[a]!=0)
			{
				//printf("%d %d\n",a,indegree[a]);
				flag=1;
				continue;
			}else{
				for (int t = 0; t < v[a].size(); ++t)
				{
					indegree[v[a][t]]--;
				}
			}
		}
		if (flag==1)
		{
			if (index==0)
			{
				printf("%d",i);
				index++;
			}else{
				printf(" %d",i);
			}
		}
		for (int j = 1; j <= n; ++j)
		{
			indegree[j]=temp[j];
		}

	}
	return 0;
}