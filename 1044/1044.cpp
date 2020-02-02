#include<cstdio>
#include<vector>
using namespace std;
int sum[100010]={};
int n,m;
void search(int i,int &j, int &temp)
{
	int left=i; int right=n;
	while(left<right){
		int mid=(left+right)/2;
		if (sum[mid]-sum[i-1]>=m)
		{
			right=mid;
		}else{
			left=mid+1;
		}
	}
	j=right;
	temp=sum[j]-sum[i-1];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	int min=sum[n];
	vector<int> ans;
	for (int i = 1; i <=n ; ++i)
	{
		int j,temp;
		search(i,j,temp);
		if(temp>min)
			continue;
		if(temp>=m){
			if(temp<min){
				ans.clear();
				min=temp;
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