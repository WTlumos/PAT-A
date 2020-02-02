#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=10010;
int num[maxn];
int matrix[maxn][maxn]={};
bool cmp(int x,int y)
{
	return x>y;
}
int N;
int get()
{
	int a=sqrt(1.0*N);
	while(a!=1){
		if (N%a==0)
		{
			return a;
		}else{
			a--;
		}
	}
	return a;
}
int main()
{
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&num[i]);
	}
    sort(num,num+N,cmp);
    int n=get();
    int m=N/n;
    int t=0;
    int level=m/2+m%2;
    for (int j = 0; j < level; ++j)
    {
	    	//->
	    for (int i = j; i < n-j&&t<N; ++i)
	    {
	    	matrix[j][i]=num[t++];
	    }
	    //|
	    for (int i = j+1; i < m-j&&t<N; ++i)
	    {
	    	matrix[i][n-1-j]=num[t++];
	    }
	    //<-
	    for (int i = n-2-j; i >= j&&t<N; i--)
	    {
	    	matrix[m-1-j][i]=num[t++];
	    }
	    //|
	    for (int i = m-2-j; i >= 1+j&&t<N ; i--)
	    {
	    	matrix[i][j]=num[t++];
	    }
    }
    for (int i = 0; i < m; ++i)
    {
    	printf("%d",matrix[i][0]);
    	for (int j = 1; j < n; ++j)
    	{
    		printf(" %d",matrix[i][j]);
    	}
    	printf("\n");
    }


	return 0;
}