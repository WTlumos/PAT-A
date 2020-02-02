 #include<cstdio>
int player[101]={};
 int main()
 {
 	int n;
 	scanf("%d",&n);
 	for (int i = 1; i <= n; ++i)
 	{
 		scanf("%d",&player[i]);
 	}
 	//i，j为wolf
 	int wolf1=0;
 	int wolf2=0;
 	for (int i = 1; i <= n; ++i)
 	{
 		for (int j = i+1; j <= n; ++j)
 		{
 			int human=0; int wolf=0;
 			for (int k = 1; k<= n; ++k)
 			{
 				if ((player[k]<0&&-player[k]!=i&&-player[k]!=j)||
 					(player[k]>0&&(player[k]==i||player[k]==j)))
 				{
 					if(k!=i&&k!=j){
 						human++;
 					}
 					else{
 						wolf++;
 					}
 				}
 			}
 			if (human==1&&wolf==1)
 			{
 				wolf1=i;
 				wolf2=j;
 				break;			
 			}
 		}
 		if (wolf1!=0)
 		{
 			break;
 		}
 	}
 	if (wolf1!=0)
 	{
 		printf("%d %d\n",wolf1,wolf2);
 	}else{
 		printf("No Solution\n");
 	}
	 return 0;
 }