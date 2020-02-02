#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node{
	string username,password;
	node(string Username,string Password){
		username=Username;
		password=Password;
	}
};
vector<node> v;
int main()
{
	int n;
	cin>>n;
	string id,str;
	for (int i = 0; i < n; ++i)
	{
		cin>>id>>str;
		int flag=0;
		for (int j = 0; j < str.length(); ++j)
		{
			switch(str[j]) {
                case '1' : str[j] = '@'; flag = 1; break;
                case '0' : str[j] = '%'; flag = 1; break;
                case 'l' : str[j] = 'L'; flag = 1; break;
                case 'O' : str[j] = 'o'; flag = 1; break;
            }
        }
        if(flag)
		{
			v.push_back(node(id,str));
		}
	}
	if (v.size()>0)
	{ 
        cout<<v.size()<<endl;
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i].username<<" "<<v[i].password<<endl;
		}
	}else{
		if (n==1)
		{
			cout<<"There is 1 account and no account is modified"<<endl;
		}else{
			cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
		}
	}
	return 0;
}