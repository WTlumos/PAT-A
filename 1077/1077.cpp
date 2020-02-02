#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;

	getchar();

	string a,b;
	getline(cin,a);
	reverse(a.begin(), a.end());

	int lena=a.length();
	int lenb,len;

	string ans;
	ans=a;

	for (int i = 1; i < n; ++i)
	{
		getline(cin,b);
		reverse(b.begin(), b.end());
		lenb=b.length();

		len=min(lena,lenb);
		for (int j = 0; j < len; ++j)
		{
			if(ans[j]!=b[j]){
				ans=b.substr(0,j);
				break;
			}
		}

	}
	reverse(ans.begin(), ans.end());
	if (ans.length()==0)
	{
		cout<<"nai"<<endl;
	}else{
		cout<<ans<<endl;
	}
	return 0;
}