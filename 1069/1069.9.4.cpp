#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
void toarray(int num[],int x)
{
	for (int i = 0; i < 4; ++i)
	{
		num[i]=x%10;
		x=x/10;
	}
}
int tonum(int num[]){
	int x=0;
	for (int i = 0; i < 4; ++i)
	{
		x=x*10+num[i];
	}
	return x;
}
int num[10010]={};
int main()
{
	int n;
	scanf("%d",&n);
	while(true){

	    toarray(num,n);

	    sort(num,num+4,cmp);
	    int a=tonum(num);

	    sort(num,num+4);
	    int b=tonum(num);

	    printf("%04d - %04d = %04d\n",a,b,a-b);
	    if (a-b==0||a-b==6174)
	    {
	    	break;
	    }
	    n=a-b;

	}

	return 0;
}