#include<cstdio>
#include<algorithm>
using namespace std;
long long num[100010]={};
int main()
{
	int n;
	long long p;
	scanf("%d%lld",&n,&p);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld",&num[i]);
	}
	sort(num,num+n);
	int i=0;
	int j=0;
	int ans=-1;
	for (; i < n; ++i)
	{
		for (; j < n; ++j)
		{
			if (num[j]>num[i]*p)
			{
				break;
			}
		}
		if (j-i>ans)
		{
			ans=j-i;
		}
	}
	printf("%d\n", ans);
	return 0;
}