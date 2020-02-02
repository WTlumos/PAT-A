#include<cstdio>
#include<vector>
using namespace std;
int sum[100010]={};
int n,m;
void fun(int i,int &j,int &tempsum)
{
	int left=i;
	int right=n;
	while(left<right)
	{
		int mid=(left+right)/2;
		if (sum[mid]-sum[i-1]>=m)
		{
			right=mid;
		}else{
			left=mid+1;
		}
	}
	j=right;
	tempsum=sum[j]-sum[i-1];
}
int main()
{
	scanf("%d%d",&n,&m);
	int a;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a);
		sum[i]=sum[i-1]+a;
	}
	int minsum=sum[n];
	vector<int> ans;
	for (int i = 1; i <= n; ++i)
	{
		int j,tempsum;
		fun(i,j,tempsum);
		if (tempsum>minsum)
		{
			continue;
		}
		if (tempsum>=m)
		{
			if (tempsum<minsum)
			{
				minsum=tempsum;
				ans.clear();
			}
			ans.push_back(i);
			ans.push_back(j);		
		}
	}
	for (int i = 0; i < ans.size(); i+=2)
	{
		printf("%d-%d\n",ans[i],ans[i+1]);
	}
	return 0;
}