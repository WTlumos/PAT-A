#include<iostream>
#include<string>
using namespace std;
int dp[1010][1010];
int main()
{
    string str;
	getline(cin,str);
	int ans=0;
    int len=0;
    for (int i = 0; i < str.length(); ++i)
    {
        len++;
    	dp[i][i]=1;
    	ans=1;
    }
    for (int i = 0; i < str.length() -1 ; ++i)
    {
    	if (str[i]==str[i+1])
    	{
    		dp[i][i+1]=1;
    		ans=2;
    	}
    }
	for (int L = 3; L<= len ; ++L){
		for (int i = 0; L+i-1 <len ; ++i){
			int j=L+i-1;
			if (str[i]==str[j]&&dp[i+1][j-1]==1){
				dp[i][j]=1;
				ans=L;
			}
		}
	}
    cout<<ans<<endl;
	return 0;
}