#include<stdio.h>
#include "stdlib.h"
#define N 5
void main()
{
	int a[N][N],i,j,max;
	printf("rand 5*5 matrix");/*����һ�������5*5����*/
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	a[i][j]=rand()%10;
	printf("���ԭ���飺\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)	
			printf("%5d",a[i][j]);
		printf("\n");
	}
	max=a[0][0];
	for(j=0;j<N;j++){
	for(i=0;i<N;i++)
	{
		if(a[i][j]>max) max=a[i][j];
	}
		printf("��%d�����ֵ=%d  ",j+1,max);/*���ÿһ�е����ֵ*/
		}
		printf("\n");
}