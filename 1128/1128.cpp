#include<cstdio>
#include<algorithm>
using namespace std;
int queen[1010];
int main()
{
	int k;
	scanf("%d",&k);
	while(k--){
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&queen[i]);		
		}
		int flag=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				if(abs(j-i)==abs(queen[j]-queen[i])||queen[i]==queen[j])
				{
					flag=1;
					break;
				}
				
			}
			if (flag==1)
			{
				break;
			}
		}
		if (flag==1)
		{
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	return 0;
}