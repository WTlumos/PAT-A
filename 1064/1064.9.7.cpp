#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int in[1010]={};
int level[1010]={};
int n;
void levelorder(int l,int r,int index){
	if (l>r)
	{
		return;
	}
	int num=r-l+1;
	int lay=log(num+1)/log(2);
	int leaves=num-(pow(2,lay)-1);
	int root=l+(pow(2,lay-1)-1)+min((int)pow(2,lay-1),leaves);
	level[index]=in[root];
	levelorder(l,root-1,2*index+1);
	levelorder(root+1,r,2*index+2);

}
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&in[i]);
	}
	sort(in,in+n);
	levelorder(0,n-1,0);
	for (int i = 0; i < n; ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d",level[i]);
	}
	return 0;
}