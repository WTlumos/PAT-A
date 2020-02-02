#include<cstdio>
#include<vector>
using namespace std;
int in[40]={};
int post[40]={};
int maxdeep=-1;
vector<int> level[40];
void getLevel(int inl,int inr,int postr,int deep){
	if (deep>maxdeep)
	{
		maxdeep=deep;
	}
	if (inl>inr)
	{
		return;
	}
	level[deep].push_back(post[postr]);
	int i=0;
	for (i = inl; i <= inr; ++i)
	{
		if (in[i]==post[postr])
		{
			break;
		}
	}
	getLevel(inl,i-1,postr-(inr-i)-1,deep+1);
	getLevel(i+1,inr,postr-1,deep+1);

}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&in[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&post[i]);
	}
	getLevel(0,n-1,n-1,1);

	printf("%d", level[1][0]);
	for (int i = 2; i <= maxdeep; ++i)
	{
		if (i%2==0)
		{
			for (int j = 0; j < level[i].size(); ++j)
			{
				printf(" %d",level[i][j]);
			}
		}else{
			for (int j = level[i].size()-1; j >=0 ; j--)
			{
				printf(" %d",level[i][j]);
			}
		}
	}
	return 0;
}