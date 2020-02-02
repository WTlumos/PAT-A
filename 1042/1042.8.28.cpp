#include<cstdio>
#include<map>
using namespace std;
map<int,int> m;
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		m[a]++;
	}
	int flag=0;
	int key=0;
	for (map<int,int>::iterator i = m.begin(); i != m.end(); ++i)
	{
		if (i->second==1)
		{
			if (key>0)
			{
				flag=1;
				printf("%d\n",i->first);
				break;
			}
			key++;
		}
	}
	if (flag==0)
	{
		printf("None\n");
	}
	return 0;
}