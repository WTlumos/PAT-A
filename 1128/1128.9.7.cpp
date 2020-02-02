#include<cstdio>
#include<algorithm>
using namespace std;
int num[1010]={};
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int n;
		scanf("%d",&n);
		int flag=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&num[i]);
			if (flag==1)
			{
				continue;
			}
			for (int j = 0; j < i; ++j)
			{
				if (num[j]==num[i]||(abs(j-i)==abs(num[j]-num[i])))
				{
					flag=1;
					printf("NO\n");
					break;
				}
			}
		}
		if (flag==0)
		{
			printf("YES\n");
		}
	}
	return 0;
}