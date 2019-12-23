#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int blocks[7][4][4][4] = {
	0, 0, 0, 0,//J
	2, 0, 0, 0,
	2, 2, 2, 0,
	0, 0, 0, 0,
	
	0, 0, 0, 0,
	0, 2, 2, 0,
	0, 2, 0, 0,
	0, 2, 0, 0,
	
	0, 0, 0, 0,
	0, 0, 0, 0,
	2, 2, 2, 0,
	0, 0, 2, 0,
	
	0, 0, 0, 0,
	0, 2, 0, 0,
	0, 2, 0, 0,
	2, 2, 0, 0,
	
	0, 0, 0, 0,//L
	0, 0, 2, 0,
	2, 2, 2, 0,
	0, 0, 0, 0,
	
	0, 0, 0, 0,
	0, 2, 0, 0,
	0, 2, 0, 0,
	0, 2, 2, 0,
	
	0, 0, 0, 0,
	0, 0, 0, 0,
	2, 2, 2, 0,
	2, 0, 0, 0,
	
	0, 0, 0, 0,
	2, 2, 0, 0,
	0, 2, 0, 0,
	0, 2, 0, 0,
	
	0, 0, 0, 0, //T
	2, 2, 2, 0,
	0, 2, 0, 0,
	0, 0, 0, 0,
	
	0, 2, 0, 0,
	2, 2, 0, 0,
	0, 2, 0, 0,
	0, 0, 0, 0,
	
	0, 2, 0, 0,
	2, 2, 2, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	
	0, 2, 0, 0,
	0, 2, 2, 0,
	0, 2, 0, 0,
	0, 0, 0, 0,
	
	0, 0, 0, 0, //S
	0, 2, 2, 0,
	2, 2, 0, 0,
	0, 0, 0, 0,
	
	0, 2, 0, 0,
	0, 2, 2, 0,
	0, 0, 2, 0,
	0, 0, 0, 0,
	
	0, 0, 0, 0,
	0, 2, 2, 0,
	2, 2, 0, 0,
	0, 0, 0, 0,
	
	2, 0, 0, 0,
	2, 2, 0, 0,
	0, 2, 0, 0,
	0, 0, 0, 0,
	
	0, 0, 0, 0, //Z
	2, 2, 0, 0,
	0, 2, 2, 0,
	0, 0, 0, 0,
	
	0, 2, 0, 0,
	2, 2, 0, 0,
	2, 0, 0, 0,
	0, 0, 0, 0,
	
	2, 2, 0, 0,
	0, 2, 2, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	
	0, 0, 2, 0,
	0, 2, 2, 0,
	0, 2, 0, 0,
	0, 0, 0, 0,
	
	0, 0, 0, 0, //O
	0, 2, 2, 0,
	0, 2, 2, 0,
	0, 0, 0, 0,
	
	0, 0, 0, 0,
	0, 2, 2, 0,
	0, 2, 2, 0,
	0, 0, 0, 0,
	
	0, 0, 0, 0,
	0, 2, 2, 0,
	0, 2, 2, 0,
	0, 0, 0, 0,
	
	0, 0, 0, 0,
	0, 2, 2, 0,
	0, 2, 2, 0,
	0, 0, 0, 0,
	
	0, 0, 0, 0, //I
	2, 2, 2, 2,
	0, 0, 0, 0,
	0, 0, 0, 0,
	
	0, 0, 2, 0,
	0, 0, 2, 0,
	0, 0, 2, 0,
	0, 0, 2, 0,
	
	0, 0, 0, 0,
	0, 0, 0, 0,
	2, 2, 2, 2,
	0, 0, 0, 0,
	
	0, 2, 0, 0,
	0, 2, 0, 0,
	0, 2, 0, 0,
	0, 2, 0, 0
};


int Board[31][12] = {0,};
int x = 8, y = 0;
int lineclear = 0;
int IsHard = 0;
int blocktype = 0;
int rotation = 0;
int CanLeft = 1;
int CanRight = 1;
int CanDown = 1;
int level1 = 1;
int level2 = 1;
int level3 = 1;
int level4 = 1;
int level5 = 1;
int score  = 0;
int level = 1;
float Time = 1000;

void Random();
void KeyMove();
void Rotation();
void Landing();
void LineClear();
void HardDrop();
void MakeMap();
void NumberMap();
void DrawBlocks();
void DeleteBlocks();
void IsOver();
void gotoxy(int x, int y);

int main()
{
	Random();
	MakeMap();
	//NumberMap();
	DrawBlocks();
	KeyMove();
	
	return 0;
}

