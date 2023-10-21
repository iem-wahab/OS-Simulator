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

void movefile()
{
int result=1;
  char oldname[500];
  char newname[500];
  cout << "Enter the Location of the file"<<endl;
  cin >> oldname;
  cout << "Enter the new location"<<endl;
  cin >> newname;

  result = rename( oldname , newname );
  if ( result == 0 )
    cout << "File successfully moved" << endl;
  else
    cout << "Error moving file" << endl;
}
int main()
{
	movefile();
	return 0;
}
