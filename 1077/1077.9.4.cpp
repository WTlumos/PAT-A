#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	string str1,ans;
	getline(cin,str1);
	while(--n)
	{
		string str2;
		getline(cin,str2);
		int i=str1.length()-1; int j=str2.length()-1;
		while (i>=0&&j>=0)
		{
			if (str1[i]==str2[j])
			{
				ans+=str1[i];
			}else{
				break;
			}
			i--; j--;
		}
		reverse(ans.begin(),ans.end());
		str1=ans;
		ans.clear();
	}
	if (str1.length()==0)
	{
		cout<<"nai"<<endl;
	}else{
		cout<<str1<<endl;
	}
	return 0;
}