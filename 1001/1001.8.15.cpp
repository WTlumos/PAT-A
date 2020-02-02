#include<cstdio>
#include<string>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int sum=a+b;
	if(sum<0){
		printf("-");
		sum=-sum;
	}
	string str=to_string(sum);
	string ans;
	int cnt=1;
	for(int i=str.length()-1;i>=0;i--)
	{
		ans+=str[i];
		if(cnt%3==0&&i!=0){
			ans+=',';
		}
		cnt++;
	}
	for (int i = ans.length()-1; i >=0; i--)
	{
		printf("%c",ans[i]);
	}
	printf("\n");
	return 0;
}