#include<cstdio>
#include<cstring>
int cnt1[10]={};
int cnt2[10]={};
int main()
{
	char c[21];
	scanf("%s",c);
	int len=strlen(c);
	int index=0;
	char ans[30];
	int carry=0;
	for (int i = len-1; i >= 0; i--)
	{
		int temp=(c[i]-'0')*2+carry;
		ans[index++]=temp%10+'0';
		carry=temp/10;	
	}
	while(carry!=0)
	{
		ans[index++]=carry%10+'0';
		carry/=10;
	}
	for (int i = 0; i < len; ++i)
	{
		cnt1[c[i]-'0']++;
	}
	for (int i = 0; i < index; ++i)
	{
		cnt2[ans[i]-'0']++;
	}
	for (int i = 0; i < index/2; ++i)
	{
		char ch=ans[i];
		ans[i]=ans[index-1-i];
		ans[index-1-i]=ch;
	}
	int flag=0;
	for (int i = 0; i < 10; ++i)
	{
		if(cnt1[i]!=cnt2[i]){
			flag=1;
		}
	}
	if (flag==1)
	{
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	printf("%s\n",ans);
	return 0;
}