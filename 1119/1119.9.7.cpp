#include<cstdio>
#include<vector>
using namespace std;
int pre[40]={};
int post[40]={};
vector<int> in;
bool isunique=true;
void inorder(int prel,int prer,int postl,int postr){
	if (prel==prer)
	{
		in.push_back(pre[prel]);
		return;
	}
	int i=0;
	for (i = prel; i <= prer; ++i)
	{
		if (pre[i]==post[postr-1])
		{
			break;
		}
	}
	int left=i-prel-1;
	int right=prer-i+1;
	if (left>0)
	{
		inorder(prel+1,prel+left,postl,postr-1-right);
	}else{
		isunique=false;
	}
	in.push_back(post[postr]);
    inorder(prel+left+1,prer,postr-right,postr-1);

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
	if (isunique)
	{
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	for (int i = 0; i < n; ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d",in[i]);
	}
	printf("\n");
	return 0;
}