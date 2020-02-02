#include<cstdio>
#include<set>
using namespace std;
const int maxn=100010;
set<int> num;
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
			num.insert(a);
		}
	}
	int idx=1;
	for (set<int>::iterator i = num.begin(); i != num.end(); ++i)
	{
		if (idx==*i)
		{
			idx++;
		}	
	}
	printf("%d\n",idx);
	return 0;
}