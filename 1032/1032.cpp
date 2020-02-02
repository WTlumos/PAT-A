#include<cstdio>
const int maxn=100010;
int address[maxn]={};
int nextAddress[maxn]={};
int match[maxn]={};
int main()
{
	int first1,first2,n;
	scanf("%d%d%d",&first1,&first2,&n);
	int a,ne;
	char c;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %c %d",&a,&c,&ne);
		address[a]=a;
		nextAddress[a]=ne;
	}
	for (int i = first1; i!=-1; i=nextAddress[i])
	{
		match[i]++;	
	}
	for (int i = first2; i!=-1; i=nextAddress[i])
	{
		if (match[i]>0)
		{
			printf("%05d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}