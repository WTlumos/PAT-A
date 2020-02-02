/*
分析：
已知某个树的根结点，若a和b在根结点的左边，则a和b的最近公共祖先在当前子树根结点的左子树寻找，
如果a和b在当前子树根结点的两边，在当前子树的根结点就是a和b的最近公共祖先，
如果a和b在当前子树根结点的右边，则a和b的最近公共祖先就在当前子树的右子树寻找。
中序加先序可以唯一确定一棵树，在不构建树的情况下，在每一层的递归中，可以得到树的根结点，在此时并入lca算法可以确定两个结点的公共祖先～
*/
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
const int maxn=10001;
int in[maxn];
int pre[maxn];
map<int,int> exist;

void getLCA(int in1,int in2,int preRoot,int a,int b)
{
	if(in1>in2)
		return;
	int inRoot=exist[pre[preRoot]];
	int aIndex=exist[a];
	int bIndex=exist[b];
	//都大于根结点 说明在右子树上
	if(aIndex>inRoot&&bIndex>inRoot){
		getLCA(inRoot+1,in2,preRoot+1+inRoot-in1,a,b);
	}else if((aIndex>inRoot&&bIndex<inRoot)||
		(aIndex<inRoot&&bIndex>inRoot))
	{
		printf("LCA of %d and %d is %d.\n",a,b,in[inRoot]);
	}else if(aIndex<inRoot&&bIndex<inRoot){
		getLCA(in1,inRoot-1,preRoot+1,a,b);
	}else if(aIndex==inRoot){
		printf("%d is an ancestor of %d.\n",a,b);
	}else if(bIndex==inRoot){
		printf("%d is an ancestor of %d.\n",b,a);
	}

}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&in[i]);
		exist[in[i]]=i;
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&pre[i]);
	}
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		if (exist[a]==0&&exist[b]==0)
		{
			printf("ERROR: %d and %d are not found.\n",a,b);
		}
		if(exist[a]==0&&exist[b]>0){
			printf("ERROR: %d is not found.\n",a);
		}
		if(exist[b]==0&&exist[a]>0){
			printf("ERROR: %d is not found.\n",b);
		}
		if (exist[a]>0&&exist[b]>0)
		{
			getLCA(1,n,1,a,b);
		}
	}

	return 0;
}