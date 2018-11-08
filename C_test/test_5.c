#include<stdio.h>
#define  N  10 
main() 
	{
	int a[N][N]; 
	int i,j; 
	for(i=0;i<10;i++) 
	for(j=0;j<10;j++) 
	{
	if(i>=j)
		{
			a[i][0]=1;
			a[i][i]=1;
		}
		else
		a[i][j]=0;
	}
	for(i=2;i<10;i++)  
	for(j=1;j<i;j++) 
		a[i][j]=a[i-1][j-1]+a[i-1][j]; 
	for(i=0;i<10;i++)   /*´òÓ¡Ñî»ÔÈý½ÇÐÎ*/  
	{  
		for(j=0;j<10;j++)
		{
		if(a[i][j]!=0) 
			printf("%10d",a[i][j]);
		} 
		printf("\n");
	} 
}