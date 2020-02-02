#include<cstdio>
#include<vector>
using namespace std;
vector<int> in,pre;
void postorder(int inl,int inr,int prel,int prer)
{
	if (prel>prer)
	{
		return;
	}
	int i=inl;
	while(in[i]!=pre[prel]&&i<=inr){
		i++;
	}
	int left=i-inl;
	int right=inr-i;
	if (left==1)
	{
		printf("%d\n",in[inl]);
	}
	else if (left>1)
	{
		postorder(inl,i-1,prel+1,prel+left);
	}else if(right==1){
		printf("%d\n",in[inr]);
	}else if (right>1)
	{
		postorder(i+1,inr,prel+left+1,prer);
	}

}
int main()
{
    int n;
    scanf("%d",&n);
    int a;
    for(int i=0;i<n;i++){
       scanf("%d",&a);
       pre.push_back(a);
    }
    for(int i=0;i<n;i++){
       scanf("%d",&a);
       in.push_back(a);
    }
    postorder(0,n-1,0,n-1);
	return 0;
}