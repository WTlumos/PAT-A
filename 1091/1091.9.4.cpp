#include<cstdio>
#include<queue>
using namespace std;
int matrix[70][1300][130];
bool visit[70][1300][130];
int X[]={1,-1,0,0,0,0};
int Y[]={0,0,1,-1,0,0};
int Z[]={0,0,0,0,1,-1};
int m,n,l,t;
struct node
{
	int x,y,z;
	node(int X,int Y,int Z): x(X),y(Y),z(Z){};
};
bool judge(int x,int y,int z)
{
	if (x<0||x>=l||y<0||y>=m||z<0||z>=n)
	{
		return false;
	}
	if (visit[x][y][z])
	{
		return false;
	}
	if (matrix[x][y][z]==0)
	{
		return false;
	}
	return true;
}
void init()
{
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				visit[i][j][k]=false;
				matrix[i][j][k]=0;
			}
		}
	}
}
int bfs(int x,int y,int z){
	int ans=0;
	queue<node> q;
	q.push(node(x,y,z));
	visit[x][y][z]=true;
	while(!q.empty()){
		node temp=q.front();
		ans++;
		q.pop();
		for (int i = 0; i < 6; ++i)
		{
			int nowx=temp.x+X[i];
			int nowy=temp.y+Y[i];
			int nowz=temp.z+Z[i];
			if (judge(nowx,nowy,nowz))
			{
				q.push(node(nowx,nowy,nowz));
				visit[nowx][nowy][nowz]=true;
			}
		}
	}
	if (ans<t)
	{
		return 0;
	}else{
		return ans;
	}
}
int main()
{
	scanf("%d%d%d%d",&m,&n,&l,&t);
	init();
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				scanf("%d",&matrix[i][j][k]);
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
				if(visit[i][j][k]==false&&matrix[i][j][k]==1){
					ans+=bfs(i,j,k);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}