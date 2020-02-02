#include<cstdio>
#include<string>
using namespace std;
struct node
{
	string data;
	int lchild,rchild;
}v[30];
int indegree[30];
int root=0;
string inorder(int idx){
	if (idx==-1)
	{
		return "";
	}
	if (v[idx].rchild!=-1)
	{
		v[idx].data=inorder(v[idx].lchild)+v[idx].data+inorder(v[idx].rchild);
		if (idx!=root)
		{
			v[idx].data="("+v[idx].data+")";
		}
	}
	return v[idx].data;
}
char str[20];
int main()
{
	int n;
	scanf("%d",&n);
	node temp;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s%d%d",str,&temp.lchild,&temp.rchild);
		temp.data=str;
		v[i]=temp;
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
	printf("%s\n", inorder(root).c_str());

	return 0;
}