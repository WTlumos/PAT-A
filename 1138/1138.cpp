#include<cstdio>
#include<vector>
using namespace std;
vector<int> pre;
vector<int> in;
void postOrder(int pl,int pr,int il,int ir){
	if (pl>pr)
	{
		return;
	}
	int i;
	for (i = il; i<=ir; ++i)
	{
		if (in[i]==pre[pl])
		{
			break;
		}
	}
	int left=i-il;
	int right=ir-i;
	if(left==1){
		printf("%d\n",in[il]);
	}else if(left>1){
		postOrder(pl+1,pl+left,il,i-1);
	}else if(right==1){
		printf("%d\n",in[ir]);
	}else if(right>1){
		postOrder(pl+left+1,pr,i+1,ir);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		pre.push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		in.push_back(a);
	}
	postOrder(0,n-1,0,n-1);
	return 0;
}