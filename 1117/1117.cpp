#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		v.push_back(a);
	}
	sort(v.begin(), v.end(),cmp);
	int e=1;
	for (int i = 0; i < n; ++i)
	{
		if (v[i]>e)
		{
			e++;
		}
	}
	printf("%d\n",e-1);
	return 0;
}