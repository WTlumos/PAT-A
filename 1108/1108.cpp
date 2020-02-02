#include<cstdio>
#include<cstring>
const int maxn=10000;
char c1[maxn],c2[maxn];
int main(){
	int n;
	scanf("%d",&n);
	double a;
	double sum=0;
	int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",c1);
		sscanf(c1,"%lf",&a);
		sprintf(c2,"%.2f",a);
		int len=strlen(c1);
		int flag=0;
		for (int i = 0; i < len; ++i)
		{
			if (c1[i]!=c2[i])
			{
				flag=1;
				break;
			}
		}
		if (flag==1||(a<-1000||a>1000))
		{
			printf("ERROR: %s is not a legal number\n",c1);
		}else{
			sum+=a;
			cnt++;
		}
	}
	if (cnt==1)
	{
		printf("The average of 1 number is %.2f\n",sum);
	}else if(cnt>1){
		printf("The average of %d numbers is %.2f\n", cnt,sum/cnt);
	}else{
		printf("The average of 0 numbers is Undefined\n");
	}
	return 0;
}