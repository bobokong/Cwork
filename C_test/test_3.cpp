#include<stdio.h>
#define N 5
main()
{
	int a[N][N],i=0,j=0;
	a[0][0]=1;
	for(i=0;i<N;i++) 
	{
		for(j=0;j<=i;j++)
		a[i][j]=a[i][j-1]+a[i][j];
		printf("%d",a[i][j]);
	}
}