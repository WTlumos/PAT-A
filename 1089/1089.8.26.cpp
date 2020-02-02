#include<cstdio>
#include<algorithm>
using namespace std;
int origin[110]={};
int temp[110]={};
int match[110]={};
int n;
bool equal(int a[],int b[])
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
bool insertionSort()
{
	int key=0;
	for (int i = 2; i < n; ++i)
	{
		sort(origin,origin+i);
		if (key>0)
		{
			printf("Insertion Sort\n");
			for (int j = 0; j < n; ++j)
			{
				if (j!=0)
				{
					printf(" ");
				}
				printf("%d", origin[j]);
			}
			printf("\n");
			return true;
		}
		if (equal(origin,match))
		{
			key++;
		}
	}
	return false;
}
void mergeSort()
{
	int key=0;
	for (int step = 2;; step=2*step)
	{
		for (int j = 0; j < n; j+=step)
		{
			sort(temp+j,temp+min(j+step,n));
		}
		if (key>0)
		{
			printf("Merge Sort\n");
			for (int i = 0; i < n; ++i)
			{
				if (i!=0)
				{
					printf(" ");
				}
				printf("%d",temp[i]);
			}
			printf("\n");
			break;
		}
		if (equal(temp,match))
		{
			key++;
		}
		if (step>n)
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
		scanf("%d",&origin[i]);
		temp[i]=origin[i];
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&match[i]);
	}
	if(insertionSort()==false)
	{
		mergeSort();
	}
	return 0;
}