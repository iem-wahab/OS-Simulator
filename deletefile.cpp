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
void deletefile()
{
int status;
    char fileName[20];
    cout<<"Enter the Name of File: "<<endl;
    cin>>fileName;
    status = remove(fileName);
    if(status==0)
        cout<<"\nFile Deleted Successfully!"<<endl;
    else
        cout<<"\nErorr Occurred!"<<endl;
    cout<<endl;
}
int main()
{
    deletefile();
    return 0;
}
