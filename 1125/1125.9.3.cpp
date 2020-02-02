#include<cstdio>
#include<algorithm>
using namespace std;
int num[10010]={};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	double ans=1.0*num[0];
	for (int i = 1; i < n; ++i)
	{
		ans+=1.0*num[i];
		ans/=2;
	}
	printf("%d\n", (int)ans);
	return 0;
}