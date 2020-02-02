#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
map<int,int> exist;
bool isPrime(int x){
	if (x<2)
	{
		return false;
	}
	for (int i = 2; i <= (int)sqrt(1.0*x); ++i)
	{
		if (x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(){
	int msize,n;
	scanf("%d%d",&msize,&n);
	while(!isPrime(msize)){
		msize++;
	}
	int a; int key=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		int flag=0; int idx=0; 
		for (int j = 0; j < msize; ++j)
		{
			int h=(a+j*j)%msize;
			if (exist[h]==0)
			{
				flag=1;
				exist[h]++;
				idx=h;
				break;
			}
		}
		if (flag==0)
		{
			if (key>0)
			{
				printf(" ");
			}else{
				key++;
			}
			printf("-");
		}else{
			if (key>0)
			{
				printf(" ");
			}else{
				key++;
			}
			printf("%d",idx);
		}
	}
	return 0;
}