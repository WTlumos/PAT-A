#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
vector<int> ans;
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	ans=v;
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}