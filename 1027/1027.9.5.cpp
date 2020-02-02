#include<cstdio>
void getchar(int x)
{
	if (x<=9)
	{
		printf("%c", x+'0'); 
	}else{
		printf("%c", x-10+'A');
	}
}
int main()
{
	int red,blue,green;
	scanf("%d%d%d",&red,&blue,&green);
    printf("#");
    getchar(red/13);getchar(red%13);
    getchar(blue/13);getchar(blue%13);
    getchar(green/13);getchar(green%13);
	return 0;
}