#include<iostream>
#include<string>
using namespace std;
int s[1001][1001];
int main()
{
	string str;
    getline(cin,str);
    int ans=1;
    for (int i = 0; i < str.length(); ++i)
    {
    	s[i][i]=1;
    }
	for (int i = 0; i < str.length()-1; ++i)
	{
		if(str[i]==str[i+1]){
			s[i][i+1]=1;
			ans=2;
		}
	}
	for (int L = 3; L <= str.length() ; ++L)
	{
		for (int i = 0; L+i-1<str.length(); ++i)
		{
			int j=L+i-1;
			if(str[i]==str[j]&&s[i+1][j-1]==1){
				s[i][j]=1;
				ans=L;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}