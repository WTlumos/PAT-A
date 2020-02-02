#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int num[10010]={};
void getArray(int n,vector<int> &v)
{
	for (int i = 0; i < 4; ++i)
	{
		v.push_back(n%10);
		n/=10;
	}
}
int getNum(vector<int> v)
{
	int sum=0;
	for (int i = 0; i < 4; ++i)
	{
		sum=sum*10+v[i];
	}
	return sum;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(true){
	    vector<int> v1,v2;
	    getArray(n,v1);
	    sort(v1.begin(), v1.end(),cmp);
	    int a=getNum(v1);
	    v2=v1;
	    sort(v2.begin(), v2.end());
	    int b=getNum(v2);
	    int c=a-b;
	    printf("%04d - %04d = %04d\n",a,b,c);
	    n=c;
	    if (c==6174||c==0)
	    {
	    	break;
	    }
	}
	return 0;
}