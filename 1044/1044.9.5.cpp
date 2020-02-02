#include<cstdio>
#include<vector>
using namespace std;
vector<int> ans;
int num[1010]={};
int n,m;
void getsum(int i,int &sum,int &j){
	int left=i;
	int right=n;
	while(left<right){
		int mid=(left+right)/2;
		if (num[mid]-num[i-1]>=m)
		{
			right=mid;
		}else{
			left=mid+1;
		}
	}
	sum=num[right]-num[i-1];
	j=right;
}
int main()
{
	scanf("%d%d",&n,&m);
	int a;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a);
		num[i]=num[i-1]+a;
	}
	int max=num[n];
	for (int i = 1; i <= n; ++i)
	{
		int j; int sum;
		getsum(i,sum,j);
		//printf("%d %d %d\n", i,j,sum);
		if (sum>max)
		{
			continue;
		}
		if (sum>=m)
		{
			if (sum<max)
			{
				max=sum;
				ans.clear();
			}
			ans.push_back(i);
			ans.push_back(j);	
		}	
	}
	for (int i = 0; i < ans.size(); i+=2)
	{
		printf("%d-%d\n", ans[i],ans[i+1]);
	}
	return 0;
}