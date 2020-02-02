#include<cstdio>
char c[10000];
int main()
{
	scanf("%s",c);
	int pos=0;
	if (c[0]=='-')
	{
		printf("-");
		pos++;
	}
	while (c[pos] != '\0'&&c[pos]!='E')
	{
		pos++;
	}
	//printf("%d\n",pos);
	//+1.23400E-03
	int flag=1;
	if (c[pos+1]=='-')
	{
		flag=-1;
	}
	int e=0;
	for (int i = pos+2; c[i] != '\0' ; ++i)
	{
		e=e*10+(c[i]-'0');
	}
	if (e==0){
		for (int i = 1; i < pos; ++i)
		{
			printf("%c",c[i]);
		}
	}
	else if(flag==-1)
	{
		printf("0.");
		for (int i = 0; i < e-1; ++i)
		{
			printf("0");
		}
		printf("%c",c[1]);
		for (int i = 3; i < pos; ++i)
		{
			printf("%c",c[i]);
		}
	}else{
		//+1.2000E+2
		printf("%c",c[1]);
		if (e+3<pos)
		{
			
			for (int i = 3; i < e+3; ++i)
			{
				printf("%c",c[i]);
			}
			printf(".");
			for (int i = e+3; i < pos; ++i)
			{
				printf("%c",c[i]);
			}
		}else{
			//+1.2E+10
			for (int i = 3; i < pos; ++i)
			{
				printf("%c",c[i]);
			}
			for (int i = 0; i < e-(pos-3); ++i)
			{
				printf("0");
			}
		}
	}
	printf("\n");
	return 0;
}