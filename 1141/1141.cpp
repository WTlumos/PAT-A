#include<iostream>
#include<cctype>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<string,int> cnt;
map<string,double> score;
struct node
{
	string school;
	int ns,tws;
	node(string School,int Ns,int Tws){
		school=School;
		ns=Ns;
		tws=Tws;
	}
};
bool cmp(node a,node b){
	if (a.tws!=b.tws){
		return a.tws>b.tws;
	}else if (a.ns!=b.ns){
		return a.ns<b.ns;
	}else{
		return a.school<b.school;
	}
}
void exchage(string &str){
	for (int i = 0; i < str.length(); ++i)
	{
		str[i]=tolower(str[i]);
	}
}
vector<node> v;
int main()
{
	int n;
	cin>>n;
	string id,school; double grade;
	for (int i = 0; i < n; ++i)
	{
		cin>>id>>grade>>school;
		exchage(school);
		if (id[0]=='A')
		{
			score[school]+=grade;
		}else if(id[0]=='B'){
			score[school]+=grade/1.5;
		}else{
			score[school]+=grade*1.5;
		}
		cnt[school]++;
	}
	for (map<string,int>::iterator i=cnt.begin(); i!= cnt.end(); ++i)
	{
		v.push_back(node(i->first,i->second,score[i->first]));
	}
	sort(v.begin(), v.end(),cmp);
	cout<<v.size()<<endl;
	int r=1;
	for (int i = 0; i < v.size(); ++i)
	{
		if(i>0&&v[i].tws!=v[i-1].tws){
			r=i+1;
		}
		cout<<r<<" "<<v[i].school<<" "<<v[i].tws<<" "<<v[i].ns<<endl;	
	}
	return 0;
}