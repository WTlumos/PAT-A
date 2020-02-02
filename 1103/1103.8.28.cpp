#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<int> v,ans,path;
int k,n;
int maxFactorSum=-1;
void dfs(int index,int sum,int cnt,int factorSum)
{
	if (cnt==k)
	{
		if (sum==n&&factorSum>maxFactorSum)
		{
			maxFactorSum=factorSum;
			ans=path;
		}
		return;
	}
	while(index>=1){
		if (sum+v[index]<=n)
		{
			path[cnt]=index;
			dfs(index,sum+v[index],cnt+1,factorSum+index);
		}
		if (index==1)
		{
			break;
		}
		index--;
	}
}
int main()
{
	int p;
	scanf("%d%d%d",&n,&k,&p);
    int cnt=1;
    int sum=0;
    while(sum<=n){
    	v.push_back(sum);
    	sum=pow(cnt,p);
        cnt++;
    }
    path.resize(k);
    dfs(v.size()-1,0,0,0);
    if (ans.size()==0)
    {
    	printf("Impossible\n");
    }else{
    	printf("%d = ",n);
    	for (int i = 0; i < ans.size(); ++i)
    	{
    		if (i!=0)
    		{
    			printf(" + ");
    		}
    		printf("%d^%d",ans[i],p);
    	}
    	printf("\n");
    }
	return 0;
}