#include<cstdio>
#include<map>
using namespace std;
const int maxn=10010;
int in[maxn]={};
int pre[maxn]={};
map<int,int> exist;
void LCA(int l,int r,int root,int u,int v)
{
	if (l>r)
	{
		return;
	}
	int rootIdx=exist[pre[root]];
	int uIdx=exist[u];
	int vIdx=exist[v];
	if (uIdx<rootIdx&&vIdx<rootIdx)
	{
		LCA(l,rootIdx-1,root+1,u,v);
	}else if ((uIdx>rootIdx&&vIdx<rootIdx)||(uIdx<rootIdx&&vIdx>rootIdx))
	{
		printf("LCA of %d and %d is %d.\n",u,v,pre[root]);
	}else if(uIdx>rootIdx&&vIdx>rootIdx){
		LCA(rootIdx+1,r,root+1+rootIdx-l,u,v);
	}else if (uIdx==rootIdx)
	{
		printf("%d is an ancestor of %d.\n",u,v);
	}else if (vIdx==rootIdx){
		printf("%d is an ancestor of %d.\n",v,u);
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
	int u,v;
	while(m--){
		scanf("%d%d",&u,&v);
		if (exist[u]==0&&exist[v]==0)
		{
			printf("ERROR: %d and %d are not found.\n",u,v);
		}else if(exist[u]==0){
			printf("ERROR: %d is not found.\n",u);
		}else if (exist[v]==0)
		{
			printf("ERROR: %d is not found.\n",v);
		}else{
			LCA(1,n,1,u,v);
		}
	}
	return 0;
}