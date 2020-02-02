//1 (one) by @, 0 (zero) by %, l by L, and O by o
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node
{
	string id,str;
	node(string Id,string Str){
		id=Id;
		str=Str;
	}
};
vector<node> v;
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string checked="10lO";
	string str,id;
	for (int i = 0; i < n; ++i)
	{
		cin>>id>>str; 
		int flag=0;
		for (int i = 0; i < str.length(); ++i)
		{
			if (checked.find(str[i])!=string::npos)
			{
				flag=1;
				if (str[i]=='1'){ str[i]='@';}
				if (str[i]=='0'){ str[i]='%';}
				if (str[i]=='l'){ str[i]='L';}
				if (str[i]=='O'){ str[i]='o';}
			}
		}
		if (flag==1)
		{
			v.push_back(node(id,str));
		}
	}
	if (v.size()==0)
	{
		if (n==1)
		{
			cout<<"There is 1 account and no account is modified"<<endl;
		}else{
			cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
		}
	}
	else{
		cout<<v.size()<<endl;
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i].id<<" "<<v[i].str<<endl;
		}
	}
	return 0;
}