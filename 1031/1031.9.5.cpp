#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[100];
char matrix[100][100];
int main()
{
	fill(matrix[0],matrix[0]+100*100,' ');
	scanf("%s",str);
	int len=strlen(str)+2;
	int n1=len/3;
	int n2=len/3+len%3;
	int t=0;
	for (int i = 0; i < n1-1; ++i)
	{
		matrix[i][0]=str[t++];
	}
	for (int i = 0; i < n2; ++i)
	{
		matrix[n1-1][i]=str[t++];
	}
	for (int i = n1-2; i >= 0; i--)
	{
		matrix[i][n2-1]=str[t++];
	}
	for (int i = 0; i < n1; ++i)
	{
		for (int j = 0; j < n2; ++j)
		{
			printf("%c",matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}