#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int origin[110],temp[110],match[110];
bool equal(int a[],int b[])
{
	for (int i = 1; i <= n; ++i)
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
	for (int i = 3; i <= n; ++i)
	{
		sort(origin,origin+i);
		if (key>0)
		{
			printf("Insertion Sort\n");
			for (int j = 1; j <= n ; ++j)
			{
				if (j!=1)
				{
					printf(" ");
				}
				printf("%d",origin[j]);
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
void adjustDown(int i,int len)
{
	int j=2*i;
	while(j<=len)
	{
		if (j+1<=len&&temp[j]<temp[j+1])
		{
			j++;
		}
		if (temp[i]>temp[j])
		{
			break;
		}
		if (temp[i]<temp[j])
		{
			swap(temp[i],temp[j]);
			i=j;
			j=2*i;
		}
	}
}
void createHeap()
{
	for (int i = n/2; i > 0; i--)
	{
		adjustDown(i,n);
	}
}
void heapSort()
{
	int key=0;
	createHeap();
	for (int i = n; i > 1; i--)
	{
		if (key>0)
		{
			printf("Heap Sort\n");
			for (int j = 1; j <= n ; ++j)
			{
				if (j!=1)
				{
					printf(" ");
				}
				printf("%d",temp[j]);
			}
			printf("\n");
			break;
		}
		if (equal(temp,match))
		{
			key++;
		}
		swap(temp[1],temp[i]);
		adjustDown(1,i-1);
	}

}
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&origin[i]);
		temp[i]=origin[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&match[i]);
	}
	if(insertionSort()==false)
	{
		heapSort();
	}
	return 0;
}