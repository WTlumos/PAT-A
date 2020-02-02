#include<cstdio>
#include<algorithm>
using namespace std;
int num[100010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int total=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);
		total+=num[i];
	}
	sort(num,num+n);
	int sum=0;
	for (int i = 0; i < n/2; ++i)
	{
		sum+=num[i];
	}
	if (n%2==0)
	{
		printf("0 ");
	}else{
		printf("1 ");
	}
	printf("%d\n",abs(total-sum-sum));

	return 0;
}