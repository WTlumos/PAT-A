#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1010;
vector<int> v[maxn];
int indegree[maxn]={};
int temp[maxn]={};
vector<int> ans;
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
		temp[b]++;
	}
	int k; int key=0;
	scanf("%d",&k);
	for(int t=0;t<k;t++){
		int flag=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a);
			if (indegree[a]!=0)
			{
				flag=1;
				continue;
			}else{
				for (int j = 0; j < v[a].size(); ++j)
				{
					indegree[v[a][j]]--;
				}
			}
		}
		if (flag==1)
		{
			if (key==0)
			{
				printf("%d",t);
				key++;
			}else{
				printf(" %d",t);
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			indegree[i]=temp[i];
		}
	}
	printf("\n");
	return 0;
}