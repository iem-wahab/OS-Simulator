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
class minesweeper
{
	int	arr[81], arr1[81];
	int score = 0;
	int num = -1;
	int	row = -1;		//row
	int	col = -1;		//coloum
	int	posi = 0;		//position that user enter
	int	mine = 7;		//mines value
	int p1 = -1, p2 = -1, p3 = -1, p4 = -1, p5 = -1, p6 = -1, p7 = -1, p8 = -1;
	int check1 = -1;	//for loop in check function
	int cinput = 0;	//for loop in input function
	int minecheck = -1;	//for loop in mine check function
	bool wiin = false;
public:
	void random()
	{
		for (int i = 0; i < 81; i++)//populate table
		{
			arr[i] = 0;
			arr1[i] = 0;
		}
		for (int i = 0; i < 10; i++)// in{ 0..10 } #place mines
		{
			minecheck = -1;
			while (minecheck == -1)
			{
				num = rand() % 81;
				if (arr[num] == mine)//to check whether the position has already a mine or not
					minecheck = -1;
				else
				{
					minecheck = 0;
					arr[num] = mine;
				}
			}

		}
	}
	void print(int ar[81])
	{
		cout << "   0  1  2  3  4  5  6  7  8\n";
		cout << "-------------------------------\n";
		for (int i = 0; i < 9; i++)
		{
			cout << i << "|";
			for (int j = 0; j < 9; j++)
			{
				cout << " " << ar[(9 * i) + j] << " ";
			}
			cout << endl;
		}
		cout << "--------------------------------\n";
		cout << "	   score  " << score << endl;
		cout << "---------------------------------\n";
	}
	void input()
	{
		cinput = 0;

		while (cinput == 0)
		{
			cout << "Enter row Number:";
			cin >> row;
			cout << "Enter coloum Number:";
			cin >> col;
			posi = (row * 9); //horizental movement
			posi = (posi + col); //vertical movement
			if (arr[posi] == 1)
				cout << "You cannot enter at this position! Try again.";
			else
				cinput = 1;
		}
	}

	void check()
	{
		int j = 0;
		posi = (row * 9); //horizental movement
		posi = (posi + col); //vertical movement
		for (int i = 0; i < 81; i++)   //win check
		{
			if (arr[i] == 0)
				j++;
		}

		wiin = win(j);
		if (wiin)
			return;
		if (arr[posi] == mine)// #mine check
		{
			check1 = 1;
			print(arr);
			cout << "OOpss! you step on a mine\n";

		}
		else
		{
			if (arr[posi] != mine)
			{
				position(posi);
			}
		}

	}
	void position(int po)
	{
		//create the other position around the user input position
		posi = po;
		p1 = (posi + 1);
		p2 = (posi - 1);
		p3 = (posi - 9);
		p4 = (posi + 9);
		p5 = (posi - 10);
		p6 = (posi + 10);
		p7 = (posi - 8);
		p8 = (posi + 8);
		arr[posi] = 1;
		arr1[posi] = 1;
		if (row == 0 && col == 0)
		{
			if (arr[p1] == mine || arr[p4] == mine || arr[p6] == mine)
			{
				score = (score + 10);
			}
			else
			{

				arr[p1] = 1;
				arr[p4] = 1;
				arr[p6] = 1;

				arr1[p1] = 1;
				arr1[p4] = 1;
				arr1[p6] = 1;
				score = (score + 40);
			}
		}
		else if (row == 8 && col == 8)
		{
			if (arr[p2] == mine || arr[p3] == mine || arr[p5] == mine)
				score = (score + 10);

			else
			{
				arr[p2] = 1;
				arr[p3] = 1;
				arr[p5] = 1;

				arr1[p2] = 1;
				arr1[p3] = 1;
				arr1[p5] = 1;
				score = (score + 40);
			}
		}
		else if (row == 8 && col == 0)
		{
			if (arr[p1] == mine || arr[p3] == mine || arr[p7] == mine)
				score = (score + 10);
			else
			{
				arr[p1] = 1;
				arr[p3] = 1;
				arr[p7] = 1;

				arr1[p1] = 1;
				arr1[p3] = 1;
				arr1[p7] = 1;
				score = (score + 40);
			}
		}
		else if (row == 0)
		{
			if (arr[p1] == mine || arr[p2] == mine || arr[p4] == mine || arr[p6] == mine || arr[p8] == mine)
				score = (score + 10);
			else
			{
				arr[p1] = 1;
				arr[p2] = 1;
				arr[p4] = 1;
				arr[p6] = 1;
				arr[p8] = 1;

				arr1[p1] = 1;
				arr1[p2] = 1;
				arr1[p4] = 1;
				arr1[p6] = 1;
				arr1[p8] = 1;
				score = (score + 60);
			}
		}
		else if (row == 8)
		{
			if (arr[p1] == mine || arr[p2] == mine || arr[p3] == mine || arr[p5] == mine || arr[p7] == mine)
				score = (score + 10);
			else
			{
				arr[p1] = 1;
				arr[p2] = 1;
				arr[p3] = 1;
				arr[p5] = 1;
				arr[p7] = 1;

				arr1[p1] = 1;
				arr1[p2] = 1;
				arr1[p3] = 1;
				arr1[p5] = 1;
				arr1[p7] = 1;
				score = (score + 60);
			}
		}
		else if (col == 0)
		{
			if (arr[p1] == mine || arr[p3] == mine || arr[p4] == mine || arr[p6] == mine || arr[p7] == mine)
				score = (score + 10);
			else
			{
				arr[p1] = 1;
				arr[p3] = 1;
				arr[p4] = 1;
				arr[p6] = 1;
				arr[p7] = 1;

				arr1[p1] = 1;
				arr1[p3] = 1;
				arr1[p4] = 1;
				arr1[p6] = 1;
				arr1[p7] = 1;
				score = (score + 60);
			}
		}
		else if (col == 8)
		{
			if (arr[p2] == mine || arr[p3] == mine || arr[p4] == mine || arr[p6] == mine || arr[p8] == mine)
				score = (score + 10);
			else
			{
				arr[p2] = 1;
				arr[p3] = 1;
				arr[p4] = 1;
				arr[p5] = 1;
				arr[p8] = 1;

				arr1[p2] = 1;
				arr1[p3] = 1;
				arr1[p4] = 1;
				arr1[p5] = 1;
				arr1[p8] = 1;
				score = (score + 60);
			}
		}
		else
		{
			if (arr[p1] == mine || arr[p2] == mine || arr[p3] == mine || arr[p4] == mine || arr[p5] == mine || arr[p6] == mine || arr[p7] == mine || arr[p8] == mine)
				score = (score + 10);
			else
			{
				arr[p1] = 1;
				arr[p2] = 1;
				arr[p3] = 1;
				arr[p4] = 1;
				arr[p5] = 1;
				arr[p6] = 1;
				arr[p7] = 1;
				arr[p8] = 1;

				arr1[p1] = 1;
				arr1[p2] = 1;
				arr1[p3] = 1;
				arr1[p4] = 1;
				arr1[p5] = 1;
				arr1[p6] = 1;
				arr1[p7] = 1;
				arr1[p8] = 1;
				score = (score + 90);
			}

		}

	}
	bool win(int s)
	{
		if (s == 0)
		{
			cout << "You won!!\n";
			return true;
		}
		return false;

	}
	void start()
	{
		random();
		while (check1 < 0)
		{
			print(arr1);
			input();
			check();
		}
	}
};

int main()
{
	minesweeper M;
	M.start();
	return 0;
}
