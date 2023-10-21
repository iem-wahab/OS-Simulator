#include <iostream>
#include <iomanip>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
using namespace std;
int main()
{
int endin;
int mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int DaysinWeek = 0;
int year;
int day;
int FirstDayOfMonth = 0;
int month = 1;



cout << "Calendar Program" << endl << endl;
cout << "Please enter the year: ";
cin >> year;
if (year < 0)
{cout << "The year must be greater than or equal to 0!" << endl;
return 0;}
day=0;
if (day < 0 || day > 6)
{cout << "The day of January 1st must be between 0 and 6!" << endl;
return 0;}

cout << endl << endl;






// Print this year's calendar
for (int month = 0; month < 12; ++month) {
{
    
for (int i = 0; i < DaysinWeek; ++i)
{cout << setw(3) << " ";}


if (month == 0)
{cout << "January \n";}

if (month == 1)
{cout << "February \n";
 if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
mdays[1] = 29;}

if (month == 2)
{cout << "March \n";}

if (month == 3)
{cout << "April \n";}

if (month == 4)
{cout << "May \n";}

if (month ==5)
{cout << "June \n";}

if (month == 6)
{cout << "July \n";}

if (month == 7)
{cout << "August \n";}

if (month == 8)
{cout << "September \n";}

if (month == 9)
{cout << "October \n";}

if (month == 10)
{cout << "November \n";}

if (month == 11)
{cout << "December \n";}

}


//spaces
for (int i = 0; i < day; i++)
    {cout << "  ";
}

  //Determine where the first day begins
day = 0;
    for (FirstDayOfMonth; FirstDayOfMonth < day; ++FirstDayOfMonth)
    {   
        cout << setw(3);
    } 

// Print this month's calendar
for (int mday = 0; mday < mdays[month]; ++mday) {
cout << setw(3) << mday + 1;
DaysinWeek++;
if (DaysinWeek == 7) {
cout << "\n" << setw(3);
DaysinWeek = 0;
}

}

// Set up for the next month
if (DaysinWeek != 7) {
cout << "\n";
}

cout << endl;
day = DaysinWeek + 1;
}


int res,n=10;
  res=open("fifo1",O_WRONLY);
  write(res,"1",1);
  printf("Sender Process %d sent the data\n",getpid());


cout<<"press any number to continue\n";
cin>>endin;

return 0;
}