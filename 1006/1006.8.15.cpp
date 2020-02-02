#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int m;
	scanf("%d",&m);

	int min=312312312;
	int max=-1;

    char c[20];

    int h1,m1,s1,h2,m2,s2;
    int time1,time2;

    char maxAns[20],minAns[20];
	for (int i = 0; i < m; ++i)
	{
		scanf("%s",c);
		scanf("%d:%d:%d",&h1,&m1,&s1);
		scanf("%d:%d:%d",&h2,&m2,&s2);
		time1=h1*3600+m1*60+s1;
		time2=h2*3600+m2*60+s2;

		//printf("%d %d\n",time1,time2);

		if (time1<min)
		{
			strcpy(maxAns,c);
			min=time1;
		}
		if (time2>max)
		{
			strcpy(minAns,c);
			max=time2;		
		}	
	}
	printf("%s %s\n",maxAns,minAns);
	return 0;
}