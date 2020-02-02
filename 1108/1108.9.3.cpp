#include<cstdio>
char c1[1000],c2[1000];
int main()
{
	int n;
	scanf("%d",&n);
	double num=0;
	int cnt=0;
	double sum=0; 
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",c1);
		sscanf(c1,"%lf",&num);
		sprintf(c2,"%.2f",num);
		int flag=0;
		for (int i = 0; c1[i] != '\0'; ++i)
		{
			if (c1[i]!=c2[i])
			{
				flag=1;
				break;
			}
		}
		if (flag==1||(num<-1000||num>1000))
		{
			printf("ERROR: %s is not a legal number\n",c1);
		}else{
			cnt++;
			sum+=num;
		}
	}
	if (cnt==1)
	{
		printf("The average of 1 number is %.2f\n",sum);
	}else if(cnt>1){
        printf("The average of %d numbers is %.2f\n",cnt,sum/cnt);
	}else{
		printf("The average of 0 numbers is Undefined\n");
	}
	return 0;
}