#include<cstdio>
#include<cmath>
int main()
{
	int n;
	scanf("%d",&n);
	int sqr=sqrt(1.0*n);
	int cnt=0;
	int first=0;
	for (int i = 2; i <= sqr; ++i)
	{
		int j=i;
		int temp=1;
		for (; j <= sqr; ++j)
		{
			temp*=j;
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
		printf("1\n1");
		return 0;
	}
	printf("%d\n",cnt);
	for (int i = 0; i < cnt; ++i)
	{
		if (i!=0)
		{
			printf("*");
		}
		printf("%d",first+i);
	}
	printf("\n");
	return 0;
}