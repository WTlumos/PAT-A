#include<cstdio>
#include<cstring>
#include<cctype>
const int maxn=100;
char a[maxn],b[maxn],c[maxn],d[maxn];
char weeks[][4]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
	scanf("%s%s%s%s",a,b,c,d);
	int lena=strlen(a); int lenb=strlen(b); 
	int lenc=strlen(c); int lend=strlen(d);

	int len=lena>lenb?lenb:lena;
	int week,minute,second;
	int i=0;
	for (; i < len; ++i)
	{
		if(a[i]==b[i]&&(a[i]>='A'&&a[i]<='G')){
			week=a[i]-'A';
			break;
		}
	}
	i++;
	for (; i < len; ++i)
	{
		if (a[i]==b[i]&&((a[i]>='A'&&a[i]<='N')||(a[i]>='0'&&a[i]<='9'))){
			if(a[i]>='A'&&a[i]<='N'){
				minute=a[i]-'A'+10;
			}else if(a[i]>='0'&&a[i]<='9'){
				minute=a[i]-'0';
			}
			break;
		}
	}
	len=lenc>lend?lend:lenc;
	for (int j = 0; j < len; ++j)
	{
		if (c[j]==d[j]&&isalpha(c[j]))
		{
			second=j;
			break;
		}
	}
	printf("%s %02d:%02d\n",weeks[week],minute,second);
	return 0;
}