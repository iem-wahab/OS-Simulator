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

void copyfile()
{
  char h, sfile[100], dfile[100];
  FILE* s;
  FILE* p;
  cout << "Enter name of source file\n";
  cin >> sfile;
  cout << "Enter Destination file name\n";
  cin >> dfile;
  s = fopen(sfile, "r");
  p = fopen(dfile, "w");
  h = fgetc(s);
  while (h != EOF)
  {
    fputc(h, p);
    h = fgetc(s);
  }
  fclose(s);
  fclose(p);
}
int main()
{
	copyfile();
	return 0;
}
