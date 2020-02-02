#include<cstdio>
#include<cstring>
char str[10000];
int main()
{
	scanf("%s",str);
	if (str[0]=='-')
	{
		printf("-");
	}
	//find E
	int len=strlen(str);
	int pos=0;
	for(;pos<len;pos++){
		if (str[pos]=='E')
		{
			break;
		}
	}
	//printf("%d\n", pos);
	int flag=1;
	if (str[pos+1]=='-')
	{
		flag=-1;
	}
	int e=0;
	for (int i = pos+2; i < len; ++i)
	{
		e=e*10+str[i]-'0';
	}
	if (e==0)
	{
		for (int i = 1; i < pos; ++i)
		{
			printf("%c",str[i]);
		}
		printf("\n");
	}else{
		if (flag==-1)
		{
			printf("0.");
			for (int i = 0; i < e-1; ++i)
			{
				printf("0");
			}
			printf("%c",str[1]);
			for (int i = 3; i < pos; ++i)
			{
				printf("%c",str[i]);
			}
			printf("\n");
		}else{
			if (pos-e-3>0)
			{
				printf("%c",str[1]);
				for(int i=3;i<e+3;i++){
					printf("%c",str[i]);
				}
				printf(".");
				for (int i = e+3; i < pos; ++i)
				{
					printf("%c",str[i]);
				}
				printf("\n");
			}else{
				printf("%c",str[1]);
				for (int i = 3; i < pos; ++i)
				{
					printf("%c",str[i]);
				}
				for (int i = 0; i < e-(pos-3); ++i)
				{
					printf("0");
				}
				printf("\n");
			}
		}
	}

	return 0;
}