#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int i, j, a[8][8] = { 0 }, b[8][8] = { 0 };

void gotoxy(int x, int y);
void title();
void start();
int color(int x);
void rule();
int dayin();

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void title()       //制作边框
{
	color(2);
	for (j = 0; j <= 16; j += 2)
	{
		gotoxy(34, 6 + j);
		for (i = 0; i <= 80; i += 2)
		{

			printf("─");
		}
	}
	for (j = 0; j <= 40; j += 5)
		for (i = 0; i < 16; i += 2)
		{
			gotoxy(34 + j, 7 + i);
			printf("│");
		}
//	gotoxy(37, 7);
//	printf("0");

//	gotoxy(75, 25);
//	printf("制作人：罗来富");

}


	
void start()
{
	void srand(unsigned seed);
	int c = 0,d=0;
	srand(time(NULL));
	color(12);
	for (i = 0;i<=1;i++)
		for(j=0;j<=10;j++)
		{
			c = rand() % 8;
			d = rand() % 8;
			a[c][d] = 1;
		}
}


int dayin()//打印细胞
{
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		{
			gotoxy(37 + 5 * i, 7 + 2 * j);
			if (a[i][j] == 1)
			{
				printf("0");
			}
			b[i][j] = a[i][j];
		}
}



void rule() 
{//中间36格规则
	for (i = 1; i < 7; i++)
		for (j = 1; j < 7; j++)
		{
			if (a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1] >= 4)
				b[i][j] = 0;
			if (a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1] == 3 && a[i][j] == 0)
				b[i][j] = 1;
			if (a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1] <= 1)
				b[i][j] = 0;
		}
	//顶点规则
	if (a[1][1] + a[0][1] + a[1][0] == 1 && a[0][0] == 0)
		b[0][0] = 1;
	if (a[1][1] + a[0][1] + a[1][0] >= 2)
		b[0][0] = 0;

	if (a[0][6] + a[1][6] + a[1][7] == 1 && a[0][7] == 0)
		b[0][7] = 1;
	if (a[0][6] + a[1][6] + a[1][7] >= 2)
		b[0][7] = 0;

	if (a[6][0] + a[6][1] + a[7][1] == 1 && a[7][0] == 0)
		b[7][0] = 1;
	if (a[6][0] + a[6][1] + a[7][1] >= 2)
		b[7][0] = 0;

	if (a[6][6] + a[6][7] + a[7][6] == 1 && a[7][7] == 0)
		b[7][7] = 1;
	if (a[6][6] + a[6][7] + a[7][6] >= 2)
		b[7][7] = 0;
	//剩余部分的规则
	for (i = 1; i <= 6; i++)
	{
		if (a[i - 1][0] + a[i - 1][1] + a[i][1] + a[i + 1][0] + a[i + 1][1] >= 3)
			b[i][0] = 0;
		if (a[i - 1][0] + a[i - 1][1] + a[i][1] + a[i + 1][0] + a[i + 1][1] == 2 && a[i][0] == 0)
			b[i][0] = 1;
		if (a[i - 1][0] + a[i - 1][1] + a[i][1] + a[i + 1][0] + a[i + 1][1] ==0)
			b[i][0] = 0;

		if (a[i - 1][7] + a[i - 1][6] + a[i][6] + a[i + 1][7] + a[i + 1][6] >= 3)
			b[i][7] = 0;
		if (a[i - 1][7] + a[i - 1][6] + a[i][6] + a[i + 1][7] + a[i + 1][6] == 2 && a[i][7] == 0)
			b[i][7] = 1;
		if (a[i - 1][7] + a[i - 1][6] + a[i][6] + a[i + 1][7] + a[i + 1][6] == 0)
			b[i][7] = 0;
	}
	for (j = 1; j <= 6; j++)
	{
		if (a[0][j-1] + a[0][j+1] + a[1][j-1] + a[1][j] + a[1][j+1] >= 3)
			b[0][j] = 0;
		if (a[0][j-1] + a[0][j+1] + a[1][j-1] + a[1][j] + a[1][j+1] == 2 && a[0][j] == 0)
			b[0][j] = 1;
		if (a[0][j-1] + a[0][j+1] + a[1][j-1] + a[1][j] + a[1][j+1] == 0)
			b[0][j] = 0;

		if (a[7][j-1] + a[7][j+1] + a[6][j-1] + a[6][j] + a[6][j+1] >= 3)
			b[7][j] = 0;
		if (a[7][j-1] + a[7][j+1] + a[6][j-1] + a[6][j] + a[6][j+1] == 2 && a[7][j] == 0)
			b[7][j] = 1;
		if (a[7][j-1] + a[7][j+1] + a[6][j-1] + a[6][j] + a[6][j+1] == 0)
			b[7][j] = 0;
	}
}



int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}


int main()
{
	gotoxy(50, 5);
	printf("生命游戏");
	start();
	title();
	dayin();
	//scanf("", );
	return 0;
}










