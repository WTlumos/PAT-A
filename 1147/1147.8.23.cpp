/*
测试点错误
*/
#include<cstdio>
const int maxn=1010;
int heap[maxn]={};
int n;
void postOrder(int index)
{
	if (index>n)
	{
		return;
	}
	postOrder(2*index);
	postOrder(2*index+1);
	printf("%d",heap[index]);
	if (index!=1)
	{
		printf(" ");
	}else{
		printf("\n");
	}
}
int main()
{
	int m;
	scanf("%d%d",&m,&n);
	while(m--){
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d",&heap[i]);
		}
		int flag=-1;
		if (heap[1]>heap[2])
		{
			flag=1;
		}
		for (int i = 1; i < n/2; ++i)
		{
			int left = i * 2;
			int right = i * 2 + 1;
            if (flag == 1 && (heap[i] < heap[left] || (right <= n && heap[i] < heap[right]))) flag = 0;
            if (flag == -1 && (heap[i] > heap[left] || (right <= n && heap[i] > heap[right]))) flag = 0;
			
		}
		if (flag==0)
		{
			printf("Not Heap\n");
		}else {
			if(flag==1){
				printf("Max Heap\n");
			}
			else{
				printf("Min Heap\n");
			}
		}
		postOrder(1);
	}
	return 0;
}