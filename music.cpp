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
void music()
{
	system("canberra-gtk-play -f file_example_OOG_1MG.ogg");
}

int main()
{
	music();
	return 0;
}

