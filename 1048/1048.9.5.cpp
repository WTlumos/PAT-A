#include<cstdio>
#include<algorithm>
using namespace std;
int num[100010]={};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	int i=0;int j=n-1; int flag=0;
	while(i!=j){
		if (num[i]+num[j]==m)
		{
			flag=1;
			printf("%d %d\n",num[i],num[j]);
			break;
		}else if (num[i]+num[j]<m)
		{
			i++;
		}else{
			j--;
		}
	}
	if (flag==0)
	{
		printf("No Solution\n");
	}
	return 0;
}