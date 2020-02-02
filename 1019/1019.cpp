#include<cstdio>
int main()
{
	int num,decimal;
	scanf("%d%d",&num,&decimal);
	int array[50];
	int index=0;
	while(num)
	{
		array[index++]=num%decimal;
		num/=decimal;
	}
	int flag=0;
	for (int i = 0; i < index/2; i++)
	{
		if (array[i]!=array[index-1-i])
		{
			flag=1;
			break;
		}
	}
	if (flag==1)
	{
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	for (int i = index-1; i >= 0; i--)
	{
		printf("%d", array[i]);
		if (i>0)
		{
			printf(" ");
		}else{
			printf("\n");
		}
	}
	if (index==0)
	{
		printf("0\n");
	}

	return 0;
}