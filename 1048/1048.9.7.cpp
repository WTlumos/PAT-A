#include<cstdio>
#include<stack>
using namespace std;
int num[1010];
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
		int current=1;
		stack<int> s;
		for (int i = 1; i <= n; ++i)
		{
			s.push(i);
			if (s.size()>m)
			{
				break;
			}
			while(!s.empty()&&num[current]==s.top()){
				current++;
				s.pop();
			}	
		}
		if (current==n+1){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}