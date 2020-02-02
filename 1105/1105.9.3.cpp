#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int num[10010]={};
bool cmp(int x,int y){
	return x>y;
}
int getnum(int x){
	int a=sqrt(1.0*x);
	while(a!=1){
		if (x%a==0)
		{
			break;
		}else{
			a--;
		}
	}
	return a;
}
int matrix[10010][10010];
int main()
{
	int N;
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+N,cmp);
    int n=getnum(N);
    int m=N/n;
    int level=N/2+N%2;
    int t=0;
    for (int j = 0; j < level; ++j)
    {
    	for (int i = j; i < n-j&&t<N; ++i)
	    {
	    	matrix[j][i]=num[t++];
	    }
	    for (int i = 1+j; i < m-j&&t<N; ++i)
	    {
	    	matrix[i][n-1-j]=num[t++];
	    }
	    for (int i = n-2-j; i >= j&&t<N ; i--)
	    {
	    	matrix[m-1-j][i]=num[t++];
	    }
	    for (int i = m-2-j; i >= j+1&&t<N ; i--)
	    {
	    	matrix[i][j]=num[t++];
	    }
    }
    for (int i = 0; i < m; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		if (j!=0)
    		{
    			printf(" ");
    		}
			printf("%d",matrix[i][j]);
    	}
    	printf("\n");
    }


	return 0;
}