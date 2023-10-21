#include<iostream>
#include<ctime>
#include<string>
#include<filesystem>
#include<fstream>
#include<cstdio>
#include<stdio.h>
#include<ios>
#include<queue>
#include <unistd.h>
using namespace std;
char var1 = '1', var2 = '2', var3 = '3', var4 = '4', var5 = '5', var6 = '6', var7 = '7', var8 = '8', var9 = '9';
char zero = 'O';
char x = 'X';
void board()
{
	system("cls");
	cout << "  Tic Tac Toe" << endl;
	cout << "Player 1: X	Player 2: O" << endl;


	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << var1 << "  |  " << var2 << "  |  " << var3 << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << var4 << "  |  " << var5 << "  |  " << var6 << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << var7 << "  |  " << var8 << "  |  " << var9 << endl;

	cout << "     |     |     " << endl << endl;
}
int checkwin()
{
	int x;
	if (var1 == var2 && var2 == var3)
	{
		x = 1;
		return x;
	}
	else
	{
		if (var4 == var5 && var5 == var6)
		{
			x = 1;
			return x;
		}
		else
		{
			if (var7 == var8 && var8 == var9)
			{
				x = 1;
				return x;
			}
			else
			{
				if (var1 == var4 && var4 == var7)
				{
					x = 1;
					return x;
				}
				else
				{
					if (var2 == var5 && var5 == var8)
					{
						x = 1;
						return x;
					}
					else
					{
						if (var3 == var6 && var6 == var9)
						{
							x = 1;
							return x;
						}
						else
						{
							if (var1 == var5 && var5 == var9)
							{
								x = 1;
								return x;
							}
							else
							{
								if (var3 == var5 && var5 == var7)
								{
									x = 1;
									return x;
								}
								else
								{
									if (var1 != ' ' && var2 != ' ' && var5 != ' ' && var5 != ' ' && var5 != ' ' && var5 != ' ' && var5 != ' ' && var5 != ' ' && var5 != ' ')
									{
										x = 0;
										return 0;
									}
									else
									{
										x = 0;
										return x;
									}
								}
							}
						}
					}
				}
			}
		}
	}

}

void game()
{
	int player;
	int temp;
	int sel;
	player = 1;
	board();
	do
	{
		cout << "Enter the number of box" << endl;
		cin >> sel;
		if (sel == 1)
		{
			var1 = 'X';
		}
		else
		{
			if (sel == 2)
			{
				var2 = 'X';
			}
			else
			{
				if (sel == 3)
				{
					var3 = 'X';
				}
				else
				{
					if (sel == 4)
					{
						var4 = 'X';
					}
					else
					{
						if (sel == 5)
						{
							var5 = 'X';
						}
						else
						{
							if (sel == 6)
							{
								var6 = 'X';
							}
							else
							{
								if (sel == 7)
								{
									var7 = 'X';
								}
								else
								{
									if (sel == 8)
									{
										var8 = 'X';
									}
									else
									{
										if (sel == 9)
										{
											var9 = 'X';
										}
									}
								}
							}
						}
					}
				}
			}
		}
		temp = checkwin();
		if (temp == 1)
		{
			cout << "player1 won" << endl;
			break;
		}
		cout << "Now second turn" << endl;
		cout << "Enter the number of box" << endl;
		cin >> sel;
		if (sel == 1)
		{
			var1 = 'O';
		}
		else
		{
			if (sel == 2)
			{
				var2 = 'O';
			}
			else
			{
				if (sel == 3)
				{
					var3 = 'O';
				}
				else
				{
					if (sel == 4)
					{
						var4 = 'O';
					}
					else
					{
						if (sel == 5)
						{
							var5 = 'O';
						}
						else
						{
							if (sel == 6)
							{
								var6 = 'O';
							}
							else
							{
								if (sel == 7)
								{
									var7 = 'O';
								}
								else
								{
									if (sel == 8)
									{
										var8 = 'O';
									}
									else
									{
										if (sel == 9 && var9 == 9)
										{

											var9 = 'O';

										}
									}
								}
							}
						}
					}
				}
			}
		}
		temp = checkwin();
		if (temp == 1)
		{
			cout << "player2 won" << endl;
			break;
		}
		board();
	} while (1);
}

int main()
{
	game();
	return 0;
}

