#include<cstdio>
#include<map>
#include<string>
using namespace std;
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	map<string,int> image;
	char c[100];
	string str;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%s",c);
			str=c;
			image[str]++;
		}
	}
	for(map<string,int>::iterator i=image.begin();i!= image.end();i++)
	{
		if (i->second>m*n/2)
		{
			printf("%s\n",i->first.c_str());
			break;
		}
	}
	return 0;
}