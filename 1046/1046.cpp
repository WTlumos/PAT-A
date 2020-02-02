#include<cstdio>
int ds[100010]={0};
int main()
{
	int n;
	scanf("%d",&n);
	int sum=0; int temp;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&temp);
		sum+=temp;
		ds[i]=sum;
	}
	int m;
	scanf("%d",&m);
	int left,right;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&left,&right);
		if(left>right){
			int a = left;
			left=right;
			right=a;
		}
		int temp=ds[right-1]-ds[left-1];
		if (sum-temp>temp)
		{
			printf("%d\n",temp);
		}else{
			printf("%d\n",sum-temp);
		}

	}
	return 0;
}