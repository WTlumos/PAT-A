#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<int> v,path,tempath;
int n,k;
int maxsum=-1;
void dfs(int index,int sum,int cntK,int factsum){
	if (cntK==k)
	{
		if (sum==n&&factsum>maxsum)
		{
			maxsum=factsum;
			path=tempath;
		}
		return;
	}
	while(index>=1){
		if (sum+v[index]<=n)
		{
			tempath[cntK]=index;
			dfs(index,sum+v[index],cntK+1,factsum+index);
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
	int p;
	scanf("%d%d%d",&n,&k,&p);
	int sum=0;
	int idx=1;
	while(sum<=n){
		v.push_back(sum);
		sum=pow(idx,p);
		idx++;
	}
	tempath.resize(k);
	dfs(v.size()-1,0,0,0);
	if (maxsum==-1)
	{
		printf("Impossible\n");
	}else{
		printf("%d = %d^%d", n,path[0],p);
		for (int i = 1; i < path.size(); ++i)
		{
			printf(" + %d^%d",path[i],p);
		}
		printf("\n");
	}
	return 0;
}