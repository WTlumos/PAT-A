#include<cstdio>
#include<cmath>
int main()
{
	int n;
	scanf("%d",&n);
	int first=0;
	int len=-1;
	int maxn=sqrt(1.0*n);
	for (int i = 2; i <= maxn; ++i)
	{
		int temp=1;
		int j=0;
		for (j = i; j <= maxn; ++j)
		{
			temp*=j;
			if (n%temp!=0)
			{
				break;
			}	
		}
		if (j-i>len)
		{
			len=j-i;
			first=i;
		}
	}
	if (first==0)
	{
		printf("1\n%d",n);
	}else{
		printf("%d\n%d",len,first);
		for (int i = 1; i < len; ++i)
		{
			printf("*%d",first+i);	
		}
	}
	printf("\n");
	return 0;
}