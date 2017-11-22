#include<iostream>
#include<string>
#include<windows.h>
#include<stdio.h>
#include<conio.h>

#define BLACK 1
#define WHITE 2
using namespace std;
void InitGameUI();
void gotoXY(short, short);
void CreateChessboard();
bool RunChess(string);
bool judgeWin();
// global variable
const string black{ "○" };
const string white{ "●" };
int x = 0, y = 0;
int position[19][19] = { 0 };
int main(void)
{
	InitGameUI();
	
	Sleep(1000);
	system("cls");
	CreateChessboard();
	gotoXY(0, 0);
	while (1)
	{
		RunChess(black);
		RunChess(white);			
	}
	return 0;
}
//move chess pieces
bool RunChess(string color)
{
	char ch = 'B';
	while (ch != 'J')
	{
		ch = _getch();
		if (ch == 'W')
		{
			if (y != 0)
			{
				y = y - 1;
				gotoXY(x, y);
			}
		}
		else if (ch == 'S')
		{
			if (y != 18)
			{
				y = y + 1;
				gotoXY(x, y);
			}
		}
		else if (ch == 'A')
		{
			if (x != 0)
			{
				x = x - 2;
				gotoXY(x, y);
			}
		}
		else if (ch == 'D')
		{
			if (x != 36)
			{
				x = x + 2;
				gotoXY(x, y);
			}
		}
		else if (ch == 'J')
		{
			if (position[y][x >> 1] != 0)
			{
				ch = 'N';
				continue;
			}
			cout << color << endl;
			gotoXY(x, y);
			if (color == black)
			{
				position[y][x>>1] = BLACK;
			}
			else
			{
				position[y][x>>1] = WHITE;
			}
			judgeWin();
		}
	}
	return true;
	}
void CreateChessboard()
{
	for(int y = 0;y <= 18;y++)
	{
		for (int x = 0;x <= 18;x++)
		{
			if (x == 0 && y == 0)
			{
				cout << "┌";
			}
			if(x > 0 && x < 18&&y==0)
			{				
				cout << "┬";				
			}
			if (x == 18 && y == 0)
			{
				cout << "┐";
			}
			if (y > 0 && y < 18 && x == 0 )
			{
				cout << "├";
			}
			if (y > 0 && y < 18 && x>0 && x < 18)
			{
				cout << "┼";
			}
			if (y > 0 && y < 18 && x == 18)
			{
				cout << "┤";
			}
			if (x == 0 && y == 18)
			{
				cout << "└";
			}
			if (x > 0 && x < 18 && y == 18)
			{
				cout << "┴";
			}
			if (x == 18 && y == 18)
			{
				cout << "┘";
			}
		}
		cout << endl;
	}
}
void InitGameUI()
{
	for (int x = 0;x != 19;x++)
	{
		for (int y = 0;y != 19;y++)
		{
			cout << " ";
			if (x == 9 && y == 2)
			{
				cout << "five-in-a-row game being!";
			}
		}
		cout << endl;
	}
}
void gotoXY(short x, short y)
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}
bool judgeWin()
{
	int cnt = 0;
	int xp = 0,yp = 0;
	int before = -1;
	int h = 0, v = 0;
	int b = 0, w = 0;
		//judge horization fruit
		for (v = 0;v < 19;++v)
		{
			for (h = 0;h < 19;++h)
			{
				if (position[v][h] == BLACK)
				{					
					++b;
					w = 0;
					if (b == 5)
					{
						gotoXY(13, 8);
						cout << "black win!" << endl;
						return true;
					}
				}
				else if (position[v][h] == WHITE)
				{
					++w;
					b = 0;
					if (w == 5)
					{
						gotoXY(13, 8);
						cout << "white win!" << endl;
						return true;
					}
				}
				else
				{
					b = 0;
					w = 0;
				}
			}
		}
		h = 0;
		v = 0;
		//judge veritical fruit
		for (v = 0;v < 19;++v)
		{
			for (h = 0;h < 19;++h)
			{
				if (position[h][v] == BLACK)
				{
					++b;
					w = 0;
					if (b == 5)
					{
						gotoXY(13, 8);
						cout << "black win!" << endl;
						return true;
					}
				}
				else if (position[h][v] == WHITE)
				{
					++w;
					b = 0;
					if (w == 5)
					{
						gotoXY(13, 8);
						cout << "white win!" << endl;
						return true;
					}
				}
				else
				{
					b = 0;
					w = 0;
				}
			}

		}
		//angles	左上|右下
		for (v = 0;v < 19;v++)
		{
			xp = cnt;
			yp = 0;
			for (h = 0;h < v + 1;h++)
			{
				if (position[xp][yp] == BLACK)
				{
					++b;
					w = 0;
					if (b == 5)
					{
						gotoXY(13, 8);
						cout << "black win!" << endl;
						return true;
					}
				}
				else if (position[xp][yp] == WHITE)
				{
					++w;
					b = 0;
					if (w == 5)
					{
						gotoXY(13, 8);
						cout << "white win!" << endl;
						return true;
					}
				}
				else
				{
					b = 0;
					w = 0;
				}
			
				xp -= 1;
				yp += 1;
				
			}
			cnt++;
		}
		cnt = 1;
		for (v = 18;v >0;--v)
		{
			xp = 18;
			yp = cnt;
			for (h = 0;h < v ;h++)
			{
				if (position[xp][yp] == BLACK)
				{
					++b;
					w = 0;
					if (b == 5)
					{
						gotoXY(13, 8);
						cout << "black win!" << endl;
						return true;
					}
				}
				else if (position[xp][yp] == WHITE)
				{
					++w;
					b = 0;
					if (w == 5)
					{
						gotoXY(13, 8);
						cout << "white win!" << endl;
						return true;
					}
				}
				else
				{
					b = 0;
					w = 0;
				}
				//cout << position[xp][yp];
				//cout << "(" << xp << "," << yp << ")";
				xp -= 1;
				yp += 1;
			}
			++cnt;
		}
		//angle 右上|左下
		cnt = 18;
		for (v = 0;v < 19;v++)
		{
			xp = 0;
			yp = cnt;
			for (h = 0;h < v + 1;h++)
			{
				if (position[xp][yp] == BLACK)
				{
					++b;
					w = 0;
					if (b == 5)
					{
						gotoXY(13, 8);
						cout << "black win!" << endl;
						return true;
					}
				}
				else if (position[xp][yp] == WHITE)
				{
					++w;
					b = 0;
					if (w == 5)
					{
						gotoXY(13, 8);
						cout << "white win!" << endl;
						return true;
					}
				}
				else
				{
					b = 0;
					w = 0;
				}
				xp += 1;
				yp += 1;
			}
			--cnt;
		}
		cnt = 1;
		for (v = 18;v >0;--v)
		{
			xp = cnt;
			yp = 0;
			for (h = 0;h < v;h++)
			{
				if (position[xp][yp] == BLACK)
				{
					++b;
					w = 0;
					if (b == 5)
					{
						gotoXY(13, 8);
						cout << "black win!" << endl;
						return true;
					}
				}
				else if (position[xp][yp] == WHITE)
				{
					++w;
					b = 0;
					if (w == 5)
					{
						gotoXY(13, 8);
						cout << "white win!" << endl;
						return true;
					}
				}
				else
				{
					b = 0;
					w = 0;
				}
				//cout << position[xp][yp];
				//cout << "(" << xp << "," << yp << ")";
				xp += 1;
				yp += 1;

			}
			++cnt;
		}
		return false;
}
//v1.0
