#include<cstdio>
void getAns(int num)
{
	char c[]="ABC";
	int shi=num/13;
	int ge=num%13;
	if (shi<=9)
	{
		printf("%d",shi);		
	}else{
        printf("%c",c[shi-10]);
	}
	if (ge<=9)
	{
		printf("%d",ge);		
	}else{
        printf("%c",c[ge-10]);
	}
}
int main()
{
	int red,green,blue;
	scanf("%d%d%d",&red,&green,&blue);
	printf("#");
	getAns(red);
	getAns(green);
	getAns(blue);
	printf("\n");
	return 0;
}