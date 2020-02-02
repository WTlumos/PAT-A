#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int level[1010]={};
int in[1010]={};
void levelorder(int left,int right,int index)
{
	if(left>right){
		return;
	}
	int n=right-left+1;
	int l=log(n+1)/log(2);
	int leaves=n-(pow(2,l)-1);
	int root=left+(pow(2,l-1)-1)+min((int)pow(2,l-1),leaves);
	level[index]=in[root];
	levelorder(left,root-1,2*index+1);
	levelorder(root+1,right,2*index+2);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&in[i]);
	}
	sort(in,in+n);
	levelorder(0,n-1,0);
	for (int i = 0; i < n; ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d", level[i]);
	}
	printf("\n");
	return 0;
}