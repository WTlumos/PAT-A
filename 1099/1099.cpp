#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct node{
	int data;
	int rchild,lchild;
};
node tree[101];
int num[101];
int temp=0;
void match(int root)
{
	if(root==-1){
		return;
	}
	match(tree[root].lchild);
	tree[root].data=num[temp];
	//printf("%d %d\n",root,num[temp]);
	temp++;
	match(tree[root].rchild);
}
vector<int> ans;
void levelOrder()
{
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		ans.push_back(tree[node].data);
		if (tree[node].lchild!=-1)
		{
			q.push(tree[node].lchild);
		}
		if (tree[node].rchild!=-1)
		{
			q.push(tree[node].rchild);
		}
	}

}
int main()
{
	int n;
	scanf("%d",&n);
	int a,b;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&a,&b);
		tree[i].lchild=a;
		tree[i].rchild=b;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);	
	}
	sort(num,num+n);
	match(0);
	levelOrder();
	printf("%d",ans[0]);
	for (int i = 1; i < ans.size(); ++i)
	{
		printf(" %d", ans[i]);
	}
	return 0;
}