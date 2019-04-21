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
}


return 0;
}
