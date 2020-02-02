#include<cstring>
#include<cstdio>
int main()
{
	char c[10000];
	scanf("%s",c);
	if (c[0]=='-')
	{
		printf("-");
	}
	int len=strlen(c);
	int pos=1;
	for (; c[pos]!='E'; ++pos);
	bool flag=true;
	if(c[pos+1]=='-'){
		flag=false;
	}
	int e=0;
	for (int i = pos+2; i < len; ++i)
	{
		e=e*10+(c[i]-'0');
	}
	if (flag) //+10
	{
		if(pos-3>e) //+1.234E+1
		{
			printf("%c",c[1]);
			for (int i = 3; i < e+3; ++i)
			{
				printf("%c",c[i]);
			}
			printf(".");
			for (int i = e+3; i < pos; ++i)
			{
				printf("%c",c[i]);
			}
			printf("\n");
		}else{
			printf("%c",c[1]);
			for (int i = 3; i < pos; ++i)
			{
				printf("%c",c[i]);
			}
			for (int i = pos-3; i < e; ++i)
			{
				printf("0");
			}
			printf("\n");

		}
		
	}else{ //-03
		if (e!=0)
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
			for (int i = 1; i < pos; ++i)
			{
				printf("%c",c[i]);
			}
		}
		printf("\n");

	}
	return 0;
}