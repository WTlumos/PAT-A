#include<cstdio>
#include<algorithm>
using namespace std;
int num[101];
int temp[101];
int copyArray[101];
int n;
bool equal(int num[],int temp[])
{
	for (int i = 1; i <= n; ++i)
	{
		if (num[i]!=temp[i])
		{
			return false;
		}
	}
	return true;

}
bool Insertion(int num[],int temp[]){
	int key=0;
	for (int i = 3; i <= n; ++i)
	{
		sort(num+1,num+i);
		if (key>0)
		{
			printf("Insertion Sort\n");
			printf("%d",num[1]);
			for (int i = 2; i <= n; ++i)
			{
				printf(" %d",num[i]);
			}
			printf("\n");	
			return true;	
		}
		if (equal(num,temp))
		{
			key++;
		}

	}
	return false;
}
void adjustDown(int i,int len)
{
	int temp=copyArray[i];
	int j=i*2;
	while(j<=len)
	{
		if(j+1<=len&&copyArray[j+1]>copyArray[j]){
			j++;
		}
		if (copyArray[i]>=copyArray[j])
		{
			break;
		}
		else{
			swap(copyArray[i],copyArray[j]);
			i=j;
			j=2*i;
		}
	}
}
void createHeap()
{
	for (int i = n/2 ; i>0; i--)
	{
		adjustDown(i,n);
	}

}
void heap(int temp[])
{
	createHeap();
	int key=0;
	for (int i = n; i >0; i--)
	{
		if (key>0)
		{

			printf("Heap Sort\n%d",copyArray[1]);
			for (int i = 2; i <= n; ++i)
			{
				printf(" %d",copyArray[i]);
			}
			printf("\n");
			break;
		}
		if (equal(copyArray,temp))
		{
			key++;
		}
		swap(copyArray[i],copyArray[1]);
		adjustDown(1,i-1);
	}


}
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&num[i]);
		copyArray[i]=num[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&temp[i]);
	}
	bool flag=Insertion(num,temp);
	if (!flag)
	{
		heap(temp);
	}
	return 0;
}