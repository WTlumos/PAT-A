#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int num[1000]={};
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int sum=a+b;
	if (sum<0)
	{
		printf("-");
		sum=-sum;
	}
	int idx=0;
	do{
		num[idx++]=sum%10;
		sum/=10;
	}while(sum!=0);
	int cnt=1;
	string ans;
    for (int i = 0; i < idx; ++i)
    {
    	ans+=num[i]+'0';
    	if (cnt%3==0&&i!=idx-1)
    	{
    		ans+=',';
    	}
    	cnt++;
    }
    reverse(ans.begin(),ans.end());
    printf("%s\n",ans.c_str());

	return 0;
}