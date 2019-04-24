#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <dirent.h>
#include <string>

using namespace std;

/**                                                                                                                                                                                                 
 *                                                                                                                                                                                                  
 */
int main(){
int numArgs = 0;
  char line[512];
  char* start;
  int i = 1;
  cin.getline(line, 512);
  char* argv[11];
  start = strtok(line," ");
  char* cmd = start;
  argv[0] = cmd; 
  while(start != NULL){
   // printf("%s\n", start);
    numArgs++;
    start = strtok(NULL," ");
    argv[i] = start;
    i++;
  } // while  
   argv[i+1] = (char*) NULL;
                                                                                                                                                                                     

  cout << "done parsing" << endl;
  cout << "num args: " << numArgs << endl;
  for (int j = 0; j < numArgs; j++)
  {
   cout << argv[j] << endl;
  }
  
  execvp(cmd, argv);

} // main                                                                                                                                                                                           

