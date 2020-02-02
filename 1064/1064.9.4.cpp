#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int in[1010]={};
int levelorder[1010]={};
void getLevel(int left,int right,int index)
{
	if (left>right)
	{
		return;
	}
	int num=right-left+1;
	int level=log(num+1)/log(2);
	int leaves=num-(pow(2,level)-1);
	int root=left+(pow(2,level-1)-1)+min((int)pow(2,level-1),leaves);
	levelorder[index]=in[root];
	getLevel(left,root-1,2*index+1);
	getLevel(root+1,right,2*index+2);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	    scanf("%d",&in[i]);
	}
	sort(in,in+n);
	getLevel(0,n-1,0);
	for (int i = 0; i < n; ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d",levelorder[i]);
	}
	printf("\n");
}