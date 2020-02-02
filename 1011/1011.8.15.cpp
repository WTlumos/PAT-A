#include<cstdio>
int main()
{
	double num[3][3];
	char c[]={'W','T','L'};
	double sum=1;
	for (int i = 0; i < 3; ++i)
	{
		double max=-1; int index=0;
		for (int j = 0; j < 3; ++j)
		{
			scanf("%lf",&num[i][j]);
			if (num[i][j]>max)
			{
				max=num[i][j];
				index=j;
			}
		}
		printf("%c ",c[index]);
		sum*=max;
	}
	sum=(sum*0.65-1)*2;
	printf("%.2f\n",sum);
	return 0;
}