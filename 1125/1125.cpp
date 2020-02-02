#include<cstdio>
#include<algorithm>
using namespace std;
double num[10010]={};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",&num[i]);
	}
	sort(num,num+n);
	double ans=num[0];
	for (int i = 1; i < n; ++i)
	{
		ans=(num[i]+ans)/2;
	}
	printf("%d\n",(int)ans);
	return 0;
}