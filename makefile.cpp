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
void makefile()
{
fstream file;
file.open("testing.txt",ios::out);

if(!file)
{
cout<<"Error in creating file!!!";
}

cout<<"File created successfully.";
}
int main()
{
	makefile();
	return 0;
}
