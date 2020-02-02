#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int data;
	int lchild,rchild;
}v[110];
int in[110]={};
int t=0;
void inorder(int root){
	if (root==-1)
	{
		return;
	}
	inorder(v[root].lchild);
	v[root].data=in[t++];
	//printf("%d\n",v[root].data);
	inorder(v[root].rchild);
}
int key;
void levelorder(int root){
   queue<int> q;
   q.push(root);
   while(!q.empty()){
   	 int temp=q.front();
   	 if (key==0)
   	 {
   	 	printf("%d",v[temp].data);
   	 	key++;
   	 }else{
   	 	printf(" %d",v[temp].data);
   	 }
   	 q.pop();
   	 if (v[temp].lchild!=-1)
   	 {
   	 	q.push(v[temp].lchild);
   	 }
   	 if (v[temp].rchild!=-1)
   	 {
   	 	q.push(v[temp].rchild);
   	 }
   }

}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&v[i].lchild,&v[i].rchild);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&in[i]);
	}
	sort(in,in+n);
	inorder(0);
	levelorder(0);
	return 0;
}