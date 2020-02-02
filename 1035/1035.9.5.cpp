#include<cstdio>
#include<string>
using namespace std;
char name[20],pass[20];
struct node
{
	char name[20],password[20];
}v[1010];
string match="10lO";
int main()
{
	int n;
	scanf("%d",&n);
	node temp;  int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s",temp.name,temp.password);
		int flag=0;
		for (int j = 0; temp.password[j] != '\0'; ++j)
		{
			if (match.find(temp.password[j])!=string::npos)
			{
				flag=1;
				if(temp.password[j]=='1'){ temp.password[j]='@';}
				if(temp.password[j]=='0'){ temp.password[j]='%';}
				if(temp.password[j]=='l'){ temp.password[j]='L';}
				if(temp.password[j]=='O'){ temp.password[j]='o';}
			}
		}
		if (flag==1)
		{
			v[cnt++]=temp;
		}
	}
	if (cnt==0)
	{
		if (n==1)
		{
			printf("There is 1 account and no account is modified\n");
		}else if(n>1){
			printf("There are %d accounts and no account is modified\n",n);
		}
	}else{
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; ++i)
		{
			printf("%s %s\n",v[i].name,v[i].password);
		}
	}
	return 0;
}