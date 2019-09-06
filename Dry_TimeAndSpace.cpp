#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define N 40    //研究区域大小
#define dry_num 8 //干旱事件数
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
	int num;	//记录总共有多少个干旱块
	struct CELL cell[N*N];		//记录干旱块
}point[dry_num];	//干旱事件i
struct EDGE_CELL	//保存各干旱事件的边缘块
{
	int edge_num;	//记录边缘块的数量
	struct CELL edge_cell[N*N];
}edge[dry_num];



/*①初始化干旱事件*/
int Init_dry(int i)///////////Is ok
{
	int p1,p2;
	/*随机指定干旱区域和干旱事件，并用结构体point记录各干旱事件发生的位置*/
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
/*②干旱事件case_i在空间上的扩张  每次扩张一个区块-------每次扩张前先更新边缘块的存储库edge*/
int Dry_expand(int i,int ii)	//i：干旱事件      ii:干旱事件i的第i个边缘块
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
		dry[x][y]=0;	//①将此区块标记为非干旱
		if(ii==point[i].num-1)	//如果是最后一块则直接令长度减一
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



/*边缘判断-------判断干旱事件i的边缘块并保存到edge[i]*/
int Is_edge(int case_i)	
{
	int x,y,edge_num=0;
	edge[case_i-1].edge_num=0;
	for(int cell_num=1;cell_num<=point[case_i-1].num;cell_num++)	//判断干旱事件i的cell_num块是否是边缘块
	{
		x=point[case_i-1].cell[cell_num-1].x;	//记录需要检查区块的位置
		y=point[case_i-1].cell[cell_num-1].y;
		for(int i=-1;i<2;i++)		//以要检查的块为中心，检查九方格里是否存在非干旱块，若存在则跳出九方格循环，并记录为边缘块
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
/*边缘库更新------通过Is_edge()*/
int edge_store_up()
{
	for(int i=1;i<=dry_num;i++)
		Is_edge(i);	//通过调用Is_edge()将不同的干旱事件的边缘区块的信息保存在edge[i-1].edge_cell[edge_num]中
	return 1;
}
void gotoxy(int x,int y) //移动坐标//////////////Is ok
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
			printf("■");    
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
	for(n=0;n<30;n++)//模拟1个月
	{
		print_interface();
		i=rand()%dry_num;

		if(rand()%2)//随机指定扩张或缩小,随机数为1则扩大
		{
			nn=point[i].num;
			for(int j=0;j<nn;j++)
			{
				ii=edge[i].edge_num-1;//第ii块边缘区块
				gotoxy(50,88);
				printf("i%d   ii%d",i,ii);	
				Dry_expand(i,ii);
			gotoxy(48,90);
			printf("扩大");
			}
		}
		else
		{
			nn=point[i].num;//随机扩张或缩小块数,nn为缩小块数。表现为缩小速度是干旱块数的10%
			for(int j=0;j<nn;j++)
			{
				ii=point[i].num-1;
				gotoxy(50,88);
				printf("%d",ii);
				Dry_reduce(i,ii);
			}
			gotoxy(44,88);
			printf("缩小 i%d  ii%d  nn:%d",i,ii,nn);
		}
		edge_store_up();
		getchar();
		system("cls");
		system("color 7");
	}
}