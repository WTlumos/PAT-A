#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
int num[maxn]={};
int temp[maxn]={};
int match[maxn]={};
int n;
bool equal(int a[],int b[]){
	for (int i = 0; i < n; ++i)
	{
		if (a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
bool insertionsort(){
	int key=0;
	for (int i = 2; i < n; ++i)
	{
		sort(num,num+i);
		if (key>0)
		{
			printf("Insertion Sort\n");
			for (int j = 0; j < n; ++j)
			{
				printf("%d",num[j]);
				if (j<n-1)
				{
					printf(" ");
				}else{
					printf("\n");
				}
			}
			return true;
		}
		if (equal(num,match))
		{
			key++;
		}

	}
	return false;
}
void merge(){
	int key=0;
	for (int step = 2; ; step+=2)
	{
		for (int i = 0; i < n; i+=step)
		{
			sort(temp+i,temp+min(i+step,n));
		}
		if (key>0)
		{
			printf("Merge Sort\n");
			for (int j = 0; j < n; ++j)
			{
				printf("%d",temp[j]);
				if (j<n-1)
				{
					printf(" ");
				}else{
					printf("\n");
				}
			}
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
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);
		temp[i]=num[i];
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&match[i]);
	}
	if(!insertionsort()){
		merge();
	}
	return 0;
}