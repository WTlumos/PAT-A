#include<cstdio>
const int cnt=55;
int scan[cnt],end[cnt],start[cnt];
int main()
{
	int k;
	scanf("%d",&k);
	for (int i = 1; i < cnt; ++i)
	{
		scanf("%d",&scan[i]);
		end[i]=i;
	}
	for (int i = 0; i < k; ++i)
	{
		for (int j = 1; j < cnt; ++j)
		{
			start[j]=end[j];
		}
		for (int j = 1; j < cnt; ++j)
		{
			end[scan[j]]=start[j];
		}
	}
	char c[]={"SHCDJ"};
	for (int i = 1; i < cnt; ++i)
	{
		if (i!=1)
		{
			printf(" ");
		}
		int pos=end[i]-1;
		printf("%c%d",c[pos/13],pos%13+1);
	}
	printf("\n");
	return 0;
}