#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
char c1[1010],c2[1010];
map<char,int> m;
int main(){
	scanf("%s%s",c1,c2);
	for (int i = 0; i < strlen(c1); ++i)
	{
		m[c1[i]]++;		
	}
	int flag=0;
	int cnt=0;
	for (int i = 0; i < strlen(c2); ++i)
	{
		if (m[c2[i]]>0)
		{
			m[c2[i]]--;
		}else{
			flag=1;
			cnt++;
			
		}
	}
	if (flag==0)
	{
		int size=strlen(c1)-strlen(c2);
		printf("Yes %d\n",size);
	}else{
		printf("No %d\n",cnt);

	}
	return 0;
}