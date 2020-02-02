#include<cstdio>
#include<map>
#include<cctype>
#include<string>
using namespace std;
map<char,int> exist;
char str1[100],str2[100];
int main()
{
	scanf("%s%s",str1,str2);
	for (int i = 0; str2[i] != '\0'; ++i)
	{
		str2[i]=toupper(str2[i]);
		exist[str2[i]]++;
	}
    string ans;
	for (int i = 0; str1[i] != '\0'; ++i)
	{
		str1[i]=toupper(str1[i]);
		if(exist[str1[i]]==0&&ans.find(str1[i])==string::npos){
			ans+=str1[i];
		}
	}
     printf("%s\n",ans.c_str());
	return 0;
}