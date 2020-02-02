#include<cstdio>
#include<vector>
#include<string>
using namespace std;
const int maxn=30;
struct node{
	string data;
	int lchild,rchild;
};
node tree[maxn];
int indegree[maxn]={};
int root=0;
string inorder(int index)
{
	if (index==-1)
	{
		return "";
	}
    if(tree[index].rchild!=-1){
		tree[index].data=inorder(tree[index].lchild)+tree[index].data+inorder(tree[index].rchild);
	    if(index!=root){
	    	tree[index].data="("+tree[index].data+")";
	    }
	}
    return tree[index].data;
}
int main()
{
	int n;
	scanf("%d",&n);
	node temp; char c[20];
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s%d%d",c,&temp.lchild,&temp.rchild);
		temp.data=c;
        tree[i]=temp;
        indegree[temp.lchild]++;
        indegree[temp.rchild]++;	
	}
	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i]==0)
		{
			root=i;
			break;
		}
	}
	//printf("%d\n",root);
	printf("%s\n",inorder(root).c_str());
	return 0;
}