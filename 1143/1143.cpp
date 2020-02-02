/*超时*/
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<int> pre;
vector<int> in;
map<int,int> pos;
void getLCA(int inl,int inr,int preRoot,int a,int b){
	if (inl>inr)
	{
		return;
	}
	int inRoot=pos[pre[preRoot]];
	int aIndex=pos[a];
	int bIndex=pos[b];
	if (aIndex>inRoot&&bIndex>inRoot)
	{	getLCA(inRoot+1,inr,preRoot+1+inRoot-inl,a,b);
	}else if((aIndex>inRoot&&bIndex<inRoot)||(aIndex<inRoot&&bIndex>inRoot)){
		printf("LCA of %d and %d is %d.\n",a,b,in[inRoot]);
	}else if(aIndex<inRoot&&bIndex<inRoot){
		getLCA(inl,inRoot-1,preRoot+1,a,b);
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
    int a;
    pre.push_back(-100);
    in.push_back(-100);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a);
        pre.push_back(a);
		in.push_back(a);
	}
	sort(in.begin()+1,in.end());
	for (int i = 1; i <= n; ++i)
	{
		pos[in[i]]=i;	
	}
	int b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		if (pos[a]==0&&pos[b]==0)
		{
			printf("ERROR: %d and %d are not found.\n",a,b);
		}else if(pos[a]==0){
			printf("ERROR: %d is not found.\n",a);
		}else if(pos[b]==0){
			printf("ERROR: %d is not found.\n",b);
		}else{
			getLCA(1,n,1,a,b);
		}
	}
	return 0;
}