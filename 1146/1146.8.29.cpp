#include<cstdio>
#include<vector>
using namespace std;
vector<int> v[1010];
int indegree[1010]={};
int indegreeTemp[1010]={};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		indegree[b]++;
		indegreeTemp[b]++;
	}
	int k;
	scanf("%d",&k);
	int key=0;
	for (int i = 0; i < k; ++i)
	{
		int flag=0;
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d",&a);
			if (indegree[a]!=0)
			{
				flag=1;
				continue;
			}
			for (int k = 0; k < v[a].size(); ++k)
			{
				indegree[v[a][k]]--;
			}
		}
		if (flag==1)
		{
			if (key==0)
			{
				printf("%d",i);
				key++;
			}
			else{
				printf(" %d",i);
			}
		}
		for (int j = 1; j <= n; ++j)
		{
			indegree[j]=indegreeTemp[j];
		}
	}
	return 0;
}