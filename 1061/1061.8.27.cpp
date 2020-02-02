#include<cstdio>
#include<cctype>
#include<cstring>
const int maxn=70;
char c1[maxn],c2[maxn],c3[maxn],c4[maxn];
char week[][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
	scanf("%s%s%s%s",c1,c2,c3,c4);
    int len1=strlen(c1);
    int len2=strlen(c2);
    int len=len1>len2?len2:len1;
    int i=0;
	for (; i < len; ++i)
	{
		if (c1[i]==c2[i]&&(c1[i]>='A'&&c1[i]<='G'))
		{
			printf("%s ", week[c1[i]-'A']);
			break;
		}
	}
	for (i=i+1; i < len; ++i)
	{
		if (c1[i]==c2[i]&&((c1[i]>='0'&&c1[i]<='9')||(c1[i]>='A'&&c1[i]<='N')))
		{
			if (c1[i]>='0'&&c1[i]<='9')
			{
				printf("%02d:",c1[i]-'0');
				break;
			}else if(c1[i]>='A'&&c1[i]<='N'){
				printf("%02d:",10+c1[i]-'A');
				break;
			}
		}
	}
    len1=strlen(c3);
    len2=strlen(c4);
    len=len1>len2?len2:len1;
    for (int pos = 0; pos < len; ++pos)
    {
    	if (c3[pos]==c4[pos]&&isalpha(c3[pos]))
    	{
    		printf("%02d\n",pos);
    		break;
    	}
    }
	return 0;
}