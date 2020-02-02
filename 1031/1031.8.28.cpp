/*
helloworld!
h   !
e   d
l   l
lowor
*/
#include<cstdio>
#include<cstring>
char str[100];
char ans[30][30];
int main()
{
	scanf("%s",str);
    int n=strlen(str)+2;
    memset(ans,' ',sizeof(ans));
    int n1=n/3;
    int n2=n/3+n%3;
    int n3=n+2-n1-n2;
    int t=0;
    for (int i = 0; i < n1; ++i)
    {
    	ans[i][0]=str[t++];
    }
    for (int i = 1; i < n2-1; ++i)
    {
    	ans[n1-1][i]=str[t++];
    }
    for (int i = n1-1; i >= 0 ; i--)
    {
    	ans[i][n2-1]=str[t++];
    }
    for (int i = 0; i < n1; ++i)
    {
    	for (int j = 0; j < n2; ++j)
    	{
    		printf("%c", ans[i][j]);
    	}
    	printf("\n");
    }
	return 0;
}