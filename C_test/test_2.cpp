#include "stdlib.h"
#define N 5
void main()
{
int a[N][N],i,j;
printf("����һ�������5*5����");
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
for(i=0;i<N;i++)
for(j=N-1;j>=i;j--)
a[i][j]=0;
printf("����仯������飺\n");
for(i=0;i<N;i++)
{
 for(j=0;j<N;j++)
printf("%5d",a[i][j]);
printf("\n");
}
}