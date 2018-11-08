/*输出主对角线的最大值，输出辅对角线的最小值*/
#include "stdio.h"
main()
{
	int a[4][4],i,j,min,max;/*定义一个4*4的矩阵*/
	printf("给数组元素赋值：\n");
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
		scanf("%d",&a[i][j]);
		printf("输出4*4的矩阵:\n");/*打印出此矩阵*/
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		printf("%4d",a[i][j]);
		printf("\n");
	}
	max=a[0][0];
	min=a[0][3];
	for(i=0;i<4;i++)
	{
		if(a[i][i]>max) max=a[i][i];
		if(a[i][3-i]<min) min=a[i][3-i];
	}
	printf("min=%d,max=%d\n",min,max);
}
