#include<cstdio>
#include<set>
using namespace std;
set<int> s[60];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)
    {
    	int k;
    	scanf("%d",&k);
    	int a;
    	for (int j = 0; j < k; ++j)
    	{
    		scanf("%d",&a);
    		s[i].insert(a);
    	}
    }
    int q;
    scanf("%d",&q);
    int a,b;
    for (int i = 0; i < q; ++i)
    {
    	scanf("%d%d",&a,&b);
    	set<int> s1=s[a];
    	set<int> s2=s[b];
    	int nt=s1.size();
    	int nc=0;
    	for (set<int>::iterator i = s2.begin(); i != s2.end(); ++i)
    	{
    		if (s1.find(*i)!=s1.end())
    		{
    			nc++;
    		}else{
    			nt++;
    		}
    	}
    	printf("%.1f%%\n", 1.0*nc/nt*100);
    }
	return 0;
}