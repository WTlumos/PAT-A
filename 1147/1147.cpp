#include<cstdio>
const int maxn=1010;
int heap[maxn]={};
int n;
void postOrder(int index)
{
	if (index>=n)
	{
		return;
	}
	postOrder(2*index+1);
	postOrder(2*index+2);
	printf("%d",heap[index]);
	if (index!=0)
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
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&heap[i]);
		}
		int flag=-1;
		if (heap[0]>heap[1])
		{
			flag=1;
		}
		for (int i = 0; i <= (n-1)/2; ++i)
		{
			int left = i * 2 + 1;
			int right = i * 2 + 2;
            if (flag == 1 && (heap[i] < heap[left] || (right < n && heap[i] < heap[right]))) flag = 0;
            if (flag == -1 && (heap[i] > heap[left] || (right < n && heap[i] > heap[right]))) flag = 0;
			
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
		postOrder(0);
	}
	return 0;
}