#include<cstdio>
#include<algorithm>
using namespace std;
int num[110]={};
int temp[110]={};
int match[110]={};
int n;
bool equal(int a[],int b[]){
	for (int i = 1; i <= n; ++i)
	{
		if (a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
bool insertionsort()
{
	bool flag=false;
	int key=0;
	for (int i = 2; i <= n; ++i)
	{
		sort(num+1,num+1+i);
		if (key>0)
		{
			flag=true;
			printf("Insertion Sort\n");
			for (int j = 1; j <= n; ++j)
			{
				if (j!=1)
				{
					printf(" ");
				}		
				printf("%d",num[j]);
			}
			printf("\n");
			break;
		}
		if (equal(num,match))
		{
			key++;
		}
	}
	return flag;
}
void adjustdown(int i,int len){
	//printf("%d\n",temp[i]);
	int j=2*i;
	while(j<=len){
		if (j+1<=len&&temp[j+1]>temp[j])
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
		adjustdown(i,n);
	}
}
void heapsort()
{
	int key=0;
	createHeap();
	for (int i = n; i > 1 ; i--)
	{
		if (key>0)
		{
			printf("Heap Sort\n");
			for (int j = 1; j <= n; ++j)
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
		adjustdown(1,i-1);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&num[i]);
		temp[i]=num[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&match[i]);
	}
	if(!insertionsort()){
		heapsort();
	}
	return 0;
}