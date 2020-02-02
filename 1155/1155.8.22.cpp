#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
int n;
int a[1010];
void dfs(int index){
	if(index*2>n && index*2+1>n){
		if(index<=n){
		for(int i=0;i<v.size();i++){
			printf("%d%s",v[i],i==v.size()-1? "\n":" ");	
		}
	}
	}else{
		v.push_back(a[index*2+1]);
		dfs(index*2+1);
		v.pop_back();
		v.push_back(a[index*2]);
		dfs(index*2);
		v.pop_back();
	}
}
 
int main(){
	cin>>n;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	v.push_back(a[1]);
	dfs(1);
	//大小根堆判断：
	bool max=true,min=true;
	for(int i=1;i<n/2;i++){
		if(a[i]>a[i*2] || a[i]>a[i*2+1]) min=false;
		if(a[i]<a[i*2] || a[i]<a[i*2+1]) max=false;
	} 
	if(max) cout<<"Max Heap";
	else if(min) cout<<"Min Heap";
	else cout<<"Not Heap";
	return 0;
}