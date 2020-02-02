#include<cstdio>
int scan[55]={};
int end[55]={};
int start[55]={};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i < 55; ++i)
	{
		scanf("%d",&scan[i]);
		end[i]=i;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < 55; ++j)
		{
			start[j]=end[j];
		}
		for (int j = 1; j < 55; ++j)
		{
			end[scan[j]]=start[j];
		}
	}
	char c[]={'S','H','C','D','J'};
	for (int i = 1; i < 55; ++i)
	{
		int pos=end[i]-1;
		if (i!=1)
		{
			printf(" ");
		}
		printf("%c%d",c[pos/13],pos%13+1);
	}
	return 0;
}