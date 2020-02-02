#include<cstdio>
#include<vector>
using namespace std;
int in[40],post[40];
vector<int> level[40];
int maxdeep;
void levelorder(int inl,int inr,int postl,int postr,int deep){
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
	levelorder(inl,i-1,postl,postl+i-inl-1,deep+1);
	levelorder(i+1,inr,postl+i-inl,postr-1,deep+1);
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
	levelorder(0,n-1,0,n-1,0);
	printf("%d",level[0][0]);
	for (int i = 1; i <= maxdeep; ++i)
	{
		if (i%2!=0)
		{
			for (int j = 0; j < level[i].size(); ++j)
			{
				printf(" %d", level[i][j]);
			}
		}else{
			for (int j = level[i].size()-1; j >= 0; j--)
			{
				printf(" %d", level[i][j]);
			}
		}
	}
	printf("\n");
	return 0;
}