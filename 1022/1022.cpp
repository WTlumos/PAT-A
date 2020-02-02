#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	string id,title,author,publisher,year;
	vector<string> keywords;
};
node book[10010];
bool cmp(node a,node b)
{
	return a.id<b.id;
}
int main()
{
	int n;
	cin>>n;
	node temp;
	string words;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp.id;
		getchar();
		getline(cin,temp.title);
		getline(cin,temp.author);
		getline(cin,words);
		getline(cin,temp.publisher);
		cin>>temp.year;
		for (int i = 0; i < words.length(); ++i)
		{
			string str;
			while(words[i]!=' '&&words[i]!='\0'){
				str+=words[i];
				i++;
			}
			temp.keywords.push_back(str);
			str.clear();
		}
		book[i]=temp;
		temp.keywords.clear();	
	}
	sort(book,book+n,cmp);
	int m,index; string str;
	cin>>m;
	int flag;
	for (int i = 0; i < m; ++i)
	{
		cin>>index;getchar();getchar();getline(cin,str);
		cout<<index<<": "<<str<<endl;
		if(index==1){
			flag=0;
			for (int i = 0; i < n; ++i)
			{
				if (str==book[i].title)
				{
					flag=1;
					cout<<book[i].id<<endl;
				}
			}
			if(flag==0){
				cout<<"Not Found"<<endl;
			}
		}
		else if(index==2){
			flag=0;
			for (int i = 0; i < n; ++i)
			{
				if (str==book[i].author)
				{
					flag=1;
					cout<<book[i].id<<endl;
				}
			}
			if(flag==0){
				cout<<"Not Found"<<endl;
			}
		}else if(index==3){
			flag=0; int flag1=0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < book[i].keywords.size(); ++j)
				{
					if(str==book[i].keywords[j]){
						//cout<<str<<endl;
						flag=1;
						flag1=1;
						break;
					}
				}
				if (flag1==1)
				{
					cout<<book[i].id<<endl;
					flag1=0;
				}
			}
			if(flag==0){
				cout<<"Not Found"<<endl;
			}
		}else if(index==4){
			flag=0;
			for (int i = 0; i < n; ++i)
			{
				if (str==book[i].publisher)
				{
					flag=1;
					cout<<book[i].id<<endl;
				}
			}
			if(flag==0){
				cout<<"Not Found"<<endl;
			}
		}else if(index==5){
			flag=0;
			for (int i = 0; i < n; ++i)
			{
				if (str==book[i].year)
				{
					flag=1;
					cout<<book[i].id<<endl;
				}
			}
			if(flag==0){
				cout<<"Not Found"<<endl;
			}
		}
	}
	return 0;
}