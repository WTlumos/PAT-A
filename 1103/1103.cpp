#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<int> num;
int maxfactor=-1;
vector<int> path,tempath;
int n,k,p;
void dfs(int index,int sum,int cnt,int factorsum)
{
	//printf("%d\n",index);
	if (cnt==k)
	{
		if (sum==n&&factorsum>maxfactor)
		{
			path=tempath;
			maxfactor=factorsum;
		}
		return;
	}
	while(index>=1){
		if (sum+num[index]<=n)
		{
			tempath[cnt]=index;
			dfs(index,sum+num[index],cnt+1,factorsum+index);
		}
		if (index==1)
		{
			return;
		}
		index--;
	}
}
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	int index=1;
	int temp=0;
	//预存结果
	while(temp<=n)
	{
		num.push_back(temp);
		temp=pow(index,p);
		index++;
	}
	tempath.resize(k);
	dfs(num.size()-1,0,0,0);
	if (maxfactor==-1)
	{
		printf("Impossible\n");
		return 0;
	}
	printf("%d = ", n);
	for (int i = 0; i < path.size(); ++i)
	{
		if (i!=0)
		{
			printf(" + ");
		}
		printf("%d^%d",path[i],p);
	}
	printf("\n");

	return 0;
}