#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	int sum=0; int idx=0; int sub=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		sub=a-idx;
		if (sub>0)
		{
			sum+=sub*6;
		}else{
			sub=-sub;
			sum+=sub*4;
		}
		sum+=5;
		idx=a;
	}
	printf("%d\n",sum);
	return 0;
}