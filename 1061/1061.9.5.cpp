#include<cstdio>
#include<cctype>
#include<cstring>
char str1[100],str2[100],str3[100],str4[100];
char day[][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
	scanf("%s%s%s%s",str1,str2,str3,str4);

	 int len1=strlen(str1);
	 int len2=strlen(str2);
	 int len=len1>len2?len2:len1;
	 int i=0;
	 for (; i < len; ++i)
	 {
	 	if (str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='G')
	 	{
	 		printf("%s",day[str1[i]-'A']);
	 		break;
	 	}
	 }
	 for (i=i+1; i < len; ++i)
	 {
	 	if (str1[i]==str2[i]&&(isdigit(str1[i])||(str1[i]>='A'&&str1[i]<='N')))
	 	{
	 		if (isdigit(str1[i]))
	 		{
	 			printf(" %02d:",str1[i]-'0');
	 		}else{
	 			printf(" %02d:",str1[i]-'A'+10);
	 		}
	 		break;
	 	}
	 }
 	 len1=strlen(str3);
	 len2=strlen(str4);
	 len=len1>len2?len2:len1;
	 for (i = 0; i < len; ++i)
	 {
	 	if (str3[i]==str4[i]&&isalpha(str3[i]))
	 	{
	 		printf("%02d\n",i);
	 		break;
	 	}
	 	
	 }

	return 0;
}