#include<cstdio>
#include<map>
using namespace std;
map<int,int> exist;
int pre[10010]={};
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&pre[i]);
		exist[pre[i]]++;
	}
	int u,v;
	while(m--)
	{
		scanf("%d%d",&u,&v);
		int a=0;
        for (int i = 0; i < n; ++i)
        {
        	a=pre[i];
        	if ((u<=a&&v>=a)||(u>=a&&v<=a))
        	{
        		break;
        	}	
        }
		if (exist[u]==0&&exist[v]==0)
		{
			printf("ERROR: %d and %d are not found.\n",u,v);
		}else if(exist[u]==0){
			printf("ERROR: %d is not found.\n",u);
		}else if(exist[v]==0){
			printf("ERROR: %d is not found.\n",v);
		}else if(u==a){
			printf("%d is an ancestor of %d.\n",u,v);
		}else if(v==a){
			printf("%d is an ancestor of %d.\n",v,u);
		}else{
			printf("LCA of %d and %d is %d.\n",u,v,a);
		}
	}
	return 0;
}