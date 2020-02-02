#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int a,b;
};
node goods[100000];
int match[100000]={};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&a,&b);
		goods[i].a=a;
		goods[i].b=b;
	}
	while(m--)
	{
		int k;
		scanf("%d",&k);
		int flag=0;
		fill(match,match+100000,0);
		for (int i = 0; i < k; ++i)
		{
			scanf("%d",&a);
			match[a]=1;
		}
		for (int i = 0; i < n; ++i)
		{
			if (match[goods[i].a]==1&&match[goods[i].b]==1)
			{
				flag=1;
				printf("No\n");
				break;
			}
		}
		if (flag==0)
		{
			printf("Yes\n");
		}
	}
	return 0;
}