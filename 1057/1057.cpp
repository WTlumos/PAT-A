#include<iostream>
#include<string>
#include<stack>
#define lowbits(i) ((i)&(-i))
using namespace std;
const int maxn=100010;
int c[maxn]={0};
int n;
stack<int> s;
void update(int x,int v)
{
	for (int i = x; i < maxn ; i+=lowbits(i))
	{
		c[i]+=v;
	}
}
int getsum(int x){
	int sum=0;
	for (int i = x; i >=1 ; i-=lowbits(i))
	{
		sum+=c[i];
	}
	return sum;
}
void PeekMedian()
{
	int low=1; int high=maxn; int k=(s.size()+1)/2;
	int mid=0;
	while(low<high){
		mid=(low+high)/2;
		if(getsum(mid)>=k){
			high=mid;
		}else{
			low=mid+1;
		}
	}
	printf("%d\n",low);
}
int main()
{
	cin>>n;
	string str;
	int a;
	for (int i = 0; i < n; ++i)
	{
		cin>>str;
		if (str=="Push")
		{
			cin>>a;
			s.push(a);
			update(a,1);
		}else if(str=="PeekMedian"){
			if (s.empty())
			{
				cout<<"Invalid"<<endl;
			}else{
				PeekMedian();
			}
		}else{
			if (s.empty())
			{
				cout<<"Invalid"<<endl;
			}else{
				update(s.top(),-1);
				cout<<s.top()<<endl;
				s.pop();
			}
		}		
	}
	return 0;
}