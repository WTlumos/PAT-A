#include<cstdio>
#include<string>
using namespace std;
struct node{
	string data;
	int lchild,rchild;
}tree[30];
int indegree[30]={};
int root=0;
string experssion(int idx){
	if (idx==-1)
	{
		return "";
	}
	if (tree[idx].rchild!=-1)
	{
		tree[idx].data=experssion(tree[idx].lchild)+tree[idx].data+experssion(tree[idx].rchild);
	    if (idx!=root)
	    {
	    	tree[idx].data="("+tree[idx].data+")";
	    }
	}
	return tree[idx].data;
}
char str[30];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s%d%d",str,&tree[i].lchild,&tree[i].rchild);
		tree[i].data=str;
		indegree[tree[i].lchild]++;
		indegree[tree[i].rchild]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i]==0)
		{
			root=i;
			break;
		}
	}
	string ans=experssion(root);
	printf("%s\n", ans.c_str());
	return 0;
}