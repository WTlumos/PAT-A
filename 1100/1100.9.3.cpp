#include<iostream>
#include<string>
using namespace std;
string ge[]={"tret","jan","feb","mar","apr","may","jun",
"jly","aug","sep","oct","nov","dec"};

string shi[]={"","tam","hel","maa","huh","tou","kes",
"hei","elo","syy","lok","mer","jou"};
int main()
{
	int n;
	cin>>n;
	getchar();
	string str;
	while(n--)
	{
		getline(cin,str);
		if (str[0]<='9'&&str[0]>='0')
		{
			int num=0;
			for (int i = 0; i < str.length(); ++i)
			{
				num=num*10+str[i]-'0';
			}
			if (num<13)
			{
				cout<<ge[num]<<endl;
			}else if(num%13==0){
				cout<<shi[num/13]<<endl;
			}else{
				cout<<shi[num/13]<<" "<<ge[num%13]<<endl;
			}
		}
		else{
			if (str.find(" ")==string::npos)
			{
				int flag=0;
				for (int i = 0; i < 13; ++i)
				{
					if (ge[i]==str)
					{
						flag=1;
						cout<<i<<endl;
						break;
					}
				}
				if (flag==0)
				{
					for (int i = 0; i < 13; ++i)
					{
						if (shi[i]==str)
						{
							flag=1;
							cout<<i*13<<endl;
							break;
						}
					}
				}
			}
			else{
				int pos=0;
				for (; pos < str.length(); ++pos)
				{
					if (str[pos]==' '){ break; }
				}
				string str1=str.substr(0,pos);
				string str2=str.substr(pos+1,str.length()-pos);
				//cout<<str1<<"..."<<str2<<endl;
				int num=0;
				for (int i = 0; i < 13; ++i)
				{
					if (shi[i]==str1)
					{
						num=i*13;
						break;
					}
				}
				for (int i = 0; i < 13; ++i)
				{
					if (ge[i]==str2)
					{
						num+=i;
						break;
					}
				}
				cout<<num<<endl;
			}
		}
	}    
	return 0;
}