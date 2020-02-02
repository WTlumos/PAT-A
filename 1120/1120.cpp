#include<cstdio>
#include<set>
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
		int sum=0;
		while(a){
			sum+=a%10;
			a/=10;
		}
		s.insert(sum);
	}
	printf("%lu\n",s.size());
	for (set<int>::iterator i=s.begin(); i!= s.end(); ++i)
	{
		if(i!=s.begin()){
			printf(" ");
		}
		printf("%d",*i);
	}
	return 0;
}