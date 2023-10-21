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
struct node
{
	char data = ' ';
	node* l = NULL;
	node* r = NULL;
	node* u = NULL;
	node* d = NULL;
};
class notepad
{
	node* ptr;
	node* head = NULL;
	node* current = NULL;
	int* arr;
	int s;
	char redo1 = '~';

public:
	notepad()
	{
		arr = new int[10];
		head = NULL;
		s = -1;
		current = NULL;
		for (int x = 0; x < 10; x++)
		{
			arr[x] = '~';
		}
	}
	void nextline(char n)
	{
		node* temp = head;
		while (1)
		{
			if (temp->d == NULL)
			{
				break;
			}
			temp = temp->d;
		}
		node* current1;
		current1 = new node;
		current1->data = n;
		temp->d = current1;
		current1->u = temp;
		current1->l = current;
		current->r = current1;
		current = current1;

	}
	void newnode(char n)
	{
		node* temp = new node;
		if (head == NULL)
		{
			head = temp;
			temp->data = n;
			temp->d = NULL;
			temp->u = NULL;
			temp->l = NULL;
			temp->r = NULL;
			current = head;
			return;
		}
		temp->data = n;
		temp->d = NULL;
		temp->l = current;
		current->r = temp;
		temp->r = NULL;
		if (current != NULL)
		{
			if (current->u != NULL)
			{
				if (current->u->r != NULL)
				{
					temp->u = current->u->r;
				}
			}
		}
		current = temp;

	}
	void input(node* ptr)
	{
		int check1 = 0, check2 = 0;
		while (1)
		{
			char c = getchar();
			if (current != NULL)
				redo1 = current->data;
			if (c != 25)
			{
				check1 = 0;
			}
			if (c != 26)
			{
				check2 = 0;
			}

			if (c == '*')
			{
				newnode(' ');
				break;
			}
			else
			{
				if (c == 25)
				{
					if (check1 == 0)
					{
						check1++;
						redo();
					}

				}

				else if (c == 26)
				{
					if (check2 < 11)
					{
						check2++;
						undo();
					}
				}
				else if (c == 13)
				{
					newnode(c);
					cout << endl;
					c = getchar();
					redo1 = current->data;
					if (c != 25)
					{
						check1 = 0;
					}
					if (c != 26)
					{
						check2 = 0;
					}

					///////////////////
					if (c == 26)
					{
						if (check2 < 10)
						{
							check2++;
							undo();
						}
					}
					if (c == 25)
					{
						if (check1 == 0) {
							check1++;
							redo();
						}
					}
					/////////////////
					if (c == '*')
					{
						newnode(' ');
						break;
					}
					nextline(c);
				}

				else
				{
					newnode(c);

				}
			}
			/////////////
		}
	}
	int find(string str1)
	{
		node* temp = head;

		node* temp1 = head;
		int x = 0; int a = 0;
		int check = 0;
		while (1)
		{
			if (check == 0)
			{
				if (temp == NULL)
				{
					return 0;
				}
				if (str1[0] == temp->data)
				{
					if (temp->l == NULL || temp->l->data == 13 || temp->l->data == ' ')
					{
						temp1 = temp; check = 1;
					}
					else
					{
						temp = temp->r;
						continue;
					}
				}
				else
				{
					temp = temp->r;
				}
			}
			////////////////////

			if (check == 1)
			{
				if (temp1->data == str1[x])
				{
					temp1 = temp1->r;
					x++;
					if (temp1->data == 13 || temp1->data == ' ')
					{
						if (str1[x] == '\0')
						{
							return 1;
						}
					}
				}
				else
				{
					check = 0;
					x = 0;
					temp = temp1;
				}
			}
			////////////////////////////
		}
		return 0;
	}
	void replace(string str1, string str2)
	{
		node* temp = head;

		node* temp1 = head;
		int x = 0; int a = 0;
		int check = 0;
		while (1)
		{
			if (check == 0)
			{
				if (temp == NULL)
				{
					cout << "Word hasnot found" << endl;
					return;
				}
				if (str1[0] == temp->data)
				{
					if (temp->l == NULL || temp->l->data == 13 || temp->l->data == ' ')
					{
						temp1 = temp; check = 1;
					}
					else
					{
						temp = temp->r;
						continue;
					}
				}
				else
				{
					temp = temp->r;
				}
			}
			////////////////////

			if (check == 1)
			{
				if (temp1->data == str1[x])
				{
					temp1 = temp1->r;
					x++;
					if (temp1->data == 13 || temp1->data == ' ')
					{
						if (str1[x] == '\0')
						{
							check = 2;
							break;
						}
					}
				}
				else
				{
					check = 0;
					x = 0;
					temp = temp1;
				}
			}
			////////////////////////////
		}
		if (check == 2)
		{
			for (int x = 0; x < str2.length(); x++)
			{
				temp->data = str2[x];
				temp = temp->r;
			}
		}

	}
	void print()
	{

		node* temp = head;
		while (1)
		{
			if (temp->data == 13)
				cout << endl;
			else
				cout << temp->data;
			temp = temp->r;
			if (temp == NULL)
			{
				cout << endl;
				break;
			}
		}
	}
	void undo()
	{
		node* temp = current;
		current = current->l;
		if (current != NULL) {
			current->r = NULL;
		}
		if (temp->u != NULL)
		{
			temp->u->d = NULL;
		}
		char a = temp->data;
		delete temp;
		s++;
		arr[s % 10] = a;

	}
	void  redo()
	{
		if (redo1 != '~')
		{
			newnode(redo1);
		}

	}
	void input1()
	{
		input(current);
	}
};

void note()
{
	cout << "Instructions   \n      enter ctrl+z to undo\n      enter ctrl+y to redo   \n      you will see impact when you print the notepad    \n      enter * if wana to go to main menu" << endl;

	notepad obj1;
	int check;
	while (1) {
		cout << "press \n1 to enter data\n2 to find\n3 to replace\n4 to print\n5 to exit::";
		cin >> check;
		if (check == 1)
		{
			cout << "Enter '*' in data if wana to return to main menu" << endl;
			obj1.input1();
			cout << endl;

		}
		else if (check == 2)
		{
			string str1;
			cout << "Enter word to find::";
			cin.ignore();
			getline(cin, str1);
			int a = obj1.find(str1);
			if (a == 1)
			{
				cout << "word has found......" << endl;
			}
			else
			{
				cout << "word hasnot found......" << endl;

			}
		}
		else if (check == 3)
		{
			string str1;
			cout << "Enter word to find::";
			cin.ignore();
			getline(cin, str1);
			string str2;
			cout << "Enter word to replace::";

			getline(cin, str2);
			int a = str1.length();
			int b = str2.length();
			if (a == b)
			{
				obj1.replace(str1, str2);
			}
			else
			{
				cout << "length of both words is different....so cannot replace it" << endl;
			}
		}
		else if (check == 4)
		{
			system("cls");
			cout << endl;
			cout << "               Notepad";
			cout << endl;
			cout << "-----------------------------------------------------" << endl;
			obj1.print();
			cout << endl;
			cout << "------------------------------------------------------" << endl;
		}
		else if (check == 5)
		{
			break;
		}
	}
}
int main()
{
	note();
	return 0;
}


