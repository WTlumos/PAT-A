#include<cstdio>
int level[1010]={};
int n;
int key=0;
void postorder(int root)
{
	if (root>=n)
	{
		return;
	}
	postorder(2*root+1);
	postorder(2*root+2);
	if (key!=0)
	{
		printf(" ");
	}else{
		key++;
	}
	printf("%d",level[root]);
}
int main()
{
	int m;
	scanf("%d%d",&m,&n);
	while(m--)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&level[i]);
		}
		int flag=-1;
		if (level[0]>level[1])
		{
			flag=1;
		}
		for (int i = 0; i <= (n-1)/2; ++i)
		{
			int left=2*i+1;
			int right=2*i+2;
			if (flag==1)
			{
				if ((level[i]<level[left]&&left<n)||(level[i]<level[right]&&right<n))
				{
					flag=0;
				}
			}
			if (flag==-1)
			{
				if ((level[i]>level[left]&&left<n)||(level[i]>level[right]&&right<n))
				{
					flag=0;
				}
			}
		}
		if (flag==0)
		{
			printf("Not Heap\n");
		}
		if (flag==1)
		{
			printf("Max Heap\n");
		}
		if (flag==-1)
		{
			printf("Min Heap\n");
		}
		postorder(0);
		printf("\n");
		key=0;
	}
	return 0;
}