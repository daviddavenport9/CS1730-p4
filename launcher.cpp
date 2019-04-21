#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <dirent.h>
#include <string>
#include <sys/wait.h>
#include <signal.h>

using namespace std;

int main() {

string argument;
cin >> argument;

pid_t child = fork();
int status;

if(child < 0)
  {
    perror("fork error");
  }
else if(child == 0)//in child process
{
    cout << "Child" << endl;
}

else
{
cout << "Parent" << endl;
waitpid(child, &status, WNOHANG | WUNTRACED | WCONTINUED);
cout << "Waiting on child: " << getpid() << endl;
if(WIFSIGNALED(status))
  {
     cout << "Termination by signal" << endl; 
      int signalStatus = WTERMSIG(status); 
       cout << "signal: " << signalStatus << " -- " << strsignal(signalStatus) << endl;
  }//if
if (WIFEXITED(status)) 
   { 
      cout << "Termination by exit" << endl; 
      int exitStatus = WEXITSTATUS(status);  
      cout << "exit code: " << exitStatus << endl;
   }//if
}//else


return 0;
}
