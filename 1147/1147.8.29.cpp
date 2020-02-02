#include<cstdio>
int num[1010]={};
int n;
int key=0;
void post(int root)
{
	if (root>=n)
	{
		return;
	}
	post(2*root+1);
	post(2*root+2);
	if (key==0)
	{
		printf("%d",num[root]);
		key++;
	}else{
		printf(" %d",num[root]);
	}
}
int main()
{
	int m;
	scanf("%d%d",&m,&n);
	while(m--){
		key=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&num[i]);
		}
		int flag=-1;
		if (num[0]>num[1])
		{
			flag=1;
		}
		int left=0; int right=0;
		for (int i = 0; i < n/2  ; ++i)
		{
			left=2*i+1; right=2*i+2;
			if (flag==1)
			{
				if ((num[i]<num[left]&&left<n)||(right<n&&num[i]<num[right]))
				{
					flag=0;
					break;
				}
			}
			if (flag==-1)
			{
				if ((num[i]>num[left]&&left<n)||(right<n&&num[i]>num[right]))
				{
					flag=0;
					break;
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
		if(flag==-1)
		{
			printf("Min Heap\n");
		}
		post(0);
		printf("\n");
	}
	return 0;
}