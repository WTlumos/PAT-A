#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
char c[1010];
bool isPrime(int x){
	if (x<2)
	{
		return false;
	}
	int sqr=sqrt(1.0*x);
	for (int i = 2; i <= sqr; ++i)
	{
		if (x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int l,k;
	scanf("%d%d",&l,&k);
	scanf("%s",c);
	string str=c;
	int flag=0;
	for (int i = 0; i <= l-k; ++i)
	{
		string part=str.substr(i,k);
		int temp=atoi(part.c_str());
		if (isPrime(temp))
		{
			flag=1;
			printf("%s\n",part.c_str());
			break;
		}
	}
	if (flag==0)
	{
		printf("404\n");
	}

	return 0;
}