void Random()
{
	srand((unsigned)time(NULL));
	 blocktype = rand()%7;
}

void KeyMove()
{
	int keycode;
	int i, j;
	float checkTime = 0;
	clock_t start, end;
	
	while(1)
	{
		start = clock();
		if(kbhit())
		{
			keycode = getch();
			
			if(keycode == 72) //up
			{
				if(blocktype == 6)
				{
					if(x<0)
						x+=4;
					else if(x==0)
						x+=2;
					else if(x == 16)
						x-=2;
					else if(x == 18)
						x-=4;
				}
				else if(x == 0)
					x+=2;
				else if(x == 18)
					x-=2;
			
				gotoxy(x,y);
				
				Rotation();
			}
			
			else if(keycode == 80) //down
			{
				
				if(CanDown)
				{	
					DeleteBlocks();
					y++;
					gotoxy(x,y);
					DrawBlocks();
					score++;
				}
			}
			
			else if(keycode == 75) //left
			{
				if(CanLeft)
				{
					DeleteBlocks();
					x-=2;
					gotoxy(x,y);
					DrawBlocks();
					
				}
			}
			
			else if(keycode == 77) //right
			{
				if(CanRight)
				{
					DeleteBlocks();
					x+=2;
					gotoxy(x,y);
					DrawBlocks();
				}
			}
			
			else if(keycode == 32)
			{
				HardDrop();
			}
			
			else if(keycode == 27)
			{
				gotoxy(0,33);
				exit(0);
			}
			
			else if(keycode == 83)
			{
				while(1)
				{
					Sleep(1);
					if(kbhit())
					{
						keycode = getch();
						if(keycode == 83)
							break;
					}
				}
			}
		}
		
		if(CanDown == 0)
			Landing();
			
		end = clock();
		checkTime += end - start;
		
		if(checkTime >= Time)
		{	
			DeleteBlocks();
			y++;
			gotoxy(x,y);
			DrawBlocks();
			
			system("cls");
			LineClear();
			//NumberMap();
			MakeMap();
			
			checkTime = 0;
		}
		IsOver();  
	}
}

void Rotation()
{
	int X = x, Y = y;
	int i, j;
	int dontrotate = 0;
	int q;
	
	gotoxy(X,Y);
	
	rotation ++;
	q= rotation / 4;
	rotation = rotation % 4;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(blocks[blocktype][rotation][i][j] == 2)
			{
				if(Board[Y][X/2] == 1)
					dontrotate++;
			}
			X+=2;
		}
		if(dontrotate != 0)
			break;
		X=x;
		Y++;
	}
	if(dontrotate != 0)
	{
		rotation = q*4 + rotation;
		rotation--;
	}
	gotoxy(x,y);
	DeleteBlocks();
	DrawBlocks();
}

void Landing()
{
	int keycode;
	int i,j;
	float checkTime = 0;
	clock_t start, end;
	
	if(IsHard != 1)
	{
		if(CanDown == 0)
		{
			while(1)
			{
				start = clock();
				
				if(kbhit())
				{
					keycode = getch();
					
					if(keycode == 72)
					{
						if(blocktype == 6)
						{
							if(x<0)
								x+=4;
							else if(x==0)
								x+=2;
							else if(x == 16)
								x-=2;
							else if(x == 18)
								x-=4;
						}
						else if(x == 0)
							x+=2;
						else if(x == 18)
							x-=2;
					
						gotoxy(x,y);
						
						Rotation();
						
						if(CanDown)
							break;
					}
					
					if(keycode == 75) //left
					{
						if(CanLeft)
						{
							DeleteBlocks();
							x-=2;
							gotoxy(x,y);
							DrawBlocks();
							
							if(CanDown)
								break;
						}
					}
					
					else if(keycode == 77) //right
					{
						if(CanRight)
						{
							DeleteBlocks();
							x+=2;
							gotoxy(x,y);
							DrawBlocks();
							
							if(CanDown)
								break;
						}
					}
					
					else if(keycode == 33)
					{
						gotoxy(0,28);
						exit(0);
					}
				}
				end = clock();
				checkTime += end - start;
				
				if(checkTime >= 2*Time)
				{
					for(i=0;i<31;i++)
					{
						for(j=0;j<12;j++)
						{
							if(Board[i][j] == 2)
								Board[i][j] = 1;
						}
					}
					CanLeft = 1;
					CanRight = 1 ;
					CanDown = 1;
					x = 8;
					y = 1;
					gotoxy(x,y);
					Random();
					DrawBlocks();
					
					break;
				}
				
			}
		}	
	}
	
	else
	{
		for(i=0;i<31;i++)
		{
			for(j=0;j<12;j++)
			{
				if(Board[i][j] == 2)
					Board[i][j] = 1;
			}
		}
		CanLeft = 1;
		CanRight = 1 ;
		CanDown = 1;
		x = 8;
		y = 1;
		gotoxy(x,y);
		Random();
		DrawBlocks();
		
		IsHard = 0;
	}
}

