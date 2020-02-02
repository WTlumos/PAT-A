#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int num[maxn]={};
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
	printf("%d %d\n",n%2==0?0:1,abs(total-2*sum));
	return 0;
}