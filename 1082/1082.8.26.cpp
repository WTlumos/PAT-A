#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> v;
vector<int> num;
int main()
{
	string ge[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string shi[]={"","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};
	int a;
	scanf("%d",&a);
	if (a==0)
	{
		printf("ling\n");
		return 0;
	}
	if (a<0)
	{
		printf("Fu ");
		a=-a;
	}
	while(a)
	{
		num.push_back(a%10);
		a/=10;
	}
	//100800 --> 008001
	int pos=0;
	while(pos<num.size()&&num[pos]==0)
	{
		pos++;
	}
	for (int i = pos; i < num.size(); i++)
	{
		if (i!=0&&(num[i]!=0||i==4||i==8)) //wan yi 需要加入
		{
			v.push_back(shi[i]);
		}
		v.push_back(ge[num[i]]);
	}
	for (int i = v.size()-1; i >= 0; i--)
	{
		int cnt=0;
		//yi Shi ling Wan ling ba Bai
		while (v[i]=="ling"&&i>=0)
		{
			i--;
			cnt++;
		}
		if (cnt>0&&v[i]!="Wan")
		{
			printf("ling ");
		}

		printf("%s",v[i].c_str());
		if (i>0)
		{
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
}