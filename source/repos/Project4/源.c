#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define FrameX 13
#define FrameY 3
#define Frame_height 20
#define Frame_width 18

int i, j, Temp, Temp1, Temp2;
int a[80][80] = { 0 };//0,1,2
int b[4];
struct Tetris
{
	int x;
	int y;
	int flag;
	int next;
	int speed;
	int number;
	int socre;
	int level;
};
HANDLE hOut;

/*函数声明*/
void gotoxy(int x, int y);
void DrwaGameframe();
void Flag(struct Tetris *);
void MakeTetris(struct Tetris *);
void PrintTetris(struct Tetris *);
void CleanTetris(struct Tetris *);
int ifmove(struct Tetris *);
void Del_Fullline(struct Tetris *);
void Gameplay();
void regulation();
void explation();
void welcom();
void Replay(struct Tetris *);
void title();
void flower();
void close();


/*控制文字颜色*/
int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
	return 0;
}
/*控制文字显示位置*/
void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
/*欢迎界面上的标题*/
void title()
{
	color(15);
	gotoxy(24, 3);
	printf("趣 味 俄 罗 斯 方 块");
	color(11);
	gotoxy(18, 5);
	printf("▢ ");
	gotoxy(18, 6);
	printf("▢ ▢ ");
	gotoxy(18, 7);
	printf("▢ ");

	color(14);
	gotoxy(26, 6);
	printf("▢ ▢");
	gotoxy(28, 7);
	printf("▢ ▢ ");

	color(10);
	gotoxy(36, 6);
	printf("▢ ▢ ");
	gotoxy(36, 7);
	printf("▢ ▢ ");

	color(13);
	gotoxy(45, 5);
	printf("▢ ");
	gotoxy(45, 6);
	printf("▢ ");
	gotoxy(45, 7);
	printf("▢ ");
	gotoxy(45, 8);
	printf("▢ ");

	color(12);
	gotoxy(56, 6);
	printf("▢ ");
	gotoxy(52, 7);
	printf("▢ ▢ ▢ ");

}
/*绘制字符花*/
void flower()
{
	gotoxy(66, 11);
	color(12);
	printf("(_)");
}
/*菜单选项*/
void welcom()
{
	int i,j,n;
	color(14);
	for (i = 9; i <= 20; i++)
	{
		for (j = 15; j <= 60; j++)
		{
			gotoxy(j, i);
			if (i == 9 || i == 20)
			{
				printf("=");
			}
			else
				if (j == 15 || j == 59)
				{
					printf("||");
				}
		}
	}
	color(12);
	gotoxy(25, 12);
	printf("1,开始游戏");
	gotoxy(40, 12);
	printf("2,按键说明");
	gotoxy(25, 17);
	printf("3,游戏规则");
	gotoxy(40, 17);
	printf("4,退出");
	
	gotoxy(21, 22);
	color(3);
	printf("请选择[1 2 3 4]:[ ]\b\b");
	color(14);
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		system("cls");//清屏函数
		DrwaGameframe();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;

	}
}
/*制作游戏框*/
void DrwaGameframe()
{
	gotoxy(FrameX + Frame_width - 7, FrameY - 2);
	color(11);
	printf("趣味俄罗斯方块");

	color(12);
	gotoxy(FrameX, FrameY);
	printf("╔");
	gotoxy(FrameX + 2 * Frame_width - 2, FrameY);
	printf("╗");
	gotoxy(FrameX,FrameY+Frame_height);
	printf("╚");
	gotoxy(FrameX+2*Frame_width-2,FrameY+Frame_height);
	printf("╝");

	//上横框
	for (i = 2; i < 2 * Frame_width - 2; i += 2)
	{
		gotoxy(FrameX + i, FrameY);
		printf("━");
	}
	//下横框
	for (i = 2;; i < 2 * Frame_width - 2, i += 2);
	{
		gotoxy(FrameX + i, FrameY + Frame_height);
		printf("━");
	}
	//左横框
	for (i = 1; i < Frame_height; i++)
	{
		gotoxy(FrameX, FrameY+i);
		printf("");
	}
	//右横框
	for (i = 1; i < Frame_height; i++)
	{
		gotoxy(FrameX+2*Frame_width-2, FrameY + i);
		printf("│");
	}
}
int main()
{
	title();
	flower();
	welcom();
}