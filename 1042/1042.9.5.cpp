#include<cstdio>
int scan[60]={};
int start[60]={};
int end[60]={};
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
	char str[]="SHCDJ";
	for (int i = 1; i < 55; ++i)
	{
		if (i!=1)
		{
			printf(" ");
		}
		int pos=end[i]-1;
		printf("%c%d",str[pos/13],pos%13+1);
	}
	return 0;
}