#include<cstdio>
#include<vector>
using namespace std;
vector<int> v[1010];
int degree[1010]={};
int temp[1010]={};
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int root,children;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&root,&children);
		v[root].push_back(children);
		v[children].push_back(root);
		degree[children]++;
		degree[root]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		temp[i]=degree[i];
	}
	for (int i = 0; i < k; ++i)
	{
		scanf("%d",&root);
		for (int j = 0; j < v[root].size(); ++j)
		{
			degree[v[root][j]]--;
		}
		int single=0;
		int connect=0;

		for (int i = 1; i <= n; ++i)
		{
			if(i==root){
				continue;
			}
			if(degree[i]==0){
				single++;
			}else{
				connect++;
			}
		}
		printf("%d\n",single);
		for (int i = 1; i <= n; ++i)
		{
			degree[i]=temp[i];
		}
	}


	return 0;
}