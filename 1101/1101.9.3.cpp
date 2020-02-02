#include<cstdio>
#include<algorithm>
using namespace std;
int num[100010]={};
int temp[100010]={};
int ans[100010]={};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);
		temp[i]=num[i];
	}
	sort(temp,temp+n);
	int max=-1;
	int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		if (num[i]==temp[i]&&temp[i]>max)
		{
			ans[cnt++]=num[i];
		}
		if (temp[i]>max)
		{
			max=temp[i];
		}
	}
	printf("%d\n",cnt);
	for (int i = 0; i < cnt; ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d",ans[i]);
	}
	return 0;
}