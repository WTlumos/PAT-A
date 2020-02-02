#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1010;
int in[maxn]={0};
int level[maxn]={0};
void levelOrder(int start,int end,int index)
{
	if(start>end){
		return;
	}
	int n=end-start+1;
	//层数
	int l=log(n+1)/log(2);
	//叶子数
	int leave=n-(pow(2,l)-1);

	int root=start+(pow(2,l-1)-1)+min((int)pow(2,l-1),leave);
    level[index]=in[root];
    levelOrder(start,root-1,2*index+1);
    levelOrder(root+1,end,2*index+2);
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
	levelOrder(0,n-1,0);
	for (int i = 0; i < n; ++i)
	{
		printf("%d",level[i]);
		if (i<n-1)
		{
			printf(" ");
		}else{
			printf("\n");
		}
	}

	return 0;
}