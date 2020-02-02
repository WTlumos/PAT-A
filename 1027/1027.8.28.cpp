#include<cstdio>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	char match[]={"0123456789ABC"};
	printf("#%c%c%c%c%c%c\n",match[a/13],match[a%13],
		match[b/13],match[b%13],
		match[c/13],match[c%13]);
	return 0;
}