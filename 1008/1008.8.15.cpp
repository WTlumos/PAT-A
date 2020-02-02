#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	int sum=0;
	int a,sub;
	int init=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		sub=a-init;
		if (sub>0)
		{
			sum+=sub*6;
		}else if(sub<0){
			sum+=(-sub)*4;

		}
		init=a;
		sum+=5;	
	}
	printf("%d\n",sum);
	return 0;
}