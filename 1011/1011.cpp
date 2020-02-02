#include<cstdio>
double games[3][3];
int main()
{
	char ans[]={'W','T','L'};
	double sum=1;
	for (int i = 0; i < 3; ++i)
	{
		int maxIndex;
		double max=-1;
		for (int j=0; j < 3; ++j)
		{
			scanf("%lf",&games[i][j]);
			//printf("%f %f\n",games[i][j],max);
			if (games[i][j]>max)
			{
				max=games[i][j];
				maxIndex=j;
			}
		}
		sum*=max;
		printf("%c ",ans[maxIndex]);
	}
	sum=2*(sum*0.65-1);
	printf("%.2f\n",sum);
	return 0;
}