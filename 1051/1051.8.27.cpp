#include<cstdio>
#include<stack>
using namespace std;
int num[1010]={};
int main()
{
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	while(k--)
	{
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d",&num[i]);
		}
		stack<int> s;
		int cnt=1;
		for (int i = 1; i <= n; ++i)
		{
			s.push(i);
			if (s.size()>m)
			{
				break;
			}
			while(!s.empty()&&s.top()==num[cnt]){
				s.pop();
				cnt++;
			}
		}
		if (cnt==n+1)
		{
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}