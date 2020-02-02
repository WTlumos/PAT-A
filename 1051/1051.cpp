#include<cstdio>
#include<stack>
using namespace std;
int num[1001];
int main()
{
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	for (int i = 0; i < k; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d",&num[j]);
		}
		stack<int> s;
		int current=1;
		for (int j = 1; j <= n; ++j)
		{
			s.push(j);
			if(s.size()>m){
				break;
			}
			while(!s.empty()&&s.top()==num[current]){
				s.pop();
				current++;
			}
		}
		if (current==n+1)
		{
			printf("YES\n");
		}else{
			printf("NO\n");
		}

	}
	return 0;
}