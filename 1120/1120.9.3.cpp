#include<cstdio>
#include<set>
using namespace std;
char str[100];
set<int> s;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		int sum=0;
		for (int i = 0; str[i] != '\0'; ++i)
		{
			int num=str[i]-'0';
			sum+=num;
		}
		s.insert(sum);	
	}
	printf("%lu\n",s.size());
	for (set<int>::iterator i = s.begin(); i != s.end(); ++i)
	{
		if (i!=s.begin())
		{
			printf(" ");
		}
		printf("%d",*i);
	}
	return 0;
}