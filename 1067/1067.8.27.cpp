#include<cstdio>
#include<algorithm>
using namespace std;
int num[100010]={};
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		num[a]=i;
	}
	int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		if (num[i]!=i)
		{
			while(num[0]!=0){
				swap(num[0],num[num[0]]);
				cnt++;

			}
			if (num[i]!=i)
			{
				swap(num[0],num[i]);
				cnt++;
			}
		}
	}
	printf("%d\n",cnt );
	return 0;
}