#include<cstdio>
#include<cstring>
int main()
{
	char c[100];
	scanf("%s",c);
    int n1,n2,n3;
	int n=strlen(c)+2;
	char u[30][30];
	memset(u,' ',sizeof(u));
	n1=n/3;
	n2=n/3+n%3;
	int index=0;
	for (int i = 0; i < n1; ++i)
	{
		u[i][0]=c[index++];
	}
	for (int i = 1; i <= n2-2 ; ++i)
	{
		u[n1-1][i]=c[index++];
	}
	for (int i = n1-1; i >=0; i--)
	{
		u[i][n2-1]=c[index++];
	}
	for (int i = 0; i < n1; ++i)
	{
		for (int j = 0; j < n2; ++j)
		{
			printf("%c",u[i][j]);
		}
		printf("\n");
	}
	return 0;
}