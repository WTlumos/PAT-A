#include<cstdio>
#include<map>
using namespace std;
map<int,int> exist;
int num[100010]={};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);
		exist[num[i]]++;
	}
	int flag=0;
	for (int i = 0; i < n; ++i)
	{
		if (exist[num[i]]==1)
		{
			flag=1;
			printf("%d\n", num[i]);
			break;
		}
	}
	if (flag==0)
	{
		printf("None\n");
	}
	return 0;
}