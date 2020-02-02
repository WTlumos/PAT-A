#include<cstdio>
#include<cstring>
char c[100010];
int leftP[100010]={};
const int mod=1000000007;
int main()
{
	scanf("%s",c);
	int len=strlen(c);
	for (int i = 0; i < len; ++i)
	{
		if (i>0)
		{
			leftP[i]=leftP[i-1];
		}
		if (c[i]=='P')
		{
			leftP[i]++;
		}	
	}
	int rightT=0;
	int ans=0;
	for (int i = len-1; i >= 0 ; i--)
	{
		if (c[i]=='T')
		{
			rightT++;
		}
		if (c[i]=='A')
		{
			ans=(ans+rightT*leftP[i])%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}