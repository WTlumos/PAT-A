#include<cstdio>
#include<algorithm>
using namespace std;
int origin[110];
int match[110];
int temp[110];
int n;
bool equal(int a[],int b[])
{
	for (int i = 1; i <= n; ++i)
	{
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}
bool insertSort()
{
	int key=0;
	for (int i = 3; i <= n; ++i)
	{
		sort(origin,origin+i);
		if (key>0)
		{
			printf("Insertion Sort\n");
			for (int i = 1; i <= n; ++i)
			{
				if (i!=1)
				{
					printf(" ");
				}
				printf("%d",origin[i]);
			}
			printf("\n");
			return true;
		}
		if(equal(origin,match)){
			key++;
		}
	}
	return false;
}
void adjustDown(int k,int len)
{
	//printf("%d\n",k);
	int j=2*k;
	while(j<=len)
	{
		if(j+1<=len&&temp[j+1]>temp[j]){
			j++;
		}
		if (temp[k]>temp[j])
		{
			break;
		}
		if(temp[k]<temp[j]){
			swap(temp[k],temp[j]);
			k=j;
			j=2*k;
		}
	}
}
void createHeap()
{
	for (int i = n/2; i > 0 ; i--)
	{
		adjustDown(i,n);
	}
}
void heapSort()
{
	createHeap();
	int key=0;
	for (int i = n; i > 0 ; i--)
	{
		if (key>0)
		{
			printf("Heap Sort\n");
			for (int i = 1; i <= n; ++i)
			{
				if (i!=1)
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
	if(insertSort()==false)
	{
		heapSort();
	}
	//heapSort();

	return 0;
}