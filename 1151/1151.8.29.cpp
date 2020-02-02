#include<cstdio>
#include<map>
using namespace std;
int in[10010]={};
int pre[10010]={};
map<int,int> exist;
void lca(int l,int r,int root,int a,int b){
	if (l>r)
	{
		return;
	}
	int rootIdx=exist[pre[root]];
    int aIdx=exist[a];
    int bIdx=exist[b];
    //都在左子树
    if (aIdx<rootIdx&&bIdx<rootIdx)
    {
    	lca(l,rootIdx-1,root+1,a,b);
    }else if((aIdx<rootIdx&&bIdx>rootIdx)||(aIdx>rootIdx&&bIdx<rootIdx)){
    	printf("LCA of %d and %d is %d.\n",a,b,pre[root]);
    }else if(aIdx>rootIdx&&bIdx>rootIdx){
    	lca(rootIdx+1,r,root+1+rootIdx-l,a,b);
    }else if(aIdx==rootIdx){
    	printf("%d is an ancestor of %d.\n",a,b);
    }else if(bIdx==rootIdx){
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
	int u,v;
	while(m--){
		scanf("%d%d",&u,&v);
		if (exist[u]==0&&exist[v]==0)
		{
			printf("ERROR: %d and %d are not found.\n",u,v);
		}else if(exist[u]==0){
			printf("ERROR: %d is not found.\n",u);
		}else if(exist[v]==0){
			printf("ERROR: %d is not found.\n",v);
		}else{
			lca(1,n,1,u,v);
		}
	}
	return 0;
}