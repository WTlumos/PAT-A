#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;
long long convert(string str,int radix){
	long long a=0l;
    long long p=1;
    long long ans=0l;
	for (int i = str.length()-1; i >=0 ; i--)
	{
		if(isdigit(str[i])){
			a=str[i]-'0';
		}else if(isalpha(str[i])){
			a=(str[i]-'a')+10;
		}
		ans+=a*p;
		p=p*radix;	
	}
	return ans;

}
int getMax(string str){
	char maxChar='0';
	int index=0;
	for (int i = 0; i < str.length(); ++i)
	{
		if(str[i]>maxChar){
			maxChar=str[i];
		}		
	}
	if(isdigit(maxChar)){
		index=maxChar-'0';
	}else if(isalpha(maxChar)){
		index=(maxChar-'a')+10;
	}
	return index;
}
void print(string n1,string n2,int radix)
{
	long long a=convert(n1,radix);
	long long right=a+1;
	long long left=getMax(n2)+1;
	long long mid=0;
	bool flag=false;
	long sum=0l;
	while(left<=right){
		mid=(left+right)/2;
		//cout<<left<<" "<<right<<" "<<mid<<endl;
		sum=convert(n2,mid);
		if(sum==a){
			flag=true;
			cout<<mid<<endl;
			break;
		}else if(sum>a||sum<0){
			right=mid-1;
		}else{
			left=mid+1;
		}
	}
	if(!flag){
		cout<<"Impossible"<<endl;
	}

}

int main()
{
	string n1,n2;
	int tag,radix;
	cin>>n1>>n2>>tag>>radix;

	if(tag!=1&&tag!=2){
		cout<<"Impossible"<<endl;
		return 0;
	}

	if (tag==1)
	{
		print(n1,n2,radix);
		
	}else if(tag==2){
		print(n2,n1,radix);
	}
	return 0;
}