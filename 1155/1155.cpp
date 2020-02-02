#include<cstdio>
#include<vector>
using namespace std;
int order[1001];
vector<int> v;
int n;
//先序遍历 根右左
void dfs(int index)
{
	if (2*index+1>n && 2*index>n)
	{
		if (index<=n)
		{
			for (int i = 0; i < v.size(); ++i)
			{
				printf("%d",v[i]);
				if (i<v.size()-1)
				{
					printf(" ");
				}else{
					printf("\n");
				}
			}
		}
	}else{
		v.push_back(order[2*index+1]);
		dfs(2*index+1);
		v.pop_back();
		v.push_back(order[2*index]);
		dfs(2*index);
		v.pop_back();
	}
}
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&order[i]);
	}
	v.push_back(order[1]);
	dfs(1);
	bool min=true; bool max=true;
	for (int i = 1; i < n/2; ++i)
	{
		if(order[i]>order[2*i+1]||order[i]>order[2*i])
		{
			min=false;
		}
		if(order[i]<order[2*i+1]||order[i]<order[2*i])
		{
			max=false;
		}
	}
	if (max)
	{
		printf("Max Heap\n");
	}else if(min){
		printf("Min Heap\n");
	}else{
		printf("Not Heap\n");
	}
	return 0;
}