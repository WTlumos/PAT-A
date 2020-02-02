#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
set<int> s;
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		if (a>0)
		{
			s.insert(a);	
		}
	}
	int index=1;
	for (set<int>::iterator i=s.begin(); i!= s.end(); ++i)
	{
		if (*i==index)
		{
			index++;
		}
	}
	printf("%d\n",index);
	return 0;
}