void LineClear()
{
	int i, j,m,n,count = 0 ;
	for(i=0;i<=29;i++)
	{
		for(j=1;j<=10;j++)
		{
			if(Board[i][j] == 1)
				count ++;
			else
			{
				count=0;
				break;
			}
		}
		
		if(count == 10)
		{
			for(m=i;m>0;m--)
			{
				for(n=10;n>=0;n--)
				{
					Board[m][n] = Board[m-1][n];
				}
			}
			lineclear++;
			score+=100;
			count = 0;
		}
	}
	
	if(lineclear >=50)
	{
		if(level5)
		{
			level++;
			Time=(Time/4)*3;
			level5 = 0;
		}
	}
	
	else if(lineclear >= 40)
	{
		if(level4)
		{
			level++;
			Time = (Time/4)*3;
			level4 = 0;
		}
		
	}
	
	else if(lineclear >= 30)
	{
		if(level3)
		{
			level++;
			Time = (Time/4)*3;
			level3 = 0;
		}
		
	}
	
	else if(lineclear >= 20)
	{
		if(level2)
		{
			level++;
			Time = (Time/4)*3;
			level2 = 0;
		}
	}
	
	else if(lineclear >= 10)
	{
		if(level1)
		{
			level++;
			Time = (Time/4)*3;
			level1 = 0;
		}
	}
}

void HardDrop()
{
	while(1)
	{
		if(CanDown)
		{
			DeleteBlocks();
			y++;
			gotoxy(x,y);
			DrawBlocks();
			score+=2;
		}
		else
			break;
	}
	IsHard = 1;
}

void MakeMap()
{
	gotoxy(0,0);
	
	int i,j;
	for(i=0;i<31;i++)
	{
		for(j=0;j<12;j++)
		{
			if(i == 30)
			{
				for(j=0;j<12;j++)
					Board[i][j] = 1;
			}
			else if(j == 0 || j == 11)
				Board[i][j] = 1;
		}
	}
	
	for(i=0;i<31;i++)
	{
		for(j=0;j<12;j++)
		{
			if(Board[i][j] == 0)
				printf("  ");
			else if(Board[i][j] == 1)
				printf("бс");
			else if(Board[i][j] == 2)
				printf("бр");
		}
		printf("\n");
	}
	gotoxy(25,9);
	printf("в╕");
	
	gotoxy(0, 31);
	printf("LineClear : %d",lineclear);
	printf("\nScore : %d",score);
	printf("\nLevel : %d",level);
}

void NumberMap()
{
	int k =0;
	gotoxy(30,0);
	
	int i, j;
	for(i=0;i<31;i++)
	{
		for(j=0;j<12;j++)
		{
			printf("%d",Board[i][j]);
		}
		k++;
		gotoxy(30,k);
	}
	
}

void DrawBlocks()
{
	int i, j;
	int X=x,Y=y;
	
	CanLeft = 1;
	CanRight = 1;
	CanDown = 1;
	
	gotoxy(X,Y);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(blocks[blocktype][rotation][i][j] == 2)
			{ 
				Board[Y][X/2] = 2;
				if(Board[Y][X/2 - 1] == 1)
					CanLeft = 0;
				if(Board[Y][X/2 + 1] == 1)
					CanRight = 0;
				if(Board[Y + 1][X/2] == 1)
					CanDown = 0;
				
				gotoxy(X,Y);
				printf("бр");
			}
			X+=2;
		}
		X=x;
		Y++;
	}
	
	gotoxy(x,y);
}

void DeleteBlocks()
{
	int i,j;
	for(i=0;i<31;i++)
	{
		for(j=0;j<12;j++)
		{
			if(Board[i][j] == 2)
			{
				Board[i][j] = 0;
				gotoxy(j*2,i);
				printf("  ");
			}
		}
	}
}

void IsOver()
{
	int i;
	for(i=1;i<11;i++)
	{
		if(Board[8][i] == 1)
		{
			gotoxy(0,35);
			printf("Game Over");
			exit(0);
		}
	}
}

void gotoxy(int x, int y)
{
    COORD Pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
