#include<iostream>
#include<unistd.h>
#include <stdlib.h>
#include<errno.h> 
#include <cstdlib>
#include<curses.h>
#include <semaphore.h>
#include <stdio.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>      
using namespace std;
// the criticle section
float ramValue, hardValue, coreValue;
float hardDrive;
float cores;
int processes[15];
int status;
int waitingQueue[15];
pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond;
int Ram[15] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 100, 100, 100, 130, 150};
void menuPannel()
{

    pthread_mutex_lock(&lock);
    ramValue -= 0.5;
    cout<<"                      Welcome "<<endl;
    cout<<"\n\tCalender.\t\t(Press 1)"
        <<"\tTime.\t\t\t(Press 2)"<<endl
        <<"\n\tNotepad.\t\t(Press 3)"
        <<"\tCalculator.\t\t(Press 4)"<<endl
        <<"\n\tCreate txt File.\t(Press 5)"
        <<"\tCopyss txt File.\t(Press 6)"<<endl
        <<"\n\tDelete txt File.\t(Press 7)"
        <<"\tMove txt File.\t\t(Press 8)"<<endl
        <<"\n\tNumber Guess Game.\t(Press 9)"
        <<"\tTic Tac Toe Game.\t(Press 10)"<<endl
        <<"\n\tZombie Kill Game.\t(Press 11)"
        <<"\tMine Sweeper Game.\t(Press 12)"<<endl
        <<"\n\tPlay Music.\t\t(Press 13)"
        <<"\tPacMan Game.\t\t(Press 14)"<<endl
        <<"\n\tSnake Game.\t\t(Press 15)"<<endl;
    pthread_mutex_unlock(&lock);
}
void ShowRam()
{
    if(ramValue > 0)
    {
        cout<< "Remaining Ram "<<ramValue<<endl;
    }
}
int main(int argc, char** argv)
{
    while(1)
    {
        int res;
    res = mkfifo("fifo",0777);
    printf("named pipe created\n");
    ramValue = atoi(argv[1])*1000;
    hardValue = atoi(argv[2])*1000;
    coreValue = atoi(argv[3]);
    int inp;
    pid_t child_pid, wpid;
    if( ramValue <=0 || hardValue <= 0 || coreValue <= 0 )
    {
        cout<<"Invalid Specifications Aborting....."<<endl;
        exit(0);
    }
    //pthread_t threadHandlers[15];
    //pthread_create(&threadHandlers[0], NULL, menuPannel, NULL);
    menuPannel();
    cout<<endl<<"You are using ram value of : "<<ramValue <<" Mbs "<<endl<<"The Hard Drive Of : "<<hardValue<<" Mbs "<<endl<<"And Total Number Of "<<coreValue<<" Cores"<<endl;
    //pthread_join(threadHandlers[0], NULL);
    cout<<"Enter the input to start the program"<<endl;
    cin>>inp;
    pid_t pid;
    printf("before fork\n");
    pid=fork();
    if(pid==0)
    {
        switch(inp)
        {

         case 1:
         {
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ calender.cpp -o calender");
            system("gnome-terminal --  \"./calender\"");
            char const *cmd = "./calender";
            char const *args[]={ "./calender" , NULL };
            execvp(args[0], argv); 
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);
         }
         case 2:
         {
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ time.cpp -o time");
            system("gnome-terminal --  \"./time\"");
            char const *cmd = "./time";
            char const *args[]={ "./time" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         case 3:
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ notepad.cpp -o notepad");
            system("gnome-terminal --  \"./notepad\"");
            char const *cmd = "./notepad";
            char const *args[]={ "./notepad" , NULL };
            execvp(args[0], argv); 
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
        case 4:
         {
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ calculator.cpp -o calculator");
            system("gnome-terminal --  \"./calculator\"");
            char const *cmd = "./calculator";
            char const *args[]={ "./calculator" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         case 5:
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ makefile.cpp -o makefile");
            system("gnome-terminal --  \"./makefile\"");
            char const *cmd = "./makefile";
            char const *args[]={ "./makefile" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         case 6:
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ copyfile.cpp -o copyfile");
            system("gnome-terminal --  \"./copyfile\"");
            char const *cmd = "./copyfile";
            char const *args[]={ "./copyfile" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         case 7:
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ deletefile.cpp -o deletefile");
            system("gnome-terminal --  \"./deletefile\"");
            char const *cmd = "./deletefile";
            char const *args[]={ "./deletefile" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         case 8:
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ movefile.cpp -o movefile");
            system("gnome-terminal --  \"./movefile\"");
            char const *cmd = "./movefile";
            char const *args[]={ "./movefile" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         case 9:
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ guessnumber.cpp -o guessnumber");
            system("gnome-terminal --  \"./guessnumber\"");
            char const *cmd = "./guessnumber";
            char const *args[]={ "./guessnumber" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         case 10:
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ tictactoe.cpp -o tictactoe");
            system("gnome-terminal --  \"./tictactoe\"");
            char const *cmd = "./tictactoe";
            char const *args[]={ "./tictactoe" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         case 11:
         {
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ zombiegame.cpp -o zombiegame");
            system("gnome-terminal --  \"./zombiegame\"");
            char const *cmd = "./zombiegame";
            char const *args[]={ "./zombiegame" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         case 12:
         {
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ minesweeper.cpp -o minesweeper");
            system("gnome-terminal --  \"./minesweeper\"");
            char const *cmd = "./minesweeper";
            char const *args[]={ "./minesweeper" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         case 13:
         {
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > Ram[inp -1]))
            {
                ramValue -= Ram[inp - 1];
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
            system("g++ music.cpp -o music");
            system("gnome-terminal --  \"./music\"");
            char const *cmd = "./music";
            char const *args[]={ "./music" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
        default: 
        {
            wait(NULL);
            int res,n;
            char *buffer;
            cout<<"Opened the file"<<endl;
            res=open("fifo", O_RDWR);
            if (res < 0 )
            {
                perror("ERROR: Error in opening the file");
                exit(0);
            }
            cout<<"Reading";
            n=read(res,buffer,1);
            if(n < 0)
            {
                perror("ERROR: Error in opening the pipe");
                exit(0);
            }
            cout<<endl<<"Read Data : "<<buffer[0]<<endl;
            int readData;
            readData = buffer[0] - '0';
            ramValue += readData;

            printf("My child's id is %d\n",pid);
            printf("I am parent having id %d\n",getpid());
        }
    }
    }
    }
    return 0;
}
