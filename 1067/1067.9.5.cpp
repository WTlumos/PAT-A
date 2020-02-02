#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int num;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num);
		a[num]=i;
	}
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i]!=i)
		{
			while(a[0]!=0){
				swap(a[0],a[a[0]]);
				ans++;
			}
			if (a[i]!=i)
			{
				swap(a[0],a[i]);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}