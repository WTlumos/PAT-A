#include<cstdio>
#include<vector>
using namespace std;
int level[1010]={};
vector<int> v;
int n;
void dfs(int index)
{
	if (2*index>n&&2*index+1>n)
	{
		if (index<=n)
		{
			printf("%d", level[v[0]]);
			for (int i = 1; i < v.size(); ++i)
			{
				printf(" %d",level[v[i]]);
			}
			printf("\n");
		}
		return;
	}
	v.push_back(2*index+1);
	dfs(2*index+1);
	v.pop_back();
	v.push_back(2*index);
	dfs(2*index);
	v.pop_back();
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
	bool min=true; bool max=true;
	for (int i = 1; i < n/2; ++i)
	{
		if (level[i]>level[2*i]||level[i]>level[2*i+1])
		{
			min=false;
		}
		if (level[i]<level[2*i]||level[i]<level[2*i+1])
		{
			max=false;
		}
	}
	if (max)
	{
		printf("Max Heap\n");
	}else if (min){
		printf("Min Heap\n");
	}else{
		printf("Not Heap\n");
	}

	return 0;
}