#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int ans=-1;
	int i=0;
	int j=0;
	while(i<n)
	{
		while(v[j]<=v[i]*p&&j<n){
			j++;
		}
		ans=max(ans,j-i);
		i++;
	}
	printf("%d\n",ans);
	return 0;
}