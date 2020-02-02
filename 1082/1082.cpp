#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
int main()
{
	string wei[]={"","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};
	string num[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int n;
	scanf("%d",&n);
	if (n == 0){
        printf("ling");
        return 0;
    }
	if (n<0)
	{
		printf("Fu ");
		n=-n;
	}
	vector<int> v;
	while(n){
		v.push_back(n%10);
		n/=10;
	}
	int pos=0;
	for (; pos < v.size()&&v[pos]==0; ++pos);
	vector<string> result;
	for (int i = pos; i < v.size(); ++i)
	{
		if(i!=0&&(v[i]!=0||i==4||i==8)){
			result.push_back(wei[i]);
		}
		result.push_back(num[v[i]]);
	}
	for (int i = result.size()-1; i >= 0; i--)
	{
		int cnt=0;
		while(result[i]=="ling"&&i>=0){
			i--;
			cnt++;
		}
		if (cnt!=0&&result[i]!="Wan")
		{
			printf("ling ");
		}
		printf("%s",result[i].c_str());
		if (i>0)
		{
			printf(" ");
		}else{
			printf("\n");
		}
	}

	return 0;
}