#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
char a[1010];
char b[1010];
int main()
{
	scanf("%s%s",a,b);
	map<char,int> m;
	int len=strlen(a);
	for (int i = 0; i < len; ++i)
	{
		m[a[i]]++;
	}
    len=strlen(b);
    int get=0;
    int lost=0;
    for (int i = 0; i < len; ++i)
    {
    	if (m[b[i]]>0)
    	{
    		m[b[i]]--;
    		get++;
    	}else{
    		lost++;
    		
    	}
    }
    if (lost>0)
    {
    	printf("No %d\n",lost);
    }else{
    	printf("Yes %d\n",(int)strlen(a)-get);
    }
	return 0;
}