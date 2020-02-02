#include<cstdio>
#include<algorithm>
using namespace std;
int num[101];
int cpy[101];
int temp[101];
int n;
bool Insertion()
{
	int key=0;
	for (int i = 2; i < n; ++i)
	{
		sort(num,num+i);
		if (key>0)
		{
			printf("Insertion Sort\n%d",num[0]);
			for (int i = 1; i < n; ++i)
			{
				printf(" %d",num[i]);
			}
			printf("\n");
			return true;
		}
		if (equal(num,num+n,temp))
		{
			key++;
		}
	}
	return false;
}
void Merge()
{
	int key=0;
	for (int i = 2;; i=2*i)
	{
		for (int j = 0; j <n ; j=j+i)
		{
			sort(cpy+j,cpy+min(j+i,n));
		}
		if (key>0)
		{
			printf("Merge Sort\n%d",cpy[0]);
			for (int i = 1; i < n; ++i)
			{
				printf(" %d",cpy[i]);
			}
			printf("\n");
			break;
		}
		if (equal(cpy,cpy+n,temp))
		{
			key++;
		}
		if (i>n)
		{
			break;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);
		cpy[i]=num[i];
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&temp[i]);
	}
	bool flag=Insertion();
	if (!flag)
	{
		Merge();
	}
	return 0;
}