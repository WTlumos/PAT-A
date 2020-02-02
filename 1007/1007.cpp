#include<stdio.h>
#include<vector>
using namespace std;
vector<int> num;
vector<int> ans;
int main()
{
	int k;
	scanf("%d",&k);
	int a;
	int sum=-1;
	int right=k-1;
	int left=0;
	int temp=0;
	int tempIndex=0;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d",&a);
		num.push_back(a);
		temp+=a;
		if(temp<0){
			temp=0;
			tempIndex=i+1;
		}else if(temp>sum){
			sum=temp;
			left=tempIndex;
			right=i;

		}
	}
	if(sum<0){
		sum=0;
	}
	printf("%d %d %d\n",sum,num[left],num[right]);
	return 0;
}