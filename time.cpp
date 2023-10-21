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
void time1()
{
	time_t now = time(0);


	char* date_time = ctime(&now);
	cout << "The current date and time is: " << date_time << endl;
	sleep(5000);
}

int main()
{
	time1();
	return 0;
}

