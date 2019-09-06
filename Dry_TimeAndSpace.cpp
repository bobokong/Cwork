#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define N 40    //�о������С
#define dry_num 8 //�ɺ��¼���
int dry[N][N]={0};
void color(int);
void gotoxy(int ,int );
struct CELL 
{
	int x;
	int y;
	int time;/////////////////////////////////////////////////////////////
};
struct Point
{
	int num;	//��¼�ܹ��ж��ٸ��ɺ���
	struct CELL cell[N*N];		//��¼�ɺ���
}point[dry_num];	//�ɺ��¼�i
struct EDGE_CELL	//������ɺ��¼��ı�Ե��
{
	int edge_num;	//��¼��Ե�������
	struct CELL edge_cell[N*N];
}edge[dry_num];



/*�ٳ�ʼ���ɺ��¼�*/
int Init_dry(int i)///////////Is ok
{
	int p1,p2;
	/*���ָ���ɺ�����͸ɺ��¼������ýṹ��point��¼���ɺ��¼�������λ��*/
	for(;i<=dry_num;i++)
	{
		p1=rand()%N;		
		p2=rand()%N;
		if(!dry[p1][p2])
		{		
			dry[p1][p2]=i;
			point[i-1].cell[0].x=p1;
			point[i-1].cell[0].y=p2;
			point[i-1].num=1;
			edge[i-1].edge_num=1;
		}
		else
			Init_dry(i);
	}
	return 1;
}
/*�ڸɺ��¼�case_i�ڿռ��ϵ�����  ÿ������һ������-------ÿ������ǰ�ȸ��±�Ե��Ĵ洢��edge*/
int Dry_expand(int i,int ii)	//i���ɺ��¼�      ii:�ɺ��¼�i�ĵ�i����Ե��
{
	int ii_x=edge[i].edge_cell[ii].x;
	int ii_y=edge[i].edge_cell[ii].y;
	int r1=(rand()%3+1)%3-1;
	int r2=(rand()%3+1)%3-1;
	while(dry[ii_x+r1][ii_y+r2])///////////////////////////////////////////////////////
	{	
	 	r1=(rand()%3+1)%3-1;
		r2=(rand()%3+1)%3-1;
	}	
		dry[ii_x+r1][ii_y+r2]=i+1;
		point[i].num++;
	return 1;
}
int Dry_reduce(int i,int ii)
{
	int cell_num;
	int x=point[i].cell[ii].x;
	int y=point[i].cell[ii].y;
	if(!dry[x][y])
		return 0;
	else
	{
		dry[x][y]=0;	//�ٽ���������Ϊ�Ǹɺ�
		if(ii==point[i].num-1)	//��������һ����ֱ����ȼ�һ
			point[i].num--;
		else
		{	
			cell_num=point[i].num-1;
			point[i].cell[ii].x=point[i].cell[cell_num].x;
			point[i].cell[ii].y=point[i].cell[cell_num].y;
			point[i].num--;
		}	
		return 1;
	}
}



/*��Ե�ж�-------�жϸɺ��¼�i�ı�Ե�鲢���浽edge[i]*/
int Is_edge(int case_i)	
{
	int x,y,edge_num=0;
	edge[case_i-1].edge_num=0;
	for(int cell_num=1;cell_num<=point[case_i-1].num;cell_num++)	//�жϸɺ��¼�i��cell_num���Ƿ��Ǳ�Ե��
	{
		x=point[case_i-1].cell[cell_num-1].x;	//��¼��Ҫ��������λ��
		y=point[case_i-1].cell[cell_num-1].y;
		for(int i=-1;i<2;i++)		//��Ҫ���Ŀ�Ϊ���ģ����ŷ������Ƿ���ڷǸɺ��飬�������������ŷ���ѭ��������¼Ϊ��Ե��
		{	
			for(int j=-1;i<2;i++)
				if(x+i>=0&x+i<N)
					if(y+j>=0&y+j<N)
						if(!dry[x+i][y+j]) {
							edge[case_i-1].edge_cell[edge_num].x=x;
							edge[case_i-1].edge_cell[edge_num].y=y;
							edge[case_i-1].edge_num++;
							goto here;
						}
		}
		here: ;
	}
	return 1;
}
/*��Ե�����------ͨ��Is_edge()*/
int edge_store_up()
{
	for(int i=1;i<=dry_num;i++)
		Is_edge(i);	//ͨ������Is_edge()����ͬ�ĸɺ��¼��ı�Ե�������Ϣ������edge[i-1].edge_cell[edge_num]��
	return 1;
}
void gotoxy(int x,int y) //�ƶ�����//////////////Is ok
{
    COORD coord;
    coord.X=y;
    coord.Y=x;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void print_interface()//////////////Is ok
{                           
	int t=2000,x,y,n; 
	for(x=0;x<N;x++)         
		for(y=0;y<N;y++)                                                    
		{                   
			gotoxy(x,2*y); 
			n=dry[x][y];    
			color(n);       
			printf("��");    
		}	
}


void color(int c)//////////////Is ok
{
	
	if(c==0) 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void main()
{
	system("mode con cols=200 lines=104");
	int i=1,ii,n=0,nn;
	Init_dry(i);
	for(n=0;n<30;n++)//ģ��1����
	{
		print_interface();
		i=rand()%dry_num;

		if(rand()%2)//���ָ�����Ż���С,�����Ϊ1������
		{
			nn=point[i].num;
			for(int j=0;j<nn;j++)
			{
				ii=edge[i].edge_num-1;//��ii���Ե����
				gotoxy(50,88);
				printf("i%d   ii%d",i,ii);	
				Dry_expand(i,ii);
			gotoxy(48,90);
			printf("����");
			}
		}
		else
		{
			nn=point[i].num;//������Ż���С����,nnΪ��С����������Ϊ��С�ٶ��Ǹɺ�������10%
			for(int j=0;j<nn;j++)
			{
				ii=point[i].num-1;
				gotoxy(50,88);
				printf("%d",ii);
				Dry_reduce(i,ii);
			}
			gotoxy(44,88);
			printf("��С i%d  ii%d  nn:%d",i,ii,nn);
		}
		edge_store_up();
		getchar();
		system("cls");
		system("color 7");
	}
}