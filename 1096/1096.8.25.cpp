#include<cstdio>
#include<cmath>
int main()
{
	int n;
	scanf("%d",&n);
	int maxn=sqrt(1.0*n);
	int cnt=0;
	int first=0;
	for (int i = 2; i <= maxn; ++i)
	{
		int j=i;
		int temp=1;
		for (; j <= maxn; ++j)
		{
			temp=temp*j;
			if (n%temp!=0)
			{
				break;
			}	
		}
		if (j-i>cnt)
		{
			cnt=j-i;
			first=i;
		}
	}
	if (first==0)
	{
		printf("1\n%d",n);
		return 0;
	}
	printf("%d\n",cnt);
	for (int i = first; i < first+cnt; ++i)
	{
		if (i!=first)
		{
			printf("*");
		}
		printf("%d",i);
	}
	printf("\n");
	return 0;
}