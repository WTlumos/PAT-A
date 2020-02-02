#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	string str1,str2,ans;
	getline(cin,str1);
	for (int i = 1; i < n; ++i)
	{
		getline(cin,str2);
		int j=str1.length()-1;
		int k=str2.length()-1;
		while (j>=0&&k>=0)
		{
			if (str1[j]==str2[k])
			{
				ans+=str1[j];
				j--;
				k--;
			}else{
				break;
			}
		}
		reverse(ans.begin(),ans.end());
		str1=ans;
		ans.clear();
	}
    if(str1.length()==0){
    	cout<<"nai"<<endl;
    }else{
    	cout<<str1<<endl;
    }
	return 0;
}