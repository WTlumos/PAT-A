/*
测试点4错误
*/
#include<cstdio>
#include<cmath>
bool isPrime(int x){
	if(x<2){
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
int getNum(char c[],int k)
{
	int num=0;
	for (int i = 0; i < k; ++i)
	{
		num=num*10+c[i]-'0';
	}
	return num;
}
int main()
{
	int l,k;
	scanf("%d%d",&l,&k);
    char c[1001];
    scanf("%s",c);
    for (int i = 0; i < l; ++i)
    {
    	char ans[k+1]; int index=0;
    	for (int j = i; j < k+i; ++j)
    	{
    		ans[index++]=c[j];
    	}
    	ans[index]='\0';
    	if (isPrime(getNum(ans,k)))
    	{
    		printf("%s\n",ans);
    		return 0;
    	}	
    }
    printf("404\n");
	return 0;
}