#include<cstdio>
#include<queue>
using namespace std;
int slice[100][1300][130];
bool visit[100][1300][130];
int x[]={0,0,-1,1,1,0,0};
int y[]={-1,1,0,0,0,0};
int z[]={0,0,0,0,1,-1};
int m,n,l,t;
struct node
{
	int x,y,z;
	node(int X,int Y,int Z):x(X),y(Y),z(Z){};
};
bool judge(int x,int y,int z)
{
	if (x>l||x<0||y>m||y<0||z>n||z<0)
	{
		return false;
	}
	if (visit[x][y][z])
	{
		return false;
	}
	if (slice[x][y][z]==0)
	{
		return false;
	}
	return true;
}
int bfs(int i,int j,int k)
{
	int cnt=0;
	queue<node> q;
	q.push(node(i,j,k));
	visit[i][j][k]=true;
	while(!q.empty())
	{
		node temp=q.front();
		cnt++;
		q.pop();
		for (int i = 0; i < 6; ++i)
		{
			int nowX=temp.x+x[i];
			int nowY=temp.y+y[i];
			int nowZ=temp.z+z[i];
			if (judge(nowX,nowY,nowZ))
			{
				q.push(node(nowX,nowY,nowZ));
				visit[nowX][nowY][nowZ]=true;
			}
		}
	}
	if (cnt>=t)
	{
		return cnt;
	}else{
		return 0;
	}

}
int main()
{
    scanf("%d%d%d%d",&m,&n,&l,&t);
    for (int i = 0; i < l; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		for (int k = 0; k < n; ++k)
    		{
    			scanf("%d",&slice[i][j][k]);
    		}
    	}
    }
    int ans=0;
    for (int i = 0; i < l; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		for (int k = 0; k < n; ++k)
    		{
    			if (visit[i][j][k]==false&&slice[i][j][k]>0)
	    		{
	    			ans+=bfs(i,j,k);
	    		}
    		}
    	}
    }
    printf("%d\n",ans);
	return 0;
}