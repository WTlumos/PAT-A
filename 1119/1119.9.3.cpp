#include<cstdio>
#include<vector>
using namespace std;
int pre[40]={};
int post[40]={};
vector<int> in;
bool isunique=true;
void inorder(int prel,int prer,int root)
{
	if (prel==prer)
	{
		in.push_back(pre[prel]);
		return;
	}
	int i=0;
	while(i<=prer&&pre[i]!=post[root-1]){
		i++;
	}
	int left=i-prel-1;
	if (i-prel-1>0)
	{
		inorder(prel+1,i-1,root-1-(prer-i+1));
	}else{
		isunique=false;
	}
	in.push_back(post[root]);
	inorder(i,prer,root-1);

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
	inorder(0,n-1,n-1);
	if (isunique)
	{
		printf("Yes\n%d",in[0]);
	}else{
		printf("No\n%d",in[0]);
	}
	for (int i = 1; i < in.size(); ++i)
	{
		printf(" %d",in[i]);
	}
	printf("\n");
	return 0;
}