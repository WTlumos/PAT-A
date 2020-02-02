#include<cstdio>
#include<queue>
using namespace std;
int matrix[60][1300][130];
int visit[60][1300][130];
int x[]={0,0,1,-1,0,0};
int y[]={0,0,0,0,1,-1};
int z[]={1,-1,0,0,0,0};
int m,n,l,t;
struct node
{
	int x,y,z;
	node(int X,int Y,int Z):x(X),y(Y),z(Z){};
};
bool judge(int x,int y,int z)
{
	if (x<0||x>=l||y<0||y>=m||z<0||z>=n)
	{
		return false;
	}
	if (visit[x][y][z]==true)
	{
		return false;
	}
	if (matrix[x][y][z]==0)
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
	while(!q.empty()){
		node temp=q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 6; ++i)
		{
			int newx=temp.x+x[i];
			int newy=temp.y+y[i];
			int newz=temp.z+z[i];
			if (judge(newx,newy,newz))
			{
				q.push(node(newx,newy,newz));
				visit[newx][newy][newz]=true;
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
				scanf("%d",&matrix[i][j][k]);
				visit[i][j][k]=false;
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
				if (visit[i][j][k]==false&&matrix[i][j][k]==1)
				{
					ans+=bfs(i,j,k);
				}
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}