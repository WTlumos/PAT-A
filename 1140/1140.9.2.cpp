#include<iostream>
#include<string>
using namespace std;
int main()
{
	int d,n;
	scanf("%d%d",&d,&n);
	string str;
    if (n==1)
    {
    	printf("%d",d);
    	return 0;
    }
	str=d+'0';
    for (int i = 0; i < n-1; ++i)
    {
    	int cnt=1; string ans;
    	for (int j=0;j<str.length();j++)
    	{
    		if (str[j]==str[j+1])
    		{
    			cnt++;
    		}else{
    			ans+=str[j];
    			ans+=cnt+'0';
    			cnt=1;
    		}
    	}
    	str=ans;
    }
    printf("%s\n",str.c_str());

	return 0;
}