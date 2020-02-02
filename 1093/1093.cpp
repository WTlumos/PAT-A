#include<cstdio>
#include<cstring>
const int mod=1000000007;
char c[100010];
int leftp[100010]={};
int main()
{
	scanf("%s",c);
	int len=strlen(c);
	for (int i = 0; i < len; ++i)
	{
		if (i>0)
		{
			leftp[i]=leftp[i-1];
		}
		if (c[i]=='P')
		{
			leftp[i]++;
		}	
	}
	int rightT=0;
	int ans=0;
	for (int i = len-1; i >=0; i--)
	{
		if (c[i]=='T')
		{
			rightT++;
		}
		if (c[i]=='A')
		{
			ans=(ans+leftp[i]*rightT)%mod;
		}
	}
	printf("%d\n",ans);

	return 0;
}