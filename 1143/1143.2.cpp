#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector<int> pre;
map<int,int> exist;
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		pre.push_back(a);
		exist[a]=1;
	}
	int b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		int temp=0;
		for (int j = 0; j < n; ++j)
		{
			temp=pre[j];
			if((a>=temp&&b<=temp)||(a<=temp&&b>=temp)){
				break;
			}
		}
		if (exist[a]==0&&exist[b]==0)
		{
			printf("ERROR: %d and %d are not found.\n",a,b);
		}else if(exist[a]==0){
			printf("ERROR: %d is not found.\n",a);
		}else if(exist[b]==0){
			printf("ERROR: %d is not found.\n",b);
		}else if(temp==a){
			printf("%d is an ancestor of %d.\n",a,b);
		}else if(temp==b){
			printf("%d is an ancestor of %d.\n",a,b);
		}else{
			printf("LCA of %d and %d is %d.\n",a,b,temp);
		}
	}
	return 0;
}