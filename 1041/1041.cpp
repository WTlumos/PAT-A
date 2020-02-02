#include<cstdio>
int m[100010]={0};
int a[100010]={0};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		m[a[i]]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if(m[a[i]]==1){
			printf("%d\n",a[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}