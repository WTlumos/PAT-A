#include<stdio.h>
#include<map>
using namespace std;
map<int,double> num1;
map<int,double> num2;
double ans[2010]={0.0};
int main()
{
	int k;
	scanf("%d",&k);
	int a;
	double b;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%lf",&a,&b);
		num1[a]=b;
	}
	scanf("%d",&k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%lf",&a,&b);
		num2[a]=b;
	}
	double coe;
	int e;
	for (map<int,double>::iterator i=num1.begin(); i!=num1.end();++i)
	{
		for (map<int,double>::iterator j=num2.begin(); j!=num2.end();++j){
			e=i->first+j->first;
			coe=i->second*j->second;
			ans[e]+=coe;
		}
	}
	int total=0;
	for (int i=2000;i>=0;i--)
	{
		if(ans[i]!=0.0){
			total++;
		}
	}
	printf("%d",total);
	for (int i=2000;i>=0;i--)
	{
		if(ans[i]!=0.0){
			printf(" %d %.1f",i,ans[i]);
		}
	}
	return 0;
}