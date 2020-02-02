#include<cstdio>
const int maxn=55;
int scan[maxn]={0};
int start[maxn],end[maxn];
int main()
{
	int repeat;
	scanf("%d",&repeat);
	for (int i = 1; i < maxn ; ++i)
	{
		scanf("%d",&scan[i]);
		end[i]=i;
	}
	for (int i = 0; i < repeat; ++i)
	{
		for (int j = 1; j < maxn; ++j)
		{
			start[j]=end[j];
		}
		for (int j = 0; j < maxn; ++j)
		{
			end[scan[j]]=start[j];
		}
	}
	char c[6]="SHCDJ";
	for (int i = 1; i < maxn; ++i)
	{
		end[i]=end[i]-1;
		printf("%c%d",c[end[i]/13],end[i]%13+1);
		if (i<maxn-1)
		{
			printf(" ");
		}
	}
	return 0;
}