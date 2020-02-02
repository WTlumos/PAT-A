#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string ge[]={"tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string shi[]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int getIndex(string ge[],string c){
	int index=-1;
	for (int i = 0; i < 13; ++i)
	{
		if(ge[i]==c){
			index=i;
			break;
		}
	}
	return index;
}
int main()
{
	string c;
	int n;
	cin>>n;
	getchar();
	while(n--){
		getline(cin,c);
		int len=c.length();
		int num=0;
		if(isdigit(c[0])){
			for (int i = 0; i < len; ++i)
			{
				num=num*10+(c[i]-'0');
			}
			if(num<13){
				cout<<ge[num]<<endl;
			}else if(num%13==0){
				cout<<shi[num/13]<<endl;
			}else{
				cout<<shi[num/13]<<" "<<ge[num%13]<<endl;
			}
		}else{
			if (c.find(' ')==string::npos)
			{
				if (getIndex(ge,c)!=-1)
				{
					cout<<getIndex(ge,c)<<endl;
				}else{
					cout<<getIndex(shi,c)*13<<endl;
				}
			}else{
				string a; int aIndex;
				string b; int bIndex;
				for (int i = 0; i < 3; ++i)
				{
					a+=c[i];
				}
				for (int i = 4; i < len; ++i)
				{
					b+=c[i];
				}
				aIndex=getIndex(shi,a);
				bIndex=getIndex(ge,b);
				cout<<aIndex*13+bIndex<<endl;
			}
		}

	}
	return 0;
}