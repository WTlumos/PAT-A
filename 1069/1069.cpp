#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
void getArray(int n,int num[])
{
	for (int i = 3; i >=0; i--)
	{
		num[i]=n%10;
		n/=10;
	}
}
int getNum(int num[])
{
	int ans=0;
	for (int i = 0; i < 4; ++i)
	{
		ans=ans*10+num[i];
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[4];
	while(true){
		getArray(n,a);

		sort(a,a+4,cmp);
		int b=getNum(a);
		printf("%04d - ",b);

		sort(a,a+4);
		int c=getNum(a);
		printf("%04d = ",c);

		n=b-c;
		printf("%04d\n",n);
		if(n==0||n==6174){
			break;
		}
	}
	return 0;
}