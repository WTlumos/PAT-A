#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m;
	cin>>m;
	string id,intime,outtime;
	string earlist="24:00:00";
	string latest="00:00:00";
	string earName,lateName;
	for (int i = 0; i < m; ++i)
	{
		cin>>id>>intime>>outtime;
		if(outtime>intime){
			if(intime<earlist){
				earlist=intime;
				earName=id;
			}
			if(outtime>latest){
				latest=outtime;
				lateName=id;
			}
		}
	}
	cout<<earName<<" "<<lateName<<endl;

	return 0;
}