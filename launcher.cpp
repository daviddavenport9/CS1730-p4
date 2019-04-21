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

/**                                                                                                                                                                                                 
 * This launches a program (either from a command or a file path) from standard input and tells the user whether the program terminated by exit or signal                                           
 * @returns 0 on success, nonzero on error                                                                                                                                                          
 */
using namespace std;

int main() {

  string argument;
  cin >> argument;

  pid_t child = fork();
  int status;
  if(child < 0){ // if error                                                                                                                                                                        
    perror("fork error");
    return 1;
  }else if(child == 0){ // in child process                                                                                                                                                         
    //cout << "Child" << endl;                                                                                                                                                                      
    if(argument.at(0) == '.' && argument.at(1) == '/'){ // if the program begins with ./ -- is a local file                                                                                         
      execlp(argument.c_str(), argument.c_str(), (char *) NULL);
    }else{ // is a command                                                                                                                                                                          
      execlp(argument.c_str(), argument.c_str(), (char *) NULL);
    } // if                                                                                                                                                                                         
  }else{ // in parent                                                                                                                                                                               
    //cout << "Parent" << endl;                                                                                                                                                                     
    cout << "Waiting on child: " << getpid() << endl;
    wait(&status);
    if(WIFSIGNALED(status)){ // if terminated by signal                                                                                                                                             
      cout << "Termination by signal" << endl;
      int signalStatus = WTERMSIG(status);
      cout << "signal: " << signalStatus << " -- " << strsignal(signalStatus) << endl;
    }else if (WIFEXITED(status)){ // if terminated by exit                                                                                                                                          
      cout << "Termination by exit" << endl;
      int exitStatus = WEXITSTATUS(status);
      cout << "exit code: " << exitStatus << endl;
    } // if                                                                                                                                                                                         
  }  // if                                                                                                                                                                                          
  return 0;
} // main                                                             
