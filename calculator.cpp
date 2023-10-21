#include<iostream>
#include<ctime>
#include<string>
#include<filesystem>
#include<fstream>
#include<cstdio>
#include<stdio.h>
#include<ios>
#include<queue>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
using namespace std;
void calculator()
{
	int endin;
	int a, b, x;
	int sum, subt, mult, divi;
	cout << "Enter first number\n";
	cin >> a;
	cout << "Enter second number\n";
	cin >> b;
	cout << "1.Addition\n2.Multiplication\n3.subtraction\n4.division\n";
	cin >> x;
	switch (x)
	{
	case 1:
		sum = a + b;
		cout << "Sum =" << sum << endl;
		break;
	case 2:
		mult = a * b;
		cout << "Multiplication = " << mult << endl;
		break;
	case 3:
		subt = a - b;
		cout << "Subtraction = " << subt << endl;
		break;
	case 4:
		if (b == 0)
		{
			cout << "logical error\n";
		}
		else
		{
			divi = a / b;
			cout << "Division = " << divi << endl;
		}
		break;
	default:
		cout << "Wrong input\n";

	}
	cout<<"press any number to continue\n";
	cin>>endin;

}

int main()
{
	
	calculator();
	int res,n=10;
  res=open("fifo1",O_WRONLY);
  write(res,"1",1);
  printf("Sender Process %d sent the data\n",getpid());
	return 0;

}

