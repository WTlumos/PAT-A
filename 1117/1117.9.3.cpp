#include<cstdio>
#include<algorithm>
using namespace std;
int num[100010]={};
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n,cmp);
	int ans=1;
	for (int i = 0; i < n; ++i)
	{
		if (num[i]>ans)
		{
			ans++;
		}
	}
	printf("%d\n",ans-1);
	return 0;
}