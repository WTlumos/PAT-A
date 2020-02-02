#include<cstdio>
int num[110]={};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&num[i]);
	}
	int wolf1=-1; int wolf2=-1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i+1; j <= n; ++j)
		{
			int human=0; int wolf=0;
			for (int k = 1; k <= n; ++k)
			{
				if ((num[k]<0&&-num[k]!=i&&-num[k]!=j)||
					(num[k]>0&&(num[k]==i||num[k]==j)))
				{
					if (k!=i&&k!=j)
					{
						human++;
					}else{
						wolf++;
					}
				}
			}
			if (human==1&&wolf==1)
			{
				wolf1=i;
				wolf2=j;
				break;			
			}
		}
		if (wolf1!=-1)
		{
			break;
		}
	}
	if (wolf1==-1)
	{
		printf("No Solution\n");
	}else{
		printf("%d %d\n",wolf1,wolf2);
	}
	return 0;
}