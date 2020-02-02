#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a,b;
	b=0;
	int total=0;
	int sub=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		sub=a-b;
		if(sub>0){
			total+=sub*6;
		}else if(sub<0){
			sub=-sub;
			total+=sub*4;
		}
		total+=5;
		b=a;		
	}
	printf("%d\n",total);
	return 0;
}