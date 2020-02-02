#include<cstdio>
#include<map>
using namespace std;
char c1[1010],c2[1010];
map<char,int> exist;
int main()
{
	scanf("%s%s",c1,c2);
	int len1=0;
	for (int i = 0; c1[i] != '\0'; ++i)
	{
		len1++;
		exist[c1[i]]++;
	}
	int cnt=0; int len2=0;
	for (int i = 0; c2[i]!='\0'; ++i)
	{
		len2++;
		if (exist[c2[i]]==0)
		{
			cnt++;
		}else{
			exist[c2[i]]--;
		}
	}
	if (cnt==0)
	{
		printf("Yes %d\n",len1-len2);
	}else{
		printf("No %d\n",cnt);
	}
	return 0;
	
}