#include<cstdio>
#include<map>
using namespace std;
map<int,int> address,nextaddress,exist;
map<int, char> data;
int main()
{
	int first1,first2,n;
	scanf("%d%d%d",&first1,&first2,&n);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		address[a]=a;
		scanf(" %c %d",&data[a],&nextaddress[a]);
	}
	for (int i = first1; i != -1; i=nextaddress[i])
	{
		exist[i]++;
	}
	int flag=0;
	for (int i = first2; i != -1; i=nextaddress[i])
	{
		if (exist[i]>0)
		{
			flag=1;
			printf("%05d\n",i);
			break;
		}
	}
	if (flag==0)
	{
		printf("-1\n");
	}
	return 0;
}