#include<cstdio>
int main()
{
	char c[]={"WTL"};
	double ans=1;
	for (int i = 0; i < 3; ++i)
	{
		int idx=-1; double temp=-1; double a;
		for (int j = 0; j < 3; ++j)
		{
			scanf("%lf",&a);
			if (a>temp)
			{
				temp=a;
				idx=j;
			}
		}
		printf("%c ",c[idx]);
		ans*=temp;
	}
	ans=2*(ans*0.65-1);
	printf("%.2f\n", ans);
	return 0;
}