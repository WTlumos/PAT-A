#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1010;
int level[maxn]={};
vector<int> v;
int n;
void dfs(int root)
{
	if (2*root>n&&2*root+1>n)
	{
		if (root<=n)
		{
			for (int i = 0; i < v.size(); ++i)
			{
				if (i!=0)
				{
					printf(" ");
				}
				printf("%d",level[v[i]]);
			}
			printf("\n");
		}
	}
	else{
		v.push_back(2*root+1);
		dfs(2*root+1);
		v.pop_back();
		v.push_back(2*root);
		dfs(2*root);
		v.pop_back();
	}
}
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&level[i]);
	}
	v.push_back(1);
	dfs(1);
	bool max=true; bool min=true;
	for (int i = 1; i < n/2; ++i)
	{
		if(level[i]<level[2*i]||level[i]<level[2*i+1])
		{
			max=false;
		}
		if(level[i]>level[2*i]||level[i]>level[2*i+1])
		{
			min=false;
		}
	}
	if (max)
	{
		printf("Max Heap\n");
	}else if (min)
	{
		printf("Min Heap\n");
	}
	else{
		printf("Not Heap\n");
	}
	return 0;
}