#include<cstdio>
#include<cstring>
char str[100];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",str);
		int len=strlen(str);
		int a=0; int b=0; int total=0;
		for (int i = 0; i < len/2; ++i)
		{
			total=total*10+str[i]-'0';
			a=a*10+str[i]-'0';
		}
		for (int i = len/2; i < len; ++i)
		{
			total=total*10+str[i]-'0';
			b=b*10+str[i]-'0';
		}
		if (total%(a*b)==0&&(a*b)!=0)
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}

	}
	return 0;
}