#include "stdlib.h"
#define N 5
void main()
{
int a[N][N],i,j;
printf("产生一个随机的5*5矩阵");
for(i=0;i<N;i++)
for(j=0;j<N;j++)
a[i][j]=rand()%10;
printf("输出原数组：\n");
for(i=0;i<N;i++)
{
 for(j=0;j<N;j++)	
printf("%5d",a[i][j]);
printf("\n");
}
for(i=0;i<N;i++)
for(j=N-1;j>=i;j--)
a[i][j]=0;
printf("输出变化后的数组：\n");
for(i=0;i<N;i++)
{
 for(j=0;j<N;j++)
printf("%5d",a[i][j]);
printf("\n");
}
}