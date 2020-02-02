#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
map<char,bool> broken;
map<char,bool> good;
int main()
{
	int k;
	string str;
    cin>>k>>str;
    int cnt=1;
    for (int i = 0; i < str.length(); ++i)
    {
    	if (str[i]==str[i+1])
    	{
    		cnt++;
    	}
    	else{
    		if (cnt%k==0)
    		{
    			broken[str[i]]=true;
    		}else{
    			good[str[i]]=true;
    		}
    		cnt=1;    	
    	}
    }
    for (int i = 0; i < str.length(); ++i)
    {
    	if (good[str[i]])
    	{
    		broken[str[i]]=false;
    	}
    }
    string ans;
    for (int i = 0; i < str.length(); ++i)
    {
    	if (broken[str[i]]==false)
    	{
    		ans+=str[i];		
    	}else{
    		ans+=str[i];
    		i+=k-1;
    	}
    }
    set<char> s;
    for (int i = 0; i < str.length(); ++i)
    {
    	if (broken[str[i]]&&s.find(str[i])==s.end())
    	{
    		cout<<str[i];
    	}
    	s.insert(str[i]);
    }
    cout<<endl;
    cout<<ans<<endl;
	return 0;
}