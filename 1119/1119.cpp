#include<cstdio>
#include<vector>
using namespace std;
const int maxn=40;
int pre[maxn]={};
int post[maxn]={};
bool isunique=true;
vector<int> in;
void inorder(int prel,int prer,int postl,int postr)
{
	if (prel==prer)
	{
		in.push_back(pre[prel]);
		return;
	}
	if(pre[prel]==post[postr]){
		int i=prel;
		while(i<=prer&&pre[i]!=post[postr-1])
			i++;
		int left=i-prel-1;
		if (left>0)
		{
			inorder(prel+1,i-1,postl,postl+left-1);
		}else{
			isunique=false;
		}
		in.push_back(post[postr]);
		inorder(i,prer,postl+left,postr-1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&pre[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&post[i]);
	}
	inorder(0,n-1,0,n-1);
	printf("%s\n", isunique?"Yes":"No");
	printf("%d",in[0]);
	for (int i = 1; i < n; ++i)
	{
		printf(" %d",in[i]);
	}
	printf("\n");

	return 0;
}