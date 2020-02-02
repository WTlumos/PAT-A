#include<cstdio>
char c1[10000],c2[10000];
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0; double a,sum;
	sum=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",c1);
		sscanf(c1,"%lf",&a);
		sprintf(c2,"%.2f",a);
		int flag=0;
		for (int i = 0; c1[i] != '\0'; ++i)
		{
			if (c1[i]!=c2[i])
			{
				flag=1;
				break;
			}
		}
		if (flag==1||a<-1000||a>1000)
		{
			printf("ERROR: %s is not a legal number\n",c1);
		}
		else
		{
			cnt++;
			sum+=a;
		}
	}
	if (cnt==0)
	{
		printf("The average of 0 numbers is Undefined\n");
	}else if(cnt==1){
		printf("The average of 1 number is %.2f\n",sum);
	}else{
		printf("The average of %d numbers is %.2f\n",cnt,sum/cnt);
	}
	return 0;
}