#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>



void gotoxy(int x, int y);



void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



int main()
{
	gotoxy(24, 3);
	printf("…˙√¸”Œœ∑");
	return 0;
}










