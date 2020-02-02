/*超时*/
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0;
	string temple="1";
	for (int i = 1; i <= n; ++i)
	{
		string str=to_string(i);
		int index=0;
		for (int j=0;j<str.length();j++)
		{
			if(temple.find(str[j])!=string::npos){
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}